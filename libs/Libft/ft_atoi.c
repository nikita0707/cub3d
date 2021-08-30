/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmass <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:57:11 by rmass             #+#    #+#             */
/*   Updated: 2020/11/04 16:17:54 by rmass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	delete_spaces(const char *str)
{
	int find;
	int count;

	find = 1;
	count = 0;
	while (find == 1)
		if (*str == ' ' || *str == '\n' || *str == '\t')
		{
			count++;
			str++;
		}
		else if (*str == '\r' || *str == '\v' || *str == '\f')
		{
			count++;
			str++;
		}
		else
			find = 0;
	return (count);
}

int	ft_atoi(const char *str)
{
	int temp;
	int i;
	int neg;
	int t;

	temp = 0;
	i = 0;
	t = 0;
	neg = 1;
	str += delete_spaces(str);
	if (*str == '+')
		str++;
	else if (*str == '-' && str++)
		neg = -1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		temp = temp * 10 + str[i] - '0';
		t += (temp != 0) ? 1 : 0;
		if (t > 19)
			return ((neg == 1) ? -1 : 0);
		i++;
	}
	return (temp * neg);
}
