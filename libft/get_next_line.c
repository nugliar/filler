/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:02:36 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/03 10:54:48 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_to_buf(char *buf, int fd, int size)
{
	char	c;
	int		ret;

	while (size > 0)
	{
		if ((ret = read(fd, &c, 1)) < 0)
			return (-1);
		if (ret == 0 || c == '\n')
			break ;
		*buf++ = c;
		size--;
	}
	*buf = 0;
	if (!size)
		return (2);
	if (ret > 0 && size)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	if (line == NULL || fd < 0)
		return (-1);
	*line = NULL;
	while ((ret = read_to_buf(buf, fd, BUFF_SIZE)))
	{
		*line = ft_realloc(*line, BUFF_SIZE);
		ft_strcat(*line, buf);
		if (ret == 1)
			break ;
	}
	return (ret);
}
