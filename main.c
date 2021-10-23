/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:33:21 by moerradi          #+#    #+#             */
/*   Updated: 2021/10/23 16:30:23 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ret_error(const char *str)
{
	printf("%s should be a strictly positive integer.\n", str);
	return (0);
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
	if (!init(argc, argv, &data))
	{
		printf("An error occured while initializing philisophers\n");
		return (1);
	}
	philos =  (t_philo *)malloc(sizeof(t_philo) * data.philos_number);
	if (!start(!philos))
	{
		printf("An error occured while starting philisophers\n");
		return (1);	
	}
}
