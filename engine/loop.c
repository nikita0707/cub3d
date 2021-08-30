/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:51:07 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 12:43:32 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		loop(t_cub *cub)
{
	void	*mp;

	mp = cub->mlx_ptr;
	if (cub->focus && BONUS)
	{
		if (cub->mhide)
			mlx_mouse_get_pos(cub->win_ptr, &(cub->mx), &(cub->my));
		mlx_mouse_hide(mp, cub->win_ptr);
		cub->mhide = 1;
		mlx_mouse_move(cub->win_ptr, cub->s_width / 2, cub->s_height / 2);
	}
	else if (BONUS)
	{
		mlx_mouse_show(mp, cub->win_ptr);
		cub->mhide = 0;
	}
	raycast(cub);
	draw_all(cub);
	mlx_put_image_to_window(mp, cub->win_ptr, cub->screen.image, 0, 0);
	move(cub);
	return (1);
}
