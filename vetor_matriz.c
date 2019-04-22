#include <stdio.h>
#include <stdlib.h>

float *Transposta(int linha,int coluna,float*vetor){
        float *aux;
        int i,j,tamanho;
        tamanho = linha*coluna;

        aux = (float*)malloc(tamanho*sizeof(float));
        for ( i=0; i<coluna; i++){
            for (j=0;j<linha;j++){
                aux[i*linha+j] = vetor[i+coluna*j];
            }
        }
        return aux;
}
float *MultiplicaMatriz (int LinhaA,int ColunaA,int LinhaB,int ColunaB,float *MatrizA,float *MatrizB){
    float *MatrizC;
    int i,j,k,tamanho;

    if (ColunaA == LinhaB){
        tamanho = LinhaA * ColunaB;
        // ALOCACAO DINAMICA
        MatrizC = (float*)malloc(tamanho*sizeof(float));
        // FIM DA ALOCACAO
        for (i=0; i<LinhaA; i++){
            for (j=0; j<ColunaB; j++){
                MatrizC[i*ColunaB+j] = 0;
                for (k=0; k<ColunaA; k++){
                    MatrizC[i*ColunaB+j] += MatrizA[i*ColunaA+k] * MatrizB[j+ColunaB*k];
                }

            }
        }
        return MatrizC;
    }
    else {
            printf("NUMERO DE COLUNAS DE 'A' INCOMPATÍVEL COM NUMERO D ELINHA DE 'B'");
            return NULL;
    }
}
float *DiagonalPrincipal(int Linha,int Coluna,float *vetor){
    float *Diagonal;
    int i;
    Diagonal = (float*)malloc(sizeof(float)*Coluna);

    int j = 0;
    for (i=0; i<Coluna; i++){
        Diagonal[i] = vetor[i*Coluna+j];
        j++;
    }
    return Diagonal;
        /*printf("\n-------------------DIAGONAL------------------------\n");
        for ( i=0; i<Linha; i++){
            printf("%.1f \t",Diagonal[i]);
        }*/
}
float *MatrizLinha(int Linha,int Coluna,float *vetor,int k){
    float *LinhadaMatriz;
    LinhadaMatriz = (float*)malloc(sizeof(float)*Coluna);
    int i;

    for(i=0; i<Coluna; i++){
            LinhadaMatriz[i] = vetor[(Coluna*(k-1))+i];
    }
    return LinhadaMatriz;
        /*printf("\n-------------------LINHA K------------------------\n");
        for ( i=0; i<Coluna; i++){
            printf("%.1f \t",LinhadaMatriz[i]);
        }*/

}
float *MatrizColuna(int Linha,int Coluna,float *vetor,int k){
    float *ColunadaMatriz;
    ColunadaMatriz = (float*)malloc(sizeof(float)*Linha);
    int i;

    for(i=0; i<Linha; i++){
            ColunadaMatriz[i] = vetor[Coluna*i+(k-1)];
    }
    return ColunadaMatriz;
        /*printf("\n-------------------Coluna K------------------------\n");
        for ( i=0; i<Linha; i++){
            printf("%.1f \t",ColunadaMatriz[i]);
        }*/

}
float *MatrizTriangularSuperior(int Linha,int Coluna,float *vetor){
    float *Triangular;
    int tamanho = (((Linha * Coluna) - Coluna) / 2);
    Triangular = (float*)malloc(sizeof(float)*tamanho);
    int aux = 0;

    int i,j;
    for (i=0; i<Linha; i++){
        for (j=i+1; j<Coluna; j++){
            Triangular[aux] = vetor[i*Coluna+j];
            aux++;
        }
    }
    return Triangular;
        /*printf("\n-------------------TRIANGULAR-------------------------------------\n");
        for ( i=0; i<tamanho; i++){
            printf("%.1f \t",Triangular[i]);
        }*/
}
void MostraMatrizNormal(int Linha,int Coluna,float *vetor){
    int i,j;
    printf("-----------------------------------------------NORMAL----------------------------------------------\n");
        for ( i=0; i<Linha; i++){
            for (j=0;j<Coluna;j++){
                printf("%.1f \t",vetor[i*Coluna+j]);
            }
            printf("\n");
        }
}
void MostraVetor(int Linha,int Coluna,float *vetor){
    int i;
    printf("\n-----------------------------------------------VETOR----------------------------------------------\n");
    for ( i=0; i<Linha*Coluna; i++){
            printf("%.1f \t",vetor[i]);
        }
    printf("\n");
}
void MostraTrasnposta(int Linha,int Coluna,float *aux){
    int i,j;
printf("-----------------------------------------------TRANSPOSTA de A:----------------------------------------------\n");
        for ( i=0; i<Coluna; i++){
            for (j=0;j<Linha;j++){
                printf("%.1f \t",aux[i*Linha+j]);
            }
            printf("\n");
        }
        printf("-----------------------------------------------VETOR----------------------------------------------\n");
        for ( i=0; i<Linha*Coluna; i++){
            printf("%.1f \t",aux[i]);
        }
}
void MostraVetorTrriangular(int Linha,int Coluna,float *vetor){
    printf("-----------------------------------------------TRIANGULAR----------------------------------------------\n");
    if (Linha == Coluna){
        int tamanho = (((Linha * Coluna) - Coluna) / 2);
        int i;
            for ( i=0; i<tamanho; i++){
                printf("%.1f \t",vetor[i]);
            }
    }
    else{
        printf("MATRIZ INCOMPATIVEL! POR FAVOR INSIRA UMA MATRIZ QUADRADA!!!!");
    }
}
void MostraVetorDiagonal(int Linha,int Coluna,float *vetor){
    int i;
     printf("-----------------------------------------------DIAGONAL----------------------------------------------\n");
        for ( i=0; i<Coluna; i++){
            printf("%.1f \t",vetor[i]);
        }
}
void MostraVetorLinha(int Coluna,float *vetor){
    int i;
    printf("-----------------------------------------------LINHA DE K----------------------------------------------\n");
        for ( i=0; i<Coluna; i++){
            printf("%.1f \t",vetor[i]);
        }
}
void MostraVetorColuna(int Linha,float *vetor){
    int i;
    printf("-----------------------------------------------COLUNA DE K----------------------------------------------\n");
        for ( i=0; i<Linha; i++){
            printf("%.1f \t",vetor[i]);
        }
}
