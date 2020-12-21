//#include <iostream>
#include <string.h>
#include <stdio.h>

#define limite 10
void transposta(int m[limite][limite], int mt[limite][limite], int o){
	for (int i = 0, j = 0; i != o - 1 || j != o; j++){
		if (j == o) {
			j = 0;
			i++;
		}
		mt[i][j] = m[j][i];
	}
}


int main(int argc, char** argv) {
	
	int questao = 1;
	
	if (questao == 1){
		int ordem;
		printf("Digite uma ordem para sua matriz (Maximo 10): ");
		scanf("%d", &ordem);
		if (ordem > 10){
			printf("\nUltrapassou o limite");
			return 0;
		}
		printf("\nSua matriz tera ordem %u", ordem);
		int matriz[limite][limite], mtransp[limite][limite];
		for (int i = 0, j = 0; i != ordem - 1 || j != ordem; j++){
			if (j == ordem) {
				j = 0;
				i++;
			}
			printf("\nDigite o valor de posicao [%i][%i] de sua matriz: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
		printf("\nSua matriz:\n");
		for (int i = 0, j = 0; i != ordem - 1 || j != ordem; j++){
			if (j == ordem) {
				j = 0;
				i++;
				printf("\n");
			}
			printf("%i ", matriz[i][j]);
		}
		
		transposta(matriz, mtransp, ordem);
		printf("\n\nSua matriz transposta:\n");
		for (int i = 0, j = 0; i != ordem - 1 || j != ordem; j++){
			if (j == ordem) {
				j = 0;
				i++;
				printf("\n");
			}
			printf("%i ", mtransp[i][j]);
		}
	}
	else if (questao == 2){
		char string[32], letra[2], trocar[2];
		int contador = 0;
		printf("Escreva algum texto de ate 32 caracteres: ");
		gets(string);
		if (strlen(string) > 32){
			printf("Voce excedeu o limite!!!");
			return 0;
		}
		puts(string);
		printf("\nEscreva um caractere: ");
		gets(letra);
		for (int i = 0; i < strlen(string); i++) {
       		if (string[i] == letra[0]) contador++;
    	}
    	printf("\nNesse seu texto aparece %i %s o caractere '%s'!", contador, contador == 1? "vez":"vezes" ,letra);
    	
    	printf("\n\nPor qual letra voce quer trocar? ");
    	gets(trocar);
    	for (int i = 0; i < strlen(string); i++) {
       		if (string[i] == letra[0]) string[i] = trocar[0];
    	}
    	printf("\n%s", string);
	}
	else if (questao == 3 || questao == 4){	
		struct meses {
			char nome[9];
			char abr[3];
			int num;
			int dias;
		}mes[12];
		strcpy(mes[0].nome, "Janeiro");
		strcpy(mes[0].abr, "Jan");
		mes[0].num = 1;
		mes[0].dias = 31;
		
		strcpy(mes[1].nome, "Fevereiro");
		strcpy(mes[1].abr, "Fev");
		mes[1].num = 2;
		mes[1].dias = 28;
		
		strcpy(mes[2].nome, "Marco");
		strcpy(mes[2].abr, "Mar");
		mes[2].num = 3;
		mes[2].dias = 31;
		
		strcpy(mes[3].nome, "Abril");
		strcpy(mes[3].abr, "Abr");
		mes[3].num = 4;
		mes[3].dias = 30;
		
		strcpy(mes[4].nome, "Maio");
		strcpy(mes[4].abr, "Mai");
		mes[4].num = 5;
		mes[4].dias = 31;
		
		strcpy(mes[5].nome, "Junho");
		strcpy(mes[5].abr, "Jun");
		mes[5].num = 6;
		mes[5].dias = 30;
		
		strcpy(mes[6].nome, "Julho");
		strcpy(mes[6].abr, "Jul");
		mes[6].num = 7;
		mes[6].dias = 31;
		
		strcpy(mes[7].nome, "Agosto");
		strcpy(mes[7].abr, "Ago");
		mes[7].num = 8;
		mes[7].dias = 31;
		
		strcpy(mes[8].nome, "Setembro");
		strcpy(mes[8].abr, "Set");
		mes[8].num = 9;
		mes[8].dias = 30;
		
		strcpy(mes[9].nome, "Outubro");
		strcpy(mes[9].abr, "Out");
		mes[9].num = 10;
		mes[9].dias = 31;
		
		strcpy(mes[10].nome, "Novembro");
		strcpy(mes[10].abr, "Nov");
		mes[10].num = 11;
		mes[10].dias = 30;
		
		strcpy(mes[11].nome, "Dezembro");
		strcpy(mes[11].abr, "Dez");
		mes[11].num = 12;
		mes[11].dias = 31;
		
		int m, d;
		printf("Digite um mes de 1 a 12: ");
		scanf("%i", &m);
		if (m >= 1 && m <= 12) 
			printf("Voce selecionou %s, digite um dia de 1 a %i: ", mes[m-1].nome, mes[m-1].dias);
		else {
			printf("Mes incorreto!");
			return 0;
		}
		scanf("%i", &d);
		if (d >= 1){
			int total = d;
			for (int i = 0; i < m-1; i++){
				total += mes[i].dias;
			}
			printf("Total de dias decorridos desde o primeiro dia do ano ate %i de %s: %i dias", d, mes[m-1].abr, total);
		}
		else {
			printf("Dia incorreto!");
			return 0;
		}
	}
	return 0;
}

