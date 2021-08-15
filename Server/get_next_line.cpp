/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragegodthor <ragegodthor@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:07:46 by sqatim            #+#    #+#             */
/*   Updated: 2021/08/06 15:28:17 by ragegodthor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.hpp"

int		free_leak(char **ptr, int nb, int fd)
{
	if (fd >= 0 && fd < FD_SIZE)
	{
		if (*ptr && ptr)
		{
			delete  (*ptr);
			*ptr = NULL;
		}
	}
	return (nb);
}

char	*ft_check(char **tmp, int r, int fd)
{
	if (tmp[fd][r] && tmp[fd][r + 1])
	{
				// std::cout << "samir" << std::endl;
		return (ft_strdup(tmp[fd] + r + 1));
	}
	else
	{
		return (NULL);
	}
}

int		ft_remplissage(char **tmp, int fd, std::string &line)
{
	int		r;
	char	*delt;
	char	*save;

	delt = tmp[fd];
	r = 0;
	while (tmp[fd][r] != '\n' && tmp[fd][r])
		r++;
	if (tmp[fd][r] == '\0')
	{
		line = tmp[fd];
		return (free_leak(&tmp[fd], 0, fd));
	}
	save = ft_substr(tmp[fd], 0, r);
	line = save;
	delete [] save;
	tmp[fd] = ft_check(tmp, r, fd);
	delete [] delt;
	return (1);
}

int		get_next_line(int fd, std::string &line)
{
	char		*buf;
	static char	*tmp[2];
	int			r;
	
	if ((fd < 0 || fd >= FD_SIZE) ||
			!(buf = new char[BUFFER_SIZE + 1]))
		return (free_leak(&tmp[1], -1, 1));
	while ((!(ft_strchr(tmp[1], '\n'))) &&
			((r = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[r] = '\0';
		tmp[1] = ft_strjoin_free(tmp[1], buf);
	}
	delete [] buf;
	if (r == -1 || (r == 0 && !ft_strlen(tmp[1])))
	{
		line = "";
		return (free_leak(&tmp[1], r, 1));
	}
	return (ft_remplissage(tmp, 1, line));
}