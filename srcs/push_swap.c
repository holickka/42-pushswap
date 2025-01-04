/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:40:45 by hsim              #+#    #+#             */
/*   Updated: 2025/01/04 22:16:11 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * restructure array so that it follows the sequence of general argv,
 * which argv[0] is the program name and is not used in function
 * argc need to +1 here for null
 * uses malloc here
 */
void	restructure_array(t_vars *vars, char **tmp)
{
	int		x;
	int		len;
	int		str_count;

	x = 0;
	str_count = vars->argc;
	vars->argv = (char **)malloc(sizeof(char *) * (str_count + 1));
	vars->argv[0] = ft_strdup("0");
	vars->argv[str_count] = NULL;
	while (x < str_count - 1)
	{
		len = ft_strlen(tmp[x]);
		vars->argv[x + 1] = (char *)malloc(sizeof(char) * (len + 1));
		ft_strlcpy(vars->argv[x + 1], tmp[x], len + 1);
		x++;
	}
}

/*
 * Applies split when argc <= 2
 * if split result <= 1 string, return (0)
 * else return (1)
 * uses malloc
 */
int	split_argv(char **argv, t_vars *vars)
{
	int		count;
	char	**tmp;

	// /*-------debug------*/
	// int x = 0;
	// printf("enter=");
	// while (x < argc)
	// {
	// /*debug*/ printf("%d:%s ", x, argv[x]);
	// 	x++;
	// }
	// printf("\n");
	// /*-------debug end------*/

	count = 0;
	tmp = ft_split(argv[1], ' ');
	while (tmp[count])
		count++;
	if (count <= 1)
	{
		free_ptr(tmp);
		return (0);
	}
	vars->b_split = 1;
	vars->argc = count + 1;
	restructure_array(vars, tmp);
	free_ptr(tmp);
	return (1);
}

int	process_numbers(t_vars *vars, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!check_str(argv[i]))
		{
			free_all(vars);
			return (0);
		}
		vars->num[i - 1] = ft_atol(argv[i]);
		vars->sorted_num[i - 1] = vars->num[i - 1];
		i++;
	}
	return (1);
}

int	start_pushswap(t_vars *vars, char **argv, int argc)
{
	if (!check_duplicates(argv, argc, vars))
		return (0);
	if (!initialize_data_container(vars, argc))
		return (0);
	if (!process_numbers(vars, argv))
		return (0);
	if (if_sorted(vars->num, argc - 2))
		return (free_all(vars));
	merge_sort(vars->sorted_num, (argc - 1));

	// // /*------------debug------------*/
	// // int x = 0;
	// // printf("array=");
	// // while (x < argc - 1)
	// // 	/*debug*/ printf("%d ", vars.num[x++]);
	// // printf("\n");
	// // x = 0;
	// // printf("sorted=");
	// // while (x < argc - 1)
	// // 	/*debug*/ printf("%d ", vars.sorted_num[x++]);
	// // printf("\n");
	// // /*------------debug end------------*/

	find_n_replace(vars->sorted_num, vars->num, argc - 1);

	// // /*------------debug------------*/
	// // x = 0;
	// // printf("new_index=");
	// // while (x < argc - 1)
	// // 	/*debug*/ printf("%d ", vars.num[x++]);
	// // printf("\n");
	// // /*----------debug end-----------*/

	if (argc - 1 > 5)
		radix_sort(vars->num, (argc - 2));
	if (argc - 1 <= 3)
		simple_sort_3(vars->num, (argc - 2));
	else
		simple_sort_5(vars->num, (argc - 2));
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (split_argv(argv, &vars))
		{
			argv = vars.argv;
			argc = vars.argc;
		}
		else
		{
			check_str(argv[1]);
			return (0);
		}
	}
	if (!start_pushswap(&vars, argv, argc))
		return (0);
	return (free_all(&vars));
}
