/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:33:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/10/10 19:37:45 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ret_error(const char *str)
{
	printf("%s should be a strictly positive integer.", str);
	return (0);
}

int	init_data(t_data *data, char **argv, bool last_arg)
{
	data->philos_number = atoi_pro(argv[1]);
	if (data->philos_number <= 0)
		return (ret_error("Philisophers number"));
	data->time_to_die = atoi_pro(argv[2]);
		return (ret_error("time to die"));
	data->time_to_eat = atoi_pro(argv[3]);
		return (ret_error("time to eat"));
	data->time_to_sleep = atoi_pro(argv[4]);
		return ("time to sleep");
	if (last_arg)
	{
		data->max_eats = atoi_pro(argv[5]);
		if (data->max_eats <= 0)
			return (ret_error("number of times each philosopher must eat"));
	}
	else
		data->max_eats = -1;
}

int		main(int argc, char argv)
{
	t_data data;

	if (argc != 5 && argc != 6)
		return (1);
	if (!init_data(&data, argv, argc == 6))
		return (1);
}