/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:41:09 by moerradi          #+#    #+#             */
/*   Updated: 2021/10/24 15:16:14 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef unsigned long	t_time;
typedef	enum			e_status
{
	EATING,
	THINKING,
	SLEEPING,
	DIED,
	TOOK_LFORK,
	TOOK_RFORK
}						t_status;
typedef struct 			s_data
{
	int					philos_number;
	t_time				time_to_die;
	t_time				time_to_eat;
	t_time				time_to_sleep;
	unsigned long		max_eats;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
	t_time				t0;
	bool				someone_died;
}						t_data;

typedef struct			s_philo
{
	int					index;
	pthread_t			id;
	t_time				last_eated;
	t_data				*data;
}						t_philo;

t_time			get_current_time();
unsigned long	atoul_pro(const char *str);
void			*routine(void *data);
int				init(int argc, char **argv, t_data *data, t_philo **philos);

#endif