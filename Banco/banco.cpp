#include <iostream>
#include <sstream>
#include <string>		
using namespace std;

#include <vector>
#include <list>
#include <queue>


struct Cliente{
    string nome;
    int paciencia;
    int documentos;

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

    void mostrar_caixas(){
        for(int i = 0; i < this->caixas.size(); i++){
            cout << "[";

            if(this->caixas.at(i) != nullptr){ //Se a posição i do vetor for diferente de nulo, mostra o conteúdo da posição
                cout << this->caixas.at(i)->nome << ", ";
                cout << this->caixas.at(i)->documentos << ", ";
                cout << this->caixas.at(i)->paciencia;
            }
            cout << "]";

        }
        cout << endl;
    }

    void mostrar_fila_entrada(){
        cout << "{";

        for(list<Cliente*>::iterator it = this->fila_espera.begin(); 
            it != this->fila_espera.end(); it++){
                
                if(*it != nullptr){
                    cout << (*it)->nome << ", ";
                    cout << (*it)->documentos << ", ";
                    cout << (*it)->paciencia;
                }
            cout << "}";
        }

        cout << endl;
    } 

    void mostrar_fila_saida(){
        queue<Cliente*> saida = this->fila_saida;
        cout << "{";
        
        if(!saida.empty()){
            cout << saida.front()->nome << ", ";
            cout << saida.front()->documentos << ", ";
            cout << saida.front()->paciencia;
            saida.pop();

        }

        cout << "}" << endl;
    }

    void iniciar_caixas(int caixas){
        if(this->caixas.size() > 0){
            this->caixas.clear();

            for(int i = 0; i < caixas; i++){
                this->caixas.push_back(nullptr);
            }

        }else{
            for(int i = 0; i < caixas; i++){
                this->caixas.push_back(nullptr);
            }
        }
    }

    void limpar_saida(){
        while(!this->fila_saida.empty()){
            this->fila_saida.pop();
        }
    }

    void tolerancia(){
        
    }

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
         * init = cria um vector com a quantidade passada de caixas e inicia as filas de espera e saída
         * in = inseri clientes
         * tic = passa o tempo
         * show = mostra os caixas, a fila de espera e a fila de saida
         * finalizar = mostra quantos documentos foram recebidos e perdidos 
         * */

        if(comando == "end"){
            break;

        }else if(comando == "init"){
            

        }else if(comando == "show"){

            
        }else if(comando == "in"){
            string nome;
            int pac;
            int docs;
          
        }else if(comando == "tic"){

        }else if(comando == "finalizar"){

        }
   }

}