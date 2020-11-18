#ifndef PHILOUNO_H
#define PHILOUNO_H

#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned long   time_now;

typedef struct s_phil
{
    unsigned long   last_meal;
    int             total_meals;
    pthread_t       thread_id;
    pthread_mutex_t fork;     

}               t_phil;

typedef struct s_condi
{
    int     philo;
    int     time_die;
    int     time_eat;
    int     time_sleep;
    int     time_must_eat;
    pthread_mutex_t print;
    pthread_mutex_t two_forks;
    t_phil  *philos;
}               t_condi;

t_condi   stru;

int     ft_atoi(const char *str);
void    ft_putstr(char *str);
unsigned long   the_time(void);
void	ft_locked_print(char *str, int cur);
void	ft_putnbr(unsigned long n);
void    *function(void  *args);

#endif