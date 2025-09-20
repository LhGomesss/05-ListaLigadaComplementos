#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();




int main()
{
    menu();
}

void menu()
{
    int op = 0;
    while (op != 7) {
        system("cls"); // somente no windows
        cout << "Menu Lista Ligada";
        cout << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1: inicializar();
            break;
        case 2: exibirQuantidadeElementos();
            break;
        case 3: exibirElementos();
            break;
        case 4: buscarElemento();
            break;
        case 5: inserirElemento();
            break;
        case 6: excluirElemento();
            break;
        case 7:
            return;
        default:
            break;
        }

        system("pause"); // somente no windows
    }
}

void inicializar() {
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* temp = aux;
        aux = aux->prox;
        free(temp);
    }
    primeiro = NULL;
    cout << "Lista reiniciada!" << endl;
}

void exibirQuantidadeElementos() {

    int nElementos = 0;
    NO* aux = primeiro;
    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }
    cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }
    else {
        cout << "Elementos: \n";
        NO* aux = primeiro;
        while (aux != NULL) {
            cout << aux->valor << endl;
            aux = aux->prox;
        }
    }
}

void inserirElemento() {
    NO* novo = (NO*)malloc(sizeof(NO));
    cout << "Digite um valor: ";
    cin >> novo->valor;
    novo->prox = NULL;

    NO* atual = primeiro;      
    NO* anterior = NULL;       

   
    while (atual != NULL && atual->valor < novo->valor) { 
        anterior = atual;
        atual = atual->prox;
    }

    
    if (atual != NULL && atual->valor == novo->valor) {   
        cout << "Elemento ja existe!" << endl;
        free(novo);
        return;
    }

   
    if (anterior == NULL) { 
        novo->prox = primeiro;
        primeiro = novo;
    }
    else {
        
        anterior->prox = novo;
        novo->prox = atual;
    }

    cout << "Elemento inserido!" << endl;
}


void excluirElemento() {
    int numero;
    cout << "Digite o valor a excluir: ";
    cin >> numero;

    NO* atual = primeiro;  
    NO* anterior = NULL;    

    while (atual != NULL && atual->valor < numero) { 
        anterior = atual;
        atual = atual->prox;
    }

    
    if (atual == NULL || atual->valor > numero) { 
        cout << "ELEMENTO NAO ENCONTRADO!" << endl;
        return;
    }

    
    if (anterior == NULL) {   
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
    cout << "Elemento excluido!" << endl;
}


void exibirElementos() {
    if (primeiro == NULL) {
        cout << "Lista vazia!" << endl;
        return;
    }
    NO* aux = primeiro;
    cout << "Elementos da lista: ";
    while (aux != NULL) {
        cout << aux->valor << " ";
        aux = aux->prox;
    }
    cout << endl;
}



void buscarElemento() {
    int numero;
    cout << "Digite o valor a buscar: ";
    cin >> numero;

    NO* aux = primeiro;

    while (aux != NULL) {
        if (aux->valor == numero) {
            cout << "Encontrado!" << endl;
            return;
        }
        if (aux->valor > numero) {
            cout << "Elemento nao encontrado!" << endl;
            return;
        }
        aux = aux->prox;
    }

    cout << "Elemento nao encontrado!" << endl;
}

