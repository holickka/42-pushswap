/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_search.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:46:34 by hsim              #+#    #+#             */
/*   Updated: 2025/01/04 22:14:09 by hsim             ###   ########.fr       */
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

int	initialize_data_container(t_vars *vars, int argc)
{
	vars->num = (int *)malloc(sizeof(int) * (argc - 1));
	vars->sorted_num = (int *)malloc(sizeof(int) * (argc - 1));

	if (!vars->num || !vars->sorted_num)
	{
		free(vars->num);
		free(vars->sorted_num);
		return (ft_perror_fd("Error! malloc failed in initialization", 2, 0));
	}
	return (1);
}
