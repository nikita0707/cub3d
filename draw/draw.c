/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:50:55 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 16:30:45 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	g_maxw = 0;
float	g_wwa = 0;

void	draw_skybox(t_cub *cub, int x, int y)
{
	float	ray;
	int		tx;
	float	ty;
	float	dy;
	t_uint	color;

	dy = cub->skybox.height / 2 / ((float)cub->s_height * 1.5f);
	ty = (cub->s_height * 1.5f) * dy;
	while (--y > -1)
	{
		ray = norm_ray(cub->player.dir - (FOV / 720.0f));
		while (++x < cub->s_width)
		{
			tx = (int)((float)cub->skybox.width * ray);
			if (ty > 0)
				color = get_color(cub->skybox, tx, ty);
			my_mlx_pixel_put(cub, x, y, color);
			ray = norm_ray(ray + FOV / 360.0f / cub->s_width);
		}
		x = -1;
		ty -= dy;
	}
}

void	floor_casting(t_cub *cub, int x, int start)
{
	t_point	cr;
	t_uint	color;
	t_point	cur;
	t_keys	ct;
	float	t;

	start--;
	start -= cub->vision;
	while (++start < cub->s_height - cub->vision)
	{
		cr.x = cub->s_height / (2.0 * start - cub->s_height);
		cr.y = cr.x / (cub->dists)[x];
		if (cr.y > g_maxw && !cub->action && !cub->vision)
			g_maxw = cr.y;
		if (cr.y > g_wwa && cub->action)
			g_wwa = cr.y;
		t = (cub->action) ? g_wwa : g_maxw;
		cur.x = cr.y * cub->th[x].x + (t - cr.y) * cub->player.pos.x;
		cur.y = cr.y * cub->th[x].y + (t - cr.y) * cub->player.pos.y;
		ct.w = (int)(cur.x * cub->fl_tex.width / t) % cub->fl_tex.width;
		ct.a = (int)(cur.y * cub->fl_tex.height / t) % cub->fl_tex.height;
		color = apply_shadow(get_color(cub->fl_tex, ct.w, ct.a), cr.x);
		my_mlx_pixel_put(cub, x, start + cub->vision, color);
	}
}

/*
** ceiling (symmetrical!)
**
** int ceilTexX, ceilTexY;
** ceilTexX = (int)(cur.x * cub->so_tex.width / g_maxw) % cub->so_tex.width;
** ceilTexY = (int)(cur.y * cub->so_tex.height / g_maxw) % cub->so_tex.height;
**
** color = apply_shadow(get_color(cub->we_tex, ct.w, ct.a), cr.x);
** my_mlx_pixel_put(cub, x, cub->s_height - y, color);
*/

void	draw_hptex(t_cub *cub, int start, int size)
{
	t_point	t;
	t_point	d;
	int		x;
	int		y;
	t_uint	color;

	t.y = 0.0f;
	d.x = cub->hp_tex.width / (float)size;
	d.y = cub->hp_tex.height / (float)size;
	y = -1;
	while (++y < size)
	{
		x = -1;
		t.x = 0.0f;
		while (++x < size)
		{
			color = get_color(cub->hp_tex, t.x, t.y);
			if (color != 0 && color != 0xFF000000)
				my_mlx_pixel_put(cub, start + x, y, color);
			t.x += d.x;
		}
		t.y += d.y;
	}
}

void	draw_hp(t_cub *cub)
{
	int		i;
	int		size;

	size = ((cub->s_width < cub->s_height) ? cub->s_width : cub->s_height) / 10;
	i = -1;
	while (++i < cub->pts)
		draw_hptex(cub, cub->s_width - size * (i + 1), size);
}

int		draw_all(t_cub *cub)
{
	g_wwa = 0;
	clear_image(cub);
	if (BONUS)
		draw_skybox(cub, -1, cub->s_height / 2 + cub->vision);
	draw_walls(cub);
	draw_sprites(cub);
	if (BONUS)
	{
		jump(cub);
		sit(cub);
		draw_mm(cub);
		draw_hp(cub);
		draw_hand(cub);
		draw_fireball(cub);
	}
	return (1);
}
