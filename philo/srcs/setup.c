/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:06:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/05/25 16:20:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	create a thread for each philo and will execute the function passed, here
		routine.
	if an error occur from the creation of a thread, will writes the error
	and return until the main to free all and stop the program here.
*/
int	create_thread(t_table *t)
{
	t_philo	*philo;

	philo = t->philo_prime;
	while (philo)
	{
		if (pthread_create(&philo->thread, NULL, &routine, philo) != 0)
		{
			printf("Error during the creation of a thread\n");
			return (-1);
		}
		philo = philo->next;
	}
	return (0);
}

/*
	assign the next_fork for each philo.
	if nbr_philo > 1 the next_fork of the last philo needs to points to the fork
		of the first philo (thus the if and the init)
	else only no other fork so points to NULL

	Might have a problem with how I get philo_prime, might need a function that
	returns philo_prime from the table if it exist else rerutn NULL.
*/
void	link_fork(t_table *t)
{
	t_philo	*philo;
	t_philo	*tmp;

	philo = t->philo_prime;
	while (philo->next)
	{
		philo->next_fork = &philo->next->fork;
		philo = philo->next;
	}
	if (t->nbr_philo > 1)
	{
		tmp = t->philo_prime;
		philo->next_fork = &tmp->fork;
	}
	else
		philo->next_fork = NULL;
}

/*
    init the next and prev of the philo passed in arg
    if just created the first philo/first iteration:
        init philo_prime to this philo passed in arg
    WORKS JUST FINE
*/
void	philo_sit_at_table(t_table *t, t_philo *philo)
{
	t_philo	*tmp;

	if (t->philo_prime == NULL)
		t->philo_prime = philo;
	else
	{
		tmp = t->philo_prime;
		while (tmp->next)
			tmp = tmp->next;
		philo->prev = tmp;
		tmp->next = philo;
	}
}

/*
	init now start_time to get the current time in milliseconds,
		it get the time at the creation of the philos.
	
	the while will call for each philo:
		init_philo to init some var of the struct: the structs already init,
        	the int/long int with common value for each philo or its id and
			the mutex for his fork that his lock in the loop.
		philo_sit_at_table() will init next and prev of the philo just created

	after the while, still needs to init the var for the thread function (?)
	and the link from one fork to the next
*/
int	philo_spawn(t_table *t)
{
	int		i;
	t_philo	*philo;

	i = 1;
	t->time->start_time = get_time();
	while (i <= t->nbr_philo)
	{
		philo = init_philo(t, i);
		pthread_mutex_lock(&philo->fork);
		if (philo == NULL)
			return (-1);
		philo_sit_at_table(t, philo);
		i++;
	}
	link_fork(t);
	return (0);
}
