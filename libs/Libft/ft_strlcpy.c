/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:12:14 by rmass             #+#    #+#             */
/*   Updated: 2020/10/31 18:55:51 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;

	i = -1;
	if (dst == 0 && src == 0)
		return (0);
	while (++i < (int)(dstsize - 1) && src[i] != 0)
		dst[i] = src[i];
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
