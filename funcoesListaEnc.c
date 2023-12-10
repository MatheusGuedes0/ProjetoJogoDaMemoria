#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "funcoesListaEnc.h"
#define VERMELHO "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[34m"
#define RESET   "\x1b[0m"

struct item
{
    int chave; //chave que representa um numero para o usuário escolher
    char valorDaCarta; //valor da carta que representa uma letra
    int cartaAcertada; //valor boolean que indica se a carta já foi acertada ou não
};

struct celula
{
    Item item;
    Celula *ant; //A célula também guarda quem é a sua anterior
    Celula *prox;
};

struct listaDupl
{
    Celula *primeira;
};

//Cria uma lista vazia
ListaDupl *criaListaDuplVazia()
{
    ListaDupl *ld = malloc(sizeof(ListaDupl));
    ld->primeira = NULL;
    return ld;
}

//adiciona um elment no início da lista
void inserirInicio(ListaDupl *ld, int chave, char valorDaCarta, int cartaAcertada)
{
    //criar novo item que vai ser guardado na fila
    Item novo;
    novo.chave = chave;
    novo.valorDaCarta =  valorDaCarta;
    novo.cartaAcertada = cartaAcertada;
    //cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->ant = NULL;
    nova->prox = ld->primeira;
    //se a lista não está vazia, a anterior da que era a primeira será a nova
    if (!verificaListaDuplVazia(ld)) //se está vazia adiciona no início
    {
        ld->primeira->ant = nova;
    }
    ld->primeira = nova;
}

//adiciona um elemento no meio da listaDupl
void inserirMeio(ListaDupl *ld, int chaveB, int chaveI, char valorDaCarta, int cartaAcertada)
{
    Celula *anterior = buscaChave(ld, chaveB);

    if (anterior == NULL)
    {
        printf("Chave nao encontrada ou lista vazia.\n");
        return;
    }
    //criar novo item que vai ser guardado na fila
    Item novo;
    novo.chave = chaveI;
    novo.valorDaCarta = valorDaCarta;
    novo.cartaAcertada = cartaAcertada;
    Celula *proxima = anterior->prox;
    //cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->ant = anterior;
    nova->prox = proxima;
    anterior->prox = nova;
    if (proxima != NULL) //somente caso próxima não seja NULL, pois a NULL não tem anterior
    {
        proxima->ant = nova;
    }
}

//adiciona um elemento no final da lista
void inserirFinal(ListaDupl *ld, int chave, char valorDaCarta, int cartaAcertada)
{
    if (verificaListaDuplVazia(ld))
    {
        inserirInicio(ld, chave, valorDaCarta,cartaAcertada);
    }
    else
    {
        //criar noov item que vai ser guardado na fila
        Item novo;
        novo.chave = chave;
        novo.valorDaCarta = valorDaCarta;
        novo.cartaAcertada = cartaAcertada;
        //cria nova célula que vai guardar o item
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        nova->prox = NULL;
        Celula *ultima = ld->primeira;
        while (ultima->prox != NULL)
        {
            ultima = ultima->prox;
        }
        nova->ant = ultima;
        ultima->prox = nova;
    }
}

//Busca por chave na lista
Celula *buscaChave(ListaDupl *ld, int chave)
{
    Celula *aux = ld->primeira;
    while (aux != NULL && aux->item.chave != chave)
    {
        aux = aux->prox;
    }
    return aux;
}

//imprime a Lista Duplamente Encadeada da equerda para direita
void imprimeEsqDir(ListaDupl *ld)
{
    int cont=0;
    Celula *aux = ld->primeira;
    while (aux != NULL)
    {
        printf("%c|", aux->item.valorDaCarta);
        cont++;
        if(cont>2)
        {
            printf("\n");

            cont=0;
        }
        aux = aux->prox;
    }
}


//imprime a Lista Duplamente Encadeada da direita para esquerda
void imprimeDirEsq(ListaDupl *ld)
{
    //ir até a última célula
    Celula *aux = ld->primeira;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    while (aux != NULL)
    {
        printf("%c|", aux->item.valorDaCarta);
        aux = aux->ant;
    }
}


//remove um item da lista duplamente encadeada
void removePorChave(ListaDupl *ld, int chave)
{
    Celula *remover = buscaChave(ld, chave);
    if (remover == NULL)
    {
        printf("Item nao encontrado ou lista vazia.\n");
        return;
    }
    if (remover->ant == NULL && remover->prox == NULL) //é a única, ou seja, a primeira
    {
        ld->primeira = NULL;
    }
    else if (remover == ld->primeira) //remover do início
    {
        ld->primeira = remover->prox;
        ld->primeira->ant = NULL;
    }
    else //remover do meio
    {
        Celula *proxima = remover->prox;
        Celula *anterior = remover->ant;
        anterior->prox = proxima;
        if (proxima != NULL)
        {
            proxima->ant = anterior;
        }
    }
    free(remover);
}

