/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:33:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/10/22 18:40:36 by moerradi         ###   ########.fr       */
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
	if (data->time_to_die <= 0)
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

int	init_forks()
{
	
}

int	init_philos(t_data *data)
{
	int i;

	data->philos = malloc(sizeof(pthread_t) * data->philos_number);
	i = 0;	
	while (i < data->philos_number)
	{
		if (pthread_create(&data->philos[i], NULL, routine, data) != 0)
			return (0);
		usleep(30);
	}
}

int	init_forks(t_data *data)
{
	int i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_number);
	i = 0;	
	while (i < data->philos_number)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (0);
	}
}

int	destroy_forks(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philos_number)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
	}
}

int	init(int argc, char **argv, t_data *data)
{
	if (!init_data(&data, argv, argc == 6))
		return (0);
	if (!init_forks(data))
		return (0);
	if (pthread_mutex_init(&data->print, NULL))
		return (0);
	data->t0 = get_current_time();
	if (!init_philos(data))
		return (0);
}


int	main(int argc, char **argv)
{
	
	t_data		data;

	if (argc != 5 && argc != 6)
	{
		printf("usage : ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (!init(argc, argv, &data))
	{
		printf("an error occured while initializing threads\n");
		return (1);
	}
}
