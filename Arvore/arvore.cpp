#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree{
    Node * root;
    BTree(){
        this->root = nullptr;
    }

    Node * _gambinsert(Node * node, int value){
        if(node == nullptr)
            return new Node(value);
        if(rand() % 2 == 0)
            node->left = _gambinsert(node->left, value);
        else
            node->right = _gambinsert(node->right, value);
        return node;
    }

    void gambinsert(int value){
        this->root = _gambinsert(this->root, value);
    }

    void _serialize(stringstream& ss, Node * node){
        if(node == nullptr)
            ss << "# ";
        else{
            ss << node->value << " ";
            _serialize(ss, node->left);
            _serialize(ss, node->right);
        }
    }

    string serialize(){
        stringstream ss;
        _serialize(ss, this->root);
        return ss.str();
    }

    void _show(Node * node, int nivel){
        if(node == nullptr){
            cout << string(2 * nivel, ' ') << "#\n";
            return;
        }
        cout << string(2 * nivel, ' ') << node->value << "\n";
    
        if(node->left == nullptr && node->right == nullptr){
            return;
        }

        _show(node->left, nivel + 1);
        _show(node->right, nivel + 1);
    }

    void show(){
        _show(this->root, 0);
    }
};

int main(){
    BTree bt;
    srand(time(NULL));
    for(int i = 0; i < 7; i++)
        bt.gambinsert(rand() % 10);

    cout << bt.serialize() << "\n";
    bt.show();
}