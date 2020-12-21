#include <iostream>
#include <conio.h>

/*
	MIGUEL HELLMANN PREUSS (18200573)
	PROGRAMAÇÃO DE SISTEMAS AUTOMATIZADOS 2020.1
	LISTA 3
*/
int paraMaiusculo(char minusculo) {
	return minusculo <= 122 && minusculo >= 97 ? minusculo - 32 : minusculo;
}

int fatorial(int n);

void som(){
	printf("\a");
}
int main(int argc, char** argv) {
	
	int questao = 3;
		
	if (questao == 1) {
		while(true) if (getche() == 32) som();
	}
	else if (questao == 2) printf("\nMaiusculo: %c\n", paraMaiusculo(getche()));
	else if (questao == 3){
		int n;
		printf("Escreva um numero: ");
		scanf("%d", &n);
		printf("\nFatorial %d", fatorial(n));
	}
	return 0;
}
int fatorial(int n){
    if(n > 1)
      return n * fatorial(n - 1);
    else 
      return 1;
 } 







































