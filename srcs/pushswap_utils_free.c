/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:53:46 by hsim              #+#    #+#             */
/*   Updated: 2025/01/04 21:54:18 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* frees char pointer */
void	free_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	free_all(t_vars *vars)
{
	int	i;

	i = 0;
	if (!vars)
		return (-1);
	free(vars->num);
	free(vars->sorted_num);
	if (vars->b_split == 1)
	{
		free_ptr(vars->argv);
		vars->b_split = 0;
	}
	return (0);
}
