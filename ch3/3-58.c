//gcc command: gcc -0g -S 3-58.c
long decode(long x, long y, long z)
{
  // x in %rdi, y in %rsi, z in %rdx
  long result = (y - z);
  x = x * result;
  //result = x;
  result = result << 63;
  result = result >> 63;
  result = result ^ x;
  return result;
    
}
