/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:34:20 by rmass             #+#    #+#             */
/*   Updated: 2020/11/03 20:00:31 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		contains(char c, char const *set)
{
	int		i;

	i = -1;
	while (set[++i] != 0)
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		ln;
	int		j;

	if (s1 == 0 || set == 0)
		return (0);
	i = 0;
	ln = ft_strlen(s1) - 1;
	while (contains(s1[i], set))
	{
		i++;
		if (s1[i] == 0)
			return (ft_strdup(""));
	}
	while (contains(s1[ln], set))
		ln--;
	j = -1;
	if (!(res = malloc(ln - i + 2)))
		return (0);
	while (i <= ln)
		res[++j] = s1[i++];
	res[++j] = 0;
	return (res);
}
