/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:39:58 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 19:04:54 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	setup3(t_cub *cub)
{
	parse_asprite(cub, &(cub->r_tex), "./textures/ricardo/");
	parse_asprite(cub, &(cub->a_tex), "./textures/amity/");
	if (!parse_tex(cub, "./textures/lantern.xpm", &(cub->lantern)))
		error_open_file(cub);
	if (!parse_tex(cub, "./textures/hand.xpm", &(cub->hand)))
		error_open_file(cub);
	if (!parse_tex(cub, "./textures/fireball.xpm", &(cub->fireball)))
		error_open_file(cub);
	if (!parse_tex(cub, "./textures/skybox1.xpm", &(cub->skybox)))
		error_open_file(cub);
	if (!parse_tex(cub, "./textures/hp.xpm", &(cub->hp_tex)))
		error_open_file(cub);
	if (!parse_tex(cub, "./textures/point.xpm", &(cub->pnt_tex)))
		error_open_file(cub);
	if (!parse_tex(cub, "./textures/floor3.xpm", &(cub->fl_tex)))
		error_open_file(cub);
	if (!parse_tex(cub, "./textures/door2.xpm", &(cub->cdoor_tex)))
		error_open_file(cub);
	if (!parse_tex(cub, "./textures/odoor.xpm", &(cub->odoor_tex)))
		error_open_file(cub);
	parse_sprites(cub);
}

void	setup2(t_cub *cub)
{
	int		i;
	char	*it;
	char	*temp;

	cub->mx = cub->s_width / 2;
	cub->my = cub->s_height / 2;
	cub->th = (t_point*)malloc(sizeof(t_point) * cub->s_width);
	cub->tp = 0;
	i = -1;
	cub->port_tex = malloc(sizeof(t_texture) * 7);
	while (++i < 7)
	{
		it = ft_itoa(i);
		temp = ft_strjoin("./textures/portals/", it);
		free(it);
		it = ft_strjoin(temp, ".xpm");
		free(temp);
		if (!parse_tex(cub, it, &(cub->port_tex[i])))
		{
			free(it);
			error_open_file(cub);
		}
		free(it);
	}
	setup3(cub);
}

/*
** if (argc != 3)
** {
** 	mlx_get_screen_size(cub->mlx_ptr, &sx, &sy);
** 	if (cub->s_height > sy)
** 		cub->s_height = sy;
** 	if (cub->s_width > sx)
** 		cub->s_width = sx;
** }
*/

void	setup(t_cub *cub, int argc)
{
	int		e;
	int		w;
	void	*img;

	argc += 0;
	if (cub->s_height > 1080)
		cub->s_height = 1080;
	if (cub->s_width > 1920)
		cub->s_width = 1920;
	w = cub->s_width;
	cub->dists = malloc(sizeof(float) * w);
	cub->hits = malloc(sizeof(float) * w);
	cub->sides = malloc(sizeof(float) * w);
	cub->screen.width = cub->s_width;
	cub->screen.height = cub->s_height;
	cub->screen.image = mlx_new_image(cub->mlx_ptr, w, cub->s_height);
	e = 0;
	img = cub->screen.image;
	cub->screen.data = mlx_get_data_addr(img, &(cub->bpp), &(w), &e);
	setup2(cub);
}
