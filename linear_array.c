#include "public.h"
#include "linear_array.h"
void print_linear_array_int(int*arry, int len)
{
	int i = 0;
	for(i = 0; i < len; ++i)
	{
		printf("%d	",arry[i]);
	}
	printf("\n----------------------------\n");
}

int last_num_remain_in_cricle(int* array, int len, int m)
{
	int bit[100] = {0};
	int bit_0 = 0, bit_1_num = 0, cur = -1, last = 0;

	if(NULL == array || 0 == len || 0 == m)
	{
		return -1;
	}
	while(bit_1_num < len)
	{
		bit_0 = 0;
		while(bit_0 < m)
		{
			++cur;
			if(0 == bit[(cur)%len])
			{
				++bit_0;
			}
		}
		last = array[cur%len];
		printf("delete:%d\n", array[cur%len]);
		bit[cur%len] = 1;
		++bit_1_num;
	}
	printf("The Last num remaining in the cricle is: %d\n\n", last);
	return last;
}