/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:53:17 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 16:17:13 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*sfromc(char c)
{
	char	*res;
	int		ln;

	ln = 1;
	if (c)
		ln++;
	res = malloc(ln);
	if (c)
		res[0] = c;
	res[ln - 1] = 0;
	return (res);
}

char	cfrommap(t_cub *cub, int x, int y)
{
	char	**map;

	map = cub->map;
	if (x < 0 || y < 0 || y >= cub->map_size || (int)ft_strlen(map[y]) <= x)
		return ('0');
	return (map[y][x]);
}

int		issprite(t_cub *cub, int x, int y)
{
	if (cub->map[y][x] == '2' || cub->map[y][x] == 'R'
	|| cub->map[y][x] == 'A' || cub->map[y][x] == 'P'
	|| (cub->map[y][x] > '2' && cub->map[y][x] <= '9')
	|| cub->map[y][x] == 'D')
		return (1);
	return (0);
}

void	parse_sprites(t_cub *cub)
{
	int		x;
	int		y;
	int		i;

	y = -1;
	while (++y < cub->map_size && (x = -1))
	{
		while (cub->map[y][++x])
			if (issprite(cub, x, y))
				(cub->sp_count)++;
	}
	cub->sprites = (t_point*)malloc(sizeof(t_point) * cub->sp_count);
	y = -1;
	i = 0;
	while (++y < cub->map_size && (x = -1))
	{
		while (cub->map[y][++x])
			if (issprite(cub, x, y))
			{
				(cub->sprites)[i].x = (float)x + 0.5f;
				(cub->sprites)[i++].y = (float)y + 0.5f;
			}
	}
}

t_uint	get_color(t_texture tex, int x, int y)
{
	unsigned int	color;

	color = *(unsigned int*)(tex.data + (y * tex.width + x) * 4);
	return (color);
}
