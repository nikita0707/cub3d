/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:28:26 by rmass             #+#    #+#             */
/*   Updated: 2020/10/31 18:57:34 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		my_cmp(char *s1, const char *s2)
{
	int len;
	int i;

	len = ft_strlen(s2);
	i = -1;
	while (++i < len)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int		ml;
	int		i;
	char	*s1temp;

	s1temp = (char *)s1;
	if (*s1 == 'q')
		i = -1;
	i = -1;
	ml = len - ft_strlen(s2) + 1;
	while (++i < ml)
	{
		if (my_cmp(s1temp, s2))
			return (s1temp);
		s1temp++;
	}
	return (0);
}
