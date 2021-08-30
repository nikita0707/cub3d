/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:49:31 by rmass             #+#    #+#             */
/*   Updated: 2020/10/31 20:24:51 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*res;

	if (s == 0)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (!(res = malloc(len + 1)))
		return (0);
	res[len] = 0;
	i = -1;
	while (++i < (int)len)
		res[i] = s[start + i];
	res[i] = 0;
	return (res);
}
