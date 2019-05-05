#include <iostream>
#include <sstream>
#include <string>		
using namespace std;

#include <vector>
#include <list>
#include <queue>


struct Cliente{
    int paciencia;
    int documentos;
    string nome;

    Cliente(int paciencia, int documentos, string nome){
        this->paciencia = paciencia;
        this->documentos = documentos;
        this->nome = nome;
    }
};

struct Banco{
    vector<Cliente*> caixas;
    list<Cliente*> fila_espera;
    queue<Cliente*> fila_saida;

};


int main(){
   
    int docs_recebidos = 0;
    int docs_perdidos = 0;
    Banco banco;

   while(true){
       string linha;
        getline(cin, linha);
        stringstream ui(linha);
        string comando;
        ui >> comando;

        /**
         * Comandos:
         * end = termina a simulação
         * init = cria a quantidade passada de caixas
         * in = inseri clientes
         * tic = passa o tempo
         * show = mostra os caixas, a fila de espera e a fila de saida
         * finalizar = mostra quantos documentos foram recebidos e perdidos 
         * */

        if(comando == "end"){
            break;

        }else if(comando == "init"){
            int caixas;
            while(ui >> caixas){
               if(banco.caixas.size() > 0){
                   free(&banco.caixas);

               }else{
                   for(int i = 0; i < caixas; i++){
                       banco.caixas.push_back(nullptr);
                   }
               }
               
            }

            banco.fila_espera.push_back(nullptr);
            banco.fila_saida.push(nullptr);

        }else if(comando == "show"){

            
        }
   }

}