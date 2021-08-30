/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:38:19 by rmass             #+#    #+#             */
/*   Updated: 2020/11/03 16:26:43 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int j;
	int dstlen;

	j = 0;
	dstlen = ft_strlen(dst);
	i = dstlen - 1;
	while (++i < (int)(dstsize - 1) && src[j] != 0)
		dst[i] = src[j++];
	dst[i] = 0;
	if (dstlen > (int)dstsize)
		dstlen = (int)dstsize;
	return (dstlen + ft_strlen(src));
}
