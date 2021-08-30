/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:53:05 by rmass             #+#    #+#             */
/*   Updated: 2020/12/11 16:02:37 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error_open_file(t_cub *cub)
{
	ft_putstr_fd("Error while trying to open file\n", 1);
	free(cub->win_ptr);
	exit(0);
}
