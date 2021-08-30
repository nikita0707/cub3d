/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:53:00 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 19:14:20 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_destroy_image(void *mlx_ptr, void *img_ptr)
{
	if (mlx_ptr && img_ptr)
		mlx_destroy_image(mlx_ptr, img_ptr);
}

void	clear_asp(t_cub *cub, t_asprite tex)
{
	int	i;

	i = -1;
	while (++i < tex.count)
		my_mlx_destroy_image(cub->mlx_ptr, (tex.tex[i]).image);
}

void	kill_music(void)
{
	char	*kill;
	FILE	*pid;
	char	*buff;

	if (!BONUS || !MUSIC)
		return ;
	buff = calloc(10, 1);
	pid = popen("pgrep mpg123", "r");
	fscanf(pid, "%s", buff);
	pclose(pid);
	kill = ft_strjoin("kill ", buff);
	if (buff[0] != 0)
		system(kill);
	free(buff);
	free(kill);
}

void	clear2(t_cub *cub)
{
	int	i;

	i = -1;
	my_mlx_destroy_image(cub->mlx_ptr, cub->hp_tex.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->fl_tex.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->cdoor_tex.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->odoor_tex.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->pnt_tex.image);
	clear_asp(cub, cub->r_tex);
	clear_asp(cub, cub->a_tex);
	while (cub->port_tex && ++i < 7)
		my_mlx_destroy_image(cub->mlx_ptr, cub->port_tex[i].image);
	free(cub->port_tex);
	free(cub->prtls);
	free(cub->r_tex.tex);
	free(cub->a_tex.tex);
	free(cub->th);
	free(cub->hits);
	kill_music();
}

void	clear(t_cub *cub)
{
	int		i;

	my_mlx_destroy_image(cub->mlx_ptr, cub->screen.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->s_tex.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->no_tex.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->so_tex.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->we_tex.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->ea_tex.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->lantern.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->hand.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->fireball.image);
	my_mlx_destroy_image(cub->mlx_ptr, cub->skybox.image);
	clear2(cub);
	if (cub->mlx_ptr && cub->win_ptr)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	free(cub->mlx_ptr);
	free(cub->dists);
	free(cub->sides);
	free(cub->sprites);
	i = -1;
	while (++i < cub->map_size)
		free((cub->map)[i]);
	free(cub->map);
	free(cub);
	exit(0);
}
