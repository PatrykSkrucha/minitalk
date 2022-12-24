#include<stdio.h>
#include <unistd.h>
int main()
{
    // a = 5(00000101), b = 9(00001001)
	//long int a = getpid();
    //unsigned char a = 5, b = 9; 
	unsigned char c = 0;
    printf("c b4 = %i\n", c);  
    c |= 1<< 4;
    printf("c<<1 = %i\n", c);  


    return 0;
}