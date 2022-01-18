/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:14:31 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 18:14:33 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef unsigned int	t_uint;

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

size_t	ft_strlen(const char *s);
t_uint	ft_strlcpy(char *dst, const char *src, t_uint n);
t_uint	ft_strlcat(char *dst, const char *src, t_uint n);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(const char	*s1, const char	*s2, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
size_t	ft_spllen(char **spl);
void	clean_split(char **split, unsigned int i);

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_realloc(char **buf, size_t buf_size);
char	*ft_strdup(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(char *s);
int		ft_atoi_base(char *s, char *base, char *prefix, int *ovflw);
t_uint	ft_usgn_atoi_base(char *s, char *base, char *prefix, int *ovflw);

int		get_next_line(int fd, char **line);

#endif
