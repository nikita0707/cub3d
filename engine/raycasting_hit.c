/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:51:13 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 08:00:41 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		hit_out(t_cub *cub, t_point pt, int tx, int y)
{
	if ((int)floorf(pt.x + EPS) < 0)
	{
		(cub->hits)[tx] = 1.0f - (pt.y - floorf(pt.y) + EPS);
		(cub->sides)[tx] = 3;
		return (1);
	}
	if (y < 0)
	{
		(cub->hits)[tx] = pt.x - floorf(pt.x) + EPS;
		(cub->sides)[tx] = 0;
		return (1);
	}
	if (y >= cub->map_size)
	{
		(cub->hits)[tx] = 1.0 - (pt.x - floorf(pt.x) + EPS);
		(cub->sides)[tx] = 1;
		return (1);
	}
	if ((int)floorf(pt.x + EPS) >= (int)ft_strlen(cub->map[y]))
	{
		(cub->hits)[tx] = pt.y - floorf(pt.y) + EPS;
		(cub->sides)[tx] = 2;
		return (1);
	}
	return (0);
}

void	hit_the_wall3(t_cub *cub, t_point pt, float *res, int *side)
{
	int		x;
	int		y;
	char	**map;

	map = cub->map;
	x = (int)floorf(pt.x + EPS);
	y = (int)floorf(pt.y + EPS);
	if (floorf(pt.y - EPS) < floorf(pt.y))
	{
		if (map[y][x] == '1')
		{
			*res = 1.0 - (pt.x - floorf(pt.x) + EPS);
			*side = 0;
		}
		else if (map[y - 1][x] == '1')
		{
			*res = pt.x - floorf(pt.x) + EPS;
			*side = 1;
		}
	}
}

void	hit_the_wall2(t_cub *cub, t_point pt, float *res, int *side)
{
	int		x;
	int		y;
	char	**map;

	map = cub->map;
	x = (int)floorf(pt.x + EPS);
	y = (int)floorf(pt.y + EPS);
	if (floorf(pt.x - EPS) < floorf(pt.x))
	{
		if (map[y][x - 1] == '1')
		{
			*res = 1.0f - (pt.y - floorf(pt.y) + EPS);
			*side = 3;
		}
		else if (map[y][x] == '1')
		{
			*res = pt.y - floorf(pt.y) + EPS;
			*side = 2;
		}
	}
}

int		hit_the_wall(t_cub *cub, t_point pt, int tx)
{
	int		y;
	int		side;
	float	res;

	y = (int)floorf(pt.y + EPS);
	res = -1.0f;
	side = -1;
	if (hit_out(cub, pt, tx, y))
		return (1);
	hit_the_wall2(cub, pt, &res, &side);
	hit_the_wall3(cub, pt, &res, &side);
	if (res > -0.5f)
	{
		(cub->hits)[tx] = res;
		(cub->sides)[tx] = side;
		return (1);
	}
	return (0);
}
