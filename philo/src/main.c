/* ************************************************************************** */
/*			*/
/*		:::	  ::::::::   */
/*   main.c			 :+:	  :+:	:+:   */
/*			+:+ +:+		 +:+	 */
/*   By: kytan <kytan@student.42kl.edu.my>		  +#+  +:+	   +#+		*/
/*		+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/11 11:22:50 by kytan			 #+#	#+#			 */
/*   Updated: 2024/10/15 11:24:34 by kytan			###   ########.fr	   */
/*			*/
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

int mails = 0;
pthread_mutex_t mutex;

typedef struct {
	long thread_id;
	struct timeval start_time;
} thread_params;

void* routine(void* arg) {
	thread_params* params = (thread_params*)arg;

	// Initialize thread ID and start time
	params->thread_id = pthread_self();
	gettimeofday(&(params->start_time), NULL);

	printf("Thread %ld started at %ld.%06ld\n",
		   params->thread_id,
		   params->start_time.tv_sec,
		   params->start_time.tv_usec);

	for (int i = 0; i < 10000000; i++) {
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}

	return NULL;
}


t_return	error_return(t_return error, char *argv)
{
	if (error == E_INVALID_INPUT)
		printf("Usage: %s <number_of_philosophers>\n", argv);
	if (error == E_INVALID_ARGS)
		printf("%i is not a positive number of philosophers.\n", atoi(argv));
	return (error);
}

t_return	validate_input(int argc, char** argv)
{
	if (argc != 2)
		return (error_return(E_INVALID_INPUT, argv[0]));
	if (atol(argv[0]) <= 0)
		return (error_return(E_INVALID_ARGS, argv[1]));
	return (SUCCESS);
}

int main(int argc, char** argv) {
	long total_philos;
	pthread_t* philosophers;
	thread_params* params;

	if (validate_input(argc, argv) != SUCCESS)
		return (1);
	total_philos = atol(argv[1]);

	philosophers = (pthread_t*)malloc(total_philos * sizeof(pthread_t));
	params = (thread_params*)malloc(total_philos * sizeof(thread_params));
	if (philosophers == NULL || params == NULL) {
		printf("Memory allocation failed.\n");
		free(philosophers);
		free(params);
		return 1;
	}

	pthread_mutex_init(&mutex, NULL);

	for (long i = 0; i < total_philos; i++) {
		if (pthread_create(&philosophers[i], NULL, &routine, &params[i]) != 0) {
			printf("Failed to create thread %ld\n", i);
			free(philosophers);
			free(params);
			pthread_mutex_destroy(&mutex);
			return 1;
		}
	}

	for (long i = 0; i < total_philos; i++) {
		if (pthread_join(philosophers[i], NULL) != 0) {
			printf("Failed to join thread %ld\n", i);
			free(philosophers);
			free(params);
			pthread_mutex_destroy(&mutex);
			return 1;
		}
	}

	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);

	free(philosophers);
	free(params);
	return 0;
}