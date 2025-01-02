/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_search.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:46:34 by hsim              #+#    #+#             */
/*   Updated: 2025/01/01 21:03:57 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Replaces the original number array with its new corresponding 
 * position index after merge_sort applied
 * size = argc
 * *res = the returned result
 * *search = original num array
 */
void	find_n_replace(int *search, int *res, int size)
{
	int	j;
	int	k;

	j = 0;
	while (j < size)
	{
		k = 0;
		while (k < size)
		{
			if (res[j] == search[k])
			{
				res[j] = k;
				break ;
			}
			k++;
		}
		j++;
	}
}
