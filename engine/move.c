/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:51:10 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 16:30:21 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ch_dir(t_cub *cub, float sens)
{
	cub->player.dir += sens;
	if (cub->player.dir < 0.0f)
		cub->player.dir = 1.0f + cub->player.dir;
	if (cub->player.dir > 1.0f)
		cub->player.dir = cub->player.dir - 1.0f;
}

void	change_dir(t_cub *cub)
{
	int	h;
	int	dmy;

	h = cub->s_height;
	dmy = abs(h / 2 - cub->my) * (h / 40);
	if (cub->mx < cub->s_width / 2)
		ch_dir(cub, -0.005f * (cub->s_width / 2 - cub->mx));
	if (cub->mx > cub->s_width / 2)
		ch_dir(cub, 0.005f * (cub->mx - cub->s_width / 2));
	if (cub->my < cub->s_height / 2 && cub->vision + dmy < h)
		cub->vision += dmy;
	if (cub->my > cub->s_height / 2 && cub->vision - dmy > -h)
		cub->vision -= dmy;
	if (cub->keys.la)
		ch_dir(cub, -0.02f);
	if (cub->keys.ra)
		ch_dir(cub, 0.02f);
}

void	ch_pos(t_cub *cub, float dx, float dy)
{
	t_point	*pp;
	char	c;

	dx *= cub->speed;
	dy *= cub->speed;
	pp = &(cub->player.pos);
	c = cfrommap(cub, floorf(pp->x), floorf(pp->y - dy));
	if (c == '1' || c == '2' || c == 'D')
		dy = 0.0f;
	c = cfrommap(cub, floorf(pp->x + dx), floorf(pp->y));
	if (c == '1' || c == '2' || c == 'D')
		dx = 0.0f;
	c = cfrommap(cub, floorf(pp->x + dx), floorf(pp->y - dy));
	if (c == '1' || c == '2' || c == 'D')
	{
		dx = 0.0f;
		dy = 0.0f;
	}
	pp->x += dx;
	pp->y -= dy;
}

void	change_pos(t_cub *cub)
{
	float	a;
	int		x;
	int		y;
	float	op;
	float	adj;

	x = 0;
	y = 0;
	a = cub->player.dir;
	y += (cub->keys.w) ? 1 : 0;
	y -= (cub->keys.s) ? 1 : 0;
	x -= (cub->keys.a) ? 1 : 0;
	x += (cub->keys.d) ? 1 : 0;
	if (x == 0 && y == 0)
		return ;
	op = sqrt(x * x + (y - 1) * (y - 1));
	adj = sqrt(x * x + y * y);
	op = acos((adj * adj + 1 - op * op) / (2 * adj * adj));
	if (x > 0)
		a += (op / (M_PI * 2));
	else if (x < 0)
		a -= (op / (M_PI * 2));
	else if (y < 0)
		a += 0.5f;
	ch_pos(cub, sinf(a * 2.0f * M_PI) / 7, cosf(a * 2.0f * M_PI) / 7);
}

void	move(t_cub *cub)
{
	char	c;

	c = cub->map[(int)cub->player.pos.y][(int)cub->player.pos.x];
	change_dir(cub);
	change_pos(cub);
	if (c == 'P')
	{
		if (cub->pts < 5)
		{
			cub->pts++;
			cub->map[(int)cub->player.pos.y][(int)cub->player.pos.x] = '0';
		}
	}
	if (c > '2' && c <= '9')
	{
		if (!cub->tp && cub->prtls[(c - '3') * 2].x > 0.5f \
		&& ((int)cub->player.pos.x != (int)cub->prtls[(c - '3') * 2].x \
		|| (int)cub->player.pos.y != (int)cub->prtls[(c - '3') * 2].y))
			cub->player.pos = cub->prtls[(c - '3') * 2];
		else if (!cub->tp && cub->prtls[(c - '3') * 2 + 1].x > 0.5f)
			cub->player.pos = cub->prtls[(c - '3') * 2 + 1];
		cub->tp = 1;
	}
	else
		cub->tp = 0;
}
