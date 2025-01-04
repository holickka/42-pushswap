/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_radixsort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:04:08 by hsim              #+#    #+#             */
/*   Updated: 2025/01/04 16:47:21 by hsim             ###   ########.fr       */
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

// void	execute_sort(int max_bit_size, int *count, int argc)
// {

// }

/*
 * Converts number into binary, apply bitwise operation/comparison,
 * prints out push_swap command
 * argc has to be (argc - 2) here during enter
 * or can name it push_swap too
 */
void	radix_sort(int *num, int argc)
{
	int	i;
	int	x;
	int	count[2];
	int	max_bit_size;
	int	*tmp_arr;

	tmp_arr = (int *)malloc(sizeof(int) * (argc + 1));
	init_tmp_array(tmp_arr, argc + 1);

	x = 0;
	max_bit_size = 0;
	while ((argc >> max_bit_size) != 0)
		max_bit_size++;
	while (x < max_bit_size)
	{
		i = 0;
		count[RA] = 0;
		count[PB] = 0;
		while (i <= argc)
		{
			if (((num[0] >> x) & 1) == 0)
			{
				// ft_printf("pb\n");
				count[PB]++;
				push_b(num, tmp_arr, argc, count[PB]);
				// ft_printf("%d pb, num[i] %d, x %d, %d %d\n", i, num[0], x, (num[0] >> x), ((num[0] >> x) & 1));
			}
			else
			{
				// ft_printf("ra\n");
				// count[RA]++;
				// ft_printf("before %d\n", num[0]);
				rotate_a(num, argc, count[PB]);
			}
			i++;
		}
		// /*debug*/ft_printf("\n");
		while (count[PB] > 0)
		{
			push_a(num, tmp_arr, argc, count[PB]);
			// ft_printf("%d pa, num[i] %d, x %d, %d %d\n", i, num[i], x, (num[i] >> x), ((num[i] >> x) & 1));
			// ft_printf("pa\n");
			count[PB]--;
		}
		// /*debug*/ft_printf("---\n\n");
		// printf("---\n\n");
		x++;
	}
	/*remember to free tmp_arr pointer*/
	free(tmp_arr);
}
