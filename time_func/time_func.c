/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:54:28 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/26 20:13:12 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

size_t	relative_time(struct timeval time_before)
{
	struct timeval	now;

	gettimeofday(&now, 0);
	// printf("before: %ld, %d\n", time_before.tv_sec, time_before.tv_usec);
	// printf("now: %ld, %d\n", now.tv_sec, now.tv_usec);
	return ((now.tv_sec * 1000 * 1000 + now.tv_usec - (time_before.tv_sec * 1000 * 1000 + time_before.tv_usec)) / 1000);
}
