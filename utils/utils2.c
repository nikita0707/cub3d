/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:05:04 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 19:05:53 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	norm_ray(float ray)
{
	while (ray < 0.0f)
		ray += 1.0f;
	while (ray > 1.0f)
		ray -= 1.0f;
	return (ray);
}

float	absf(float f)
{
	if (f < 0)
		return (-f);
	return (f);
}

void	set_prtls(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		cub->prtls[i].x = 0.0f;
		cub->prtls[i].y = 0.0f;
	}
}

void	open_doors(t_cub *cub)
{
	int	x;
	int	y;

	if (cub->pts == 0)
		return ;
	x = cub->player.pos.x;
	y = cub->player.pos.y;
	if (cub->player.dir >= 0.875f || cub->player.dir < 0.125f)
		y--;
	else if (cub->player.dir >= 0.125f && cub->player.dir < 0.375f)
		x++;
	else if (cub->player.dir >= 0.375f && cub->player.dir < 0.625f)
		y++;
	else
		x--;
	if (cub->map[y][x] == 'D')
	{
		cub->map[y][x] = 'O';
		cub->pts--;
	}
}

void	sort_sprites(t_cub *cub)
{
	int		i;
	int		j;
	float	dist1;
	float	dist2;
	t_point	temp;

	i = -1;
	while (++i < cub->sp_count - 1)
	{
		j = -1;
		while (++j < cub->sp_count - i - 1)
		{
			dist1 = pow(cub->player.pos.x - (cub->sprites)[j].x, 2);
			dist1 += pow(cub->player.pos.y - (cub->sprites)[j].y, 2);
			dist2 = pow(cub->player.pos.x - (cub->sprites)[j + 1].x, 2);
			dist2 += pow(cub->player.pos.y - (cub->sprites)[j + 1].y, 2);
			if (dist1 < dist2)
			{
				temp = (cub->sprites)[j];
				(cub->sprites)[j] = (cub->sprites)[j + 1];
				(cub->sprites)[j + 1] = temp;
			}
		}
	}
}
