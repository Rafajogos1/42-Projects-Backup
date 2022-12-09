#include "minitalk.h"

static void	mt_reset(int *len, char **str, int *i)
{
	*len = 0;
	if (str)
	{
		ft_putendl_fd(*str, 1);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

static void	mt_receive_len(int *bit, char **str, int *len, int signal)
{
	static int	str_len = 0;

	if (signal == SIGUSR2)
		str_len += ft_power(2, *bit);
	if (*bit == 31)
	{
		*len = 1;
		*str = ft_calloc(str_len + 1, sizeof(char));
		*bit = 0;
		str_len = 0;
		return ;
	}
	(*bit)++;
}

static void	mt_recieve(int signal)
{
	static int	c = 0;
	static int	bit = 0;
	static int	len = 0;
	static char	*str = 0;
	static int	i = 0;

	if (!len)
		mt_receive_len(&bit, &str, &len, signal);
	else
	{
		if (signal == SIGUSR2)
			c += ft_power(2, bit);
		if (bit == 7)
		{	
			str[i++] = c;
			bit = 0;
			if (c == 0)
				return (mt_reset(&len, &str, &i));
			c = 0;
			return ;
		}
		bit++;
	}
}

int main(void)
{
	char				*pid;

	pid = ft_itoa(getpid());
	ft_printf("PID: %s\n", pid);
	signal(SIGUSR1, mt_recieve);
	signal(SIGUSR2, mt_recieve);
	while (1)
		pause();
}
