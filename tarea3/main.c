#include <stdio.h>
#include <stdlib.h>

void createData(int N, char* fileName){
    FILE *fp;
    fp = fopen(fileName,"w");
    char c[N];

    for (int i = 0; i < N; i++) {
        int num = (rand());//% (N + 1)
        //printf(num);
        sprintf(c,num);
        //c[i] = 'a';
        fputs(c,fp);
        fputc(' ',fp);
    }
    fclose(fp);
}

int main1() {
    printf("Hello, World!\n");
    createData(10, "caca.txt");
    return 0;
}

int main ()
{
    int i;
    char buffer [33];
    printf ("Enter a number: ");
    scanf ("%d",&i);
    itoa (i,buffer,10);
    printf ("decimal: %s\n",buffer);
    itoa (i,buffer,16);
    printf ("hexadecimal: %s\n",buffer);
    itoa (i,buffer,2);
    printf ("binary: %s\n",buffer);
    return 0;
}
