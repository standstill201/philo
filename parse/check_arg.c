/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:23:35 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/17 14:06:42 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/philosopher.h"

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
