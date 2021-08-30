/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:51:16 by rmass             #+#    #+#             */
/*   Updated: 2020/12/08 17:51:16 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	inc_ray(float r1, float r2)
{
	float	ray;

	ray = r1 + r2;
	if (ray < 0)
		ray = 360.0f + ray;
	else if (ray >= 360.0f)
		ray -= 360.0f;
	return (ray);
}

t_point	get_h_and_w(float ray, t_point temp)
{
	t_point	xh;
	t_point	yh;
	float	ta;

	ta = ray;
	while (ta > 90.0f)
		ta -= 90.0f;
	xh.x = (ray >= 0.0f && ray < 180.0f) ?
	(1.0f - (temp.x - floorf(temp.x))) : (temp.x - floorf(temp.x));
	yh.y = (ray >= 90.0f && ray < 270.0f) ?
	(1.0f - (temp.y - floorf(temp.y))) : (temp.y - floorf(temp.y));
	xh.x = (xh.x < EPS && xh.x > -EPS) ? 1.0f : xh.x;
	yh.y = (yh.y < EPS && yh.y > -EPS) ? 1.0f : yh.y;
	if ((ray >= 0.0f && ray < 90.0f) || (ray >= 180.0f && ray < 270.0f))
	{
		xh.y = xh.x * tanf((90.0f - ta) * (M_PI / 180.0f));
		yh.x = yh.y * tanf(ta * (M_PI / 180.0));
	}
	else
	{
		xh.y = xh.x * tanf(ta * (M_PI / 180.0f));
		yh.x = yh.y * tanf((90.0f - ta) * (M_PI / 180.0f));
	}
	return ((xh.x < yh.x) ? xh : yh);
}

t_point	ch_point(float ray, t_point p1, t_point p2)
{
	t_point	res;

	if (ray >= 0.0f && ray < 180.0f)
		res.x = p1.x + p2.x;
	else
		res.x = p1.x - p2.x;
	if (ray >= 90.0f && ray < 270.0f)
		res.y = p1.y + p2.y;
	else
		res.y = p1.y - p2.y;
	return (res);
}

void	add_dist(t_cub *cub, int x, float ray, t_point temp)
{
	float		dist;
	t_player	pl;

	pl = cub->player;
	dist = sqrt(pow(temp.x - pl.pos.x, 2) + pow(temp.y - pl.pos.y, 2));
	(cub->dists)[x] = dist * cosf(absf(pl.dir * 360.0f - ray) \
	* (M_PI / 180.0f));
}

void	raycast(t_cub *cub)
{
	int			x;
	float		ray;
	t_point		temp;

	x = -1;
	ray = inc_ray(cub->player.dir * 360, -(FOV / 2));
	while (++x < cub->s_width)
	{
		temp.x = cub->player.pos.x;
		temp.y = cub->player.pos.y;
		while (!hit_the_wall(cub, temp, x))
			temp = ch_point(ray, temp, get_h_and_w(ray, temp));
		add_dist(cub, x, ray, temp);
		cub->th[x] = temp;
		ray = inc_ray(ray, FOV / cub->s_width);
	}
}
