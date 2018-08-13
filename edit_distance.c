#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

int vale_a_pena(char *padrao, char *string, int maxEdit){
 	int lenPadrao, lenString;
 	
 	lenPadrao=strlen(padrao);
 	lenString=strlen(string);

 	if(lenString > (lenPadrao+maxEdit) || lenString < (lenPadrao-maxEdit))
 		return 0;
 	
  	return 1;
}

int minimo(int a, int b, int c){

	int min = a;
	if(b<a)
		min=b;
	if(c<b)
		min=c;
	return min;
}

int edit_distance(char *padrao, char *string){

	int i, j, auxS, auxP, **matriz, min, edits;

	//Cria matriz de memorização =========================================
	auxP = strlen(padrao);
	matriz = (int**) malloc((auxP+1) * sizeof(int*));

	auxS = strlen(string);
	for(i=0; i< auxP+1; i++)
		matriz[i] = (int*) malloc((auxS+1) * sizeof(int));

	//inicializa primeira linha e primeira coluna =====================
	for(j=0; j < auxS+1; j++)
		matriz[0][j] = j;
	for(i=0; i < auxP+1; i++)
		matriz[i][0] = i;


	//preencher demais células ========================================
	for(i=1; i< auxP+1; i++){
		for(j=1; j<auxS+1; j++){
			if(string[j-1]==padrao[i-1])
				matriz[i][j]=matriz[i-1][j-1];
			else{			
				min = minimo(matriz[i-1][j-1], matriz[i-1][j], matriz[i][j-1]);
				matriz[i][j]= (min + 1);
			}
		}
	}

	edits = matriz [auxP][auxS];

	for(i=0; i < auxP+1; i++)
		free(matriz[i]);
	free(matriz);



	return edits;
}

int cstring_cmp(const void *a, const void *b){ 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
} 
