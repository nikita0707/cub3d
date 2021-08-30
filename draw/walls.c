/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:53:34 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 07:56:39 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_wline(t_cub *cub, int column_h, int x, t_texture tex)
{
	int				y;
	int				thit;
	t_point			yc;
	unsigned int	color;
	int				i;

	y = (cub->s_height - column_h) / 2 + cub->vision;
	y += (float)cub->action * ((float)column_h / (float)cub->s_height);
	thit = (int)(floorf(cub->hits[x] * tex.width) + EPS);
	yc.y = ((float)tex.height / (float)column_h);
	yc.x = (y < 0) ? yc.y * (float)(-y) : 0.0f;
	y = (y < 0) ? -1 : y;
	if ((i = -1) == -1 && !BONUS)
		draw_ceiling(cub, x, cub->s_height + cub->vision, y - 1);
	while (++i < column_h && y + i < cub->s_height && yc.x < tex.height)
	{
		color = get_color(tex, thit, yc.x);
		color = apply_shadow(color, cub->dists[x]);
		my_mlx_pixel_put(cub, x, i + y, color);
		yc.x += yc.y;
	}
	if (BONUS)
		floor_casting(cub, x, i + y);
	else
		draw_floor(cub, x, cub->s_height / 2 + cub->vision, i + y);
}

void	draw_walls(t_cub *cub)
{
	int			x;
	int			y;
	int			column_h;

	x = -1;
	while (++x < cub->s_width)
	{
		column_h = cub->s_width / 2;
		column_h = (float)column_h / tanf((FOV / 2) * (M_PI / 180.0f));
		column_h = (int)ceilf((float)column_h / cub->dists[x]);
		y = (cub->s_height - column_h) / 2;
		if (y < -1)
			y = -1;
		if ((cub->sides)[x] == 0)
			draw_wline(cub, column_h, x, cub->no_tex);
		else if ((cub->sides)[x] == 1)
			draw_wline(cub, column_h, x, cub->so_tex);
		else if ((cub->sides)[x] == 2)
			draw_wline(cub, column_h, x, cub->we_tex);
		else
			draw_wline(cub, column_h, x, cub->ea_tex);
	}
}
