#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int elegirTamanio();
int generarAleatorio(int min, int max);
void cargarVectorAleatorio(int v[], int tam);
void mostarVector(int v[], int tam);
void mostrarPosicionesPares4(int v[], int tam);
int encontrarMaximoImparesNeg(int v[],int tam);
int busquedaLineal(int v[], int tam, int loquebusco);


int main(){
    srand(time(0));

    generarAleatorio(-999,999);

    int tam=elegirTamanio();
    int v[tam];
    cargarVectorAleatorio(v,tam);
    mostarVector(v,tam);
    printf("\n");
    mostrarPosicionesPares4(v,tam);

    encontrarMaximoImparesNeg(v,tam);

    busquedaLineal(v,tam,-120);

    return 0;
}

int elegirTamanio(){
    int tamanio;
    do {
    printf("Ingrese un tamanio de 2 cifras que no puede terminar en 3 o 5: ");
    scanf("%d", &tamanio);
    } while(tamanio<9 || tamanio>100 || tamanio%10==3 || tamanio%10==5);
    return tamanio;
};

int generarAleatorio(int min, int max){
    int ale;
    do{
    ale= min+rand()%(max-min+1);
    } while (ale%2==1 && ale%3==1);
    return ale;
};

void cargarVectorAleatorio(int v[], int tam){
    int numero;
    for(int i=0; i<tam; i++){
        numero=generarAleatorio(-999, 999);
        while(numero>=-99 && numero<=99){
            numero=generarAleatorio(-999, 999);
        }
        v[i]=numero;
}

};

void mostarVector(int v[], int tam){
    printf("||");
    for(int i=0; i<tam; i++){
        printf(" %d ", v[i]);
    }
    printf("||");
};

void mostrarPosicionesPares4(int v[], int tam){
    printf("\n");
    printf("||");
    for(int i=0; i<tam; i++){
        if(i%4==0){
            printf(" %d ", v[i]);
        }
    }
    printf("||");
};

int encontrarMaximoImparesNeg(int v[],int tam){
    int maximo=-9999;
    for(int i=0; i<tam; i++){
        if(v[i]>maximo && v[i]%2!=0 && v[i]<0){
            maximo=v[i];
        }
    }
    printf("\nEl mayor de los negativos es: %d",maximo);
    return maximo;
}

int busquedaLineal(int v[], int tam,int loquebusco){
    int pos=-1;
    for(int i=0; i<tam;i++){
        if(v[i]==loquebusco){
            pos=i;
        }
    }
    printf("\nEl numero q busco es el -120: %d",pos);
    return pos;
};
