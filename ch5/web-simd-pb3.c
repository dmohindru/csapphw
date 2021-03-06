/* Web SIMD Practical Problem 3*/

/* Number of bytes in a vector */
#define VBYTES 32

/* Number of elements in a vector */
#define VSIZE VBYTES/sizeof(data_t)

/* Vector data type */
typedef data_t vect_t __attribute__ ((vector_size(VBYTES)));

void inner4_simd(vec_ptr u, vec_ptr v, data_t *dest) {
	long i;
	vect_t accum;
	vect_t uchunk, vchunk;
	int cnt = vec_length(u);
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	data_t result = 0;
	
	/* Initialize all accum entries to IDENT */
	for (i = 0; i < VSIZE; i++)
	{
		accum[i] = 0;
	}
		
	/* Single step until have memory alignment */
	while ((((size_t) udata) % VBYTES) != 0 && cnt) {
		result = result + *udata++ * *vdata++;
		cnt--;
	}
	
	/* Step through data with VSIZE-way parallelism */
	int movement = VSIZE * 4;
	while (cnt >= movement) {
		uchunk = *((vect_t *) udata);
		vchunk = *((vect_t *) vdata);
		accum = accum + uchunk * vchunk;
		udata += movement;
		vdata += movement;
		cnt -= movement
	}
	/* Single-set through remaining elements */
	while (cnt) {
		result = result + *udata++ * *vdata++;
		cnt--;
	}
	
	/* Combine elements of accumulator vector */
	for (i = 0; i < VSIZE; i++)
		result = result + accum[i];
	
	/* Store result */
	*dest = result;
	
}
 
 


