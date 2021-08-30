/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:50:45 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 08:00:50 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_uint	apply_shadow(unsigned int color, float dist)
{
	int		r;
	int		g;
	int		b;
	float	d;

	if (LIGHT)
		return (color);
	d = dist;
	d += 1.0f;
	if (d < 1.0f)
		return (color);
	r = (color & (255 << 16)) >> 16;
	g = (color & (255 << 8)) >> 8;
	b = color & 255;
	r = r / d;
	g = g / d;
	b = b / d;
	return ((r << 16) | (g << 8) | b);
}

void	my_mlx_pixel_put(t_cub *cub, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= cub->s_width || y >= cub->s_height)
		return ;
	dst = cub->screen.data + (y * cub->s_width + x) * 4;
	*(unsigned int*)dst = color;
}

void	clear_image(t_cub *cub)
{
	int	x;
	int	y;

	x = -1;
	while (++x < cub->s_width)
	{
		y = -1;
		while (++y < cub->s_height)
			my_mlx_pixel_put(cub, x, y, 0);
	}
}
