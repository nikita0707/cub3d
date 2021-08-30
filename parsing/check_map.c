/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:51:25 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 16:47:46 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		valid_space(t_cub *cub, int i, int j)
{
	if ((i == 0 ||
	(cub->map)[j][i - 1] == '1' || (cub->map)[j][i - 1] == ' ')
	&& (j == 0 || i >= (int)ft_strlen((cub->map)[j - 1]) ||
	(cub->map)[j - 1][i] == '1' || (cub->map)[j - 1][i] == ' ')
	&& ((cub->map)[j][i + 1] == 0 ||
	(cub->map)[j][i + 1] == '1' || (cub->map)[j][i + 1] == ' ')
	&& (j == cub->map_size - 1 || i >= (int)ft_strlen((cub->map)[j + 1]) ||
	(cub->map)[j + 1][i] == '1' || (cub->map)[j + 1][i] == ' '))
		return (1);
	return (0);
}

int		valid_other(t_cub *cub, int i, int j, float dir)
{
	char t;

	t = cub->map[j][i];
	if (dir >= 0.0f && (t == 'N' || t == 'E' || t == 'S' || t == 'W'))
		return (0);
	if (t == 'N')
		cub->player.dir = 0.0f;
	if (t == 'E')
		cub->player.dir = 0.25f;
	if (t == 'S')
		cub->player.dir = 0.5f;
	if (t == 'W')
		cub->player.dir = 0.75f;
	if (t == 'N' || t == 'E' || t == 'S' || t == 'W')
	{
		cub->player.pos.x = i + 0.5f;
		cub->player.pos.y = j + 0.5f;
	}
	if (t != '0' && t != '2' && cub->player.dir < 0)
		return (0);
	if (i == 0 || j == 0 || i >= (int)ft_strlen((cub->map)[j - 1]) ||
	(cub->map)[j][i + 1] == 0 || j == cub->map_size - 1 ||
	i >= (int)ft_strlen((cub->map)[j + 1]))
		return (0);
	return (1);
}

int		set_portals(t_cub *cub, int i, int j)
{
	int		p;

	p = ((cub->map)[j][i] - '3') * 2;
	if (cub->prtls[p].x > 0.5f && cub->prtls[p + 1].x > 0.5f)
		return (0);
	if (cub->prtls[p].x > 0.5f)
		p++;
	cub->prtls[p].x = (float)i + 0.5f;
	cub->prtls[p].y = (float)j + 0.5f;
	return (1);
}

int		check_sprites(t_cub *cub, int i, int j)
{
	if ((cub->map)[j][i] != 'A' && (cub->map)[j][i] != 'P' \
	&& (cub->map)[j][i] != 'R' && (cub->map)[j][i] != 'D' \
	&& ((cub->map)[j][i] < '3' || (cub->map)[j][i] > '9'))
		return (1);
	if (i == 0 || j == 0 || i >= (int)ft_strlen((cub->map)[j - 1]) ||
	(cub->map)[j][i + 1] == 0 || j == cub->map_size - 1 ||
	i >= (int)ft_strlen((cub->map)[j + 1]))
		return (0);
	if ((cub->map)[j][i] > '2' && (cub->map)[j][i] <= '9' \
	&& !set_portals(cub, i, j))
		return (0);
	return (2);
}

int		check_map(t_cub *cub)
{
	int		i;
	int		j;
	int		f;

	j = -1;
	f = 1;
	while (++j < cub->map_size && (i = -1) == -1)
	{
		if (j != 0 && ((cub->map)[j][0] == 0 && cub->map_size > j - 2))
			return (0);
		while ((cub->map)[j][++i] != 0)
		{
			if (BONUS && !(f = check_sprites(cub, i, j)))
				return (0);
			if ((cub->map)[j][i] == '1' || f == 2)
				continue ;
			if ((cub->map)[j][i] == ' ' && !valid_space(cub, i, j))
				return (0);
			if ((cub->map)[j][i] != ' ' \
			&& !valid_other(cub, i, j, cub->player.dir))
				return (0);
		}
	}
	return ((cub->player.dir >= 0) ? 1 : 0);
}
