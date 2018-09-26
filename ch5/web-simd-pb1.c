/* Web SIMD Practical Problem 1*/

/* Number of bytes in a vector */
#define VBYTES 32

/* Number of elements in a vector */
#define VSIZE VBYTES/sizeof(data_t)

/* Vector data type */
typedef data_t vect_t __attribute__ ((vector_size(VBYTES)));

void simd_pb1_combine(vec_ptr v, data_t *dest) {
	long i;
	vect_t accum, accum1, accum2, accum3;
	vect_t chunk, chunk1, chunk2, chunk3;
	int cnt = vec_length(v);
	data_t result = IDENT;
	
	/* Initialize all accum entries to IDENT */
	for (i = 0; i < VSIZE; i++)
	{
		accum[i] = IDENT;
		accum1[i] = IDENT;
		accum2[i] = IDENT;
		accum3[i] = IDENT;
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
		
		accum = accum OP chunk;
		accum1 = accum1 OP chunk1;
		accum2 = accum2 OP chunk2;
		accum3 = accum3 OP chunk3;
		data += movement;
		cnt -= movement;
	}
	/* Single-set through remaining elements */
	while (cnt) {
		result = result OP *data++;
		cnt--;
	}
	
	/* combine all accumulators */
	accum = (accum OP accum1) OP (accum2 OP accum3);
	
	/* Combine elements of accumulator vector */
	for (i = 0; i < VSIZE; i++)
		result = result OP accum[i];
	
	/* Store result */
	*dest = result;
	
}
 
 

