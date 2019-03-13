#include <stdio.h>
#include  <stdlib.h>  // srand, rand
#include  <time.h>  // time ()

//const char parede = '#';
//const char buraco = 'o';

int deltaLinha[] = {0, 0, -1, 1};
int deltaColuna[] = {1, -1, 0, 0};
int lados = sizeof(deltaLinha)/sizeof(int);

void aleatorio(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        int escolhido = rand() % tamanho;
        int aux = v[i];
        v[i] = v[escolhido];
        v[escolhido] = aux; 
    }
}

void mostrar_labirinto(int linhas, int colunas, char labirinto[linhas][colunas]){
   for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%c", labirinto[i][j]);
        }
        printf("\n");
    } 
}


void furar_parede(int l, int c, char labirinto[l][c], int il, int ic){
    if( (il == 0) || (il == l) || (ic == 0) || (ic == c) ){
        return;
    }
    if(labirinto[il][ic] != '#'){
        return;
    }
    
    labirinto[l][c] = 'o';

    int v_aleatiro[] = {0, 1, 2, 3};
    aleatorio(v_aleatiro, lados);

    for(int j = 0; j < lados; j++){
        int i = v_aleatiro[j];
        furar_parede(l, c, labirinto, il + deltaLinha[i], ic + deltaColuna[i]);

    }

    mostrar_labirinto(l, c, labirinto);

}

int main(){
    srand(time(NULL));


    int n_linhas = 0;
    int n_colunas = 0;
    int l_inicio = 0;
    int c_inicio = 0;

    printf("Digite o número de linhas: \n");
    scanf("%d", &n_linhas);

    printf("Digite o número de colunas: \n");
    scanf("%d", &n_colunas);

    char labirinto[n_linhas][n_colunas];

    for(int i = 0; i < n_linhas; i++){
        for(int j = 0; j < n_colunas; j++){
            labirinto[i][j] = '#';
        }
    }

    printf("Digite as coordenadas onde deve comecar o labirinto: \n");
    scanf("%d %d", &l_inicio, &c_inicio);

    mostrar_labirinto(n_linhas, n_colunas, labirinto);

    furar_parede(n_linhas, n_colunas, labirinto, l_inicio, c_inicio);
}