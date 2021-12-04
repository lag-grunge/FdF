/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:36:54 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/09 14:36:56 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"

double	max_size(double maxa, double *b, double maxb, double scale)
{
	double	a;

	if (maxb < *b)
		*b = maxb;
	a = *b * scale;
	if (maxa < a)
	{
		a = maxa;
		*b = a / scale;
	}
	return (a);
}

int	find_max2i(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
