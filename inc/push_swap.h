/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:44:12 by hsim              #+#    #+#             */
/*   Updated: 2025/01/02 07:41:04 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "libftprintf.h"

/*remove this during eval*/
# include <stdio.h>

enum e_sort
{
	L = 0,
	R = 1,
	RA = 0,
	PB = 1
};

typedef struct s_vars
{
	int	*num;
	int	*sorted_num;
	// int	*ori_pos;
	int	bits;
}	t_vars;

int		ft_convert_base(char *str, char *base_return);
void	merge_sort(int *array, int argc);
void	find_n_replace(int *search, int *res, int size);
void	radix_sort(int *num, int argc);



#endif