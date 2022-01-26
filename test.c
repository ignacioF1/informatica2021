#include <stdio.h>

int main(){
    int a = 3;
    int b = 0;
    b=a++;
    printf("a=3, hago b=a++ y b=%d y a=%d\n", b,a);
    return 0;
}