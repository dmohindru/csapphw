/* Homework problem 5-17 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SPACE (size_t)125

void* basic_memset(void *s, int c, size_t n) 
{
	size_t cnt = 0;
	unsigned char *schar = s;
	while (cnt < n) 
	{
		*schar++ = (unsigned char) c;
		cnt++;
	}
	return s;
}

/* Efficient Memset.*/

void *efficient_memset(void *s, int c, size_t n)
{
	size_t cnt = n;
	size_t i = 0;
	unsigned char *schar = s;
	unsigned long *slong;
	size_t long_length = sizeof(unsigned long);
	unsigned long long_c = 0;
	
	/* Set mem fill constant 8 bytes long */
	for(i = 0; i < long_length; i++)
		long_c = (long_c << 8) + (unsigned char) c;
	
	/* set single byte till we find memory address aligned to long */
	while((((size_t)schar % long_length) !=0) && cnt)
	{
		*schar++ = (unsigned char) c;
		cnt--;
	}
	
	/* set memory 8 bytes in one go */
	slong = (unsigned long *)schar;
	while(cnt >= long_length)
	{
		*slong++ = long_c;
		cnt -= long_length;
	}
	
	/* set remaining bytes of memory */
	schar = (unsigned char *)slong;
	while(cnt)
	{
		*schar++ = (unsigned char) c;
		cnt--;
	}
	return s;
}

int main(int argc, char* argv[]) {
	void* basic_space = malloc(SPACE);
	void* effective_space = malloc(SPACE);
	int basic_fill = 0xFF;
	unsigned long effective_fill = ~0;
	basic_memset(basic_space, basic_fill, SPACE);
	efficient_memset(effective_space, basic_fill, SPACE);
	assert(memcmp(basic_space, effective_space, SPACE) == 0);
	return 0;
}
