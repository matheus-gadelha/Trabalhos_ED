#include <stdio.h>
#include  <stdlib.h>  // srand, rand
#include  <time.h>  // time ()

const char arvore = '#';
const char espaco = '.';
const char fogo =  'o';
const char queimado = 'x';

int deltaLinha[] = {0, 0, -1, 1};
int deltaColuna[] = {1, -1, 0, 0};
int lados = sizeof(deltaLinha)/sizeof(int);

void mostrar_matriz(int nl, int nc, char mat[nl][nc]){
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++)
            printf("%c", mat[i][j]);
        puts("");
    }
    getchar();
}

void aleatorio(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        int escolhido = rand() % tamanho;
        int aux = v[i];
        v[i] = v[escolhido];
        v[escolhido] = aux; 
    }
}

int queimar(int n_linha, int n_coluna, char matriz[n_linha][n_coluna], int linha, int coluna){
    if( (linha < 0) || (linha >= n_linha) || (coluna < 0) || (coluna >= n_coluna) ){    
        return 0;
    } 
    
    if(matriz[linha][coluna] != arvore){
        
        return 0;
    }

        matriz[linha][coluna] = fogo;
        mostrar_matriz(n_linha, n_coluna, matriz);

        int cont = 1;
        int v_aleatiro[] = {0, 1, 2, 3};
        aleatorio(v_aleatiro, lados);

        for(int j = 0; j < lados; j++){
            int i = v_aleatiro[j];
            cont += queimar(n_linha, n_coluna, matriz, linha + deltaLinha[i], coluna + deltaColuna[i]);

        }
    matriz[linha][coluna] = queimado;
    mostrar_matriz(n_linha, n_coluna, matriz);

    return cont;
}

int main(){
    srand(time(NULL));

    int n_linhas, n_colunas;
    int l, c;
    int densidade;

    printf("Digite o número de linhas e colunas: \n");
    scanf("%d %d", &n_linhas, &n_colunas);

    char matriz[n_linhas][n_colunas];

    printf("Digite a procentagem de arvores: \n");
    scanf("%d", &densidade);

    for(int i = 0; i < n_linhas; i++){
        for(int j = 0; j < n_colunas; j++){
            if(rand() % 101 <= densidade){
                matriz[i][j] = arvore;

            }else{
                matriz[i][j] = espaco;
            }
        }
    }

    printf("\n");
    mostrar_matriz(n_linhas, n_linhas, matriz);
    
    printf("Digite onde o fogo deve comecar: \n");
    scanf("%d %d", &l, &c);

    int cont = queimar(n_linhas, n_colunas, matriz, l, c);
    printf("\n");
    printf("Total de arvores queimadas: %d \n", cont);
    //mostrar_matriz(n_linhas, n_colunas, matriz);


} 