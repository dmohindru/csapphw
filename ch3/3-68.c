typedef struct {
  int x[A][B];
  long y;
} str1;

typedef struct {
  char array[B];
  int t;
  short a[A];
  long u;
} str2;

void setVal(str1 *p, str2 *q) {
  long v1 = q->t;
  long v2 = q->u;
  p->y = v1 + v2;
}
/*
Solution: A = 9, B = 5
Memory layout for str2
Mem_Add     Value
 0          array[0]
 1          array[1]
 2          array[2]
 3          array[3]
 4          array[4]
 5          padding        
 6          padding
 7          padding
 8          t_byte0
 9          t_byte1
10          t_byte2
11          t_byte3
12          a_byte0[0]
13          a_byte0[0]
14          a_byte1[1]
15          a_byte1[1]
16          a_byte2[2]
17          a_byte2[2]
18          a_byte3[3]
19          a_byte3[3]
20          a_byte4[4]
21          a_byte4[4]
23          a_byte5[5]
24          a_byte5[5]
25          a_byte6[6]
26          a_byte6[6]
27          a_byte7[7]
28          a_byte7[7]
29          a_byte8[8]
30          a_byte8[8]
31          padding
32          u_byte0
33          u_byte1
34          u_byte2
35          u_byte3
36          u_byte4
37          u_byte5
38          u_byte6
39          u_byte7
