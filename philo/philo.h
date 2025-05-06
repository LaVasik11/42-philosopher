#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define PHILO_MAX_COUNT 200

typedef struct timeval	t_timeval;
typedef pthread_mutex_t	t_mut;

typedef struct s_mutexes
{
	t_mut	*left_fork;
	t_mut	*right_fork;
	t_mut	*write_lock;
	t_mut	*meal_lock;
}	t_mutexes;

typedef struct s_times
{
	size_t	die;
	size_t	eat;
	size_t	sleep;
	size_t	last_meal;
	size_t	born_time;
}	t_times;

typedef struct s_philo
{
	int			id;
	t_times		times;
	t_mutexes	mutexes;
	int			must_eat;
	pthread_t	thread_id;
	int			meals_eaten;
	int			philo_count;
}	t_philo;

typedef struct s_engine
{
	t_mut	*forks;
	t_philo	*philos;
	t_mut	meal_lock;
	t_mut	write_lock;
}	t_engine;

void	initphilos(t_engine *en, t_philo *philos, t_mut *forks, char **argv);
void	init_forks(t_mut *forks, int count);
void	init_engine(t_engine *engine, t_philo *philos, t_mut *forks);
void	ft_error(void);
void	destroy_all(t_engine *engine, int count);
void	print_action(t_philo *philo, char *action);
size_t	get_current_time(void);
void	ft_usleep(size_t mls);
size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);
bool	is_all_eat(t_philo *philos);
void	*obsorver(void *ptr);
void	philo_routine(t_philo *philo);
void	*start_simulation(void *ptr);
void	launcher(t_engine *engine, int count);

#endif
