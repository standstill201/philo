/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:42:57 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/26 20:02:53 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosopher.h"

int	main(int argc, char *argv[])
{
	pthread_t		*philos;
	t_common		*common;
	t_philo			*philo;

	if (check_arg(argc, argv) == 1)
		return (1);
	common = set_common(argv);
	philo = philo_set(common);
	if (argc == 6)
		philo_start(philo, common, ft_atoi(argv[5]));
	else
		philo_start(philo, common, -1);
	return (0);
}
