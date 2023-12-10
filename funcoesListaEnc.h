#ifndef FUNCOESLISTAENC_H_INCLUDED
#define FUNCOESLISTAENC_H_INCLUDED


typedef struct item Item;
typedef struct listaDupl ListaDupl;
typedef struct celula Celula;

//Cria uma lista vazia
ListaDupl *criaListaDuplVazia();
void inserirInicio(ListaDupl *ld, int chave, char valorDaCarta, int cartaAcertada);
void inserirMeio(ListaDupl *ld, int chaveB, int chaveI, char valorDaCarta, int cartaAcertada);
void inserirFinal(ListaDupl *ld, int chave, char valorDaCarta, int cartaAcertada);
Celula *buscaChave(ListaDupl *ld, int chave);
void imprimeEsqDir(ListaDupl *ld);
void imprimeDirEsq(ListaDupl *ld);
void removePorChave(ListaDupl *ld, int chave);
int verificaListaDuplVazia(ListaDupl *ld);
void liberaListaDupl(ListaDupl *ld);
Celula *buscaCarta(ListaDupl *ld, char valorDaCarta);
void embaralhaLetra(ListaDupl *ld, int tam);
void imprimeEsqDirCartaVirada(ListaDupl *ld);
void imprimeCartaEscolhidaVirada(ListaDupl *ld, int escolhaCarta1);
void imprimeCartasAcertadas(ListaDupl *ld);
void interpretaCarta(ListaDupl *ld, int escolhaCarta1, int escolhaCarta2, int *vidas,int *acertos);
int verificaCartaJaAcertada(ListaDupl *ld, int cartaEscolhida);
#endif // FUNCOESLISTAENC_H_INCLUDED
