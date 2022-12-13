/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:09:16 by yaktas            #+#    #+#             */
/*   Updated: 2022/12/05 19:15:23 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat_spagetti(t_philo *ph)
{
	pthread_mutex_lock(&(ph->rules->forks[ph->left_hand]));
	action_philo("has taken a fork", ph->rules, ph->id);
	if (ph->rules->philo_num == 1)
		return (1);
	pthread_mutex_lock(&(ph->rules->forks[ph->right_hand]));
	action_philo("has taken a fork", ph->rules, ph->id);
	pthread_mutex_lock(&(ph->rules->die_check));
	action_philo("is eating", ph->rules, ph->id);
	ph->last_eat = timestamp();
	pthread_mutex_unlock(&(ph->rules->die_check));
	wait_sleep(ph->rules->eat_time, ph->rules);
	ph->meal_count++;
	pthread_mutex_unlock(&(ph->rules->forks[ph->right_hand]));
	pthread_mutex_unlock(&(ph->rules->forks[ph->left_hand]));
	return (0);
}

void	*resources(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->id % 2 == 1)
		usleep(15000);
	while (ph->rules->died)
	{
		if (ph->rules->all_ate == 0 || ph->rules->died == 0)
			break ;
		if (eat_spagetti(ph))
			return (NULL);
		action_philo("is sleeping", ph->rules, ph->id);
		wait_sleep(ph->rules->sleep_time, ph->rules);
		action_philo("is tkinking", ph->rules, ph->id);
	}
	return (NULL);
}

void	destroy_all(t_arg *rules)
{
	int	i;

	i = 0;
	while (rules->philo_num > i)
	{
		pthread_join((rules->philo + i)->philos, NULL);
		i++;
	}
	i = 0;
	while (rules->philo_num > i)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->writing);
	pthread_mutex_destroy(&rules->die_check);
}

void	dead_checker(t_arg *r)
{
	while (r->all_ate)
	{
		r->i = -1;
		while ((++r->i < r->philo_num) && r->died)
		{
			pthread_mutex_lock(&(r->die_check));
			if (time_diff((r->philo[r->i].last_eat),
					timestamp()) > r->die_time)
			{
				action_philo("died", r, r->philo->id);
				r->died = 0;
			}
			pthread_mutex_unlock(&(r->die_check));
			usleep(100);
		}
		if (r->died == 0)
			break ;
		r->i = 0;
		while (r->i < r->philo_num && r->must_eat != -1
			&& r->philo[r->i].meal_count >= r->must_eat)
			r->i++;
		if (r->i == r->philo_num)
			r->all_ate = 0;
	}
}

int	handle_resources(t_arg *rules)
{
	int	i;

	i = 0;
	rules->first_time = timestamp();
	while (i < rules->philo_num)
	{
		if (pthread_create(&((rules->philo + i)->philos), NULL, resources,
				rules->philo + i))
			return (-1);
		(rules->philo + i)->last_eat = timestamp();
		i++;
	}
	dead_checker(rules);
	destroy_all(rules);
	return (0);
}
