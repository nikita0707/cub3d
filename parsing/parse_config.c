/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:51:28 by rmass             #+#    #+#             */
/*   Updated: 2020/12/08 17:51:28 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_uint	parse_color(char *str)
{
	int		r;
	int		g;
	int		b;

	while (*str == ' ' && *str != 0)
		str++;
	if (!(valid_color(str)))
		return (-1);
	r = ft_atoi(str);
	while (str[0] <= '9' && str[0] >= '0')
		str++;
	str++;
	g = ft_atoi(str);
	while (str[0] <= '9' && str[0] >= '0')
		str++;
	str++;
	b = ft_atoi(str);
	if (r < 0 || b < 0 || g < 0 || r > 255 || b > 255 || g > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

void	parse_res(t_cub *cub, char *conf)
{
	int		i;

	i = 0;
	while (*conf == ' ' && *conf != 0)
		conf++;
	cub->s_width = ft_atoi(conf);
	while (conf[i] >= '0' && conf[i] <= '9')
		i++;
	while (*conf == ' ' && *conf != 0)
		conf++;
	cub->s_height = ft_atoi(&(conf[i]));
	while (conf[++i])
		if (conf[i] < '0' || conf[i] > '9')
			cub->s_width = 0;
}

int		parse_tex(t_cub *cub, char *path, t_texture *tex)
{
	int		ln;
	void	*img;
	char	*data;
	int		w;
	void	*ptr;

	while (*path == ' ' && *path != 0)
		path++;
	ln = ft_strlen(path);
	if (ft_strncmp(&(path[ln - 4]), ".xpm", 4))
		return (0);
	ptr = cub->mlx_ptr;
	img = mlx_xpm_file_to_image(ptr, path, &(tex->width), &(tex->height));
	if (img == 0)
		return (0);
	tex->image = img;
	w = tex->width;
	data = mlx_get_data_addr(img, &(cub->bpp), &(w), &(cub->e));
	if (data == 0)
		return (0);
	tex->data = data;
	return (1);
}

int		setup_conf2(t_cub *cub, char *conf)
{
	if (conf[0] == 'R' && conf[1] == ' ')
		parse_res(cub, &(conf[2]));
	else if (conf[0] == 'S' && conf[1] == 'O' && conf[2] == ' ')
		return (parse_tex(cub, &(conf[3]), &(cub->so_tex)));
	else if (conf[0] == 'S' && conf[1] == ' ')
		return (parse_tex(cub, &(conf[2]), &(cub->s_tex)));
	else if (conf[0] == 'F' && conf[1] == ' ')
		cub->f_color = parse_color(&(conf[2]));
	else if (conf[0] == 'C' && conf[1] == ' ')
		cub->c_color = parse_color(&(conf[2]));
	else if (conf[0] == 'N' && conf[1] == 'O' && conf[2] == ' ')
		return (parse_tex(cub, &(conf[3]), &(cub->no_tex)));
	else if (conf[0] == 'W' && conf[1] == 'E' && conf[2] == ' ')
		return (parse_tex(cub, &(conf[3]), &(cub->we_tex)));
	else if (conf[0] == 'E' && conf[1] == 'A' && conf[2] == ' ')
		return (parse_tex(cub, &(conf[3]), &(cub->ea_tex)));
	else
		return (0);
	return (1);
}

int		setup_conf(t_cub *cub)
{
	char	*conf;
	int		i;

	while (!contains_all_conf(cub))
	{
		i = 0;
		parse_line(cub, cub->config_fd, &conf);
		if (conf[0] == 0 || conf[0] == '\n')
		{
			free(conf);
			continue;
		}
		while (conf[i] == ' ')
			i++;
		if (!(setup_conf2(cub, &conf[i])))
		{
			if (conf)
				free(conf);
			return (0);
		}
		if (conf)
			free(conf);
	}
	return (check_all_conf(cub));
}
