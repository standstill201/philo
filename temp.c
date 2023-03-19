/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:42:40 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/18 18:53:58 by seokjyoo         ###   ########.fr       */
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
    size_t    time_start;
    struct timeval    current;

    gettimeofday(&current, 0);
    time_start = current.tv_sec * 1000 * 1000 + current.tv_usec;
    printf("%ld\n", time_start);
    printf("%ld\n", relative_time(time_start));
}

// 결과
4,294,967,295
1679133181340428