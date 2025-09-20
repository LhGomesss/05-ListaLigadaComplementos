#include <iostream>
using namespace std;

struct NO {
    int valor;
    NO* prox;
};


NO* primeiro = NULL;
NO* ultimo = NULL;


void inicializar() {
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* temp = aux;
        aux = aux->prox;
        free(temp);
    }
    primeiro = NULL;
    ultimo = NULL; 
    cout << "Lista reiniciada.\n";
}


void exibirElementos() {
    if (primeiro == NULL) {
        cout << "Lista vazia\n";
        return;
    }
    NO* aux = primeiro;
    cout << "Elementos: \n";
    while (aux != NULL) {
        cout << aux->valor << " ";
        aux = aux->prox;
    }
    cout << endl;
}


void inserirElemento(int valor) {
    
    NO* aux = primeiro;
    while (aux != NULL) {
        if (aux->valor == valor) {
            cout << "Elemento " << valor << " ja existe na lista.\n";
            return;
        }
        aux = aux->prox;
    }

    NO* novo = (NO*)malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo;
        ultimo = novo;
    }
    else {
        ultimo->prox = novo; 
        ultimo = novo;       
    }

    cout << "Elemento " << valor << " inserido.\n";
}


void excluirElemento(int valor) {
    if (primeiro == NULL) {
        cout << "Lista vazia, nada a excluir.\n";
        return;
    }

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        cout << "Elemento " << valor << " nao encontrado.\n";
        return;
    }

    if (anterior == NULL) 
        {
      
        primeiro = atual->prox;
        if (atual == ultimo) {
            ultimo = NULL; 
        }
    }
    else {
        anterior->prox = atual->prox;
        if (atual == ultimo) {
            ultimo = anterior; 
        }
    }

    free(atual);
    cout << "Elemento " << valor << " excluido.\n";
}