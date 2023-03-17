/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:42:40 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/17 20:56:26 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

size_t    relative_time(size_t time_start)
{
    struct timeval    current;

    gettimeofday(&current, 0);
    return (current.tv_sec * 1000 * 1000 + current.tv_usec - time_start);
}

int main()
{
	size_t time_start;

	time_start = relative_time(0);
	usleep(100);
	printf("%ld\n", relative_time(time_start));
}