//retorna 1 se a lista está vazia ou 0 se não está vazia
int verificaListaDuplVazia(ListaDupl *ld)
{
    return ld->primeira == NULL;
}

//libera da memória
void liberaListaDupl(ListaDupl *ld)
{
    Celula *aux = ld->primeira;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(ld);
}

//funções do jogo
Celula *buscaCarta(ListaDupl *ld, char valorDaCarta)
{
    Celula *aux = ld->primeira;
    while (aux != NULL && aux->item.valorDaCarta != valorDaCarta)
    {
        aux = aux->prox;
    }
    return aux;
}

void embaralhaLetra(ListaDupl *ld, int tam)
{
    srand(time(NULL));
    char letra;
    int vetor[tam/2];
    int vetorPosicaoAleatoria[tam/2];
    int j=0;
    int k=0;
    int tamRand = tam/2;


    for(int i=0; i<tam/2; i++)
    {
        letra = rand() % (90 - 65 + 1) + 65; //pega as letras maisculas da tabela ASC
        vetorPosicaoAleatoria[i] = rand() % (tam/2);
        vetor[i] = letra;
        inserirFinal(ld,i,letra,0);
    }
    for(int i=tamRand; i<tam; i++)
    {

        inserirMeio(ld,vetorPosicaoAleatoria[rand() % (tam/2)],i,vetor[j],0);
        j++;
    }
      Celula *aux = ld->primeira;
    while(aux!=NULL)
    {
       aux->item.chave = k;
        aux = aux->prox;
        k++;
    }



}
void imprimeEsqDirCartaVirada(ListaDupl *ld)
{
    int cont=0;
    Celula *aux = ld->primeira;
    printf("__________\n");
    while (aux != NULL)
    {
        printf("|%2d", aux->item.chave);
        cont++;
        if(cont>2)
        {
            printf("|\n|__|__|__|\n");

            cont=0;
        }
        aux = aux->prox;
    }
}
void imprimeCartaEscolhidaVirada(ListaDupl *ld, int escolhaCarta1)
{
    int cont = 0;

    Celula *aux = ld->primeira;
    Celula *carta = buscaChave(ld,escolhaCarta1);
    carta->item.cartaAcertada = 1;
    printf("__________\n");
    while (aux != NULL)
    {
        if (aux->item.cartaAcertada == 1)
        {
            // Imprime o valor da carta escolhida
            printf(AZUL "| %c" RESET, aux->item.valorDaCarta);
        }
        else
        {
            // Imprime o valor da chave para as outras cartas
            printf("|%2d", aux->item.chave);
        }

        cont++;

        if (cont > 2)
        {
            printf("|\n|__|__|__|\n");
            cont = 0;
        }

        aux = aux->prox;
    }
}

void imprimeCartasAcertadas(ListaDupl *ld)
{
     int cont = 0;
    Celula *aux = ld->primeira;
    printf("__________\n");
    while (aux != NULL)
    {
        if (aux->item.cartaAcertada == 1)
        {
            // Imprime o valor da carta escolhida
            printf(VERDE "| %c" RESET, aux->item.valorDaCarta);

        }
        else
        {
            // Imprime o valor da chave para as outras cartas
            printf("|%2d", aux->item.chave);
        }

        cont++;

        if (cont > 2)
        {
            printf("|\n|__|__|__|\n");
            cont = 0;
        }

        aux = aux->prox;
    }
}

void interpretaCarta(ListaDupl *ld, int escolhaCarta1, int escolhaCarta2, int *vidas,int *acertos)
{

    Celula *carta1 = buscaChave(ld,escolhaCarta1);
    Celula *carta2 = buscaChave(ld,escolhaCarta2);

    if(carta1->item.valorDaCarta == carta2->item.valorDaCarta)
    {
        printf("VOCE ACERTOU!!\n");
        (*acertos)++;
    }
    else
    {
        printf("VOCE ERROU!!\n");
        carta1->item.cartaAcertada = 0;
        carta2->item.cartaAcertada = 0;
        (*vidas)--;
    }
}

int verificaCartaJaAcertada(ListaDupl *ld, int cartaEscolhida)
{
     Celula *carta = buscaChave(ld,cartaEscolhida);

     if(carta->item.cartaAcertada == 1){
        return 1;
     }
     else
     {
         return 0;
     }
}




