#include<stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{

    char str[]="12341124.31231";
    char *m=strchr(str, ' ');
    printf("%s",m);   
    return 0;
}