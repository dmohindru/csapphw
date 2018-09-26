/* Web SIMD Practical Problem 4*/

/* Number of bytes in a vector */
#define VBYTES 32

/* Number of elements in a vector */
#define VSIZE VBYTES/sizeof(data_t)

/* Vector data type */
typedef data_t vect_t __attribute__ ((vector_size(VBYTES)));

void inner4_simd(vec_ptr u, vec_ptr v, data_t *dest) {
	long i;
	vect_t accum, accum1, accum2, accum3;
	vect_t uchunk, uchunk1, uchunk2, uchunk3; 
	vect_t vchunk, vchunk1, vchunk2, vchunk3;
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
		result += *udata++ * *vdata++;
		cnt--;
	}
	
	/* Step through data with VSIZE-way parallelism */
	int movement = VSIZE * 4;
	while (cnt >= movement) {
		// Get uchunks
		uchunk = *((vect_t *) udata);
		uchunk1 = *((vect_t *) udata+movement);
		uchunk2 = *((vect_t *) udata+2*movement);
		uchunk3 = *((vect_t *) udata+3*movement);
		// Get vchunks
		vchunk = *((vect_t *) vdata);
		vchunk1 = *((vect_t *) vdata+movement);
		vchunk2 = *((vect_t *) vdata+2*movement);
		vchunk3 = *((vect_t *) vdata+3*movement);
		
		accum = accum + uchunk * vchunk;
		accum1 = accum1 + uchunk1 * vchunk1;
		accum2 = accum2 + uchunk2 * vchunk2;
		accum3 = accum3 + uchunk3 * vchunk3;
		udata += movement;
		vdata += movement;
		cnt -= movement
	}
	/* Single-set through remaining elements */
	while (cnt) {
		result += *udata++ * *vdata++;
		cnt--;
	}
	
	/* Combine elements of accumulator vector */
	for (i = 0; i < VSIZE; i++)
		result += accum[i] + accum1[i] + accum2[i] + accum3[i] ;
	
	/* Store result */
	*dest = result;
	
}
 
 



