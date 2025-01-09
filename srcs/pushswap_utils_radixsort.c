/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_radixsort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:04:08 by hsim              #+#    #+#             */
/*   Updated: 2025/01/09 15:45:59 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*shift_array(int *dest, int *src, int len)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (src < dest)
	{
		while (len > 0)
		{
			len--;
			dest[len] = src[len];
		}
	}
	else
	{
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}

/* initializes all tmp_array values to -1 for debug ease */
void	init_tmp_array(int *tmp_arr, int argc)
{
	int	x;

	x = 0;
	while (x < argc)
		tmp_arr[x++] = -1;
}

static void	init_radix_variables(int *i, int *count_pb)
{
	*i = 0;
	*count_pb = 0;
}

static void	execute_radix_sort(int *num, int *tmp_arr, int argc, \
								int max_bit_size)
{
	int	x;
	int	i;
	int	count_pb;

	x = 0;
	while (x < max_bit_size)
	{
		init_radix_variables(&i, &count_pb);
		while (i <= argc)
		{
			if (((num[0] >> x) & 1) == 0)
				push_b(num, tmp_arr, argc, ++count_pb);
			else
				rotate_a(num, argc, count_pb);
			i++;
		}
		while (count_pb > 0)
			push_a(num, tmp_arr, argc, count_pb--);
		x++;
	}
}

/*
 * Converts number into binary, apply bitwise operation/comparison,
 * prints out push_swap command
 * argc has to be (argc - 2) here during enter
 * or can name it push_swap too
 */
void	radix_sort(int *num, int argc)
{
	int	max_bit_size;
	int	*tmp_arr;

	tmp_arr = (int *)malloc(sizeof(int) * (argc + 1));
	init_tmp_array(tmp_arr, argc + 1);
	max_bit_size = 0;
	while ((argc >> max_bit_size) != 0)
		max_bit_size++;
	execute_radix_sort(num, tmp_arr, argc, max_bit_size);
	free(tmp_arr);
}
