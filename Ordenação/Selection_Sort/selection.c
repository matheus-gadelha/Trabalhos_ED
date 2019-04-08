#include "xpaint.h"
#include "xvet.h"

int menor(int v[], int inicio, int fim){
    int imenor = inicio;
    for(int i = inicio + 1; i < fim; i++){
        if(v[imenor] > v[i]){
            imenor = i;

            xd_vet(v, fim, "rg", i, imenor);
        }
    }
    return imenor;
}

void selection(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        int imenor = menor(v, i, tamanho);

        if(v[i] > v[imenor]){

            xd_vet(v, tamanho, "rg", imenor, i);

            int aux = v[i];
            v[i] = v[imenor];
            v[imenor] = aux;

            xd_vet(v, tamanho, "rg", imenor, i);
        }
    }
}

int main(){
    x_open(600, 600);
    xs_log("imagens/");
    srand(0);

    int tamanho;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for(int i = 0; i < tamanho; i++){
        vetor[i] = xm_rand(1, 50);
    }

    xd_vet(vetor, tamanho, "");

    selection(vetor, tamanho);

    xd_vet(vetor, tamanho, "");
}