/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:17:41 by rmass             #+#    #+#             */
/*   Updated: 2020/11/03 16:22:18 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*temp;

	res = ft_strchr(s, c);
	if (res == 0 || c == 0)
		return (res);
	temp = ft_strchr(res + 1, c);
	while (temp != 0)
	{
		res = temp;
		temp = ft_strchr(res + 1, c);
	}
	return (res);
}
