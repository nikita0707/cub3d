/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:53:12 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 16:30:42 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_z3(t_cub *cub)
{
	cub->skybox.image = 0;
	cub->skybox.data = 0;
	cub->pts = 3;
}

void	set_z2(t_cub *cub)
{
	cub->screen.image = 0;
	cub->keys.w = 0;
	cub->keys.a = 0;
	cub->keys.s = 0;
	cub->keys.d = 0;
	cub->keys.la = 0;
	cub->keys.ra = 0;
	cub->dists = 0;
	cub->mx = 0;
	cub->my = 0;
	cub->focus = 0;
	cub->mhide = 0;
	cub->speed = 1.0f;
	cub->bpp = 32;
	cub->e = 0;
	cub->hits = 0;
	cub->sides = 0;
	cub->action = 0;
	cub->jump = 0;
	cub->sit = 0;
	cub->vision = 0;
	cub->lp = 0;
	cub->sprites = 0;
	cub->sp_count = 0;
	set_z3(cub);
}

void	set_z(t_cub *cub)
{
	cub->player.dir = -1;
	cub->map = 0;
	cub->config_fd = 0;
	cub->map_size = 0;
	cub->s_height = 0;
	cub->s_width = 0;
	cub->no_tex.image = 0;
	cub->so_tex.image = 0;
	cub->we_tex.image = 0;
	cub->ea_tex.image = 0;
	cub->lantern.image = 0;
	cub->hand.image = 0;
	cub->fireball.image = 0;
	cub->s_tex.image = 0;
	cub->no_tex.data = 0;
	cub->so_tex.data = 0;
	cub->we_tex.data = 0;
	cub->ea_tex.data = 0;
	cub->lantern.data = 0;
	cub->hand.data = 0;
	cub->fireball.data = 0;
	cub->s_tex.data = 0;
	cub->f_color = 0;
	cub->c_color = 0;
	set_z2(cub);
}
