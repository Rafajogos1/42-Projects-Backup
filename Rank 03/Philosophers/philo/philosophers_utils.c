/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:16:37 by rafael            #+#    #+#             */
/*   Updated: 2023/04/01 15:55:45 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	num;
	int	neg;
	int	found;

	num = 0;
	neg = 1;
	found = 1;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n') \
	|| (*str == '\r') || (*str == '\f'))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if ((*str == '-'))
			neg = -1;
		str++;
	}
	while (*str && found)
	{
		if ((*str >= '0') && (*str <= '9'))
			num = (num * 10 + *str -48);
		else
			found = 0;
		str++;
	}
	return (num * neg);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

