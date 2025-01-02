#include "push_swap.h"

int	main()
{
	int	arr[] = {10, 3, 5, 9, 7, 99};
	int	len = (sizeof(arr)/sizeof(int));
	printf("len=%d\n", len);
	merge_sort(arr, len);

	int	x = 0;
	printf("------consolidate-----\n");
	while (x < len)
		printf("%d ", arr[x++]);
}