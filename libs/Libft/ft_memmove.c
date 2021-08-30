/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:22:09 by rmass             #+#    #+#             */
/*   Updated: 2020/10/31 19:47:07 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	if (src == 0 && dst == 0)
		return (dst);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = -1;
	if (dst < src)
	{
		while (++i < (int)len)
			d[i] = s[i];
	}
	else
	{
		i++;
		while (++i <= (int)len)
			d[len - i] = s[len - i];
	}
	return (d);
}
