/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 07:40:45 by hsim              #+#    #+#             */
/*   Updated: 2025/01/04 18:06:53 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char **argv, int argc, t_vars *vars)
{
	int	i;
	while (argc > 1)
	{
		i = 1;
		while (argv[i + 1])
		{
			if (!ft_strncmp(argv[1], argv[i + 1], 11))
			{
				if (vars->b_split == 1)
					free_ptr(vars->argv);
				return(ft_perror_fd("Error\n", 2, 0));
			}
			i++;
		}
		argv++;
		argc--;
	}
	return (1);
}

/* 
 * Child function in check_str
 * Checks if input exceeds max or min int 
 * better to use int here
 */
int	check_num_limit(char *argv)
{
	int		len;
	long	tmp;

	len = ft_strlen(argv);
	if (argv[0] == '-')
	{
		if (len == 11)
		{
			tmp = ft_atol(argv);
			if (tmp < -2147483648)
				return (0);
		}
		else if (len > 11)
			return (0);
	}
	else if (argv[0] != '-')
	{
		if (len == 10)
		{
			tmp = ft_atol(argv);
			if (tmp > 2147483647)
				return (0);
		}
		else if (len > 10)
			return (0);
	}
	return (1);
}

/*
 * checks if char is 0-9, and checks if number exceeds max & min int
 */
int	check_str(char *argv)
{
	int	x;

	x = 0;
	if (!check_num_limit(argv))
		return (ft_perror_fd("Error\n", 2, 0));
	if (argv[x] == '\f' || argv[x] == '	')
		return (ft_perror_fd("Error\n", 2, 0));
	if ((argv[x] == '+' && argv[x + 1] == '+') \
		|| (argv[x] == '-' && argv[x + 1] == '-'))
		return (ft_perror_fd("Error\n", 2, 0));
	if (argv[x] == '+' || argv[x] == '-')
		x++;
	if (!argv[x])
		return (ft_perror_fd("Error\n", 2, 0));
	while (argv[x])
	{
		if (!ft_strchr("0123456789", argv[x++]))
			return (ft_perror_fd("Error\n", 2, 0));
	}
	return (1);
}

/*not needed*/
// int	count_bit(int num)
// {
// 	int	count;

// 	count = 0;
// 	while (num > 9)
// 	{
// 		num /= 10;
// 		count++;
// 	}
// 	return (count);
// }

/*not needed*/
// void	convert_to_binary(t_vars *vars, char *argv, int *num)
// {
// 	int	x;

// 	*num = ft_basetoi("01", argv, 11);
// 	x = count_bit(*num);
// 	if (x > vars->bits)
// 		vars->bits = x;
// }

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

void	free_all(t_vars *vars)
{
	int	i;

	i = 0;
	if (!vars)
		return ;
	free(vars->num);
	free(vars->sorted_num);
	if (vars->b_split == 1)
	{
		free_ptr(vars->argv);
		vars->b_split = 0;
	}
}

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
	{
		// printf("count=%d %s\n", count, tmp[count]);
		count++;
	}
	// printf("countnow=%d\n", count);
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


int	main(int argc, char **argv) // 31 - 5 -4 
{
	int		i;
	t_vars	vars;

	// /*debug*/printf("argc_enter=%d\n", argc);
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (split_argv(argv, &vars))
		{
			argv = vars.argv;
			argc = vars.argc;
			// /*debug*/printf("argc_new=%d\n", argc);
		}
		else
		{
			check_str(argv[1]);
			return (0);
		}
	}
	// /*debug*/ printf("-----------\nargc=%d\n", argc);
	// /*-------debug------*/
	// int x = 0;
	// printf("enter=");
	// while (x < argc)
	// {
	// /*debug*/ printf("%d**%s ", x, argv[x]);
	// 	x++;
	// }
	// printf("\n");
	// /*-------debug end------*/
	/*checknum*/
	if (!check_duplicates(argv, argc, &vars))
		return (0);
	if (!initialize_data_container(&vars, argc))
		return (0);
	// // // /*copy num*/
	i = 1;
	while (argv[i] != NULL) //separate
	{
		if (!check_str(argv[i]))
		{
			free_all(&vars);
			return (0);
		}
		vars.num[i - 1] = ft_atol(argv[i]);
		vars.sorted_num[i - 1] = vars.num[i - 1];
		i++;
	}
	if (if_sorted(vars.num, argc - 2)) //separate
	{
		free_all(&vars);
		return (0);
	}
	merge_sort(vars.sorted_num, (argc - 1));

	// /*------------debug------------*/
	// int x = 0;
	// printf("array=");
	// while (x < argc - 1)
	// 	/*debug*/ printf("%d ", vars.num[x++]);
	// printf("\n");
	// x = 0;
	// printf("sorted=");
	// while (x < argc - 1)
	// 	/*debug*/ printf("%d ", vars.sorted_num[x++]);
	// printf("\n");
	// /*------------debug end------------*/

	find_n_replace(vars.sorted_num, vars.num, argc - 1);

	// /*------------debug------------*/
	// x = 0;
	// printf("new_index=");
	// while (x < argc - 1)
	// 	/*debug*/ printf("%d ", vars.num[x++]);
	// printf("\n");
	// /*----------debug end-----------*/

	if (argc - 1 > 5)
		radix_sort(vars.num, (argc - 2));
	if (argc - 1 <= 3)
		simple_sort_3(vars.num, (argc - 2));
	else
		simple_sort_5(vars.num, (argc - 2));

	// /*------------debug------------*/
	// x = 0;
	// printf("\nradix_sort=");
	// while (x < argc - 1)
	// 	/*debug*/ printf("%d ", vars.num[x++]);
	// printf("\n");
	// /*----------debug end-----------*/
	// // /*remember to free initialized malloc pointers*/
	free_all(&vars);
	fflush(stderr);
	return (0);
}
