/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:54:16 by sdalton           #+#    #+#             */
/*   Updated: 2022/01/18 18:15:46 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**   The atoi() function converts the initial portion of the string
       pointed to by nptr to int.  The behavior is the same as

           strtol(nptr, NULL, 10);

       except that atoi() does not detect errors.

       The atol() and atoll() functions behave the same as atoi(),
       except that they convert the initial portion of the string to
       their return type of long or long long.
RETURN VALUE
       The converted value or 0 on error.
**/

static int	ft_isspace(int c)
{
	unsigned char	cu;

	cu = (unsigned char)c;
	return ((9 <= cu && cu <= 13) || cu == 32);
}

static int	check_overflow(int n1, int n2, int sign)
{
	if (sign == 1)
	{
		if (n1 > INT_MAX - n2)
			return (-1);
		else
			return (n1 + n2);
	}
	else if (sign == -1)
	{
		if (-n1 < INT_MIN + n2)
			return (-1);
		else
			return (-n1 - n2);
	}
	else
		return (0);
}

static int	get_digits(int n)
{
	t_uint	dig;

	dig = 0;
	if (!n)
		return (0);
	while (n)
	{
		n /= 10;
		dig++;
	}	
	return (dig);
}

static int	near_overflow(int digits)
{
	static int	int_max_dig;

	if (!int_max_dig)
		int_max_dig = get_digits(INT_MAX);
	return (digits == int_max_dig - 1);
}

int	ft_atoi(char *s)
{
	int		n;
	int		sign;
	t_uint	digits;

	n = 0;
	sign = 1;
	digits = 0;
	while (ft_isspace(*s))
		s++;
	if (*s != '-' && *s != '+' && !ft_isdigit(*s))
		return (0);
	else if (*s == '+' || *s == '-')
		sign = -2 * (*s++ == '-') + 1;
	while (*s == '0')
		s++;
	while (ft_isdigit(*s) && !near_overflow(digits++))
		n = 10 * n + (*s++) - 48;
	if (ft_isdigit(*s) && !(ft_isdigit(s[1])))
		return (check_overflow(9 * n + (*s++) - 48, n, sign));
	else if (ft_isdigit(*s))
		return (-(sign == 1));
	else
		return (sign * n);
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			printf("%d\n", atoi(argv[i]));
			printf("%d\n", ft_atoi(argv[i]));
			i++;
		}
	}

}*/
