/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:40:45 by hsim              #+#    #+#             */
/*   Updated: 2025/01/02 07:57:33 by hsim             ###   ########.fr       */
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
			// /*debug*/ ft_printf("argv %s %s\n", argv[0], argv[i]);
			i++;
		}
		argv++;
		argc--;
	}
	return (1);
}

/* 
 * Child function in check_str
 * Checks if input exceeds max or min int 
 */
int	check_num_limit(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[0] == '-')
	{
		if (len == 11)
		{
			if (argv[len - 1] == '9')
				return (0);
		}
		if (len > 11)
			return (0);
	}
	else if (argv[0] != '-')
	{
		if (len == 10)
		{
			if (argv[len - 1] == '8' || argv[len - 1] == '9')
				return (0);
		}
		if (len > 10)
			return (0);
	}
	return (1);
}

/*
 * checks if char is 0-9, and checks if number exceeds max & min int
 */
int	check_str(char *argv)
{
	int	x;

	x = 0;
	while (argv[x])
	{
		// /*debug*/ ft_printf("char=%c\n", argv[x]);
		if (!ft_strchr("-0123456789", argv[x++]))
			return (ft_perror("Input consists of non-integers", 0));
		if (!check_num_limit(argv))
			return (ft_perror("Input exceeds max or min int", 0));
	}
	return (1);
}

/*not needed*/
int	count_bit(int num)
{
	int	count;

	count = 0;
	while (num > 9)
	{
		num /= 10;
		count++;
	}
	return (count);
}

/*not needed*/
void	convert_to_binary(t_vars *vars, char *argv, int *num)
{
	int	x;

	*num = ft_basetoi("01", argv, 11);
	x = count_bit(*num);
	if (x > vars->bits)
		vars->bits = x;
}

int	initialize_data_container(t_vars *vars, int argc)
{
	vars->num = (int *)malloc(sizeof(int) * (argc - 1));
	vars->sorted_num = (int *)malloc(sizeof(int) * (argc - 1));

	if (!vars->num || !vars->sorted_num)
	{
		free(vars->num);
		free(vars->sorted_num);
		return (ft_perror("Error! malloc failed in initialization", 0));
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_vars	vars;

	i = 1;
	vars.bits = 0;
	if (argc < 2)
		return (0);
	/*debug*/ printf("argc=%d\n", argc);
	/*checknum*/
	if (!check_duplicates(argv, argc))
		return (0);
	if (!initialize_data_container(&vars, argc))
		return (0);
	/*copy num*/
	while (argv[i] != NULL)
	{
		if (!check_str(argv[i]))
		{
			free(vars.num);
			return (ft_perror("Error!", 0));
		}
		vars.num[i - 1] = ft_atoi(argv[i]);
		vars.sorted_num[i - 1] = vars.num[i - 1];
		i++;
	}
	merge_sort(vars.sorted_num, (argc - 1));

	/*------------debug------------*/
	int x = 0;
	printf("array=");
	while (x < argc - 1)
		/*debug*/ printf("%d ", vars.num[x++]);
	printf("\n");
	x = 0;
	printf("sorted=");
	while (x < argc - 1)
		/*debug*/ printf("%d ", vars.sorted_num[x++]);
	/*------------debug end------------*/

	find_n_replace(vars.sorted_num, vars.num, argc);

	/*------------debug------------*/
	x = 0;
	printf("\nnew_index=");
	while (x < argc - 1)
		/*debug*/ printf("%d ", vars.num[x++]);
	/*----------debug end-----------*/

	// /*debug*/ printf("bitwise=%d %d\n", (8 >> 2), (8 >> 2) & 1);
	radix_sort(vars.num, (argc - 2));

	/*------------debug------------*/
	x = 0;
	printf("\nradix_sort=");
	while (x < argc - 1)
		/*debug*/ printf("%d ", vars.num[x++]);
	/*----------debug end-----------*/
	/*remember to free initialized malloc pointers*/
}
