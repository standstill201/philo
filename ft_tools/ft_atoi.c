/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:22:33 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/17 20:37:05 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	return_value;

	return_value = 0;
	sign = 1;
	while (*str == '\n' || *str == '\t' || *str == '\f' || *str == '\r'
		|| *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		return_value = return_value * 10 + *str - '0';
		str++;
	}
	return (return_value * sign);
}