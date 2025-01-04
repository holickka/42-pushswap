/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_simplesort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:09:29 by hsim              #+#    #+#             */
/*   Updated: 2025/01/04 17:23:16 by hsim             ###   ########.fr       */
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
	return (1);
	// return (ft_perror("sorted!", 1));
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
// void	simple_sort_1(int *num, int argc)
// {
// 	int	i;

// 	// /*-------debug------*/
// 	// int x = 0;
// 	// printf("enter=");
// 	// while (x <= argc)
// 	// /*debug*/ printf("%d ", num[x++]);
// 	// printf("\n");
// 	// /*-------debug end------*/

// 	/*checks if sorted, some while loop here*/
// 	while (!if_sorted(num, argc))
// 	{
// 		i = 0;
// 		while (i < argc)
// 		{
// 			if (i + 1 < argc)
// 			{
// 				if ((num[0 + i] < num[1 + i]) && (num[0 + i] < num[2 + i]))
// 					i++;
// 				else if ((num[0 + i] > num[1 + i]) && (num[0 + i] > num[2 + i]))
// 					rotate_a(&num[i], argc, i);
// 				else
// 					swap_a(&num[i], argc);
// 			}
// 			else
// 			{
// 				if ((num[0 + i] < num[1 + i]))
// 					i++;
// 				else
// 					swap_a(&num[i], argc);
// 			}
// 		}
// 	}
// }

/*
 * Child function to simple_sort, only sorts the last two numbers
 * in the array
 */
// static void	sort_last_two()
// {

// }

/*
 * Child function to simple_sort, sorts the entire array
 * except (up to) the last two numbers
 * *num = &num[0 + i] when enter
 */
// static void	sort_entire_array(int *num, int *tmp_arr, int argc, int count_pb, int i)
// {
// 	if ((num[0 + i] < num[1 + i]) && (num[0 + i] < num[2 + i]))
// 	{
// 		count_pb++;
// 		push_b(num, tmp_arr, argc, count_pb);
// 	}
// 	else if ((num[0 + i] > num[1 + i]) && (num[0 + i] > num[2 + i]))
// 		rotate_a(&num[i], argc, i);
// 	else
// 		swap_a(&num[i], argc);
// }

/*
 * sort_small(3), max 3 moves
 * if num[0] < num[1] && num[2], pb
 * if num[0] > num[1] && num[2], ra
 * else, sa
 */
/*
 * when argc <= 5, use simple sort
 * argc has to be (argc - 2) here during enter
 */
// void	simple_sort_2(int *num, int argc)
// {
// 	int	i;
// 	int	*tmp_arr;
// 	int	count_pb;

// 	count_pb = 0;
// 	tmp_arr = (int *)malloc(sizeof(int) * (argc + 1));

// 	// /*-------debug------*/
// 	// int x = 0;
// 	// printf("enter=");
// 	// while (x <= argc)
// 	// /*debug*/ printf("%d ", num[x++]);
// 	// printf("\n");
// 	// /*-------debug end------*/

// 	/*checks if sorted, some while loop here*/
// 	while (!if_sorted(num, argc))
// 	{
// 		i = argc;
// 		while (i > 0)
// 		{
// 			if (i >= 2)
// 			{
// 				if ((num[0] < num[1]) && (num[0] < num[2]))
// 				{
// 					count_pb++;
// 					push_b(num, tmp_arr, argc, count_pb);
// 					i--;
// 				}
// 				else if ((num[0] > num[1]) && (num[0] > num[2]))
// 					rotate_a(num, argc, count_pb);
// 				else
// 					swap_a(num, argc);
// 			}
// 			else
// 			{
// 				if ((num[0] < num[1]))
// 				{
// 					count_pb++;
// 					push_b(num, tmp_arr, argc, count_pb);
// 					i--;
// 				}
// 				else
// 					swap_a(num, argc);
// 			}
// 		}
// 		/*ending push_a*/
// 		while (count_pb)
// 		{
// 			push_a(num, tmp_arr, argc, count_pb);
// 			count_pb--;
// 		}
// 	}
// }

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
		{
			// /*debug*/printf("min_location=%d\n", i);
			return (i);
		}
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

	// mid = (argc / 2);
	// min = locate_min(num, argc, 0);

	tmp_arr = (int *)malloc(sizeof(int) * (argc + 1));
	/*debug*/init_tmp_array(tmp_arr, argc + 1);
	count_pb = 0;
	// int x = 0;
	while (!if_sorted(num, argc - count_pb))
	{
		mid = ((argc - count_pb) / 2);
		min = locate_min(num, argc - count_pb, count_pb);
		// /*debug*/printf("\n\nmin=%d, mid=%d\n", min, mid);
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
	{
	// /*debug*/printf("ss5 count_pb=%d\n", count_pb);
		push_a(num, tmp_arr, argc, count_pb--);
	// /*debug*/printf("ss5 count_pb exit=%d\n", count_pb);
	}
	free(tmp_arr);
}

/*
 * Child function of simple_sort_3
 * Does the sorting actions, follows process of simple_sort_5
 * if 0 is at the top
 */
static void	execute_sort_3(int *num, int argc)
{
	int	min_index;

	min_index = locate_min(num, argc, 0);
	if (min_index == 0)
		simple_sort_5(num, argc);
	else if (min_index == 1)
	{
		if (argc > 1 && (num[0] < num[2]))
			swap_a(num, argc);
		else
			rotate_a(num, argc, 0);
	}
	else if (min_index == 2)
	{
		if (num[0] > num[1])
			swap_a(num, argc);
		else
			rotate_a(num, argc, 0);
	}
}

/*
 * Edition 3
 * used when argc <= 3
 * argc has to be (argc - 2) here during enter
 * uses malloc
 */
void	simple_sort_3(int *num, int argc)
{
	// int	*tmp_arr;

	// tmp_arr = (int *)malloc(sizeof(int) * (argc + 1));
	// /*-------debug------*/
	// int x = 0;
	// printf("enter=");
	// while (x <= argc)
	// /*debug*/ printf("%d ", num[x++]);
	// printf("\n");
	// /*-------debug end------*/
	while (!if_sorted(num, argc))
	{
		execute_sort_3(num, argc);
		// /*-------debug------*/
		// x = 0;
		// printf("simple_3=");
		// while (x <= argc)
		// /*debug*/ printf("%d ", num[x++]);
		// printf("\n");
		// /*-------debug end------*/
	}

}
