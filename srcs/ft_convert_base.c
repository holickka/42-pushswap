/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:10:24 by hsim              #+#    #+#             */
/*   Updated: 2025/01/03 08:00:39 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* checks if there are spaces, invalid or duplicate characters in base */
static int	checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

/* 
 * nbr have to be in base10
 * converts nbr to base defined in *base_return, and return in *res int
 * not for hexadecimals return
 */
void	ft_itobase(char *base_return, int nbr, int *res)
{
	int		baselen;
	long	n;

	n = (long)nbr;
	baselen = checkbase(base_return);
	if (baselen != 0)
	{
		*res *= 10;
		if (n < 0)
		{
			n *= -1;
			if (baselen == 10 || baselen == 2) // if its base10
				ft_putchar('-');
		}
		if (n >= baselen)
		{
			ft_itobase(base_return, (n / baselen), res);
			ft_itobase(base_return, (n % baselen), res);
		}
		if (n < baselen)
			*res += n;
	}
}

static int	check_input_limit(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '-')
	{
		if (len > 10)
			return (0);
	}
	else if (str[0] != '-')
	{
		if (len > 9)
			return (0);
	}
	return (1);
}

/* 
 * max is 9 digits (eg 214748364),
 * converts str from base10 to base_return
 * more than this will need to convert result to long
 */
int	ft_convert_base(char *base_return, char *str)
{
	int	res;

	res = 0;
	if (!check_input_limit(str))
		return (ft_perror_fd(\
				"Error! exceeded max num limit in ft_convert_base", 2, -1));
	ft_itobase(base_return, ft_atoi(str), &res);
	return (res);
}
