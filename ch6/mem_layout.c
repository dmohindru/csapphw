#include <stdio.h>
#include <unistd.h>
#include <string.h>

void access_pattern(int n, long base_address)
{
	int i, j;//, N = 60;
	int a[n][n];
	//long base_address = 0x08000000;
	long address;
	printf("===========================================\n");
	printf("Cache set access pattern for N=%d\n", n);
	printf("===========================================\n");
	printf("\n+++++++Acess pattern for sumA+++++++\n");
	for (i = 0; i < n; i++)
	{
		printf("\n---------------i=%d-----------------------\n", i);
		for (j = 0; j < n; j++)
		{
			address = (long)&a[i][j];
			printf("a[%d][%d]:[", i, j);
			address = base_address + address - (long)a;
			printf("%ld", (address>>4)&0xFF);
			printf("-0x%x]\t", (unsigned)address>>12);
			
		}
		
	}
	
	printf("\n\n+++++++Acess pattern for sumB+++++++\n");
	for (j = 0; j < n; j++)
	{
		printf("\n---------------j=%d-----------------------\n", j);
		for (i = 0; i < n; i++)
		{
			address = (long)&a[i][j];
			printf("a[%d][%d]:[", i, j);
			address = base_address + address - (long)a;
			printf("%ld", (address>>4)&0xFF);
			printf("-0x%x]\t", (unsigned)address>>12);
		}
		
	}
	
	printf("\n\n+++++++Acess pattern for sumC+++++++\n");
	for (j = 0; j < n; j+=2)
	{
		printf("\n---------------j=%d-----------------------\n", j);
		for (i = 0; i < n; i+=2)
		{
			address = (long)&a[i][j];
			printf("a[%d][%d]:[", i, j);
			address = base_address + address - (long)a;
			printf("%ld", (address>>4)&0xFF);
			printf("-0x%x]\t", (unsigned)address>>12);
			
			address = (long)&a[i+1][j];
			printf("a[%d][%d]:[", i+1, j);
			address = base_address + address - (long)a;
			printf("%ld", (address>>4)&0xFF);
			printf("-0x%x]\t", (unsigned)address>>12);
			
			address = (long)&a[i][j+1];
			printf("a[%d][%d]:[", i, j+1);
			address = base_address + address - (long)a;
			printf("%ld", (address>>4)&0xFF);
			printf("-0x%x]\t", (unsigned)address>>12);
			
			address = (long)&a[i+1][j+1];
			printf("a[%d][%d]:[", i+1, j+1);
			address = base_address + address - (long)a;
			printf("%ld", (address>>4)&0xFF);
			printf("-0x%x]\t", (unsigned)address>>12);
			
			printf("\n");
			
		}
	}
}

void usage()
{
	printf("usage: cachesim [-a size] [-s sbit_pos] [-r stride] [-m mem_size] [-c cache_size] [-b block_size]\n");
	printf("\t -a size: examine c memory layout of a 2d array of size\n");
	printf("\t -s sbit_pos: examile cache memory mapping as per position of set index bit pos\n");
	printf("\t -r stride: run cache simulation to examile hit and miss rate\n");
	printf("\t -m mem_size: specifies memory size in bytes. defaults to 8192 bytes\n");
	printf("\t -c cache_size: specifies cache memory size in bytes. defaults to 1024 bytes\n");
	printf("\t -b block_size: specifies cache meory block size in bytes. defaults to 32 bytes\n");
	
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
				address = atoi(optarg);
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
	access_pattern(n, address);
	return 0;
}
