long switch_prob(long x, long n)
{
  long result = x;
  switch(n) {
  case 60: //0x4005a1
  case 62:
    result = x * 8;
    break;
  case 63: //0x4005aa
    result = x >> 3;
    break;
  case 64: //0x4005b2
    result = x << 4;
    result = result - x;
    x = result;
  case 65: //0x4005bf
    x *= x;
  default: //0x4005c3
    result = x + 75;
    break;
  }
  
  return result;
  
}
