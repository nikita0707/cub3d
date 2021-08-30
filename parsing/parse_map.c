/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:51:31 by rmass             #+#    #+#             */
/*   Updated: 2020/12/11 16:04:17 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	add_str(char **line, char *buf)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = -1;
	ptr = *line;
	*line = malloc(ft_strlen(*line) + ft_strlen(buf) + 1);
	while (ptr && ptr[i])
	{
		(*line)[i] = ptr[i];
		i++;
	}
	if (ptr)
		free(ptr);
	while (buf[++j])
		(*line)[i++] = buf[j];
	(*line)[i] = 0;
}

void	parse_line_cr(char **line, char *buf, int j)
{
	buf[j + 1] = 0;
	if (j > -1)
		add_str(line, buf);
	if (!(*line))
		*line = sfromc(0);
}

int		parse_line(t_cub *cub, int fd, char **line)
{
	int		r;
	int		j;
	char	*buf;
	char	t;

	j = -1;
	buf = malloc(11);
	buf[10] = 0;
	*line = 0;
	while ((r = read(fd, &t, 1)))
	{
		if (r < 0)
			error_open_file(cub);
		if (t == '\n')
			break ;
		buf[++j] = t;
		if (j == 9)
		{
			j = -1;
			add_str(line, buf);
		}
	}
	parse_line_cr(line, buf, j);
	free(buf);
	return (((*line) == 0 || r == 0) ? 0 : 1);
}

void	inc_map(t_cub **cub1)
{
	char	**res;
	int		i;
	t_cub	*cub;

	cub = *cub1;
	i = -1;
	res = (char**)malloc(sizeof(char*) * (cub->map_size + 1));
	while (++i < cub->map_size)
		res[i] = (cub->map)[i];
	if (cub->map)
		free(cub->map);
	cub->map = res;
}

int		parse_map(t_cub *cub)
{
	char	*temp;

	while (parse_line(cub, cub->config_fd, &temp) || temp[0] != 0)
	{
		if (temp[0] == 0 && cub->map_size > 0)
		{
			free(temp);
			return (0);
		}
		if (temp[0] == 0)
		{
			free(temp);
			continue;
		}
		inc_map(&cub);
		(cub->map)[cub->map_size] = temp;
		(cub->map_size)++;
	}
	if (temp)
		free(temp);
	return (1);
}
