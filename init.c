/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:30:12 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/12 21:46:58 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ret_error(const char *str)
{
	printf("%s should be a strictly positive integer.\n", str);
	return (0);
}

int	init_data(t_data *data, char **argv, bool last_arg)
{
	data->philos_number = atoi_pro(argv[1]);
	if (data->philos_number <= 0)
		return (ret_error("Philisophers number"));
	data->time_to_die = atoi_pro(argv[2]);
	if (data->time_to_die <= 0)
		return (ret_error("time to die"));
	data->time_to_eat = atoi_pro(argv[3]);
	if (data->time_to_eat <= 0)
		return (ret_error("time to eat"));
	data->time_to_sleep = atoi_pro(argv[4]);
	if (data->time_to_sleep <= 0)
		return (ret_error("time to sleep"));
	if (last_arg)
	{
		data->max_eats = atoi_pro(argv[5]);
		if (data->max_eats <= 0)
			return (ret_error("number of times each philosopher must eat"));
	}
	else
		data->max_eats = -1;
	return (1);
}

int	init_mutexes(t_data *data)
{
	int i;

	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_number);
	if (!data->forks)
		return(1);
	i = 0;	
	while (i < data->philos_number)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL))
			return (0);
	}
	return (1);
}

t_philo	*init(int argc, char **argv, t_data *data)
{
	int		i;
	t_philo	*ret;

	if (!init_data(data, argv, argc == 6))
		return (NULL);
	if (!init_mutexes(data))
		return (NULL);
	data->t0 = get_current_time();
	ret = (t_philo *)malloc(sizeof(t_philo) * data->philos_number);
	i = 0;
	while (i < data->philos_number)
	{
		ret[i].index = i + 1;
		ret[i].lfork = i;
		ret[i].rfork = (i + 1) % data->philos_number;
		ret[i].eat_count = 0;
		ret[i++].data = data;
		pthread_mutex_init(&ret[i].super, NULL);
	}
	return (ret);
}
