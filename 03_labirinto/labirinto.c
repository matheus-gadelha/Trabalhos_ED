#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int l;
    int c;
} Posicao_vizinhos;

const char vizitado = 'v';

#define get_vizinhos(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}

void aleatorio(Posicao_vizinhos v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        int escolhido = rand() % tamanho;
        Posicao_vizinhos aux = v[i];
        v[i] = v[escolhido];
        v[escolhido] = aux; 
    }
}


// Diz se a posição é parede;
bool equals(int nl, int nc, char mat[nl][nc], int l, int c, char value){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return false;
    return mat[l][c] == value;
}

// Descobre se pode furar a paredde;
bool eh_furavel(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!equals(nl, nc, mat, l, c, '#')){ //Se não for parede, não faz nada
        return false;
    }

    int cont = 0;
    Posicao_vizinhos vizinhos[] = get_vizinhos(l, c);
    for(int i = 0; i < 4; i++)
        if(equals(nl, nc, mat, vizinhos[i].l, vizinhos[i].c, '#'))
            cont++;
    if(cont < 3){
        return false;
    }
    return true;
}


void mostrar_labirinto(int linhas, int colunas, char labirinto[linhas][colunas]){
   for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(labirinto[i][j] == '#'){
                printf("█");
            }else{
                printf("%c", labirinto[i][j]);
            }
        }
        printf("\n");
    }
    getchar(); 
}


void furar_parede(int nl, int nc, char labirinto[nl][nc], int il, int ic, int fl, int fc){
    if(!eh_furavel(nl, nc, labirinto, il, ic)){
        return;
    }
    
    labirinto[il][ic] = ' ';
    Posicao_vizinhos vizinhos[] = get_vizinhos(il, ic);
    aleatorio(vizinhos, 4);
    for(int i = 0; i < 4; i++){
        furar_parede(nl, nc, labirinto, vizinhos[i].l, vizinhos[i].c, fl, fc);

        if((il == fl && ic == fc) || (vizinhos[i].l == fl && vizinhos[i].c == fc) ){
            labirinto[il][ic] = '.';
            fl = vizinhos[i].l;
            fc = vizinhos[i].c;
        }

    }

   
    
     

}

void caminho(int nl, int nc, char labirinto[nl][nc], int il, int ic, int fl, int fc){
 
}


int main(){
    srand(time(NULL));


    int n_linhas = 0;
    int n_colunas = 0;
    int l_fim = 0;
    int c_fim = 0;

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

    printf("Digite as coordenadas onde deve terminnar o labirinto: \n");
    scanf("%d %d", &l_fim, &c_fim);  

    furar_parede(n_linhas, n_colunas, labirinto, 1, 1, l_fim, c_fim);
    mostrar_labirinto(n_linhas, n_colunas, labirinto);
}
