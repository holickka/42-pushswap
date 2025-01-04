#include "push_swap.h"
#include <stdio.h>

int	main()
{
	// /*--------------------merge_sort_test---------------------*/
	// int	arr[] = {10, 3, 5, 9, 7, 99};
	// int	len = (sizeof(arr)/sizeof(int));
	// printf("len=%d\n", len);
	// merge_sort(arr, len);

	// int	x = 0;
	// printf("------consolidate-----\n");
	// while (x < len)
	// 	printf("%d ", arr[x++]);
	/*--------------------ft_split_test---------------------*/
	char **str = ft_split("12", 'a');
	int i = 0;
	while (str[i])
		i++;
	printf("%d\n", i);
	// printf("%s\n", str[i++]);
}