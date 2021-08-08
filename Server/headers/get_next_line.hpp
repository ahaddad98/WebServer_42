/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:08:39 by sqatim            #+#    #+#             */
/*   Updated: 2021/08/06 14:00:17 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_HPP
# define GET_NEXT_LINE_HPP

#include <iostream>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define FD_SIZE  4864
# define BUFFER_SIZE 100

int		get_next_line(int fd, std::string &line);
int		ft_remplissage(char **tmp, int fd, char **line);
char	*ft_check(char **tmp, int r, int fd);
int		free_leak(char **ptr, int nb, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif
