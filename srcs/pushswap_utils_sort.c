/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 21:36:01 by hsim              #+#    #+#             */
/*   Updated: 2025/01/02 12:25:03 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_array(int *dest, int *src, int n)
{
	while (--n >= 0)
		dest[n] = src[n];
}

void	free_ptr(int *ptr[2], int n)
{
	while (n > 0)
		free(ptr[--n]);
}

/* 21 lines ok! */
/*
 * Child function in merge_sort
 * *arr[2] = double pointer to left & right array
 * *array = the original full length array
 */
static void	merge_final(int *arr[2], int *array, int argc)
{
	int	i;
	int	l;
	int	r;
	int	len[2];

	i = 0;
	l = 0;
	r = 0;
	len[L] = (argc / 2);
	len[R] = (argc - len[L]);
	// /*debug*/ printf("len_LR=%d %d, argc=%d\n", len[L], len[R], argc);

	while (l < len[L] && r < len[R] && i < argc)
	{
		if (arr[L][l] < arr[R][r])
			array[i] = arr[L][l++];
		else if (arr[R][r] < arr[L][l])
			array[i] = arr[R][r++];
		i++;
		// /*debug*/ printf("array=%d\n", array[i++]);
	}
	while (l < len[L])
		array[i++] = arr[L][l++];
	while (r < len[R])
		array[i++] = arr[R][r++];

	i = 0;
	// /*debug*/
	// printf("-----final_array-----\n");
	// while (i < argc)
	// 	printf("%d ", array[i++]);
	// printf("\n");
	// /*debug end*/
}

/* 14 lines ok! */
/*
 * argc indicates the length of array
 * argc has to be argc -1 in here
 * returns result in int *array
 */
void	merge_sort(int *array, int argc)
{
	int	*arr[2];
	int	mid;

	if (argc <= 1)
		return ;
	mid = (argc / 2);
	arr[L] = (int *)malloc(sizeof(int) * mid);
	arr[R] = (int *)malloc(sizeof(int) * (argc - mid));
	// /*debug*/ printf("mid=%d, len=%d\n", mid, argc);
	copy_array(arr[L], array, mid);
	copy_array(arr[R], &array[mid], (argc - mid));

	// /*debug*/
	// int x = 0;
	// while (x < mid)
	// 	printf("arr_left=%d\n", arr[L][x++]);
	// x = 0;
	// while (x < (argc - mid))
	// 	printf("arr_right=%d\n", arr[R][x++]);
	// printf("\n");
	// /*debug end*/
	/*call function again*/
	merge_sort(arr[L], mid);
	merge_sort(arr[R], argc - mid);
	/*merge_final*/
	merge_final(arr, array, argc);
	// /*debug*/printf("end\n\n");
	free_ptr(arr, 2);
}
