/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:25:49 by rmass             #+#    #+#             */
/*   Updated: 2020/10/31 20:33:44 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*res;
	int		l1;
	int		l2;

	if (s1 == 0 || s2 == 0)
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(res = malloc(l1 + l2 + 1)))
		return (0);
	i = -1;
	while (++i < (l1 + l2))
		if (i < l1)
			res[i] = s1[i];
		else
			res[i] = s2[i - l1];
	res[i] = 0;
	return (res);
}
