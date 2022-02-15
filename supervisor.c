/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:38:31 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/15 08:41:39 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*handle_maxeats(t_data *data)
{
	print_status(data, 0, STOP);
	pthread_mutex_unlock(&data->s_died);
	return (NULL);
}

void	increase_max_reached(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->max_eats_m);
	if (!philo->done)
	{
		philo->data->max_reached++;
		philo->done = true;
	}
	pthread_mutex_unlock(&philo->data->max_eats_m);
}

void	*supervisor(void *philo)
{
	t_philo	*tmp;
	t_data	*data;
	t_time	since_last;

	tmp = (t_philo *)philo;
	data = tmp->data;
	while (!data->death)
	{
		pthread_mutex_lock(&tmp->super);
		since_last = get_current_time() - tmp->last_eated;
		if (since_last >= (t_time)data->time_to_die && !tmp->iseating)
		{
			data->death = true;
			print_status(data, tmp->index, DIED);
			pthread_mutex_unlock(&data->s_died);
			return (NULL);
		}
		if (data->max_eats != -1 && tmp->eat_count >= data->max_eats)
			increase_max_reached(tmp);
		if (data->max_reached == data->philos_number)
			return (handle_maxeats(data));
		pthread_mutex_unlock(&tmp->super);
		usleep(1000);
	}
	return (NULL);
}
