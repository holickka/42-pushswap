/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:32:30 by hsim              #+#    #+#             */
/*   Updated: 2025/01/09 14:30:59 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * argc = initial argc - 2
 * argc need to minus counts of push_b in order to rotate only the remainders
 * if there are no push_b involved, count_pb can be 0
 */
void	rotate_a(int *num, int argc, int count_pb)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = num[0];
	shift_array(&num[0], &num[1], argc - count_pb);
	num[argc - count_pb] = tmp;
	ft_printf("ra\n");
}

/*
 * argc = initial argc - 2
 * argc need to minus counts of push_b in order to rotate only the remainders
 * if there are no push_b involved, count_pb can be 0
 */
void	rev_rotate_a(int *num, int argc, int count_pb)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = num[argc - count_pb];
	shift_array(&num[1], &num[0], argc - count_pb);
	num[0] = tmp;
	ft_printf("rra\n");
}

/*
 * argc = initial argc - 2
 * *tmp has to be created & malloc before entering the function
 * 
 * count_pb is for getting the amount of numbers that is in pb_array,
 * to shift the pb_array down accurately, add new numbers
 * & copy over the correct amount of numbers
 */
void	push_b(int *num, int *tmp, int argc, int count_pb)
{
	shift_array(&tmp[1], &tmp[0], count_pb);
	tmp[0] = num[0];
	shift_array(&num[0], &num[1], argc - count_pb + 1);
	num[argc - count_pb + 1] = -1;
	ft_printf("pb\n");
}

/*
 * pushes array from *tmp to *num
 * *count = count[PB];
 */
void	push_a(int *num, int *tmp, int argc, int count_pb)
{
	shift_array(&num[1], &num[0], argc - count_pb + 1);
	num[0] = tmp[0];
	shift_array(&tmp[0], &tmp[1], count_pb);
	tmp[count_pb] = -1;
	ft_printf("pa\n");
}

void	swap_a(int *num)
{
	int	tmp;

	tmp = num[0];
	num[0] = num[1];
	num[1] = tmp;
	ft_printf("sa\n");
}
