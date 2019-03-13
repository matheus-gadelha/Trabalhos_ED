#include <stdio.h>

const int morto = 0;

int prox_vivo(int v[], int tamanho, int inicio){
    int posicao = (inicio + i) % tamanho;
    while(v[posicao] == morto){
        posicao = (posicao + 1) % tamanho;
    }
    return posicao;
}

void mostrar_vetor(int v[], int tamanho, int escolhido){

    printf("[ ");
    for(int i = 0; i < tamanho; i++){
        if(v[i] != morto){
            printf(" %d", v[i]);
        }
        if(i == escolhido && escolhido > 0){
            printf(">");
        }else{
            printf("<");
        }
    }
    printf(" ]\n");
}


int main(){
    int tamanho = 0;
    int escolhido = 0;
    int direcao = 0;
    int vetor[tamanho];

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tamanho);

    printf("Digite qual é o escolhido: \n");
    scanf("%d", &escolhido);

    printf("Digite em que direção a espada deve cortar: \n");
    scanf("%d", &direcao);

    for(int i = 0; i < tamanho; i++){
        vetor[i] = (i + 1) * direcao;
        direcao *= -1;
        
    } 
    

    mostrar_vetor(vetor, tamanho, escolhido);

    int quantidade = tamanho - 1;

    /*while(quantidade--){
        int quem_morre = prox_vivo(vetor, tamanho, escolhido);
        vetor[quem_morre] = 0;
        escolhido = prox_vivo(vetor, tamanho, quem_morre);
        mostrar_vetor(vetor, tamanho, escolhido);
    } */ 
 

}