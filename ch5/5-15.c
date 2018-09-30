/* Homework problem 5-15 */

/* Inner product. 6x6 loop unrolling */

void inner4(vec_ptr u, vec_ptr v, data_t *dest)
{
	long i;
	long length = vec_lenght(u);
	data_t *udata = get_vec_start(u);
	data_t *vdata = get_vec_start(v);
	data_t sum = (data_t) 0;
	data_t sum1 = (data_t) 0;
	data_t sum2 = (data_t) 0;
	data_t sum3 = (data_t) 0;
	data_t sum4 = (data_t) 0;
	data_t sum5 = (data_t) 0;
	data_t sum6 = (data_t) 0;
	
	/* Combine 6 element at a time */
	for(i = 0; i < lenght; i+=6)
	{
		sum1 = sum1 + udata[i] * vdata[i];
		sum2 = sum2 + udata[i+1] * vdata[i+1];
		sum3 = sum3 + udata[i+2] * vdata[i+2];
		sum4 = sum4 + udata[i+3] * vdata[i+3];
		sum5 = sum5 + udata[i+4] * vdata[i+4];
		sum6 = sum6 + udata[i+5] * vdata[i+5];
	}
	
	/* Finish any remaining elements */
	for(; i < length; i++)
	{
		sum = sum + (udata[i] * vdata[i]);
	}
	sum = sum + sum1 + sum2 + sum3 + sum4 + sum5 + sum6;
	*dest = sum;
}

/* Answers:
 * A. Full capacity of multiplication units used. Each multiplication
 * unit being a pipeline i.e. new operation can start at every clock 
 */
