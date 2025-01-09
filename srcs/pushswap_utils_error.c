/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:56:13 by hsim              #+#    #+#             */
/*   Updated: 2025/01/09 15:45:11 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char **argv, int argc, t_vars *vars)
{
	int	i;

	while (argc > 1)
	{
		i = 1;
		while (argv[i + 1])
		{
			if (!ft_strncmp(argv[1], argv[i + 1], 11))
			{
				if (vars->b_split == 1)
					free_ptr(vars->argv);
				return (ft_perror_fd("Error\n", 2, 0));
			}
			i++;
		}
		argv++;
		argc--;
	}
	return (1);
}

static int	validate_min_int(char *argv, int len)
{
	long	tmp;

	if (len == 11)
	{
		tmp = ft_atol(argv);
		if (tmp < -2147483648)
			return (0);
	}
	else if (len > 11)
		return (0);
	return (1);
}

static int	validate_max_int(char *argv, int len)
{
	long	tmp;

	if (len == 10)
	{
		tmp = ft_atol(argv);
		if (tmp > 2147483647)
			return (0);
	}
	else if (len > 10)
		return (0);
	return (1);
}

/* 
 * Child function in check_str
 * Checks if input exceeds max or min int 
 * better to use int here
 */
int	check_num_limit(char *argv)
{
	int		len;

	len = ft_strlen(argv);
	if (argv[0] == '-' && !validate_min_int(argv, len))
		return (0);
	else if (argv[0] != '-' && !validate_max_int(argv, len))
		return (0);
	return (1);
}

/*
 * checks if char is 0-9, and checks if number exceeds max & min int
 */
int	check_str(char *argv)
{
	int	x;

	x = 0;
	if (!check_num_limit(argv))
		return (ft_perror_fd("Error\n", 2, 0));
	if (argv[x] == '\f' || argv[x] == '	')
		return (ft_perror_fd("Error\n", 2, 0));
	if ((argv[x] == '+' && argv[x + 1] == '+') \
		|| (argv[x] == '-' && argv[x + 1] == '-'))
		return (ft_perror_fd("Error\n", 2, 0));
	if (argv[x] == '+' || argv[x] == '-')
		x++;
	if (!argv[x])
		return (ft_perror_fd("Error\n", 2, 0));
	while (argv[x])
	{
		if (!ft_strchr("0123456789", argv[x++]))
			return (ft_perror_fd("Error\n", 2, 0));
	}
	return (1);
}
