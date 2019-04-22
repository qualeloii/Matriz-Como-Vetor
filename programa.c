#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Header.h"

int main (void){
    float *MatrizA,*MatrizB,*MatrizC,*aux_transposta;
    char url_A[50],url_B[50];
    int ColA,ColB,LinA,LinB,k,escolha;
    bool operation = true;

    printf("Diretorio da Matriz A:\t");
    gets(url_A);
    MatrizA = Matriz_Arquivo(url_A);
    LinA = LinhaMatriz(url_A);
    ColA = ColunaMatriz(url_A);
    printf("Diretorio da Matriz B:\t");
    gets(url_B);
    MatrizB = Matriz_Arquivo(url_B);
    LinB = LinhaMatriz(url_B);
    ColB = ColunaMatriz(url_B);
    Sleep(1000);
    system("cls");
        while (operation){
            system("cls");
                // MOSTRAR MATRIZES //
            printf("\n \t\tMatriz A:\n");
            MostraMatrizNormal(LinA,ColA,MatrizA);
            MostraVetor(LinA,ColA,MatrizA);
            printf("\n\n\t\tMatriz B:\n");
            MostraMatrizNormal(LinB,ColB,MatrizB);
            MostraVetor(LinB,ColB,MatrizB);
                // TERMINA DE MOSTRAR MATRIZES
            printf("\n 1 - A x B \t 2- Transposta de A \t 3- A x Transposta de B \t 4- Ttriangular Superior de A \n 5- Diagonal de A \t 6- Procurar Linha na Matriz A \t 7- Procurar coluna na Matriz A\n");
            scanf("%d",&escolha);
            switch(escolha){
                case 1:{
                    system("cls");
                    printf("\n AxB:\n");
                    MatrizC = MultiplicaMatriz(LinA,ColA,LinB,ColB,MatrizA,MatrizB);
                    MostraMatrizNormal(LinA,ColB,MatrizC);
                    MostraVetor(LinA,ColB,MatrizC);
                    Sleep(4000);
                    break;}
                case 2:{
                    system("cls");
                    printf("\n\n Transposta de A:\n\n");
                    aux_transposta = Transposta(LinA,ColA,MatrizA);
                    MostraTrasnposta(LinA,ColA,aux_transposta);
                    Sleep(4000);
                    break;}
                case 3:{
                    system("cls");
                    printf("\n\n A x Tansposta de B:\n\n");
                    free(aux_transposta);
                    aux_transposta = Transposta(LinB,ColB,MatrizB);
                    MatrizC = MultiplicaMatriz(LinA,ColA,ColB,LinB,MatrizA,aux_transposta);
                    MostraMatrizNormal(LinA,LinB,MatrizC);
                    MostraVetor(LinA,LinB,MatrizC);
                    Sleep(4000);
                    break;}
                case 4:{
                    system("cls");
                    printf("\n\n Triangular Superior de A:\n\n");
                    free(aux_transposta);
                    aux_transposta = MatrizTriangularSuperior(LinA,ColA,MatrizA);
                    MostraVetorTrriangular(LinA,ColA,aux_transposta);
                    Sleep(4000);
                    break;}
                case 5:{
                    system("cls");
                    printf("\n\n Diagonal de A:\n\n");
                    free(aux_transposta);
                    aux_transposta = DiagonalPrincipal(LinA,ColA,MatrizA);
                    MostraVetorDiagonal(LinA,ColA,aux_transposta);
                    Sleep(4000);
                    break;}
                case 6:{
                    system("cls");
                    printf("\n\n Linha K da Matriz A:\n\n");
                    scanf("%d",&k);
                    free(aux_transposta);
                    aux_transposta = MatrizLinha(LinA,ColA,MatrizA,k);
                    MostraVetorLinha(ColA,aux_transposta);
                    Sleep(4000);
                    break;}
                case 7:{
                    system("cls");
                    printf("\n\n Coluna K da Matriz A:\n\n");
                    scanf("%d",&k);
                    free(aux_transposta);
                    aux_transposta = MatrizColuna(LinA,ColA,MatrizA,k);
                    MostraVetorColuna(LinA,aux_transposta);
                    Sleep(3000);
                    break;}
                default:{
                    system("cls");
                    printf("PROGRAMA ENCERRADO!!!");
                    operation = false;
                    Sleep(1000);
                    break;}
            }
        }
        return 0;
}
