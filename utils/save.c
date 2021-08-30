/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <rmass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:53:14 by rmass             #+#    #+#             */
/*   Updated: 2020/12/08 17:53:15 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	bmp_header(t_cub *cub, int fd)
{
	int		t;
	short	d;

	write(fd, "BM", 2);
	t = 14 + 40 + cub->s_width * cub->s_height * 4;
	write(fd, &t, sizeof(t));
	d = 0;
	write(fd, &d, sizeof(d));
	write(fd, &d, sizeof(d));
	t = 14 + 40;
	write(fd, &t, sizeof(t));
}

void	image_header(t_cub *cub, int fd)
{
	int		t;
	short	d;

	t = 40;
	write(fd, &t, sizeof(t));
	t = cub->s_width;
	write(fd, &t, sizeof(t));
	t = cub->s_height;
	write(fd, &t, sizeof(t));
	d = 1;
	write(fd, &d, sizeof(d));
	d = 32;
	write(fd, &d, sizeof(d));
	t = 0;
	write(fd, &t, sizeof(t));
	t = cub->s_width * cub->s_height * 4;
	write(fd, &t, sizeof(t));
	t = 2795;
	write(fd, &t, sizeof(t));
	write(fd, &t, sizeof(t));
	t = 0;
	write(fd, &t, sizeof(t));
	write(fd, &t, sizeof(t));
}

char	*find_fn(void)
{
	int		c;
	int		fd;
	char	*fn;
	char	*it;
	char	*temp;

	c = 1;
	it = ft_itoa(c);
	temp = ft_strjoin("screenshots/screenshot", it);
	free(it);
	fn = ft_strjoin(temp, ".bmp");
	free(temp);
	while ((fd = open(fn, O_RDONLY)) > -1)
	{
		close(fd);
		free(fn);
		it = ft_itoa(++c);
		temp = ft_strjoin("screenshots/screenshot", it);
		free(it);
		fn = ft_strjoin(temp, ".bmp");
		free(temp);
	}
	return (fn);
}

int		scr_sh(t_cub *cub, int cr)
{
	int		fd;
	int		i;
	char	*fn;

	fn = find_fn();
	if ((fd = open(fn, O_RDWR | O_CREAT | O_TRUNC, 00600 | 00060 | 00006)) < 0)
		error_open_file(cub);
	free(fn);
	if (cr)
	{
		raycast(cub);
		draw_all(cub);
	}
	bmp_header(cub, fd);
	image_header(cub, fd);
	i = cub->s_height;
	while (--i >= 0)
		write(fd, cub->screen.data + i * cub->s_width * 4, 4 * cub->s_width);
	close(fd);
	return (0);
}
