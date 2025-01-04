/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:32:30 by hsim              #+#    #+#             */
/*   Updated: 2025/01/03 13:35:48 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * argc = initial argc - 2
 * argc need to minus counts of push_b
 * if there are no push_b involve, count_pb can be 0
 */
void	rotate_a(int *num, int argc, int count_pb)
{
	int	i;
	int	tmp;

	// /*-------debug-------*/
	// int x = 0;
	// printf("before ra=");
	// while (x <= argc)
	// 	printf("%d ", num[x++]);
	// /*-------debug end-------*/

	i = 0;
	tmp = num[0];
	shift_array(&num[0], &num[1], argc - count_pb);
	num[argc - count_pb] = tmp;
	ft_printf("ra\n");

	// /*-------debug-------*/
	// printf("\nafter ra= ");
	// x = 0;
	// while (x <= argc)
	// 	printf("%d ", num[x++]);
	// printf("\n");
	// /*-------debug end-------*/
}

/*
 * argc = initial argc - 2
 */
void	push_b(int *num, int *tmp, int argc, int count_pb)
{
	// /*debug*/
	// printf("\nbefore pb= ");
	// int x = 0;
	// while (x <= argc)
	// 	printf("%d ", num[x++]);
	// /*debug end*/

	shift_array(&tmp[1], &tmp[0], count_pb); //append tmp
	tmp[0] = num[0]; // copy over
	shift_array(&num[0], &num[1], argc - count_pb + 1); //update array
	num[argc - count_pb + 1] = -1; //replace empty array with -1
	ft_printf("pb\n");

	// /*debug*/
	// printf("num[argc] %d", num[argc]);
	// printf("\nafter pb= ");
	// x = 0;
	// while (x <= argc)
	// 	printf("%d ", num[x++]);
	// x = 0;
	// printf("\npb_arr= ");
	// while (x <= argc)
	// 	printf("%d ", tmp[x++]);
	// printf("\n");
	// /*debug end*/
}

/* pushes array from *tmp to *num */
void	push_a(int *num, int *tmp, int argc, int *count)
{
	// /*debug*/
	// printf("\nbefore pa= ");
	// int x = 0;
	// while (x <= argc)
	// 	printf("%d ", num[x++]);
	// printf("\ncount_ra %d | pb %d | argc %d", count[RA], count[PB], argc);
	// /*debug end*/

	shift_array(&num[1], &num[0], argc - count[PB] + 1); //shirt num array down, might be RA
	num[0] = tmp[0];
	shift_array(&tmp[0], &tmp[1], count[PB]); //shift tmp array up
	tmp[count[PB]] = -1; //replace empty array with -1
	ft_printf("pa\n");

	// count[PB] -= 1;

	// /*debug*/
	// printf("\nafter pa= ");
	// x = 0;
	// while (x <= argc)
	// 	printf("%d ", num[x++]);
	// x = 0;
	// printf("\npb_arr= ");
	// while (x <= argc)
	// 	printf("%d ", tmp[x++]);
	// printf("\n");
	// /*debug end*/
}

void	swap_a(int *num, int argc)
{
    (void)  argc;
	int	tmp;

	// /*-------debug------*/
	// int x = 0;
	// printf("before sa=");
	// while (x <= argc)
	// /*debug*/ printf("%d ", num[x++]);
	// printf("\n");
	// /*-------debug end------*/

	tmp = num[0];
	num[0] = num[1];
	num[1] = tmp;
	ft_printf("sa\n");

	// /*-------debug------*/
	// x = 0;
	// printf("sa=");
	// while (x <= argc)
	// /*debug*/ printf("%d ", num[x++]);
	// printf("\n");
	// /*-------debug end------*/
}