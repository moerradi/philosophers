/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:41:09 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/12 21:46:04 by moerradi         ###   ########.fr       */
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
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					max_eats;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
	t_time				t0;
	bool				someone_died;
}						t_data;

typedef struct			s_philo
{
	bool				iseating;
	int					index;
	pthread_t			id;
	t_time				last_eated;
	t_data				*data;
	int					lfork;
	int					rfork;
	int					eat_count;
	pthread_mutex_t		super;
}						t_philo;

t_time			get_current_time();
int				atoi_pro(const char *str);
void			*routine(void *philo);
t_philo			*init(int argc, char **argv, t_data *data);
void			print_status(t_data *data, int id, t_status status);

#endif