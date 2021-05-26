#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Math.h>

int * createRandomArray(int N) {
    //inicializo el arreglo a llenar
    int r[N];

    //cota de digitos para los numeros aleatorios
    int digitos = 5;
    //inicializan el numero maximo dado la cota de digitos maximos
    int upper = (int) (pow(10, digitos)) - 1;

    //set the seed
    srand((unsigned) time(NULL));

    int i = 1;
    //valor actual del random, restringido al primer N-esimo trozo de las posibilidades
    int v_actual = rand() % ((upper/N)-1);

    //setteo el valor inicial
    r[0] = v_actual;
    //printf("%d\n", v_actual);


    //while para llenar el arreglo
    while ( i < N){
        //el restringimiento de las posibilidades disminuye a medida que se llenan los espacios
        int v_aleatorio = rand() % ((upper * i)/N);


        //se coloca un nuevo valor aleatorio si este es mayor al anterior
        if(v_actual < v_aleatorio){

            //printf("%d\n", v_aleatorio);

            r[i] = v_aleatorio;
            //printf("%d\n", *r);

            v_actual = v_aleatorio;
            i++;
        }

    }

    return r;
}
void createData(int N, char* fileName){
    FILE *fp;
    fp = fopen(fileName, "w");
    char c[N];

    int arreglo[N];
    //arreglo = createRandomArray(N);
    //inicializo el arreglo a llenar

    //cota de digitos para los numeros aleatorios
    int digitos = 5;
    //inicializan el numero maximo dado la cota de digitos maximos
    int upper = (int) (pow(10, digitos)) - 1;

    //set the seed
    srand((unsigned) time(NULL));

    int i = 1;
    //valor actual del random, restringido al primer N-esimo trozo de las posibilidades
    int v_actual = rand() % ((upper/N)-1);

    //setteo el valor inicial
    arreglo[0] = v_actual;
    sprintf(c,"%d",v_actual);
    fputs(c, fp);
    fputc(' ', fp);
    //printf("%d\n", v_actual);


    //while para llenar el arreglo
    while ( i < N){
        //el restringimiento de las posibilidades disminuye a medida que se llenan los espacios
        int v_aleatorio = rand() % ((upper * i)/N);


        //se coloca un nuevo valor aleatorio si este es mayor al anterior
        if(v_actual < v_aleatorio){

            //printf("%d\n", v_aleatorio);

            arreglo[i] = v_aleatorio;
            sprintf(c,"%d",v_aleatorio);
            fputs(c, fp);
            fputc(' ', fp);
            //printf("%d\n", *r);

            v_actual = v_aleatorio;
            i++;
        }

    }
    fclose(fp);
//    for(int i = 0; i < N; i++){
//        //printf("*(r+%d) : %d\n", i, *(arreglo + i));
//        sprintf(c,"%d",i);
//        fputs(c, fp);
//        fputc(' ', fp);
//    }
//    fclose(fp);
}

int busquedaBinaria(int arr[], int l, int r, int x){
    while(l <= r){
        int m= l + (r-l) /2;
        //se encuentra x
        if(arr[m]==x){
            return m;
        }
        //x es mayor, busco en la mitad superior
        if(arr[m] < x){
            l = m + 1;
        }
        else{
            r = m - l;
        }

    }
    //si no lo encontramos en el arreglo
    return -1;
}
typedef struct staticVEBTree{
    int* arreglo;
};

int main() {
    //createRandomArray(5);
    createData(10,"poto.txt");

    //busqueda binaria
    int arr[] = {2,3,4,10,40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = busquedaBinaria(arr,0,n-1,x);
    if(result == -1){
        printf("elemento no presente ene el arreglo");
    } else
        printf("el elemento esta presente en el index %d",result);

}