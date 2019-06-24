#include <list>
#include <iterator>
#include <sstream>
#include <iostream>
using namespace std;

struct Editor{ 
    list<char> texto;
    list<char>:: iterator cursor;

    Editor(){
        this->cursor = this->texto.begin();
    }

    void show(){
        for(auto it = this->texto.begin(); it != this->texto.end(); it++){
            if(it == this->cursor){
                cout << "|";

            }else{
                cout << *it;
            }

            if(this->cursor == this->texto.end()){
                cout << "|";
            }

        }
    }

    void insert_texto(char c){
        this->texto.insert(this->cursor, c);
        this->cursor++;
    }

    void apagar_backspace(){
        auto back = this->cursor;
        back--;
        this->texto.erase(back);
    }

    void apagar_delete(){
        auto back = this->cursor;
        this->texto.erase(back);
    }

    void mv_esquerda(){
        this->cursor--;
    }

    void mv_direita(){
        this->cursor++;
    }

};


int main(){
    Editor *edt = new Editor();
    string entrada;

    while(true){
        getline(cin, entrada);
        stringstream ui;
        char comando;

        while(ui >> comando){
            switch(comando){
                case 'delete':
                    edt->apagar_delete();
                break;

                case 'backspace':
                    edt->apagar_backspace();
                break;

                case 'show':
                    edt->show();
                break;

                case '>':
                    while(ui >> comando){
                        edt->mv_direita();
                    }

                break;

                case '<':
                    while(ui >> comando){
                        edt->mv_esquerda();
                    }
                break;      

                default:
                    edt->insert_texto(comando);
                break;
            }
        }
    }
}