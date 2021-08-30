/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:51:19 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 16:52:29 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_texture	g_tex;

int			d_tex_set(t_cub *cub, int size, float *ty, t_point *d)
{
	int			y;

	y = (cub->s_height - size) / 2;
	y += (float)cub->action * (float)size / (float)cub->s_height;
	*ty = 0.0f;
	d->x = (float)g_tex.width / (float)size;
	d->y = (float)g_tex.height / (float)size;
	y += cub->vision;
	if (y < 0)
	{
		*ty = d->y * (float)(-y);
		y = -1;
	}
	return (y);
}

void		draw_sptex(t_cub *cub, int size, int start, float dist)
{
	t_point			d;
	float			ty;
	t_keys			cr;
	unsigned int	color;

	cr.a = d_tex_set(cub, size, &ty, &d);
	cr.s = -1;
	while (++cr.s < size && cr.s + cr.a < cub->s_height \
	&& ty < g_tex.height)
	{
		cr.w = -1;
		if (start < 0)
			cr.w += -start;
		while (++cr.w < size && start + cr.w < cub->s_width)
		{
			color = get_color(g_tex, (float)cr.w * d.x, ty);
			if (color != 0 && cub->dists[start + cr.w] >= dist - 0.5 \
			&& color != 0xFF000000)
			{
				color = apply_shadow(color, dist);
				my_mlx_pixel_put(cub, start + cr.w, cr.a + cr.s, color);
			}
		}
		ty += d.y;
	}
}

void		d_s(t_cub *cub, t_point sprite)
{
	t_point	ang;
	t_point	dist;
	t_point	dp;
	int		x;
	int		size;

	ang.x = cub->player.dir - 0.75f;
	if (ang.x < 0.0f)
		ang.x += 1.0f;
	ang.x *= (2 * M_PI);
	dist.y = (float)(cub->s_width / 2) / tan(((66.0f * M_PI / 180.0f) / 2));
	dp.x = cub->player.pos.x - sprite.x;
	dp.y = cub->player.pos.y - sprite.y;
	dist.x = sqrt(dp.x * dp.x + dp.y * dp.y);
	ang.y = atan2(dp.y, dp.x) - ang.x;
	size = dist.y / (cosf(ang.y) * dist.x);
	x = tan(ang.y) * dist.y;
	x = cub->s_width / 2 + x - size / 2;
	if (size <= 0 || x < -size || x >= cub->s_width)
		return ;
	draw_sptex(cub, size, x, dist.x);
}

void		set_texture(t_cub *cub, char c)
{
	if (c == '2')
		g_tex = cub->s_tex;
	if (c == 'R')
		g_tex = cub->r_tex.tex[cub->r_tex.tf];
	if (c == 'A')
		g_tex = cub->a_tex.tex[cub->a_tex.tf];
	if (c == 'P')
		g_tex = cub->pnt_tex;
	if (c == 'D')
		g_tex = cub->cdoor_tex;
	if (c == 'O')
		g_tex = cub->odoor_tex;
	if (c > '2' && c <= '9')
		g_tex = cub->port_tex[c - '3'];
}

void		draw_sprites(t_cub *cub)
{
	int		i;
	int		count;
	char	c;

	sort_sprites(cub);
	i = -1;
	while (++i < cub->sp_count)
	{
		c = cfrommap(cub, (cub->sprites)[i].x, (cub->sprites)[i].y);
		if (c == '0')
			continue;
		set_texture(cub, c);
		d_s(cub, (cub->sprites)[i]);
	}
	count = cub->r_tex.count - 1;
	cub->r_tex.tf += (cub->r_tex.tf == count) ? -count : 1;
	count = cub->a_tex.count - 1;
	cub->a_tex.tf += (cub->a_tex.tf == count) ? -count : 1;
}
