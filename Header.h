#include <stdio.h>
#include <stdlib.h>

float *Matriz_Arquivo(char *url);
int LinhaMatriz(char *url);
int ColunaMatriz(char *url);
float *MultiplicaMatriz (int LinhaA,int ColunaA,int LinhaB,int ColunaB,float *MatrizA,float *MatrizB);
float *Transposta(int linha,int coluna,float*vetor);
float *DiagonalPrincipal(int Linha,int Coluna,float *vetor);
float *MatrizLinha(int Linha,int Coluna,float *vetor,int k);
float *MatrizColuna(int Linha,int Coluna,float *vetor,int k);
float *MatrizTriangularSuperior(int Linha,int Coluna,float *vetor);
void MostraMatrizNormal(int Linha,int Coluna,float *vetor);
void MostraVetor(int Linha,int Coluna,float *vetor);
void MostraTrasnposta(int Linha,int Coluna,float *aux);
void MostraVetorTrriangular(int Linha,int Coluna,float *vetor);
void MostraVetorDiagonal(int Linha,int Coluna,float *vetor);
void MostraVetorLinha(int Coluna,float *vetor);
void MostraVetorColuna(int Linha,float *vetor);
