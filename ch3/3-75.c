#include <complex.h>

double c_imag(double complex x) {
  return cimag(x);
}

double c_real(double complex x) {
  return creal(x);
}

double complex c_sub(double complex x, double complex y)
{
  return x - y;
}

Answer A:
agrument 1
real part in %xmm0, imaginary part in %xmm1
argument 2
real part in %xmm2, imaginary part in %xmm3
and so on.....

Answer B:
real part in %xmm0, imaginary part in %xmm1
