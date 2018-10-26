/* Homework problem 6-38*/

/* Cache = 1024 bytes
 * Block = 16 bytes
 * Sets = 1024/16 = 64 sets
 * Block bits = log2(16) = 4 bits
 * Set bits = log2(64) = 6 bits
 * Set bits mask = 11 1111 = 0x3F
 */
#include <stdio.h>

#define N 16
#define CACHE_SIZE 64

int cache[CACHE_SIZE];

void clear_cache()
{
	int i;
	for (i = 0; i < CACHE_SIZE; i++)
		cache[i] = -1;
}
// Total size of struct = 4*4 = 16 bytes
struct point_color {
	int c;
	int m;
	int y;
	int k;
};

//Total size of array = 16 * 16 * 16 = 4096
struct point_color square[N][N];
/* So at any 1 point cache can hold at most 1/4 of array
*/
void access_pattern_6_38()
{
	int i, j, col_width=4, num_access, num_miss, cache_set, cache_tag;
	long address;
	printf("===========================================\n");
	printf("Cache set access pattern for N=%d\n", N);
	printf("===========================================\n");
	printf("\n+++++++Acess pattern for problem 6-38+++++++\n");
	clear_cache();
	num_access = 0;
	num_miss = 0;
	for (i = 15; i >= 0; i--)
	{
		printf("\n---------------i=%d-----------------------\n", i);
		for (j = 15; j>=0; j--)
		{
			//if (j % col_width == 0)
			
			address = (long)&square[i][j].c - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].c=[%d-0x%x] ", i, j, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&square[i][j].m - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].m=[%d-0x%x] ", i, j, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&square[i][j].y - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].y=[%d-0x%x] ", i, j, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&square[i][j].k - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].k=[%d-0x%x] ", i, j, cache_set, cache_tag);
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

void access_pattern_6_39()
{
	int i, j, col_width=4, num_access, num_miss, cache_set, cache_tag;
	long address;
	printf("===========================================\n");
	printf("Cache set access pattern for N=%d\n", N);
	printf("===========================================\n");
	printf("\n+++++++Acess pattern for problem 6-39+++++++\n");
	clear_cache();
	num_access = 0;
	num_miss = 0;
	for (i = 15; i >= 0; i--)
	{
		printf("\n---------------i=%d-----------------------\n", i);
		for (j = 15; j>=0; j--)
		{
			//if (j % col_width == 0)
			
			address = (long)&square[j][i].c - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].c=[%d-0x%x] ", j, i, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&square[j][i].m - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].m=[%d-0x%x] ", j, i, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&square[j][i].y - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].y=[%d-0x%x] ", j, i, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&square[j][i].k - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].k=[%d-0x%x] ", j, i, cache_set, cache_tag);
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
}

void access_pattern_6_40()
{
	int i, j, col_width=4, num_access, num_miss, cache_set, cache_tag;
	long address;
	printf("===========================================\n");
	printf("Cache set access pattern for N=%d\n", N);
	printf("===========================================\n");
	printf("\n+++++++Acess pattern for problem 6-40+++++++\n");
	clear_cache();
	num_access = 0;
	num_miss = 0;
	for (i = 15; i >= 0; i--)
	{
		printf("\n---------------i=%d-----------------------\n", i);
		for (j = 15; j>=0; j--)
		{
			//if (j % col_width == 0)
			
			address = (long)&square[i][j].y - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].y=[%d-0x%x] ", i, j, cache_set, cache_tag);
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
	for (i = 15; i >= 0; i--)
	{
		printf("\n---------------i=%d-----------------------\n", i);
		for (j = 15; j>=0; j--)
		{
			//if (j % col_width == 0)
			
			address = (long)&square[i][j].c - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].c=[%d-0x%x] ", i, j, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&square[i][j].m - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].m=[%d-0x%x] ", i, j, cache_set, cache_tag);
			//printf(", cache[%d]=%d", cache_set, cache[cache_set]);
			if (cache[cache_set] != cache_tag)
			{
				num_miss++;
				cache[cache_set] = cache_tag;
			}
			num_access++;
			address = (long)&square[i][j].k - (long)square;
			cache_set = (address>>4)&0x3F;
			cache_tag = (unsigned)address>>10;
			printf("square[%d][%d].k=[%d-0x%x] ", i, j, cache_set, cache_tag);
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
int main(int argc, char *argv[])
{
	//access_pattern_6_38();
	//access_pattern_6_39();
	access_pattern_6_40();
	return 0;
}
