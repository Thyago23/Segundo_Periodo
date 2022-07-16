#include <iostream>
using namespace std;

typedef struct reg{
    int conteudo;
    struct reg *prox;
} celula;

celula *busca(int x, celula *head){
    celula *aux;
    aux = head;
    while (aux->prox != NULL && aux->conteudo != x) 
        aux = aux->prox;

    if(aux->prox == NULL && aux->conteudo != x){
        cout << "valor nao encontrado, retornando o ultimo indice..." << endl;
        return aux;
    }
    else{
        cout << endl << "o valor encontrado foi: " << aux->conteudo << endl;
        cout << "retornando o indice atual..." << endl;
        return aux;
    }
}

void insere(int x, celula *body){
    celula *nova;
    nova = (celula*) malloc (sizeof (celula));
    if(nova == NULL){
        free(nova);
        exit(1);
    }
    nova->conteudo = x;
    nova->prox = body->prox;
    body->prox = nova;
}

void remove(celula *body){
    celula *lixo;
    lixo = body->prox;
    body->prox = lixo->prox;
    free(lixo);
    }

void imprima(celula *head, int numValores) {
    int i = numValores-1;
    celula *exibir;
    for(exibir = head->prox; exibir != NULL; exibir = exibir->prox){
        cout << "valor[" << i << "]: " << exibir->conteudo << endl;
        i--;
    }
    cout << endl;
}

int main(void){
    int valorAux, escolha, numValores = 0;
    celula *body = NULL, *head = NULL, *posicaoEncontrada = NULL;

    head = (celula*) malloc(sizeof(celula));
    if(head == NULL){
        free(head);
        exit(1);
    }
    head->prox = NULL;

    body = head;

    do{
        cout << "[1] - inserir novo valor" << endl;
        cout << "[2] - remover ultimo valor" << endl;
        cout << "[3] - buscar algum valor" << endl;
        cout << "[4] - imprimir a lista" << endl;
        cout << "[5] - sair" << "\n\n";
        cin >> escolha;

        switch(escolha){
            case 1:
                cout << "insira o novo valor: ";
                cin >> valorAux;
                insere(valorAux, body);
                cout << endl << "insercao concluida!" << endl;
                numValores++;
                break;
            case 2:
                remove(body);
                cout << "remocao concluida!" << endl;
                numValores--;
                break;
            case 3:
                cout << "insira o valor para a busca: ";
                cin >> valorAux;
                posicaoEncontrada = busca(valorAux, head);
                break;
            case 4:
                imprima(head, numValores);
                break;
            case 5:
                cout << "encerrando o programa, aguarde!" << endl;
                break;
            default:
                cout << "operecao invalida!" << endl;
                break;
        }

    }while(escolha != 5);

    free(body);
    free(head);
    free(posicaoEncontrada);

    return 0;
}
