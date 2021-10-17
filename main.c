/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:33:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/10/15 19:07:38 by moerradi         ###   ########.fr       */
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



int init_philos(t_data *data)
{
	pthread_t thread;

	if (pthread_create(&thread, NULL, routine, data) != 0)
		return (0);
	return(1);
	// else
		// printf("lhbal\n");
}

int	main(int argc, char **argv)
{
	
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("usage : ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (!init_data(&data, argv, argc == 6))
		return (1);
	if (!init_philos(&data))
		return (1);
	// // while (1)
		usleep(300);
}
