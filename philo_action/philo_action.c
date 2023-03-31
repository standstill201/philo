/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:26:14 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/31 18:25:57 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	philo_wait(t_philo *philo, int trg)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (trg == 1)
	{
		while (relative_time(now) < philo->common->time_to_eat)
		{
			pthread_mutex_lock(&philo->common->print_m);
			if (philo->common->is_ended)
			{
				pthread_mutex_unlock(&philo->common->print_m);
				break ;
			}
			pthread_mutex_unlock(&philo->common->print_m);
			usleep(50);
		}
	}
	else
	{
		while (relative_time(now) < philo->common->time_to_sleep)
		{
			pthread_mutex_lock(&philo->common->print_m);
			if (philo->common->is_ended)
			{
				pthread_mutex_unlock(&philo->common->print_m);
				break ;
			}
			pthread_mutex_unlock(&philo->common->print_m);
			usleep(50);
		}
	}
}

int	check_is_alive(t_philo* philo)
{
	
	pthread_mutex_lock(&philo->common->print_m);
	if (philo->common->is_ended == 1)
	{
		pthread_mutex_unlock(&philo->common->print_m);
		return (0);
	}
	pthread_mutex_unlock(&philo->common->print_m);
	return (1);
}

void	philo_eat_left(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	if (check_is_alive(philo))
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (philo->common->is_ended == 0)
			printf("%03ld %d has taken a fork\n", relative_time(philo->common->start_time), philo->id);
		pthread_mutex_unlock(&philo->common->print_m);
	}
	pthread_mutex_lock(philo->right_fork_mutex);
	if (check_is_alive(philo))
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (philo->common->is_ended == 0)
			printf("%03ld %d has taken a fork\n", relative_time(philo->common->start_time), philo->id);
		pthread_mutex_unlock(&philo->common->print_m);
	}
	if (check_is_alive(philo))
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (philo->common->is_ended == 0)
			printf("%03ld %d is eating\n", relative_time(philo->common->start_time), philo->id);
		// pthread_mutex_unlock(&philo->common->print_m);
		// pthread_mutex_lock(&philo->common->print_m);
		gettimeofday(&philo->last_eat_time, NULL);
		pthread_mutex_unlock(&philo->common->print_m);
	}
	philo->eat_count++;
	philo_wait(philo, 1);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
}

void	philo_eat_right(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork_mutex);
	if (check_is_alive(philo))
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (philo->common->is_ended == 0)
			printf("%03ld %d has taken a fork\n", relative_time(philo->common->start_time), philo->id);
		pthread_mutex_unlock(&philo->common->print_m);
	}
	pthread_mutex_lock(philo->left_fork_mutex);
	if (check_is_alive(philo))
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (philo->common->is_ended == 0)
			printf("%03ld %d has taken a fork\n", relative_time(philo->common->start_time), philo->id);
		pthread_mutex_unlock(&philo->common->print_m);
	}
	if (check_is_alive(philo))
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (philo->common->is_ended == 0)
			printf("%03ld %d is eating\n", relative_time(philo->common->start_time), philo->id);
		gettimeofday(&philo->last_eat_time, NULL);
		pthread_mutex_unlock(&philo->common->print_m);
	}
	philo->eat_count++;
	philo_wait(philo, 1);
	pthread_mutex_unlock(philo->right_fork_mutex);
	pthread_mutex_unlock(philo->left_fork_mutex);
}

void	philo_sleep(t_philo *philo)
{
	if (check_is_alive(philo))
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (philo->common->is_ended == 0)
			printf("%03ld %d is sleeping\n", relative_time(philo->common->start_time), philo->id);
		pthread_mutex_unlock(&philo->common->print_m);
	}
	philo_wait(philo, 0);
}

void	philo_think(t_philo *philo)
{
	if (check_is_alive(philo))
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (philo->common->is_ended == 0)
			printf("%03ld %d is thinking\n", relative_time(philo->common->start_time), philo->id);
		pthread_mutex_unlock(&philo->common->print_m);
	}
}

void	*philo_action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->common->init_m);
	pthread_mutex_unlock(&philo->common->init_m);
	if(philo->id % 2 == 0)
		usleep(300);
	while (check_is_alive(philo))
	{
		if (philo->common->number_of_times > 0 && philo->eat_count >= philo->common->number_of_times)
			break ;
		if (philo->id % 2 == 0)
			philo_eat_right(philo);
		else
			philo_eat_left(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}


void	philo_start(t_philo *philo, t_common *common, int num_of_times)
{
	int		index;

	index = 0;
	pthread_mutex_init(&common->init_m, NULL);
	pthread_mutex_init(&common->print_m, NULL);
	pthread_mutex_lock(&common->init_m);
	while (index < common->number_of_philo)
	{
		pthread_create(&philo[index].thread, NULL, philo_action, &philo[index]);
		index++;
	}
	usleep(100);
	gettimeofday(&common->start_time, NULL);
	while (index--)
		philo[index].last_eat_time = philo[index].common->start_time;
	pthread_mutex_unlock(&common->init_m);
	pthread_mutex_destroy(&common->init_m);
	main_thread_task(philo, common);
	while (index < common->number_of_philo)
		pthread_join(philo[index++].thread, NULL);
}
