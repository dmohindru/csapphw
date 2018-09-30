/* Homework problem 5-18 */

double poly(double a[], double x, long degree)
{
	long i, j;
	double result = a[0];
	double xpwr[4];
	xpwr[0] = x;
	for (j = 1; j < 4; j++) {
		xpwr[j] = xpwr[j-1] * x;
	}
	/* loop unroll 4x1a */
	for (i = 1; i <= degree; i+=4) {
		result = result + (a[i] * xpwr[0] + a[i+1] * xpwr[1] + a[i+2] * xpwr[2] + a[i+3] * xpwr[3]) ;
		xpwr[0] = x * xpwr[3];
		for (j = 1; j < 4; j++)
		{
			xpwr[j] = xpwr[j-1] * x;
		}
	}
	xpwr[0] = xpwr[3] * x;
	for(; i <=degree; i++)
	{
		result = result + (a[i] * xpwr[0]);
		xpwr[0] = xpwr[0] * x;
	}
	
	return result;
}

double polyh(double a[], double x, long degree) 
{
	long i;
	double result = a[degree];
	for (i = degree-1; i >= 0; i--) {
		result = a[i] + x*result;
	}
}
