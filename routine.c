/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:41:06 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/16 14:47:28 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	custom_sleep(useconds_t time, t_data *data)
{
	t_time	t;

	t = get_current_time();
	while (!data->death)
	{
		if ((get_current_time() - t) * 1000 >= time)
			break ;
		usleep(300);
	}
}

void	eat(t_philo	*philo)
{
	pthread_mutex_lock(&philo->super);
	philo->iseating = true;
	philo->last_eated = get_current_time();
	print_status(philo->data, philo->index, EATING);
	custom_sleep(philo->data->time_to_eat * 1000, philo->data);
	philo->eat_count++;
	philo->iseating = false;
	pthread_mutex_unlock(&philo->super);
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
	t_philo		*tmp;
	t_data		*data;
	pthread_t	super;

	if (pthread_create(&super, NULL, &supervisor, philo))
		return (NULL);
	pthread_detach(super);
	tmp = (t_philo *)philo;
	data = tmp->data;
	while (!data->death && !tmp->done)
	{
		takeforks(tmp);
		eat(tmp);
		print_status(data, tmp->index, SLEEPING);
		pthread_mutex_unlock(data->forks + tmp->lfork);
		pthread_mutex_unlock(data->forks + tmp->rfork);
		custom_sleep(data->time_to_sleep * 1000, data);
		print_status(data, tmp->index, THINKING);
	}
	return (NULL);
}
