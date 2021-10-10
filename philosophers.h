#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_data
{
	int	philos_number;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_eats;
}	t_data;

int	atoi_pro(const char *str);

#endif