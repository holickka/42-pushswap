/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:40:45 by hsim              #+#    #+#             */
/*   Updated: 2024/12/28 23:12:54 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char **argv, int argc)
{
	int	i;

	while (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			if (!ft_strncmp(argv[0], argv[i], 11))
				return (ft_perror("Error!\nDuplicates detected!", 0));
			/*debug*/ ft_printf("argv %s %s\n", argv[0], argv[i]);
			i++;
		}
		argv++;
		argc--;
	}
	return (1);
}

int	check_num(char *argv)
{
	int	x;

	x = 0;
	while (argv[x])
	{
		/*debug*/ ft_printf("char=%c\n", argv[x]);
		if (!ft_strchr("-0123456789", argv[x++]))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	/*checknum*/
	if (!check_duplicates(argv, argc))
		return (0);
	while (argv[i] != NULL)
	{
		if (!check_num(argv[i]))
			return (ft_perror("Error!", 0));
		ft_printf("%s\n", argv[i++]);
	}
}
