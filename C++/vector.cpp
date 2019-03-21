#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Vector{
    int * data;
    int size;
    int capacity;
};

Vector * vector_create(int cap){
    Vector * vec = (Vector*) malloc(sizeof(Vector));
    vec->size = 0;
    vec->capacity = cap;
    vec->data = (int*) malloc(cap * sizeof(int));
    return vec;
}

void vector_destroy(Vector * vec){
    free(vec->data);
    free(vec);
}

void vector_push_back(Vector * vec, int value){
    if(vec->size == vec->capacity)
        return;
    vec->data[vec->size] = value;
    vec->size += 1;
}

void vector_push_back(Vector * vec, int value){
    if(vec->size == vec->capacity)
        return;
    vec->data[vec->size] = value;
    vec->size += 1;
}

void vector_show(Vector * vector){
    printf("[ ");
    for(int i = 0; i < vector->size; i++){
        printf("%d ", vector->data[i]);
    }
    printf("]\n");
}


int main(){
    Vector * vec = vector_create(4);
    vector_show(vec);
    vector_push_back(vec, 4);
    vector_show(vec);
    vector_push_back(vec, 6);
    vector_show(vec);
    vector_push_back(vec, 2);
    vector_show(vec);
    vector_push_back(vec, 1);
    vector_show(vec);
    vector_push_back(vec, 8);
    vector_show(vec);
}