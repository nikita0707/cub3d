/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:51:37 by rmass             #+#    #+#             */
/*   Updated: 2020/12/12 16:03:17 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		check_correct_args(int argc, char **argv)
{
	int		ln;

	if (argc < 2)
	{
		ft_putstr_fd("Not enough arguments!\n", 1);
		return (0);
	}
	if (argc > 3)
	{
		ft_putstr_fd("Too much arguments!\n", 1);
		return (0);
	}
	ln = ft_strlen(argv[1]);
	if (ln < 5 || ft_strncmp(".map", &(argv[1][ln - 4]), 4))
	{
		ft_putstr_fd("Wrong map!\n", 1);
		return (0);
	}
	if (argc == 3 && ft_strncmp("--save", argv[2], 6))
	{
		ft_putstr_fd("Wrong second param!\n", 1);
		return (0);
	}
	return (1);
}

int		map_and_conf(t_cub *cub)
{
	if (!setup_conf(cub))
	{
		ft_putstr_fd("Not valid config!\n", 1);
		clear(cub);
		return (0);
	}
	if (!parse_map(cub) || !(check_map(cub)))
	{
		ft_putstr_fd("Not valid map!\n", 1);
		clear(cub);
		return (0);
	}
	return (1);
}

void	start(t_cub *cub)
{
	mlx_hook(cub->win_ptr, 17, 1L << 17, exita, cub);
	mlx_hook(cub->win_ptr, 2, 1L << 0, down, cub);
	mlx_hook(cub->win_ptr, 3, 1L << 1, up, cub);
	mlx_hook(cub->win_ptr, 9, 1L << 21, fi, cub);
	mlx_hook(cub->win_ptr, 10, 1L << 21, fo, cub);
	mlx_loop_hook(cub->mlx_ptr, loop, cub);
	mlx_loop(cub->mlx_ptr);
}

void	music(t_cub *cub)
{
	cub->pid = fork();
	if (!(cub->pid))
		execlp("mpg123", "mpg123", "-q", "-f", "-1600", "./m.mp3", NULL);
}

int		main(int argc, char **argv)
{
	t_cub		*cub;
	int			w;
	int			h;

	if (!(check_correct_args(argc, argv)))
		return (0);
	cub = (t_cub*)malloc(sizeof(t_cub));
	set_z(cub);
	cub->config_fd = open(argv[1], O_RDONLY);
	cub->mlx_ptr = mlx_init();
	cub->prtls = (t_point*)malloc(sizeof(t_point) * 14);
	set_prtls(cub);
	if (!(map_and_conf(cub)))
		return (0);
	setup(cub, argc);
	if (argc == 3)
		return (scr_sh(cub, 1));
	w = cub->s_width;
	h = cub->s_height;
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, w, h, "cub3D");
	if (BONUS && MUSIC)
		music(cub);
	fi(cub);
	start(cub);
	return (argc);
}
