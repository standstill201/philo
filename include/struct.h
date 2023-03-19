/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:57:47 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/03/19 17:09:00 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_philo t_philo;
typedef struct s_common t_common;

typedef struct	s_common
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times;
	int				*forks;
	t_philo			*philos;
	pthread_mutex_t	*init_m;
	pthread_mutex_t	*forks_mutex;
	struct timeval	start_time;
}	t_common;

typedef struct	s_philo
{
	int				id;
	int				eat_count;
	int				is_alive;
	struct timeval	last_eat_time;
	pthread_mutex_t	*live_m;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	pthread_t		thread;
	t_common		*common;
}	t_philo;

#endif