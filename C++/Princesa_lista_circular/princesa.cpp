#include <iostream>
using namespace std;

struct Node{
    int valor;
    Node * anterior;
    Node * proximo;

    Node(int valor){
        this->valor = valor;
        this->anterior = this;
        this->proximo = this;
    }

    void inserir_direita(Node * ref, int valor){
        Node * node = new Node(valor);

        node->proximo = ref->proximo;
        node->anterior = ref;
        ref->proximo = node;
        node->proximo->anterior = node; 
    }

    void inserir_esquerda(Node * ref, int valor){
        inserir_direita(ref->anterior, valor);
    }

    //Método remover base
    void remover(Node * node){
        node->proximo->anterior = node->anterior;
        node->anterior->proximo = node->proximo;
    }

    void remover_direita(Node * ref){
        remover(ref->proximo);
    }

    void remover_esquerda(Node * ref){
        remover(ref->anterior);
    }

    void imprimir(Node * node, Node * espada = nullptr){

        printf("[ ");

        if(node != nullptr){
            Node * aux = node;
            do{
                printf("%d ", aux->valor);

                if((espada != nullptr) && (aux == espada))
                    printf(">");
                aux = aux->proximo;
            }while(aux != node);
        }
        printf("]\n");
    }

    Node * selecionar(Node * node, int valor){

       do{
           if(node->valor == valor){
               return node;
           }
        node = node->proximo;

       }while(node != this);
       return NULL;

    }

    void matar(Node * node, int escolhido){
        do{
            if(node->valor == escolhido){
                if(node->valor > 0){
                    node->remover_direita(node->proximo);
                    //node->imprimir(node);

                    node = node->proximo;
                    escolhido = node->valor;

                }else if(node->valor < 0){
                    node->remover_esquerda(node->anterior);
                    //node->imprimir(node);

                    node = node->anterior;
                    escolhido = node->valor; 
                }
            }

        }while(node != node);
            return;

    }
};

int main(){
    Node * lista = nullptr;
    lista = new Node(1);

    int direcao;
    int tamanho;
    int escolhido;

    printf("Digite o tamanho da lista: \n");
    scanf("%d", &tamanho);

    printf("Digite o escolhido: \n");
    scanf("%d", &escolhido);

    printf("Digite a direcao da espada: \n");
    scanf("%d", &direcao);

    for(int i = 1; i < tamanho; i++){
        lista->inserir_esquerda(lista, (i + 1) * direcao);
        direcao *= -1;
    }

    lista->imprimir(lista);
    printf("\n");

    Node * selecionado = lista->selecionar(lista, escolhido);
    printf("Selecionado %d \n", selecionado->valor);

    lista->matar(lista, escolhido);
    lista->imprimir(lista);
}
