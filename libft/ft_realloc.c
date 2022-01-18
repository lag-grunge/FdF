/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:07:41 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 18:16:05 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_realloc(char **buf, size_t buf_size)
{
	char	*tmp;

	tmp = *buf;
	*buf = malloc(buf_size * 2);
	if (!*buf)
	{
		free(tmp);
		return (0);
	}
	ft_memcpy(*buf, tmp, buf_size);
	free(tmp);
	return (buf_size * 2);
}
