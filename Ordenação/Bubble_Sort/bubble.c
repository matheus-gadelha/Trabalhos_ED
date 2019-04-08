#include "xpaint.h"
#include "xvet.h"


void bubble(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho - 1; j++){
            if(v[j] > v[j+1]){

                xd_vet(v, tamanho, "rg", j, j+1);

                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

                xd_vet(v, tamanho, "rg", j, j+1);
            }
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

    bubble(vetor, tamanho);

    xd_vet(vetor, tamanho, "");
}