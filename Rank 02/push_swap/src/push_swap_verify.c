#include "push_swap.h"

/* This function checks if the argument is an integer */
int	ps_check_if_int(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (!((input[i] >= 48 && input[i] <= 57) || input[i] == '-' || input[i] == '+'))
			return (0);
        i++;
	}
    if (ft_atoi(input))
        return (1);
    else
		return (0);
}

/* This function checks if the same number appears more than once */
int ps_check_if_repeat(int args, char **input)
{
    int i;
    int j;

    i = (args - 1);
    while (i > 0)
    {
        j = (i - 1);
        while (j > 0)
        {
            if (ft_strncmp(input[i], input[j], 11) == 0)
                return (0);
            j--;
        }
        i--;
    }
    return (1);
}

/* This function checks if the input is valid using the functions above*/
int	ps_check_input(int args, char **input)
{
	int	i;

	i = (args - 1);
	while (i > 0 && input[i])
	{
		if (!(ps_check_if_int(input[i]) == 1))
            return (0);
        else
            i--;
    }
    if (!(ps_check_if_repeat(args, input) == 1))
        return (0);
    else
        return (1);
}
