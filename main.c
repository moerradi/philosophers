/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:33:21 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/12 18:43:34 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



int	start(t_philo *philos)
{
	int i;
	int	num;

	num = philos->data->philos_number;
	i = 0;
	while (i < num)
	{
		if(pthread_create(&(philos[i].id), NULL, &routine, philos + i))
			return (0);
		usleep(100);
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
	printf("%lu\n", data.t0);
	if (!start(philos))
	{
		printf("An error occured while starting philisophers\n");
		return (1);	
	}
}
