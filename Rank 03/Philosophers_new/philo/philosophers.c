#include "philosophers.h"

int	philo_error_handling(int error_code)
{
	if (error_code == -1)
		write(2, "Memory allocation error.\n", 26);
	if (error_code == 0)
		write(2, "Error: Wrong number of arguments.\n", 35);
	if (error_code == 1)
		write(2, "Error: At least one argument isn't a positive integer.\n", 56);
	if (error_code == 2)
		write(2, "Only the number of times to eat can be null.\n", 46);
    if (error_code == 3)
		write(2, "Simulation runs only up to 200 philosophers.\n", 46);
	return (0);
}

int main(int ac, char **av)
{
    t_data  data;

    if (ac < 5 || ac > 6)
		return (0);
    if (philo_input_checker(av) == 0)
		return (0);
    if (philo_init(&data, av, ac) == 0)
		return (0);
    printf("Fine\n");
}