/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_mergesort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 21:36:01 by hsim              #+#    #+#             */
/*   Updated: 2025/01/09 15:45:47 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_array(int *dest, int *src, int n)
{
	while (--n >= 0)
		dest[n] = src[n];
}

static void	free_mergesort_ptr(int *ptr[2], int n)
{
	while (n > 0)
		free(ptr[--n]);
}

/* 22 lines ok! */
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
	while (l < len[L] && r < len[R] && i < argc)
	{
		if (arr[L][l] < arr[R][r])
			array[i] = arr[L][l++];
		else if (arr[R][r] < arr[L][l])
			array[i] = arr[R][r++];
		i++;
	}
	while (l < len[L])
		array[i++] = arr[L][l++];
	while (r < len[R])
		array[i++] = arr[R][r++];
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
	copy_array(arr[L], array, mid);
	copy_array(arr[R], &array[mid], (argc - mid));
	merge_sort(arr[L], mid);
	merge_sort(arr[R], argc - mid);
	merge_final(arr, array, argc);
	free_mergesort_ptr(arr, 2);
}
