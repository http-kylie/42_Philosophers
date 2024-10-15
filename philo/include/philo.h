/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:23:53 by kytan             #+#    #+#             */
/*   Updated: 2024/10/15 12:18:16 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>

typedef pthread_mutex_t		t_mutex;

typedef enum e_return
{
	SUCCESS,
	E_INVALID_ARGS,
	E_INVALID_INPUT,
	E_MALLOC
}	t_return;

typedef struct s_input
{
	int		argc;
	char	**argv;
}	t_input;

/* Philo struct */
typedef struct s_philo
{
	pthread_t		tid;
	t_mutex			fork;
	long				last_eat;
	t_mutex			last_eat_lock;
	struct s_philo	*next;
	struct s_philo	*prev;
	void			*data;
}	t_philo;




/* Main Functions */

/* Sub Functions */

/* Utilities */

#endif