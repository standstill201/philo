/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:54:28 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/18 18:56:01 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

size_t	relative_time(size_t time_before)
{
	struct timeval	now;

	gettimeofday(&now, 0);
	return (now.tv_sec * 1000 * 1000 + now.tv_usec - time_before);
}
