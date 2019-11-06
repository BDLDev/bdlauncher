asm("testfunc:\n\
mov %rsi,%rax\n\
retq\n\
");
extern "C" void testfunc();
asm("testfunc2:\n\
.byte 0x48,0x89,0xfe\n\
call testfunc\n\
retq\n\
");
extern "C" void testfunc2(int);
int main(){testfunc2(1);}
