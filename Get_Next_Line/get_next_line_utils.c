/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:33:28 by florianma         #+#    #+#             */
/*   Updated: 2021/05/18 16:31:33 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_merge2(char *s1, char *s2, char *dest)
{
	int	i;
	int	j;
	int	size_s;

	i = 0;
	j = 0;
	size_s = ft_strlen(s1);
	while (i < size_s)
	{
		dest[i] = s1[i];
		i++;
	}
	size_s = ft_strlen(s2);
	while (j < size_s)
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_merge(char *s1, char *s2)
{
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	dest = ft_merge2(s1, s2, dest);
	free(s1);
	return (dest);
}
