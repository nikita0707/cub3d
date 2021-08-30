/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:21:20 by rmass             #+#    #+#             */
/*   Updated: 2020/11/06 20:54:00 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**fr(char **arr)
{
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	int		j;
	char	**res;

	count = 1;
	i = -1;
	while (s && s[++i])
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
	i = -1;
	if (!s || !(res = malloc(sizeof(char*) * count)))
		return (0);
	res[count - 1] = 0;
	count = -1;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			j = i;
		if (s[i] != c && (s[i + 1] == 0 || s[i + 1] == c))
			if (!(res[++count] = ft_substr(s, j, i - j + 1)))
				return (fr(res));
	}
	return (res);
}
