/*==========================================
==  Universidade Federal de Minas Gerais  ==
==  Departamento de Ciência da Computação ==
==  Algoritmos e Estruturas de Dados III  ==
==  Valéria Pereira de Souza 2016/118541  ==
==  Trabalho Prático 2 - Sugestões Doodle ==
============================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "edit_distance.h"
 
int main (){

	int i, j, qtdStrings, maxEdit;
	
	char padrao[6001], string[6001]; 
	scanf("%d %d", &qtdStrings, &maxEdit);
	scanf("%s", padrao);

	//Cria vetor resposta ----------------------------------------
	int aux = strlen(padrao)+maxEdit+1; //comprimento máximo do vetor de char, mais o espaço para guardar "edit"

	char **resposta = (char**) malloc(qtdStrings * sizeof(char*));

	for(i=0; i<qtdStrings; i++){
		resposta[i] = (char*) malloc(aux * sizeof(char));
		resposta[i][0] = -1;
	}


	//Verifica palavras-------------------------------------------
	int k=0, auxS, vale, edits;
	for(i=0; i<qtdStrings; i++){
		scanf("%s", string);
		vale = vale_a_pena(padrao, string, maxEdit);

		if(vale){
			edits = edit_distance(padrao, string);
			if(edits <= maxEdit){
				resposta[k][0] = edits+48;		//guarda 'edits' na primeira casa da string
				
				auxS = strlen(string);
				for(j=0; j<auxS; j++)			//copia a string concatenando com o valor de 'edits'
					resposta[k][j+1] = string [j];
				k++;							//atualiza última casa preenchida do vetor resposta
			}
		}	
	}

	//Ordena -----------------------------------------------------
	qsort(resposta, k, sizeof(char *), cstring_cmp);


	//Ajusta e Imprime -------------------------------------------
	for(i=0; i<k; i++){							//Retorna o início da string para o índice 0 
		for(j=0; j<aux; j++)
			resposta[i][j] = resposta[i][j+1];
		resposta[i][j+1]='\0';
	}

	for(i=0; i<k; i++)			
		printf("%s\n", resposta[i]);


	// Libera estrutura -----------------------------------------
	for(i=0; i<qtdStrings; i++)
		free(resposta[i]);
	free(resposta);

	return 0;

}