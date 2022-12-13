/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_screens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:09:21 by yaktas            #+#    #+#             */
/*   Updated: 2022/12/05 19:09:25 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	wait_sleep(long long wait_time, t_arg *rules)
{
	long long	i;

	i = timestamp();
	while (rules->died)
	{
		if (wait_time <= time_diff(i, timestamp()))
			break ;
		if (rules->philo_num < 50)
			usleep(50);
	}
}
