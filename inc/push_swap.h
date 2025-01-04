/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:44:12 by hsim              #+#    #+#             */
/*   Updated: 2025/01/04 16:47:18 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "libftprintf.h"
# include <stdbool.h>

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
	int		*num;
	int		*sorted_num;
	char	**argv;
	int		argc;
	bool	b_split;
}	t_vars;

int		ft_convert_base(char *str, char *base_return);
void	merge_sort(int *array, int argc);
void	radix_sort(int *num, int argc);
void	simple_sort_3(int *num, int argc);
void	simple_sort_5(int *num, int argc);

void	swap_a(int *num, int argc);
void	push_a(int *num, int *tmp, int argc, int count_pb);
void	push_b(int *num, int *tmp, int argc, int count_pb);
void	rotate_a(int *num, int argc, int count_pb);
void	rev_rotate_a(int *num, int argc, int count_pb);

int		if_sorted(int *num, int argc);
void	*shift_array(int *dest, int *src, int len);
void	find_n_replace(int *search, int *res, int size);
void	init_tmp_array(int *tmp_arr, int argc);

void	free_ptr(char **ptr);

#endif