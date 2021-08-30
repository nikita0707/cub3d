/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:43:54 by rmass             #+#    #+#             */
/*   Updated: 2020/11/01 20:49:26 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		len;

	if (s == 0)
		return (0);
	len = ft_strlen(s);
	if (!(res = malloc(len + 1)))
		return (0);
	res[len] = 0;
	while (--len >= 0)
		res[len] = f(len, s[len]);
	return (res);
}
