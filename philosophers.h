/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:41:09 by moerradi          #+#    #+#             */
/*   Updated: 2021/10/15 19:19:27 by moerradi         ###   ########.fr       */
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

typedef struct s_data
{
	int	philos_number;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_eats;
	int	hello;
}	t_data;

int		atoi_pro(const char *str);
void	*routine(void *data);

#endif