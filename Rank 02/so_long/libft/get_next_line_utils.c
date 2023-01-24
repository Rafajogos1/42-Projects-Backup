/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:06:24 by ramartin          #+#    #+#             */
/*   Updated: 2023/01/24 18:38:18 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_ft_strlen(s)]);
	i = 0;
	while (s[i] != '\0' && s[i] != (char) c)
		i++;
	if (s[i] == (char) c)
		return ((char *)(s + i));
	return (NULL);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[gnl_ft_strlen(s1) + gnl_ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

size_t	gnl_ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
