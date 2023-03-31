/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread_task.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:29:23 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/31 18:47:50 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	main_thread_kill(t_philo *philo)
{
	int				index;
	struct timeval	now;

	pthread_mutex_lock(&philo->common->print_m);
	now = philo->last_eat_time;
	pthread_mutex_unlock(&philo->common->print_m);
	index = 0;
	if (relative_time(now) > philo->common->time_to_die)
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (philo->common->is_ended == 0 && (philo->eat_count < philo->common
				->number_of_times || philo->common->number_of_times < 0))
			printf("%03ld %d died\n", relative_time(now), philo->id);
		philo->common->is_ended = 1;
		pthread_mutex_unlock(&philo->common->print_m);
		return (1);
	}
	return (0);
}

void	main_thread_task(t_philo *philo, t_common *common)
{
	int	index;

	index = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (common->is_ended)
		{
			pthread_mutex_unlock(&philo->common->print_m);
			break ;
		}
		pthread_mutex_unlock(&philo->common->print_m);
		while (index < common->number_of_philo)
		{
			if (main_thread_kill(&philo[index]))
				return ;
			index++;
		}
		index = 0;
	}
}
