/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:30:12 by moerradi          #+#    #+#             */
/*   Updated: 2021/10/24 15:48:34 by moerradi         ###   ########.fr       */
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
	data->philos_number = atoul_pro(argv[1]);
	if (data->philos_number <= 0)
		return (ret_error("Philisophers number"));
	data->time_to_die = atoul_pro(argv[2]);
	if (data->time_to_die <= 0)
		return (ret_error("time to die"));
	data->time_to_eat = atoul_pro(argv[3]);
	if (data->time_to_eat <= 0)
		return (ret_error("time to eat"));
	data->time_to_sleep = atoul_pro(argv[4]);
	if (data->time_to_die <= 0)
		return (ret_error("time to sleep"));
	if (last_arg)
	{
		data->max_eats = atoul_pro(argv[5]);
		if (data->max_eats <= 0)
			return (ret_error("number of times each philosopher must eat"));
	}
	else
		data->max_eats = -1;
	return (1);
}

int	init_forks(t_data *data)
{
	int i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_number);
	i = 0;	
	while (i < data->philos_number)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL))
			return (0);
	}
	return (1);
}

int	init(int argc, char **argv, t_data *data, t_philo **philos)
{
	int i;
	
	if (!init_data(data, argv, argc == 6))
		return (0);
	if (!init_forks(data))
		return (0);
	if (pthread_mutex_init(&data->print, NULL))
		return (0);
	data->t0 = get_current_time();
	printf("%lu\n", data->t0);
	*philos = (t_philo *)malloc(sizeof(t_philo) * data->philos_number);
	(*philos)->data = (t_data *)malloc(sizeof(t_data));
	i = 0;
	while (i < data->philos_number)
		philos[i++]->data = data;
	// i = 0;
	// *philos[0].data = data;
	// printf("%lu\n", philos[0].data->t0);
	// 	*philos[i++]->data = *data;
	return (1);
}
