/* Homework problem 6-40*/

/* Cache = 32768 bytes
 * Block = 8 bytes
 * Sets = 32768/8 = 4096 sets
 * Set bits = log2(4096) = 12 bits
 * Block bits = log2(8) = 3 bits
 * Set bits mask = 1111 1111 1111 = 0xFFF
 */
#include <stdio.h>
#define ROWS 480
#define COLS 640
#define CACHE_SIZE 4096
#define BLOCK_BITS 3
#define SET_BITS 12
#define SET_MASK 0xFFF

int cache[CACHE_SIZE];

void clear_cache()
{
	int i;
	for (i = 0; i < CACHE_SIZE; i++)
		cache[i] = -1;
}
// Total size of struct = 1*4 = 8 bytes
struct pixel {
	char r;
	char g;
	char b;
	char a;
};

//Total size of array = 4 * 480 * 640 = 1228800 bytes = 1200 kb
struct pixel buffer[ROWS][COLS];
/* So at any 1 point cache can hold at most = 37-1/2 of buffer
*/
void access_pattern_6_41()
{
	int i, j, col_width=4, num_access, num_miss, cache_set, cache_tag;
	long address;
	//printf("===========================================\n");
	//printf("Cache set access pattern for N=%d\n", N);
	//printf("===========================================\n");
	printf("\n+++++++Acess pattern for problem 6-41+++++++\n");
	clear_cache();
	num_access = 0;
	num_miss = 0;
	for (j = 639; j >= 0; j--)
	{
		printf("\n---------------i=%d-----------------------\n", i);
		for (i = 479; i>=0; i--)
		{
			//if (j % col_width == 0)
			
			address = (long)&buffer[i][j].r - (long)buffer;
			cache_set = (address>>BLOCK_BITS)&SET_MASK;
			cache_tag = (unsigned)address>>(BLOCK_BITS+SET_BITS);
			printf("buffer[%d][%d].r=[%d-0x%x] ", i, j, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&buffer[i][j].g - (long)buffer;
			cache_set = (address>>BLOCK_BITS)&SET_MASK;
			cache_tag = (unsigned)address>>(BLOCK_BITS+SET_BITS);
			printf("buffer[%d][%d].m=[%d-0x%x] ", i, j, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&buffer[i][j].b - (long)buffer;
			cache_set = (address>>BLOCK_BITS)&SET_MASK;
			cache_tag = (unsigned)address>>(BLOCK_BITS+SET_BITS);
			printf("buffer[%d][%d].y=[%d-0x%x] ", i, j, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&buffer[i][j].a - (long)buffer;
			cache_set = (address>>BLOCK_BITS)&SET_MASK;
			cache_tag = (unsigned)address>>(BLOCK_BITS+SET_BITS);
			printf("buffer[%d][%d].a=[%d-0x%x] ", i, j, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			printf("\n");
		}
	}
	printf("\nnum_access: %d\n", num_access);
	printf("num_miss: %d\n", num_miss);
	printf("num_hits: %d\n", num_access - num_miss);
	//printf("\n================ Miss rate for 6-38: %0.2f %% ================\n", (float)(num_miss/num_access)*100);
}

void access_pattern_6_42()
{
	int i, col_width=4, num_access, num_miss, cache_set, cache_tag;
	long address;
	clear_cache();
	num_access = 0;
	num_miss = 0;
	i = 0;
	printf("\n+++++++Acess pattern for problem 6-42+++++++\n");
	char *cptr = (char *)buffer;
	for(; cptr < (((char *) buffer) + 640 * 480 * 4); cptr++)
	{
		address = (long)cptr - (long)buffer;
		cache_set = (address>>BLOCK_BITS)&SET_MASK;
		cache_tag = (unsigned)address>>(BLOCK_BITS+SET_BITS);
		printf("address(%ld)=[%d-0x%x] ", address, cache_set, cache_tag);
		if (cache[cache_set] != cache_tag)
		{
			num_miss++;
			cache[cache_set] = cache_tag;
		}
		num_access++;
		i++;
		if (i % col_width == 0)
			printf("\n");
		
	}
	printf("\nnum_access: %d\n", num_access);
	printf("num_miss: %d\n", num_miss);
	printf("num_hits: %d\n", num_access - num_miss);
	
} 


void access_pattern_6_43()
{
	int i, col_width=4, num_access, num_miss, cache_set, cache_tag;
	long address;
	clear_cache();
	num_access = 0;
	num_miss = 0;
	i = 0;
	printf("\n+++++++Acess pattern for problem 6-43+++++++\n");
	int *iptr = (int *)buffer;
	for(; iptr < ((int *) buffer + 640 * 480); iptr++)
	{
		address = (long)iptr - (long)buffer;
		cache_set = (address>>BLOCK_BITS)&SET_MASK;
		cache_tag = (unsigned)address>>(BLOCK_BITS+SET_BITS);
		printf("address(%ld)=[%d-0x%x] ", address, cache_set, cache_tag);
		if (cache[cache_set] != cache_tag)
		{
			num_miss++;
			cache[cache_set] = cache_tag;
		}
		num_access++;
		i++;
		if (i % col_width == 0)
			printf("\n");
		
	}
	printf("\nnum_access: %d\n", num_access);
	printf("num_miss: %d\n", num_miss);
	printf("num_hits: %d\n", num_access - num_miss);
}
int main(int argc, char *argv[])
{
	//access_pattern_6_41();
	//access_pattern_6_42();
	access_pattern_6_43();
	return 0;
}
