#define BLOCK 16

void col_convert(int *G, int dim) {
	int i, j;
	
	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			G[j*dim + i] = G[j*dim + i] || G[i*dim + j];
}

void col_convert_optimised(int *G, int dim) {
	int i, j, a, b, tmp;
	
	for (i = 0; i <= dim-BLOCK; i+=BLOCK)
		for (j = i; j <= dim-BLOCK; j+=BLOCK)
			for (a = i; a < i + BLOCK; a++)
				for (b = j; b < b + BLOCK; b++){
					tmp = G[b*dim+a] || G[a*dim+b];
					G[b*dim+a] = tmp;
					G[a*dim+b] = tmp;
				}
				
	for (; i < dim; i++)
		for (; j < dim; j++)
			G[j*dim + i] = G[j*dim + i] || G[i*dim + j];
				
}
