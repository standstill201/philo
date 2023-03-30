/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread_task.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:29:23 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/30 14:34:04 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	find_one_to_arr(t_common *common)
{
	int	index;

	index = 0;
	while (index < common->number_of_philo)
	{
		if (common->numbers_ended[index] == 0)
			return (1);
		index++;
	}
	return (0);
}

int	main_thread_kill(t_philo *philo)
{
	int		index;

	index = 0;
	if (relative_time(philo->last_eat_time) > philo->common->time_to_die)
	{
		pthread_mutex_lock(&philo->common->print_m);
		if (philo->common->is_ended == 0)
			printf("%03ld %d dead\n", relative_time(philo->common->start_time), philo->id);
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
	while (find_one_to_arr(common))
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
