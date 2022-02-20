//Candidato: Lucas de Moura Costa. Questão 1 do desafio de programação.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
	int N;
	int aux;
	
	printf("n = ");
	scanf("%d", &N);
	printf("\n");
	
	for (int i = N; i >= 1; i--){
		aux = i;
		
		for(int j = 1; j <= N; j++){
			if(j < aux){
				printf(" ");
			}else{
				printf("*");
			}
		}
		
		if(i > 1){
			printf("\n");
		}
	}
	printf("\n");
	system("PAUSE");
}