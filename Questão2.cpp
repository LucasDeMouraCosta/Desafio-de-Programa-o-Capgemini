//Candidato: Lucas de Moura Costa. Questão 2 do desafio de programação.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char senha[100];
	int Nmin = 0;
	char caracteresEsp[] = "!@#$%^&*()-+";
	bool digito = false;
	bool letraMin= false;
	bool letraMai = false;
	bool CarEspecial = false;
	
	scanf("%s", senha);
		
	//Verificando por dígito
	for (int i = 0; i < strlen(senha); i++){
		if(isdigit(senha[i]))
		digito = true;
	}
	if(!digito){
		Nmin++;
	}
	
	//Verificando por letra minuscula
	for (int i = 0; i < strlen(senha); i++){
		if(islower(senha[i]))
		letraMin = true;
	}
	if(!letraMin){
		Nmin++;
	}
	
	//Verificando por letra maiuscula
	for (int i = 0; i < strlen(senha); i++){
		if(isupper(senha[i]))
		letraMai = true;
	}
	if(!letraMai){
		Nmin++;
	}
	 
	//Verificando por caractere especial 
	for (int i = 0; i < strlen(senha); i++){
		for (int j = 0; j < strlen(caracteresEsp); j++ ){	
			if( senha[i] == caracteresEsp[j] ){
				CarEspecial = true;
			}	
		}	
	}
	if(!CarEspecial){
		Nmin++;
	}	

	
		
	if(Nmin + strlen(senha) < 6){		//Verificando se o requisito de 6 caracteres é atendido com o numero minino,							
		Nmin = (6 - strlen(senha)); 	//caso não seja o numero minimo é redefinido.
	}	
	
	printf("\n%d\n", Nmin);
	system("PAUSE");
}
	