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
    int docs_recebidos;
    int docs_perdidos;


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
        for(list<Cliente*>::iterator it = this->fila_espera.begin();
            it != this->fila_espera.end(); it++){
                if(*it != nullptr){
                    if((*it)->paciencia == 0){
                       this->docs_perdidos += (*it)->documentos;
                       this->fila_espera.erase(it);
                       this->fila_saida.push(*it);
                    }

                }else{
                    (*it)->paciencia -= 1;
                }
            }   
    }

    void processar_documentos(){
        for(int i = 0; i < this->caixas.size(); i++){
            
            if(this->caixas.at(i) == nullptr){ //Verifica se o caixa está vazio

                if(this->fila_espera.size() != 0){ //Verifica se tem alguem na fila de espera
                    this->caixas.at(i) = this->fila_espera.front(); //O primeiro na fila de espera vai pro caixa
                    this->fila_espera.pop_front(); //Tira o cliente da fila de espera, pois ele agora está no caixa

                }

            }else{

                if(this->caixas.at(i)->documentos != 0){
                    this->caixas.at(i)->documentos -= 1;
                    this->docs_recebidos += 1;

                    if(this->caixas.at(i)->documentos == 0){
                        this->fila_saida.push(this->caixas.at(i));
                        this->caixas.at(i) == nullptr;
                    }

                }else{
                    this->fila_saida.push(this->caixas.at(i));
                    this->caixas.at(i) == nullptr;
                }

            }
        }

        this->tolerancia();
        this->limpar_saida();
    }

    void adicionar_cliente(Cliente* cl){
        this->fila_espera.push_back(cl);
    }

    void adicionar_saida(Cliente* cl){
        this->fila_saida.push(cl);
    }

};


int main(){
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
            int caixas;
            ui >> caixas;

            banco.iniciar_caixas(caixas);

        }else if(comando == "show"){
            cout << "Caixas: ";
            banco.mostrar_caixas();

            cout << "\n";
            cout << "Entrada ";
            banco.mostrar_fila_entrada();

            cout << "\n";
            cout << "Saida: ";
            banco.mostrar_fila_saida();
            
            cout << endl;
            
        }else if(comando == "in"){
            string nome;
            int pac;
            int docs;

            ui >> nome;
            ui >> pac;
            ui >> docs;

            banco.adicionar_cliente(new Cliente(pac, docs, nome));

          
        }else if(comando == "tic"){
            banco.processar_documentos();

        }else if(comando == "finalizar"){
            cout << "Documentos recebidos: " << banco.docs_recebidos << endl;
            cout << "Documentos perdidos: " << banco.docs_perdidos << endl;


        }else{
            cout << "Comando inválido" << endl;
        }
   }

}