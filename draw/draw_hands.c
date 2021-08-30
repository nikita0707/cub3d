/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:50:40 by rmass             #+#    #+#             */
/*   Updated: 2020/12/08 17:50:41 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_lantern(t_cub *cub, float *y)
{
	if (cub->lp < 5)
		*y -= (3 * cub->lp) * cub->speed;
	else if (cub->lp < 10)
		*y -= (3 * (10 - cub->lp)) * cub->speed;
	else
	{
		cub->lp = 0;
		return ;
	}
	if (cub->keys.w || cub->keys.a || cub->keys.s || cub->keys.d)
		cub->lp++;
}

void	draw_lantern(t_cub *cub)
{
	float			dx;
	float			dy;
	t_point			p;
	t_point			tp;
	unsigned int	color;

	p.y = cub->s_height * 6 / 10;
	dx = (float)cub->lantern.width / (cub->s_height * 3 / 10);
	dy = (float)cub->lantern.height / (cub->s_height - p.y);
	tp.y = -dy;
	move_lantern(cub, &(p.y));
	while ((tp.y += dy) < cub->lantern.height)
	{
		p.x = 0;
		tp.x = 0;
		while (tp.x < cub->lantern.width)
		{
			color = get_color(cub->lantern, tp.x, tp.y);
			if (color != 0)
				my_mlx_pixel_put(cub, p.x, p.y, color);
			tp.x += dx;
			p.x++;
		}
		p.y++;
	}
}

void	draw_hand(t_cub *cub)
{
	float			dx;
	float			dy;
	t_point			p;
	t_point			tp;
	unsigned int	color;

	p.y = cub->s_height * 6 / 10;
	dx = (float)cub->hand.width / (cub->s_height * 4 / 10);
	dy = (float)cub->hand.height / (cub->s_height - p.y);
	tp.y = -dy;
	move_lantern(cub, &(p.y));
	p.y += cub->s_height / 20;
	while ((tp.y += dy) < cub->hand.height)
	{
		p.x = cub->s_width - (cub->s_height * 4 / 10);
		tp.x = -dx;
		while ((tp.x += dx) < cub->hand.width)
		{
			color = get_color(cub->hand, tp.x, tp.y);
			if (color != 0 && color != 0xFF000000)
				my_mlx_pixel_put(cub, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
}

void	draw_fireball(t_cub *cub)
{
	float			dx;
	float			dy;
	t_point			p;
	t_point			tp;
	unsigned int	color;

	p.y = cub->s_height * 3 / 10;
	dx = (float)cub->fireball.width / (cub->s_height * 3 / 10);
	dy = (float)cub->fireball.height / (cub->s_height - p.y) * 2;
	tp.y = -dy;
	move_lantern(cub, &(p.y));
	p.y += cub->s_height / 6;
	while ((tp.y += dy) < cub->fireball.height)
	{
		p.x = cub->s_width - (cub->s_height * 3 / 10) - cub->s_width / 9;
		tp.x = -dx;
		while ((tp.x += dx) < cub->fireball.width)
		{
			color = get_color(cub->fireball, tp.x, tp.y);
			if (color != 0 && color != 0xFF000000)
				my_mlx_pixel_put(cub, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
}
