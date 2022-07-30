/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:39:16 by florianma         #+#    #+#             */
/*   Updated: 2021/05/18 16:39:16 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_present(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_untiln(char *str)
{
	int		i;
	char	*rest;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	rest = (char *)malloc((i + 1) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		rest[i] = str[i];
		i++;
	}
	rest[i] = '\0';
	return (rest);
}

char	*ft_fromn(char *str)
{
	int		i;
	int		j;
	char	*rest;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (rest == NULL)
		return (NULL);
	i++;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

int	ft_errror(char *buff)
{
	free (buff);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buff;
	int			reader;
	int BUFFER_SIZE = ft_strlen(*line);

	if (!line || BUFFER_SIZE < 1 || fd < 0)						// Ici la gestion des erreurs, on check les paramètres reçus et le BUFFER_SIZE
		return (-1);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));	// Allocation sur trois lignes pour le respect de la norme
	if (buff == NULL)
		return (-1);
	reader = 1;												// Ici on active le reader pour rentrer dans la boucle qui va permettre d'extraire BUFFER_SIZE char dans buff
	while (is_present(str, '\n') == 0 && reader != 0)		// Ici on vérifie que on ne trouve pas '\n' dans notre
	{
		reader = read(fd, buff, BUFFER_SIZE);				// On call la fonction read
		if (reader == (-1))									// Ici on renvoie -1 et on libère le buff dans la fonction ft_error si problème avec read
			return (ft_errror(buff));	
		buff[reader] = '\0';					// Ici bien penser à sécuriser 
		str = ft_merge(str, buff);				// Appel de la fonction str_join identique à celle de la piscine sauf qu'on free s1 en cas ou on rerentre dans la boucle
	}
	free(buff);									//Ici on free le buff dans le cas ou on ne rentre pas dans la boucle (Buff à êtê alloué en mémoire au début de la fonction)
	*line = ft_untiln(str);						// On vient chercher le début de la str jusqu'à '\n'
	str = ft_fromn(str);						// On vient donner le reste de buff après '\n' à la static 'str'
	if (reader == 0)							// Ici la condition de fin 
		return (0);
	return (1);									// Ici la condition de non fin 