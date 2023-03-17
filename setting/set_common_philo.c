/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_common_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:34:41 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/17 20:37:15 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

t_common	*set_common(char **argv)
{
	t_common	*common;
	int			index;

	common = (t_common *)malloc(sizeof(t_common));
	common->number_of_philo = ft_atoi(argv[1]);
	common->time_to_die = ft_atoi(argv[2]);
	common->time_to_eat = ft_atoi(argv[3]);
	common->time_to_sleep = ft_atoi(argv[4]);
	common->forks = (int *)malloc(sizeof(int) * common->number_of_philo);
	common->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * common->number_of_philo);
	common->philos = (t_philo *)malloc(sizeof(t_philo) * common->number_of_philo);
	if (argv[5])
		common->number_of_times = ft_atoi(argv[5]);
	else
		common->number_of_times = -1;
	index = 0;
	while (index < common->number_of_philo)
	{
		common->forks[index] = 0;
		pthread_mutex_init(&common->forks_mutex[index], NULL);
		index++;
	}
	return (common);
}

void	set_fork_mutex(t_philo *philo, int index)
{
	philo[index].left_fork_mutex = &philo[index].common->forks_mutex[index - 1];
	if (index == 0)
	{
		philo[index].right_fork_mutex = &philo[index].common->forks_mutex[0];
		philo[index].left_fork_mutex = &philo[index].common->forks_mutex[philo[index].common->number_of_philo - 1];
	}
	else
		philo[index].right_fork_mutex = &philo[index].common->forks_mutex[index];
}

t_philo	*philo_set(t_common *common)
{
	t_philo	*philo;
	int		index;

	philo = (t_philo *)malloc(sizeof(t_philo) * common->number_of_philo);
	index = 0;
	while (index < common->number_of_philo)
	{
		philo[index].id = index + 1;
		philo[index].eat_count = 0;
		philo[index].last_eat_time = 0;
		philo[index].common = common;
		set_fork_mutex(philo, index);
		index++;
	}
	return (philo);
}