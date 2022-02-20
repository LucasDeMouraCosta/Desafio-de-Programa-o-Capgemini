//Candidato: Lucas de Moura Costa. Questão 3 do desafio de programação.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void ordenar(char *a, int MAX){ //Função para ordenar os conjuntos de letras(Exemplo: dafa -> aadf),
	int i, j, tmp;				//Trata os caracteres como os seus respectivos valores da tabela ASCII
								//Com isso é possível deixar os blocos de mesma quantidade de caracteres iguais. 
	for(i = 1; i < MAX; i++)
	{
	tmp = a[i];
	for(j = i-1; j >= 0 && tmp < a[j]; j--)
	{
	a[j+1] = a[j];
	}
	a[j+1] = tmp;
	}
}


int main(){
	char S[100];
	int N_anag = 0;
	char Anag[1000][100];
	int aux3 = 0;
	int N = 0;	
	
	scanf("%s", S);
	
	while(S[N] != '\0'){
		S[N] = tolower(S[N]);//Passando todas as letras da string de entrada para minusculas
		N++;
	}
	
	//Zerando os vetor de strings(Necessário pois estavam ocorrendo falhas na gravação que é feita mais a frente no código)
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 100; j++){
			Anag[i][j] = '\0';
		}
	}
	
	//para apenas um caracttere
	for(int i = 0; i < strlen(S); i++){
		bool teste = false;
		for(int z = 0; z < i; z++){ //loop para identificar se a letra já foi contada anteriormente.
			if(S[i] == S[z]){
				teste = true;
			}
		}
		
		if(!teste){
			for(int j = i+1; j < strlen(S); j++){//Contagem de letras iguais
				
				if(S[i] == S[j]){
					N_anag++;
					j = strlen(S); //Necessário para que um anagrama que se repete mais de 2 vezes seja contado apenas como um par. 
				}
			}
		}
	}		
	
	//para sequências de caracteres iguais, independente da posição
	for(int i = 2; i < strlen(S); i++){
		for(int j = 0; j < strlen(S); j++){
			int aux = 0;
			
			if((aux+j) < strlen(S)-i+1){ //Serve para separar os blocos de 2 caracteres, depois 3, 4, 5...
			
				do{
					Anag[j][aux] = S[j+aux];
					aux++;
				}while(aux < i);
				
				aux3 = j+1;
				ordenar(Anag[j], aux);          //Após a separação dos blocos usa a função para ordenar os caracteres em ordem alfabetica,
												//Assim blocos que contém os mesmos caracteres ficam iguais, o que facilita a conferência
			}									//dos anagramas.		
		}
		
		for(int z = 0; z < aux3; z++){
			bool teste = false;
			for(int x = 0; x < z; x++){				//Loop para identificar se o bloco de caracteres já foi contado antes.
				if(strcmp(Anag[z], Anag[x]) == 0){
					teste = true;
				}
			}
			
			if(!teste){
				for(int j = z+1; j < aux3; j++){
					if(strcmp(Anag[z], Anag[j]) == 0){	//Contagem dos blocos de caracteres iguais.
						N_anag++;
						j = aux3;	//Necessário para que um anagrama que se repete mais de 2 vezes seja contado apenas como um par. 	
					}
				}
			}
		}
	}				
	
	printf("\n%d\n", N_anag);
	system("PAUSE");
	
}