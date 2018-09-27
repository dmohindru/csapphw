/* Web SIMD Practical Problem 6*/

/* Number of bytes in a vector */
#define VBYTES 32

/* Number of elements in a vector */
#define VSIZE VBYTES/sizeof(data_t)

/* Vector data type */
typedef data_t vect_t __attribute__ ((vector_size(VBYTES)));

double poly_simd(double a[], double x, long degree) {
	long i;
	long cnt = degree+1;
	double result = 0;
	double xpwr = 1.0;
	vect_t accum, accum1, xpwr_vec, xpwr1_vec, xvv_vec, chunk, chunk1;
	
	xpwr = 1.0;
	/* Initialize all accum entries to IDENT */
	for (i = 0; i < VSIZE; i++)
	{
		accum[i] = 0;
		xpwr *= x;
	}
	
	for (i = 0; i < VSIZE; i++)
	{
		xvv_vec[i] = xpwr;
	}
	
	xpwr = 1.0;
		
	/* Single step until have memory alignment */
	
	while (((size_t) a) % VBYTES  && cnt) {
		result += *a++ * xpwr;
		xpwr *= x;
		cnt--;
	}
	
	/* Prepare xpwr_vec */
	for (i = 0; i < VSIZE; i++) 
	{
		xpwr_vec[i] = xpwr;
		xpwr *= x;
	}
	
	/* Prepare xpwr1_vec */
	for (i = 0; i < VSIZE; i++) 
	{
		xpwr1_vec[i] = xpwr;
		xpwr *= x;
	}
	
	/* Main Loop */
	int movement = VSIZE * 2;
	while (cnt >= movement) {
		// Get uchunks
		chunk = *((vect_t *) a);
		chunk1 = *((vect_t *) a+VSIZE);
		accum += chunk * xpwr_vec;
		accum1 += chunk1 * xpwr1_vec;
		xpwr_vec *= xvv_vec;
		xpwr1_vec *= xvv_vec;
		a += movement;
		cnt -= movement;
	}
	
	/* Combine elements of accumulator vector */
	xpwr = 1.0;
	for (i = 0; i < VSIZE; i++)
		result += accum[i] + accum1[i];
	
	/* Get highest power of x */
	xpwr = xpwr1_vec[0];
	
	/* Single-set through remaining elements */
	while (cnt) {
		result += *a++ * xpwr;
		xpwr *= x;
		cnt--;
	}
	
	/* Store result */
	return result;
	
}

