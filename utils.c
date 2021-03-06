/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:41:01 by moerradi          #+#    #+#             */
/*   Updated: 2022/02/16 14:57:22 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	atoi_pro(const char *str)
{
	long	result;

	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
			result = result * 10 + *str++ - '0';
	}
	if (*str != '\0')
		return (-1);
	return (result);
}

static t_time	get_relative_time(t_time start)
{
	return (get_current_time() - start);
}

t_time	get_current_time(void)
{
	struct timeval	temp;
	t_time			ret;

	gettimeofday(&temp, NULL);
	ret = temp.tv_sec * 1000 + temp.tv_usec / 1000;
	return (ret);
}

void	status_router(t_status status)
{
	if (status == EATING)
		printf("is eating\n");
	else if (status == SLEEPING)
		printf("is sleeping\n");
	else if (status == TOOK_LFORK)
		printf("has taken a fork\n");
	else if (status == TOOK_RFORK)
		printf("has taken a fork\n");
	else if (status == THINKING)
		printf("is thinking\n");
	else if (status == DIED)
		printf("died\n");
}

void	print_status(t_data *data, int id, t_status status)
{
	t_time		temp;
	static bool	done = false;

	pthread_mutex_lock(&data->print);
	if (status == STOP)
		done = true;
	if (!done)
	{
		temp = get_relative_time(data->t0);
		printf("%lu %i ", temp, id);
		status_router(status);
		if (status == DIED)
			done = true;
	}
	pthread_mutex_unlock(&data->print);
}
