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
	int i, j, col_width=4;
	long address;
	printf("===========================================\n");
	printf("Cache set access pattern for N=%d\n", N);
	printf("===========================================\n");
	printf("\n+++++++Acess pattern for problem 6-38+++++++\n");
	for (i = 15; i >= 0; i--)
	{
		printf("\n---------------i=%d-----------------------\n", i);
		for (j = 15; j>=0; j--)
		{
			//if (j % col_width == 0)
			
			address = (long)&square[i][j].c - (long)square;
			printf("square[i][j].c=[%ld] ", (address>>4)&0x3F);
			address = (long)&square[i][j].m - (long)square;
			printf("square[i][j].m=[%ld] ", (address>>4)&0x3F);
			address = (long)&square[i][j].y - (long)square;
			printf("square[i][j].y=[%ld] ", (address>>4)&0x3F);
			address = (long)&square[i][j].k - (long)square;
			printf("square[i][j].k=[%ld] ", (address>>4)&0x3F);
			printf("\n");
		}
	}
}

void access_pattern_6_39()
{
	int i, j, col_width=4;
	long address;
	printf("===========================================\n");
	printf("Cache set access pattern for N=%d\n", N);
	printf("===========================================\n");
	printf("\n+++++++Acess pattern for problem 6-38+++++++\n");
	for (i = 15; i >= 0; i--)
	{
		printf("\n---------------i=%d-----------------------\n", i);
		for (j = 15; j>=0; j--)
		{
			//if (j % col_width == 0)
			
			address = (long)&square[j][i].c - (long)square;
			printf("square[j][i].c=[%ld-0x%x] ", (address>>4)&0x3F, (unsigned)address>>10);
			address = (long)&square[j][i].m - (long)square;
			printf("square[j][i].m=[%ld-0x%x] ", (address>>4)&0x3F, (unsigned)address>>10);
			address = (long)&square[j][i].y - (long)square;
			printf("square[j][i].y=[%ld-0x%x] ", (address>>4)&0x3F, (unsigned)address>>10);
			address = (long)&square[j][i].k - (long)square;
			printf("square[j][i].k=[%ld-0x%x] ", (address>>4)&0x3F, (unsigned)address>>10);
			printf("\n");
		}
	}
}
int main(int argc, char *argv[])
{
	//access_pattern_6_38();
	access_pattern_6_39();
	return 0;
}
