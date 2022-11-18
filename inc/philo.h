/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:59:24 by yaktas            #+#    #+#             */
/*   Updated: 2022/11/04 22:59:24 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_sim
{
	int		total_meal;
	int		is_dead;
	int		philo_num;
	long	start_time;
	int		time_sleep;
} t_sim;

typedef struct	s_philo
{
	pthread_t	thread;
	int			p_id;
	int			l_fork;
	int			r_fork;
	int			eat_count;
	long		last_eat_time;
	t_sim		*sim;
} s_philo;



#endif