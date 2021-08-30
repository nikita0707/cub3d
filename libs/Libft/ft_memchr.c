/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:29:58 by rmass             #+#    #+#             */
/*   Updated: 2020/10/31 18:55:01 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*temp;

	i = -1;
	temp = (char *)s;
	while (++i < (int)n)
	{
		if (temp[0] == c)
			return (temp);
		temp++;
	}
	return (0);
}
