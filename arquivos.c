#include <stdio.h>
#include <stdlib.h>

float *Matriz_Arquivo(char *url){
    FILE *arquivo;
    float *vetor;
    int n,m,i;
    arquivo = fopen(url, "r");

    if (arquivo != NULL){
        fscanf(arquivo,"%d %d",&n,&m); // NUMERO DE LINHAS E COLUNAS
        vetor = (float*)malloc(sizeof(float*)*(m*n));

       for (i=0; i<m*n; i++){
        fscanf(arquivo,"%f",&vetor[i]);
       }
       fclose(arquivo);
       return vetor;
    }
    else {
        printf("Diretorio do arquivo inválido!");
        return NULL;
    }
}
int LinhaMatriz(char *url){
    int n;
    FILE *arquivo;
    arquivo = fopen(url, "r");
    if (arquivo != NULL){
        fscanf(arquivo,"%d",&n); // NUMERO DE LINHAS E COLUNAS
        fclose(arquivo);
        return n;}
    else {
        printf("Diretorio do arquivo inválido!");
        return -1;
    }
}
int ColunaMatriz(char *url){
    int n,m;
    FILE *arquivo;
    arquivo = fopen(url, "r");
    if (arquivo != NULL){
        fscanf(arquivo,"%d %d",&n,&m); // NUMERO DE LINHAS E COLUNAS
        fclose(arquivo);
        return m;}
    else {
        printf("Diretorio do arquivo inválido!");
        return -1;
    }
}
