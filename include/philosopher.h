/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:43:49 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/25 21:44:08 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <struct.h>

# include "struct.h"

// parse
int	check_arg(int argc, char *argv[]);

// utils
int	ft_atoi(const char *str);
size_t	relative_time(struct timeval time_before);
int	check_is_alive(t_philo* philo);

// setting
t_common	*set_common(char **argv);
t_philo		*philo_set(t_common *common);

// philo actions
void	philo_start(t_philo *philo, t_common *common, int num_of_times);

// main_thread_task
void	main_thread_task(t_philo *philo, t_common *common);

#endif