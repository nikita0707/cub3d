/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:50:58 by rmass             #+#    #+#             */
/*   Updated: 2020/12/08 17:50:59 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		g_size = 11;

void	draw_block(t_cub *cub, int x, int y, unsigned int color)
{
	int		tx;
	int		ty;
	int		min;
	int		bl_s;

	tx = 0;
	ty = 0;
	min = (cub->s_height < cub->s_width) ? cub->s_height : cub->s_width;
	bl_s = min / (g_size + 2) / 5;
	while (tx < bl_s)
	{
		ty = 0;
		while (ty < bl_s)
		{
			my_mlx_pixel_put(cub, x * bl_s + tx, y * bl_s + ty, color);
			ty++;
		}
		tx++;
	}
}

void	draw_mm_frame(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	while (x < g_size + 2)
	{
		y = 0;
		while (y < g_size + 2)
		{
			if (x == 0 || x == g_size + 1 || y == 0 || y == g_size + 1)
				draw_block(cub, x, y, cub->f_color);
			y++;
		}
		x++;
	}
}

void	draw_mm(t_cub *cub)
{
	int	x;
	int	y;
	int	xm;
	int	ym;

	x = 1;
	draw_mm_frame(cub);
	xm = floorf(cub->player.pos.x) - g_size / 2;
	while (x <= g_size)
	{
		y = 1;
		ym = floorf(cub->player.pos.y) - g_size / 2;
		while (y <= g_size)
		{
			if (cfrommap(cub, xm, ym) == '1')
				draw_block(cub, x, y, 0xFFFFFF);
			if (cfrommap(cub, xm, ym) == '2')
				draw_block(cub, x, y, 0x000000);
			y++;
			ym++;
		}
		x++;
		xm++;
	}
	draw_block(cub, g_size / 2 + 1, g_size / 2 + 1, 0xFFFF00);
}
