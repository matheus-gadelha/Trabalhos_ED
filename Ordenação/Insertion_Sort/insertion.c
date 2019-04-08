#include "xpaint.h"
#include "xvet.h"

void insertion(int v[], int tamanho){
    for(int i = 1; i < tamanho; i++){
        int aux = v[i];
        int j = i - 1;

        while( (j >= 0) && (v[j] > aux)){
            v[j + 1] = v[j];
            j = j - 1;

            xd_vet(v, tamanho, "rg", i, j);
        }
        v[j + 1] = aux;
    }
}

int main(){
    x_open(600, 600);
    xs_log("imagens/")
    srand(0);

    int tamanho;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for(int i = 0; i < tamanho; i++){
        vetor[i] = xm_rand(1, 50);
    }

    xd_vet(vetor, tamanho, "");

    insertion(vetor, tamanho);

    xd_vet(vetor, tamanho, "");
}