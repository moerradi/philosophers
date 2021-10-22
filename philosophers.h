/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:41:09 by moerradi          #+#    #+#             */
/*   Updated: 2021/10/22 11:40:34 by moerradi         ###   ########.fr       */
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

typedef unsigned long t_time;
typedef struct s_data
{
	int	philos_number;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_eats;
	pthread_mutex_t	*forks;
	pthread_t		*philos;
	pthread_mutex_t	print;
	t_time	startimes;
}				t_data;

int		atoi_pro(const char *str);
void	*routine(void *data);

#endif