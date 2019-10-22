/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:55:50 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 15:07:04 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	limit_for_int(int low, int high, int *nbr)
{
	if (*nbr < low)
		*nbr = low;
	if (*nbr > high)
		*nbr = high;
}

void	limit_for_dbl(double low, double high, double *nbr)
{
	if (*nbr > high)
		*nbr = high;
	if (*nbr < low)
		*nbr = low;
}

void	make_len_one(t_xyz *vct)
{
	double	lenght_v;
	double	div;

	lenght_v = sqrt(vct->x * vct->x
					+ vct->y * vct->y
					+ vct->z * vct->z);
	if (lenght_v > 0.0)
	{
		div = 1.0 / lenght_v;
		vct->x *= div;
		vct->y *= div;
		vct->z *= div;
	}
	if (vct->x == 0 && vct->y == 0 && vct->z == 0)
		vct->y = 1;
}

void	limit_for_xyz(double low, double high, t_xyz *vect)
{
	if (vect->x > high)
		vect->x = high;
	else if (vect->x < low)
		vect->x = low;
	if (vect->y > high)
		vect->y = high;
	else if (vect->y < low)
		vect->y = low;
	if (vect->z > high)
		vect->z = high;
	else if (vect->z < low)
		vect->z = low;
}
