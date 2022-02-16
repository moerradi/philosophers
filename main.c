/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:33:21 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/16 16:21:36 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	destroy_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_number)
	{
		if (pthread_mutex_destroy(&data->forks[i++]) != 0)
			return (0);
	}
	return (1);
}

int	cleanup(t_philo *philos, t_data *data)
{
	int	i;

	if (!destroy_forks(data))
		return (0);
	if (!pthread_mutex_destroy(&data->print))
		return (0);
	if (!pthread_mutex_destroy(&data->s_died))
		return (0);
	if (!pthread_mutex_destroy(&data->max_eats_m))
		return (0);
	i = 0;
	while (i < data->philos_number)
	{
		if (!pthread_mutex_destroy(&philos[i].super))
			return (0);
		i++;
	}
	free(data->forks);
	free(philos);
	return (1);
}

int	start(t_philo *philos)
{
	int	i;
	int	num;

	num = philos->data->philos_number;
	i = 0;
	while (i < num)
	{
		if (!(i % 2)
			&& pthread_create(&(philos[i].id), NULL, &routine, philos + i))
			return (0);
		usleep(50);
		i++;
	}
	i = 0;
	while (i < num)
	{
		if ((i % 2)
			&& pthread_create(&(philos[i].id), NULL, &routine, philos + i))
			return (0);
		usleep(50);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philos;

	if (argc != 5 && argc != 6)
	{
		printf("usage : ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	philos = init(argc, argv, &data);
	if (!philos)
	{
		printf("An error occured while initializing philisophers\n");
		return (1);
	}
	if (!start(philos))
	{
		printf("An error occured while starting philisophers\n");
		return (1);
	}
	pthread_mutex_lock(&data.s_died);
	pthread_mutex_unlock(&data.s_died);
	usleep(10000);
	cleanup(philos, &data);
	return (0);
}
