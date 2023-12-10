#include <stdio.h>
#include <stdlib.h>
#include "funcoesListaEnc.h"
#include <string.h>
#include <time.h>
#include <windows.h>
#define VERMELHO "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[34m"
#define RESET   "\x1b[0m"

int main()
{
    int escolhaNivel;
    int escolhaCarta1;
    int escolhaCarta2;
    int vidas;
    int acertos = 0;
    int tam;
    char repete;

    ListaDupl *ld = criaListaDuplVazia();
    printf(AZUL "BEM VINDO AO JOGO DA MEMORIA DO ALFABETO!!" AZUL);

    do
    {
        printf("\nEscolha o nivel que deseja jogar:\n[1] - Lvl 1\n[2] - Lvl 2\n[3] - Lvl 3\nEscolha: ");
        scanf("%d", &escolhaNivel);

        switch (escolhaNivel)
        {
        case 1:
            vidas = 5;
            tam = 12;
            embaralhaLetra(ld, tam);
            printf("Memorize as cartas:\n\n");
            imprimeEsqDir(ld);

            do
            {
                sleep(5);
                system("cls");
                imprimeCartasAcertadas(ld);
                printf("Voce tem %d vidas e %d acertos!!\n", vidas,acertos);
                do
                {
                    printf("Escolha um numero correspondente a sua carta (0 a %d): ", tam - 1);
                    scanf("%d", &escolhaCarta1);
                    if(verificaCartaJaAcertada(ld,escolhaCarta1)==1)
                    {
                        printf(VERMELHO "Voce já escolheu esta carta, escolha outra!!\n" RESET);
                    }
                }
                while(verificaCartaJaAcertada(ld,escolhaCarta1)==1);
                imprimeCartaEscolhidaVirada(ld, escolhaCarta1);
                do
                {
                    printf("Voce virou a carta %d, vire outra: ", escolhaCarta1);
                    scanf("%d", &escolhaCarta2);
                    if(verificaCartaJaAcertada(ld,escolhaCarta2)==1)
                    {
                        printf(VERMELHO "Voce jA escolheu esta carta, escolha outra!!\n" RESET);
                    }
                }
                while(verificaCartaJaAcertada(ld,escolhaCarta2)==1);
                imprimeCartaEscolhidaVirada(ld, escolhaCarta2);
                interpretaCarta(ld, escolhaCarta1, escolhaCarta2, &vidas, &acertos);

            }
            while (vidas != 0 && acertos != 6);
            if(vidas == 0)
            {
                printf(VERMELHO "GAME OVER!!" RESET);
            }
            else if(acertos ==6)
            {
                printf(VERDE "PARABÉNS, VOCE ACERTOU TODAS AS CARTAS!!" RESET);
            }
            break;
        case 2:
            vidas = 7;
            tam = 18;
            embaralhaLetra(ld, tam);
            printf("Memorize as cartas:\n\n");
            imprimeEsqDir(ld);

            do
            {
                sleep(5);
                system("cls");
                imprimeCartasAcertadas(ld);
                printf("Voce tem %d vidas e %d acertos!!\n", vidas,acertos);
                do
                {
                    printf("Escolha um numero correspondente a sua carta (0 a %d): ", tam - 1);
                    scanf("%d", &escolhaCarta1);
                    if(verificaCartaJaAcertada(ld,escolhaCarta1)==1)
                    {
                        printf(VERMELHO "Voce já escolheu esta carta, escolha outra!!\n" RESET);
                    }
                }
                while(verificaCartaJaAcertada(ld,escolhaCarta1)==1);
                imprimeCartaEscolhidaVirada(ld, escolhaCarta1);
                do
                {
                    printf("Voce virou a carta %d, vire outra: ", escolhaCarta1);
                    scanf("%d", &escolhaCarta2);
                    if(verificaCartaJaAcertada(ld,escolhaCarta2)==1)
                    {
                        printf(VERMELHO "Voce ja escolheu esta carta, escolha outra!!\n" RESET);
                    }
                }
                while(verificaCartaJaAcertada(ld,escolhaCarta2)==1);
                imprimeCartaEscolhidaVirada(ld, escolhaCarta2);
                interpretaCarta(ld, escolhaCarta1, escolhaCarta2, &vidas, &acertos);

            }
            while (vidas != 0 && acertos != 9);
            if(vidas == 0)
            {
                printf(VERMELHO "GAME OVER!!" RESET);
            }
            else if(acertos ==9)
            {
                printf(VERDE "PARABÉNS, VOCE ACERTOU TODAS AS CARTAS!!" RESET);
            }
            break;
        case 3:
            vidas = 9;
            tam = 24;
            embaralhaLetra(ld, tam);
            printf("Memorize as cartas:\n\n");
            imprimeEsqDir(ld);

            do
            {
                sleep(5);
                system("cls");
                imprimeCartasAcertadas(ld);
                printf("Voce tem %d vidas e %d acertos!!\n", vidas,acertos);
                do
                {
                    printf("Escolha um numero correspondente a sua carta (0 a %d): ", tam - 1);
                    scanf("%d", &escolhaCarta1);
                    if(verificaCartaJaAcertada(ld,escolhaCarta1)==1)
                    {
                        printf(VERMELHO "Voce já escolheu esta carta, escolha outra!!\n" RESET);
                    }
                }
                while(verificaCartaJaAcertada(ld,escolhaCarta1)==1);
                imprimeCartaEscolhidaVirada(ld, escolhaCarta1);
                do
                {
                    printf("Voce virou a carta %d, vire outra: ", escolhaCarta1);
                    scanf("%d", &escolhaCarta2);
                    if(verificaCartaJaAcertada(ld,escolhaCarta2)==1)
                    {
                        printf(VERMELHO "Voce ja escolheu esta carta, escolha outra!!\n" RESET);
                    }
                }
                while(verificaCartaJaAcertada(ld,escolhaCarta2)==1);
                imprimeCartaEscolhidaVirada(ld, escolhaCarta2);
                interpretaCarta(ld, escolhaCarta1, escolhaCarta2, &vidas, &acertos);

            }
            while (vidas != 0 && acertos != 12);
            if(vidas == 0)
            {
                printf(VERMELHO "GAME OVER!!" RESET);
            }
            else if(acertos ==12)
            {
                printf(VERDE "PARABÉNS, VOCE ACERTOU TODAS AS CARTAS!!" RESET);
            }

            break;
        default:
            printf("Escolha invalida");
            break;
        }
        printf("\nVocê deseja jogar novamente?(S/s): ");
        setbuf(stdin, NULL);
        scanf("%c", &repete);
    }
    while(repete == 'S' || repete == 's');
    liberaListaDupl(ld);
    return 0;
}

