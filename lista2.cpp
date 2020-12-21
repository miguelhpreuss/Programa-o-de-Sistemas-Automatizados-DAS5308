#include <iostream>
#include <conio.h>


/*
	MIGUEL HELLMANN PREUSS (18200573)
	PROGRAMAÇÃO DE SISTEMAS AUTOMATIZADOS 2020.1
	LISTA 2
*/

int main(int argc, char** argv) {
	
	int questao = 3;
	
	if (questao == 1){
		char tecla;
		while(int(tecla) != 27){
			printf("\nPressione uma tecla: ");
			tecla = getche();
			printf("\nTecla Decimal: %d\nTecla Hexadecimal: %x\n", tecla, tecla);
		}
	}
	else if (questao == 2){
		int tamanho = 5;
		int c1 = 177;
		int c2 = 178;
		for (int i = 0; i < (tamanho*(tamanho+1)); i++){
			if (i % (tamanho + 1) == 0) {
				printf("\n");
				int temp = c1;
				c1 = c2;
				c2 = temp;
			}
			else printf("%c", i % 2 ? c1 : c2);
		}
	}
	else if (questao == 3){
		//FOR
		int n;
		long int fatorial_for = 1;
		long int fatorial_while = 1;
		printf("Escreva um numero: ");
		scanf("%i", &n);
		
		for (int i = n; i > 0; i--){
			fatorial_for *= i;
		}
		printf("\n[for] Fatorial: %i", fatorial_for);
		//WHILE
		int j = n;
		while(j > 0){
			fatorial_while *= j;
			j--; 
		}
		printf("\n[while] Fatorial: %i", fatorial_while);
	}
	return 0;
}
