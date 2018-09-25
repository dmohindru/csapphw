/* SIMD Code
 */
/* Number of bytes in a vector */
#define VBYTES 32

/* Number of elements in a vector */
#define VSIZE VBYTES/sizeof(data_t)

/* Vector data type */
typedef data_t vect_t __attribute__ ((vector_size(VBYTES)));

void inner4_simd(vec_ptr u, vec_ptr v, data_t *dest) {
	long i;
	vect_t accum;
	vect_t chunk, chunk1;
	int length = vec_length(u);
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	data_t sum = (data_t) 0;
	//start here
	
	/* Initialize all accum entries to IDENT */
	for (i = 0; i < VSIZE; i++)
	{
		accum[i] = IDENT;
	}
		
	/* Single step until have memory alignment */
	while ((((size_t) data) % VBYTES) != 0 && cnt) {
		result = result OP *data++;
		cnt--;
	}
	
	/* Step through data with VSIZE-way parallelism */
	int movement = VSIZE * 4;
	while (cnt >= movement) {
		chunk = *((vect_t *) data);
		chunk1 = *((vect_t *) data+VSIZE);
		chunk2 = *((vect_t *) data+2*VSIZE);
		chunk3 = *((vect_t *) data+3*VSIZE);
		
		accum = accum OP (chunk OP chunk1) OP (chunk2 OP chunk3);
		data += movement;
		cnt -= movement;
	}
	/* Single-set through remaining elements */
	while (cnt) {
		result = result OP *data++;
		cnt--;
	}
	
	
	/* Combine elements of accumulator vector */
	for (i = 0; i < VSIZE; i++)
		result = result OP accum[i];
	
	/* Store result */
	*dest = result;
	
}
 
 


