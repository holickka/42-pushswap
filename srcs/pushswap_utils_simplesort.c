/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_simplesort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:09:29 by hsim              #+#    #+#             */
/*   Updated: 2025/01/09 14:32:20 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * bubble checks if numbers in array are all in ascending order
 * returns (1) if true
 * argc here is default (argc - 2) when enter
 */
int	if_sorted(int *num, int argc)
{
	int	i;
	int	x;

	x = 0;
	while (x < argc)
	{
		i = x + 1;
		while (i <= argc)
		{
			if (num[x] > num[i])
				return (0);
			i++;
		}
		x++;
	}
	return (1);
}

/*
 * Checks the index location of value 0
 * returns index location where value 0 is found
 * else, returns (-1)
 * argc has to be [(argc - 2) - count_pb] here (if push_b involved)
 * count_pb here is to update the new min number after being push_b
 * can set count_pb = 0 if no push_b involved
 */
int	locate_min(int *num, int argc, int count_pb)
{
	int	i;

	i = 0;
	while (i <= argc)
	{
		if (num[i] == 0 + count_pb)
			return (i);
		i++;
	}
	return (-1);
}

/*
 * Checks if num[0] entered is the smallest value in the array
 * returns (1) if true
 * argc is (argc - 2) here && argc has to be (argc - count_pb)
 * to exclude the number that is pushed to stack_b
 */
int	if_min(int *num, int argc)
{
	int	i;

	i = 1;
	while (i <= argc)
	{
		if (num[0] > num[i])
			return (0);
		i++;
	}
	return (1);
}

/*
 * used when argc = range of 3 to 5 
 * argc has to be (argc - 2) here during enter
 * uses malloc
 */
void	simple_sort_5(int *num, int argc)
{
	int	*tmp_arr;
	int	count_pb;
	int	mid;
	int	min;

	count_pb = 0;
	tmp_arr = (int *)malloc(sizeof(int) * (argc + 1));
	while (!if_sorted(num, argc - count_pb))
	{
		mid = ((argc - count_pb) / 2);
		min = locate_min(num, argc - count_pb, count_pb);
		if (if_min(num, argc - count_pb))
		{
			count_pb++;
			push_b(num, tmp_arr, argc, count_pb);
		}
		else if (min <= mid)
			rotate_a(num, argc, count_pb);
		else if (min > mid)
			rev_rotate_a(num, argc, count_pb);
	}
	while (count_pb > 0)
		push_a(num, tmp_arr, argc, count_pb--);
	free(tmp_arr);
}

/*
 * used when argc <= 3
 * argc has to be (argc - 2) here during enter
 * uses malloc
 */
void	simple_sort_3(int *num, int argc)
{
	int	min_index;

	while (!if_sorted(num, argc))
	{
		min_index = locate_min(num, argc, 0);
		if (min_index == 0)
			simple_sort_5(num, argc);
		else if (min_index == 1)
		{
			if (argc > 1 && (num[0] < num[2]))
				swap_a(num);
			else
				rotate_a(num, argc, 0);
		}
		else if (min_index == 2)
		{
			if (num[0] > num[1])
				swap_a(num);
			else
				rotate_a(num, argc, 0);
		}
	}
}
