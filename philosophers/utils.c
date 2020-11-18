#include "header.h"

void	ft_putnbr(unsigned long n)
{
	unsigned long i;

	i = n;
	if (i / 10 >= 1)
	{
		ft_putnbr(i / 10);
		ft_putstr(i % 10 + "0");
	}
	else
		ft_putstr(i % 10 + "0");
}

void	ft_locked_print(char *str, int cur)
{
	pthread_mutex_lock(&stru.print);
	ft_putnbr(the_time() - time_now);
	ft_putstr(" ");
	ft_putnbr(cur + 1);
	ft_putstr(" ");
	ft_putstr(str);
	ft_putstr("\n");
	pthread_mutex_unlock(&stru.print);
}

void	ft_putstr(char *str)
{
	for (int i = 0; str[i]; i++)
		write(1, &str[i], 1);
}

static int	ft_check_sign(char *str)
{
	int i;
	int sign;

	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (sign);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;
	int total;

	total = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		i++;
	sign = ft_check_sign((char *)(str + i));
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10;
		total = (str[i] - '0') + total;
		i++;
	}
	return (total * sign);
}