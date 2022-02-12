/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:41:06 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/12 22:01:24 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	eat(t_philo	*philo)
{
	pthread_mutex_lock(&philo->super);
	philo->iseating = 1;
	philo->last_eated = get_current_time();
	print_status(EATING, )
	
}

void	takeforks(t_philo *philo)
{
	pthread_mutex_lock(philo->data->forks + philo->lfork);
	print_status(philo->data, philo->index, TOOK_LFORK);
	pthread_mutex_lock(philo->data->forks + philo->rfork);
	print_status(philo->data, philo->index, TOOK_RFORK);
}



void	*routine(void *philo)
{
	t_philo	*tmp;
	t_data	*data;

	tmp = (t_philo*)philo;
	// create supervisor thread
	data = tmp->data;
	while (1)
	{
		takeforks(tmp);
		print_status(data, tmp->index, EATING);
		usleep(data->time_to_eat);
		print_status(data, tmp->index, THINKING);
		print_status(data, tmp->index, SLEEPING);
	}
	return (NULL);
}