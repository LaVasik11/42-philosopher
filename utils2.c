#include "philo.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	destroy_all(t_engine *engine, int count)
{
	while (--count >= 0)
		pthread_mutex_destroy(&engine->forks[count]);
	pthread_mutex_destroy(&engine->write_lock);
	pthread_mutex_destroy(&engine->meal_lock);
	exit(0);
}

void	print_action(t_philo *philo, char *action)
{
	size_t	time;

	pthread_mutex_lock(philo->mutexes.write_lock);
	time = get_current_time() - philo->times.born_time;
	printf("[%ld] %d-%s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}

size_t	get_current_time(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t mls)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < mls)
		usleep(100);
}
