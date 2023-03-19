/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:26:14 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/19 18:03:35 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	printf("%d has taken a left fork\n", philo->id);
	pthread_mutex_lock(philo->right_fork_mutex);
	printf("%d has taken a right fork\n", philo->id);
	printf("%d is eating\n", philo->id);
	philo->eat_count++;
	usleep(philo->common->time_to_eat * 1000);
	gettimeofday(&philo->last_eat_time, NULL);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
}

void	philo_sleep(t_philo *philo)
{
	printf("%d is sleeping\n", philo->id);
	usleep(philo->common->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
}

void	*philo_action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->common->init_m);
	pthread_mutex_unlock(philo->common->init_m);
	if(philo->id % 2 == 0)
		usleep(300);
	while (philo->is_alive && philo->eat_count < philo->common->number_of_times)
	{
		philo_eat(philo);
		if (philo->is_alive == 0)
			break ;
		philo_sleep(philo);
		if (philo->is_alive == 0)
			break ;
		philo_think(philo);
	}
	printf("!!!!!!!!!!!!!!!!!!\n");
	return (NULL);
}

void	philo_start(t_philo *philo, t_common *common, int num_of_times)
{
	int				index;
	pthread_mutex_t	init_m;

	index = 0;
	pthread_mutex_init(&init_m, NULL);
	common->init_m = &init_m;
	pthread_mutex_lock(&init_m);
	while (index < common->number_of_philo)
	{
		pthread_create(&philo[index].thread, NULL, philo_action, &philo[index]);
		index++;
	}
	sleep(1);
	gettimeofday(&common->start_time, NULL);
	while (index--)
		philo[index].last_eat_time = philo[index].common->start_time;
	pthread_mutex_unlock(&init_m);
	// main_thread_task(philo, common, num_of_times);
	sleep(2);
	pthread_mutex_destroy(&init_m);
	while (index < common->number_of_philo)
		pthread_join(philo[index++].thread, NULL);
}
