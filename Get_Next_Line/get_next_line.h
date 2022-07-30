/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:27:17 by florianma         #+#    #+#             */
/*   Updated: 2021/05/18 16:31:56 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_merge2(char *s1, char *s2, char *dest);
char	*ft_merge(char *s1, char *s2);
int		is_present(char *str, char c);
int		ft_strlen(char *str);
int		ft_errror(char *buff);
char	*ft_untiln(char *str);
char	*ft_fromn(char *str);

#endif
