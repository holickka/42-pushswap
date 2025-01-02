/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_simplesort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:09:29 by hsim              #+#    #+#             */
/*   Updated: 2025/01/02 22:59:57 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * bubble checks if numbers in array are all in ascending order
 * argc here is default (argc - 2) when enter
 */
int	if_sorted(int *num, int argc)
{
	int	i;
	int	x;

	x = 0;
	// /*debug*/ printf("argc=%d\n", argc);
	while (x < argc)
	{
		i = x + 1;
		while (i <= argc)
		{
			if (num[x] > num[i])
				return (0);
				// return (ft_perror("diff!", 0)); //sort ascending fail
			// /*debug*/ ft_printf("x%d i%d\n", num[x], num[i]);
			i++;
		}
		x++;
	}
	return (ft_perror("sorted!", 1));
}

/*
 * sort_small(3), max 3 moves
 * if num[0] < num[1] && num[2], return
 * if num[0] > num[1] && num[2], ra
 * else, sa
 */
/*
 * when argc <= 5, use simple sort
 * argc has to be (argc - 2) here during enter
 */
void	simple_sort(int *num, int argc)
{
	int	i;

	// i = 0;
	/*-------debug------*/
	int x = 0;
	printf("enter=");
	while (x <= argc)
	/*debug*/ printf("%d ", num[x++]);
	printf("\n");
	/*-------debug end------*/

	/*checks if sorted, some while loop here*/
	while (!if_sorted(num, argc))
	{
		i = 0;
		while (i < argc)
		{
			if ((num[0 + i] < num[1 + i]) && (num[0 + i] < num[2 + i]))
				i++;
			else if ((num[0 + i] > num[1 + i]) && (num[0 + i] > num[2 + i]))
				rotate_a(&num[i], argc, i);
			else
			{
				/*-------debug------*/
				x = 0;
				printf("before sa=");
				while (x <= argc)
				/*debug*/ printf("%d ", num[x++]);
				printf("\n");
				/*-------debug end------*/

				swap_a(&num[i]);

				/*-------debug------*/
				x = 0;
				printf("sa=");
				while (x <= argc)
				/*debug*/ printf("%d ", num[x++]);
				printf("\n");
				/*-------debug end------*/
			}
		}
	}
}