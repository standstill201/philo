/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:42:57 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/17 20:55:11 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosopher.h"

int	main(int argc, char *argv[])
{
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_t		*philos;
	t_common		*common;
	t_philo			*philo;

	if (check_arg(argc, argv) == 1)
		return (1);
	common = set_common(argv);
	philo = philo_set(common);
	philo_start(philo, common);
	return (0);
}

// 1000
// 1000000