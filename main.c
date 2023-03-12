/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:42:57 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/12 19:40:20 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosopher.h"

int	check_arg(int argc, char *argv[])
{
	int	index;
	int	innr_index;

	index = 1;
	while (index < argc)
	{
		innr_index = 0;
		while (argv[index][innr_index])
		{
			if (argv[index][innr_index] < '0' || argv[index][innr_index] > '9')
			{
				write(2, "Error: Wrong argument\n", 22);
				return (1);
			}
			innr_index++;
		}
		index++;
	}
	return (0);
}

int	error_valid(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		return (1);
	}
	if (error_valid(argc, argv))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	pthread_mutex_t	*forks;
	pthread_t		*philos;


	if (check_arg(argc, argv) == 1)
		return (1);
	forks = (int *)malloc(sizeof(int) * ft_atoi(argv[1]));
	while (1)
	{
		

	}
	return (0);
}