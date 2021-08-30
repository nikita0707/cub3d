/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:53:07 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 16:27:36 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		down(int key, t_cub *cub)
{
	if (key == ESC)
		clear(cub);
	cub->keys.w = (key == W) ? 1 : cub->keys.w;
	cub->keys.a = (key == A) ? 1 : cub->keys.a;
	cub->keys.s = (key == S) ? 1 : cub->keys.s;
	cub->keys.d = (key == D) ? 1 : cub->keys.d;
	if (key == LARROW)
		cub->keys.la = 1;
	if (key == RARROW)
		cub->keys.ra = 1;
	if (key == SHIFT && !cub->sit)
		cub->speed = 1.5f;
	if (key == P)
		scr_sh(cub, 0);
	if (key == SPACE && cub->action == 0 && !cub->sit)
		cub->jump = 1;
	if (key == CTRL && cub->action == 0)
	{
		cub->sit = 1;
		cub->speed = 0.5;
	}
	if (key == F)
		open_doors(cub);
	return (1);
}

int		up(int key, t_cub *cub)
{
	if (key == W)
		cub->keys.w = 0;
	if (key == A)
		cub->keys.a = 0;
	if (key == S)
		cub->keys.s = 0;
	if (key == D)
		cub->keys.d = 0;
	if (key == LARROW)
		cub->keys.la = 0;
	if (key == RARROW)
		cub->keys.ra = 0;
	if (key == SHIFT && !cub->sit)
		cub->speed = 1.0f;
	if (key == CTRL)
	{
		cub->sit = 0;
		cub->speed = 1.0f;
	}
	return (1);
}

int		fi(t_cub *cub)
{
	cub->focus = 1;
	return (1);
}

int		fo(t_cub *cub)
{
	cub->focus = 0;
	return (1);
}

int		exita(t_cub *cub)
{
	exit(0);
	free(cub->win_ptr);
	return (1);
}
