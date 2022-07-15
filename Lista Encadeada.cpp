#include <iostream>
using namespace std;

typedef struct reg{
    int conteudo;
    struct reg *prox;
} celula;

celula *busca(int x, celula *le){
    celula *aux;
    aux = le;
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

void insere(int x, celula *p){
    celula *nova;
    nova = (celula*) malloc (sizeof (celula));
    if(nova == NULL){
        free(nova);
        exit(1);
    }
    nova->conteudo = x;
    nova->prox = p->prox;
    p->prox = nova;
}

void remove(celula *p){
    celula *lixo;
    lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);
}

void imprima(celula *le, int numValores) {
    int i = numValores-1;
    celula *p;
    for(p = le->prox; p != NULL; p = p->prox){
        cout << "valor[" << i << "]: " << p->conteudo << endl;
        i--;
    }
    cout << endl;
}

int main(void){
    int valorAux, escolha, numValores = 0;
    celula *p = NULL, *le = NULL;

    le = (celula*) malloc(sizeof(celula));
    if(le == NULL){
        free(le);
        exit(1);
    }
    le->prox = NULL;

    p = le;

    do{
        cout << "[1] - inserir novo valor" << endl;
        cout << "[2] - remover valor atual" << endl;
        cout << "[3] - buscar algum valor" << endl;
        cout << "[4] - imprimir a lista" << endl;
        cout << "[5] - sair" << "\n\n";
        cin >> escolha;

        switch(escolha){
            case 1:
                cout << "insira o novo valor: ";
                cin >> valorAux;
                insere(valorAux, p);
                cout << endl << "insercao concluida!" << endl;
                numValores++;
                break;
            case 2:
                remove(p);
                cout << "remocao concluida!" << endl;
                numValores--;
                break;
            case 3:
                cout << "insira o novo para a busca: ";
                cin >> valorAux;
                p = busca(valorAux, le);
                break;
            case 4:
                imprima(le, numValores);
                break;
            case 5:
                cout << "encerrando o programa, aguarde!" << endl;
                break;
            default:
                cout << "operecao invalida!" << endl;
                break;
        }

    }while(escolha != 5);

    free(p);
    free(le);

    return 0;
}