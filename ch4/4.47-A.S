
4.47-A.o:     file format elf64-x86-64


Disassembly of section .text:
# data in %rdi, count in %rsi
0000000000000000 <bubble_p>:
   0:	4c 8d 4e ff          	lea    -0x1(%rsi),%r9            # last = count - 1
   4:	eb 2e                	jmp    34 <bubble_p+0x34>        # jump to test
   6:	48 8d 74 c7 08       	lea    0x8(%rdi,%rax,8),%rsi     # %rsi = data+i+1
   b:	48 8b 0e             	mov    (%rsi),%rcx               # %rcx = t = *(data+i+1)
   e:	48 8d 14 c7          	lea    (%rdi,%rax,8),%rdx        # %rdx = (data+i)
  12:	4c 8b 02             	mov    (%rdx),%r8                # %r8 = *(data+i)
  15:	4c 39 c1             	cmp    %r8,%rcx                  # compare %rcx and %r8
  18:	7d 06                	jge    20 <bubble_p+0x20>        # skip swapping with %rcx > %r8
  1a:	4c 89 06             	mov    %r8,(%rsi)                # else swap value: %r8 = *(data+i+1) 
  1d:	48 89 0a             	mov    %rcx,(%rdx)               # %rcx = *(data+i)
  20:	48 83 c0 01          	add    $0x1,%rax                 # i = i + 1
  24:	eb 05                	jmp    2b <bubble_p+0x2b>        # jump
  26:	b8 00 00 00 00       	mov    $0x0,%eax                 # i = 0
  2b:	4c 39 c8             	cmp    %r9,%rax                  # compare i and last
  2e:	7c d6                	jl     6 <bubble_p+0x6>          # jump if i < last
  30:	49 83 e9 01          	sub    $0x1,%r9                  # last = last - 1
  34:	4d 85 c9             	test   %r9,%r9                   # check for last == 0
  37:	7f ed                	jg     26 <bubble_p+0x26>        # jump if last > 0
  39:	f3 c3                	repz retq 
