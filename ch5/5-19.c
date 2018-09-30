/* Homework problem 5-19 */

void psum1a(float a[], float p[], long n) {
	long i;
	float last_val, val;
	last_val = p[0] = a[0];
	for (i = 1; i < n; i++) {
		val = last_val + a[i];
		p[i] = val;
		last_val = val;
	}
}

void psum4a(float a[], float p[], long n) {
	long i;
	float last_val, val, val1, val2, val3;
	last_val = p[0] = a[0];
	for (i = 1; i < n; i+=4)
	{
		val = last_val + a[i];
		val1 = val + a[i+1];
		val2 = val1 + a[i+2];
		val3 = val2 + a[i+3];
		
		p[i] = val;
		p[i+1] = val1;
		p[i+2] = val2;
		p[i+3] = val3;
		
		last_val = val + (a[i] + a[i+1] + a[i+2] + a[i+3]);
	}
	for (;i < n; i++)
	{
		val = last_val + a[i];
		p[i] = val;
		last_val = val;
	}
}
