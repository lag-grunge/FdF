/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:15:43 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 18:12:51 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif
#ifndef READ_SIZE
# define READ_SIZE 64
#endif

static int	read_bytes(char **buf, size_t *buf_size, size_t *i, int fd)
{
	int	ret;

	if (*i >= *buf_size - READ_SIZE + 1)
		*buf_size = ft_realloc(buf, *buf_size);
	ret = read(fd, *buf + *i, READ_SIZE - 1);
	if (ret <= 0 || !*buf_size)
		return (ret);
	*i += ret;
	(*buf)[*i] = 0;
	return (ret);
}

static int	read_fd_to_buf(char **buf_ptr, int fd)
{
	char	*buf;
	size_t	i;
	size_t	cur_buffer_size;
	int		ret;

	cur_buffer_size = BUFFER_SIZE;
	buf = malloc(cur_buffer_size);
	if (!buf)
		return (-1);
	buf[0] = 0;
	i = 0;
	ret = 1;
	while (ret > 0 && !ft_strchr(buf, '\n'))
		ret = read_bytes(&buf, &cur_buffer_size, &i, fd);
	if (i > 0)
		*buf_ptr = buf;
	if (ret == -1 || i == 0)
		free(buf);
	if (i == 0)
		ret = 0;
	if (ret < 0 || i == 0)
		return (ret);
	return (1);
}

int	swap_lines(char **rem, char **buf)
{
	char	*tmp;

	if (!*buf && *rem)
		*buf = *rem;
	if (*buf && *rem)
	{
		tmp = *buf;
		*buf = ft_strjoin(*rem, tmp);
		free(tmp);
		free(*rem);
	}
	*rem = NULL;
	if (!*buf)
		return (-1);
	return (0);
}

static int	get_remainder(char **rem, char **buf)
{
	char	*nl;

	nl = ft_strchr(*buf, '\n');
	if (!nl)
		return (0);
	(*buf)[nl - *buf] = 0;
	if (!nl[1])
		return (0);
	*rem = ft_strdup(nl + 1);
	if (*rem)
		return (0);
	free(*buf);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*rem;
	char		*buf;
	int			ret;

	buf = NULL;
	if (!rem || !ft_strchr(rem, '\n'))
	{
		ret = read_fd_to_buf(&buf, fd);
		if (ret <= 0 && !rem)
			return (ret);
	}
	if (swap_lines(&rem, &buf) == -1)
		return (-1);
	if (get_remainder(&rem, &buf) == -1)
		return (-1);
	*line = buf;
	return (1);
}
