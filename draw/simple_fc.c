/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_fc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:50:07 by rmass             #+#    #+#             */
/*   Updated: 2020/12/08 17:51:02 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_ceiling(t_cub *cub, int x, int mid, int end)
{
	float	dist;
	float	td;
	int		i;
	float	dif;

	dif = absf(x - cub->s_width / 2) / ((float)cub->s_width / 5.0f);
	dist = 10 + dif * dif;
	td = 0.991f;
	i = mid + 1;
	while (--i > -1)
	{
		dist *= td;
		if (i > end)
			continue ;
		my_mlx_pixel_put(cub, x, i, apply_shadow(cub->c_color, dist));
	}
}

void	draw_floor(t_cub *cub, int x, int mid, int start)
{
	float	dist;
	float	td;
	int		i;
	float	dif;

	dif = absf(x - cub->s_width / 2) / ((float)cub->s_width / 5.0f);
	dist = 10 + dif * dif;
	td = 0.991f;
	i = mid;
	while (++i < cub->s_height)
	{
		dist *= td;
		if (i < start)
			continue ;
		my_mlx_pixel_put(cub, x, i, apply_shadow(cub->f_color, dist));
	}
}
