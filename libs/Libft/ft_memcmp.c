/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:41:01 by rmass             #+#    #+#             */
/*   Updated: 2020/10/31 18:55:23 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1t;
	unsigned char	*s2t;

	i = 0;
	s1t = (unsigned char *)s1;
	s2t = (unsigned char *)s2;
	while (i < n)
	{
		if (s1t[i] > s2t[i])
			return (s1t[i] - s2t[i]);
		else if (s1t[i] < s2t[i])
			return (s1t[i] - s2t[i]);
		i++;
	}
	return (0);
}
