/* Program: 	mem_layout
 * Description:	This is small program to analyse the result of homework problem 6-37
 * 				of csapp 3e
 * Author:		Dhruv Mohindru
 * Email:		dmohindru@gmail.com
 * Date:		24/10/2018
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define CACHE_SIZE 256

int cache[CACHE_SIZE];

void clear_cache()
{
	int i;
	for (i = 0; i < CACHE_SIZE; i++)
		cache[i] = -1;
}

void access_pattern(int n, long base_address)
{
	int i, j, col_width=4, num_access, num_miss, cache_set, cache_tag;
	int a[n][n];
	//long base_address = 0x08000000;
	long address;
	printf("===========================================\n");
	printf("Cache set access pattern for N=%d\n", n);
	printf("===========================================\n");
	printf("\n+++++++Acess pattern for sumA+++++++\n");
	clear_cache();
	num_access = 0;
	num_miss = 0;
	for (i = 0; i < n; i++)
	{
		printf("\n---------------i=%d-----------------------\n", i);
		for (j = 0; j < n; j++)
		{
			if ((j > 0) && (j % col_width == 0))
				printf("\n");
			address = (long)&a[i][j];
			printf("a[%d][%d]:[", i, j);
			address = base_address + address - (long)a;
			cache_set = (address>>4)&0xFF;
			cache_tag = (unsigned)address>>12;
			printf("%d", cache_set);
			printf("-0x%x] ", cache_tag);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
		}
		
	}
	printf("\n================ Miss rate for sumA: %0.2f %% ================\n", (float)num_miss/num_access*100);
	
	printf("\n\n+++++++Acess pattern for sumB+++++++\n");
	clear_cache();
	num_access = 0;
	num_miss = 0;
	for (j = 0; j < n; j++)
	{
		printf("\n---------------j=%d-----------------------\n", j);
		for (i = 0; i < n; i++)
		{
			if ((i > 0) && (i % col_width == 0))
				printf("\n");
			address = (long)&a[i][j];
			printf("a[%d][%d]:[", i, j);
			address = base_address + address - (long)a;
			cache_set = (address>>4)&0xFF;
			cache_tag = (unsigned)address>>12;
			printf("%d", cache_set);
			printf("-0x%x] ", cache_tag);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
		}
		
	}
	printf("\n================ Miss rate for sumB: %0.2f %% ================\n", (float)num_miss/num_access*100);
	
	printf("\n\n+++++++Acess pattern for sumC+++++++\n");
	clear_cache();
	num_access = 0;
	num_miss = 0;
	for (j = 0; j < n; j+=2)
	{
		printf("\n---------------j=%d-----------------------\n", j);
		for (i = 0; i < n; i+=2)
		{
			if ((i > 0) && (i % col_width == 0))
				printf("\n");
			address = (long)&a[i][j];
			printf("a[%d][%d]:[", i, j);
			address = base_address + address - (long)a;
			cache_set = (address>>4)&0xFF;
			cache_tag = (unsigned)address>>12;
			printf("%d", cache_set);
			printf("-0x%x] ", cache_tag);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			
			address = (long)&a[i+1][j];
			printf("a[%d][%d]:[", i+1, j);
			address = base_address + address - (long)a;
			cache_set = (address>>4)&0xFF;
			cache_tag = (unsigned)address>>12;
			printf("%d", cache_set);
			printf("-0x%x] ", cache_tag);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			
			address = (long)&a[i][j+1];
			printf("a[%d][%d]:[", i, j+1);
			address = base_address + address - (long)a;
			cache_set = (address>>4)&0xFF;
			cache_tag = (unsigned)address>>12;
			printf("%d", cache_set);
			printf("-0x%x] ", cache_tag);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			
			address = (long)&a[i+1][j+1];
			printf("a[%d][%d]:[", i+1, j+1);
			address = base_address + address - (long)a;
			cache_set = (address>>4)&0xFF;
			cache_tag = (unsigned)address>>12;
			printf("%d", cache_set);
			printf("-0x%x] ", cache_tag);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			
			printf("\n");
			
		}
	}
	printf("\n================ Miss rate for sumC: %0.2f %% ================\n", (float)num_miss/num_access*100);
}

void usage()
{
	printf("usage: cachesim [-n array_size] [-a base_address]\n");
	printf("\t -n array_size: size of a 2d array\n");
	printf("\t -a base_address: base address of 2d array\n");
	
}

int main(int argc, char *argv[])
{
	int n, address;
	n = 64;
	address = 0x08000000;
	int cmd_options;
	int return_val = 0;
	while ((cmd_options = getopt(argc, argv, "n:a:")) != -1)
	{
		switch(cmd_options)
		{
			case 'n':
				//mem_layout_flag = 1;
				n = atoi(optarg);
				break;
			case 'a':
				//cache_mapping_flag = 1;
				address = strtol(optarg, NULL, 16);
				break;
			default:
				return_val = 1;
		}
	}
	if (return_val == 1)
	{
		usage();
		return return_val;
	}
	printf("Size of array n=%d\n", n);
	printf("Base address = 0x%x\n", address);
	access_pattern(n, address);
	return 0;
}
