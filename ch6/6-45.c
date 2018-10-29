#define BLOCK 16

void transpose_original(int *dst, int *src, int dim)
{
	int i, j;
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++)
		{
			dst[j*dim + i] = src[i*dim + j];
		}
	}
}

void transpose_optimized(int *dst, int *src, int dim)
{
	int i, j, a, b;
	for (i = 0; i < dim-BLOCK; i+=BLOCK) 
		for (j = 0; j < dim-BLOCK; j+=BLOCK)
			for (a = i; a < i + BLOCK; a++)
				for (b = j; b < j + BLOCK; b++)
					dst[b*dim + a] = src[a*dim + b];
			
	
	for (; i < dim; i++)
		for (; j < dim; j++)
			dst[j*dim + i] = src[i*dim + j];
}
