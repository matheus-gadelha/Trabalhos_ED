#include <stdio.h>
#include  <stdlib.h>  // srand, rand
#include  <time.h>  // time ()

//const char arvore = "#";
//const char espaco = ".";
//const char fogo =  "o";
//const char quimado = "x";


void mostrar_matriz(int nl, int nc, char mat[nl][nc]){
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++)
            printf("%c", mat[i][j]);
        puts("");
    }
    getchar();
}

void queimar(int n_linha, int n_coluna, char matriz[n_linha][n_coluna], int linha, int coluna){
    if( (linha < 0) || (linha >= n_linha) || (coluna < 0) || (coluna >= n_coluna) ){
        
        return;

    } 
    
    if(matriz[linha][coluna] != '#'){
        
        return;

    }

        
        matriz[linha][coluna] = 'o';

        mostrar_matriz(n_linha, n_coluna, matriz);

        queimar(n_linha, n_coluna, matriz, linha, coluna + 1);
        queimar(n_linha, n_coluna, matriz, linha, coluna - 1);
        queimar(n_linha, n_coluna, matriz, linha - 1, coluna);
        queimar(n_linha, n_coluna, matriz, linha + 1, coluna);
    
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
                matriz[i][j] = '#';

            }else{
                matriz[i][j] = '.';
            }
        }
    }
   
    mostrar_matriz(n_linhas, n_linhas, matriz);
    printf("\n");

    printf("Digite onde o fogo deve comecar: \n");
    scanf("%d %d", &l, &c);

    queimar(n_linhas, n_colunas, matriz, l, c);

    //mostrar_matriz(n_linhas, n_colunas, matriz);


} 