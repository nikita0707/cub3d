/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:50:36 by rmass             #+#    #+#             */
/*   Updated: 2020/12/08 17:50:37 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	jump(t_cub *cub)
{
	if (cub->jump)
	{
		cub->action += cub->s_height / 16;
		if (cub->action >= cub->s_height / 3)
			cub->jump = 0;
	}
	else
	{
		if (cub->action > 0)
			cub->action -= cub->s_height / 16;
	}
}

void	sit(t_cub *cub)
{
	if (cub->sit)
	{
		if (cub->action > -(cub->s_height / 5))
			cub->action -= cub->s_height / 16;
	}
	else
	{
		if (cub->action < 0)
			cub->action += cub->s_height / 16;
	}
}
