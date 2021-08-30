/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:53:09 by rmass             #+#    #+#             */
/*   Updated: 2020/12/09 16:28:26 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		contains_all_conf(t_cub *cub)
{
	if (cub->s_tex.image && cub->f_color && cub->c_color && cub->s_height &&
	cub->s_width && cub->no_tex.image && cub->so_tex.image &&
	cub->we_tex.image && cub->ea_tex.image)
		return (1);
	return (0);
}

int		check_all_conf(t_cub *cub)
{
	if (cub->s_tex.image && (cub->f_color <= 0xFFFFFF)
	&& (cub->c_color <= 0xFFFFFF)
	&& cub->s_height && cub->s_width && cub->no_tex.image
	&& cub->so_tex.image && cub->we_tex.image && cub->ea_tex.image)
		return (1);
	return (0);
}

int		valid_color(char *str)
{
	int		cc;
	int		i;

	cc = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			cc++;
		else if (str[i] > '9' || str[i] < '0')
			return (0);
	}
	if (cc != 2)
		return (0);
	return (1);
}

int		get_spc(char *path)
{
	int		fd;
	char	buf[5];

	path = ft_strjoin(path, "count");
	fd = open(path, O_RDONLY);
	buf[read(fd, buf, 4)] = 0;
	close(fd);
	free(path);
	return (ft_atoi(buf));
}

void	parse_asprite(t_cub *cub, t_asprite *tex, char *p)
{
	int		i;
	char	*path;
	char	*it;

	i = -1;
	tex->count = get_spc(p);
	tex->tf = 0;
	tex->tex = (t_texture*)malloc(sizeof(t_texture) * tex->count);
	while (++i < tex->count)
	{
		it = ft_itoa(i);
		path = ft_strjoin(p, it);
		free(it);
		it = ft_strjoin(path, ".xpm");
		free(path);
		if (!parse_tex(cub, it, &(tex->tex[i])))
		{
			free(it);
			error_open_file(cub);
		}
		free(it);
	}
}
