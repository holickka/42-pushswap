/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_radixsort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:04:08 by hsim              #+#    #+#             */
/*   Updated: 2025/01/02 11:25:08 by hsim             ###   ########.fr       */
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

/*
 * argc = initial argc - 2
 * argc need to minus counts of push_b
 */
static void	rotate_a(int *num, int argc, int count_pb)
{
	int	i;
	int	tmp;

	/*debug*/
	printf("\nbefore ra= ");
	int x = 0;
	while (x <= argc)
		printf("%d ", num[x++]);
	/*debug end*/

	i = 0;
	tmp = num[0];
	shift_array(&num[0], &num[1], argc - count_pb);
	num[argc - count_pb] = tmp;
	/*debug*/
	printf("num[argc] %d", num[argc]);
	printf("\nafter ra= ");
	x = 0;
	while (x <= argc)
		printf("%d ", num[x++]);
	printf("\n");
	/*debug end*/
}

/*
 * argc = initial argc - 2
 */
static void	push_b(int *num, int *tmp, int argc, int count_pb)
{
	/*debug*/
	printf("\nbefore pb= ");
	int x = 0;
	while (x <= argc)
		printf("%d ", num[x++]);
	/*debug end*/

	shift_array(&tmp[1], &tmp[0], count_pb); //append tmp
	tmp[0] = num[0]; // copy over
	shift_array(&num[0], &num[1], argc - count_pb + 1); //update array
	num[argc - count_pb + 1] = -1; //replace empty array with -1

	/*debug*/
	printf("num[argc] %d", num[argc]);
	printf("\nafter pb= ");
	x = 0;
	while (x <= argc)
		printf("%d ", num[x++]);
	x = 0;
	printf("\npb_arr= ");
	while (x <= argc)
		printf("%d ", tmp[x++]);
	printf("\n");
	/*debug end*/
}

/* pushes array from *tmp to *num */
void	push_a(int *num, int *tmp, int argc, int *count)
{
	/*debug*/
	printf("\nbefore pa= ");
	int x = 0;
	while (x <= argc)
		printf("%d ", num[x++]);
	printf("\ncount_ra %d | pb %d | argc %d", count[RA], count[PB], argc);
	/*debug end*/

	shift_array(&num[1], &num[0], argc - count[PB] + 1); //shirt num array down, might be RA
	num[0] = tmp[0];
	shift_array(&tmp[0], &tmp[1], count[PB]); //shift tmp array up
	tmp[count[PB]] = -1; //replace empty array with -1
	// count[PB] -= 1;

	/*debug*/
	printf("\nafter pa= ");
	x = 0;
	while (x <= argc)
		printf("%d ", num[x++]);
	x = 0;
	printf("\npb_arr= ");
	while (x <= argc)
		printf("%d ", tmp[x++]);
	printf("\n");
	/*debug end*/
}


static void	init_tmp_array(int *tmp_arr, int argc)
{
	int	x;

	x = 0;
	while (x < argc)
		tmp_arr[x++] = -1;
}

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
				ft_printf("%d pb, num[i] %d, x %d, %d %d\n", i, num[0], x, (num[0] >> x), ((num[0] >> x) & 1));
			}
			else
			{
				// ft_printf("ra\n");
				count[RA]++;
				ft_printf("before %d\n", num[0]);
				rotate_a(num, argc, count[PB]);
				ft_printf("%d ra %d, num[i] %d, x %d, %d %d\n", i, count[RA], num[0], x, (num[0] >> x), ((num[0] >> x) & 1));
			}
			i++;
		}
		/*debug*/ft_printf("\n");
		while (count[PB] > 0)
		{
			push_a(num, tmp_arr, argc, count);
			ft_printf("%d pa, num[i] %d, x %d, %d %d\n", i, num[i], x, (num[i] >> x), ((num[i] >> x) & 1));
			// ft_printf("pa\n");
			i++;
			count[PB]--;
		}
		/*debug*/ft_printf("---\n\n");
		printf("---\n\n");
		x++;
	}
	/*remember to free tmp_arr pointer*/
}
