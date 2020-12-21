#include <STDLIB.H>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

//para evitar bugs com uso de gets() depois de scanf()
void flush_in(){
   int ch;
   while((ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main(int argc, char** argv) {

	int questao = 2;
	
	if (questao == 1){
		typedef struct {
		   int dia, mes, ano; 
		} data;
		
		data *data1;
		
		data1 = malloc(sizeof(data));
		
		int *inteiro = (int *) malloc(sizeof(int));
		float *flutuante = (float *) malloc(sizeof(float));
		char *caractere = (char *) malloc(sizeof(char));
		double *duplo = (double *) malloc(sizeof(double));
		
		*inteiro = 21;
		*flutuante = 21.1;
		*caractere = 'a';
		*duplo = 21.1234;
		(*data1).dia = 13; 
		(*data1).mes = 10; 
		(*data1).ano = 2020;
		
		printf("%i - %f - %c - %lf", *inteiro, *flutuante, *caractere, *duplo);
		printf("\n Data1: dia = %i, mes = %i, ano = %i", (*data1).dia, (*data1).mes, (*data1).ano);
		
		if (inteiro)
			free(inteiro);
		if (flutuante)
			free(flutuante);
		if (caractere)
			free(caractere);
		if (duplo)
			free(duplo);
		if(data1)
			free(data1);
	}
	else if (questao == 2 || questao == 3 || questao == 4){
		
		// definição da struct 
		typedef struct aluno { 
			char nome[51];
			float altura;
			float peso;
			int idade;
			struct aluno *proximo; //encadeamento
		} info;
		
		//inicialização de structs
		info *ini_aluno;
		info *proximo_aluno;
		info *ultimo_aluno;
				
		proximo_aluno = (info*)malloc(sizeof(info));
		ini_aluno = proximo_aluno;
		
		int opcao, opcao4, j1 = 0, j2 = 0;
		char buffer[51];
		do {
			printf("\n\n->ALUNOS\n\n");
			printf("1 - Adicionar novo aluno\n");
			printf("2 - Remover aluno\n");
			printf("3 - Lista de alunos cadastrados (Ordem de cadastro)\n");
			printf("4 - Lista de alunos cadastrados (Ordem Alfabetica)\n");
			printf("5 - Selecionar alunos\n");
			printf("6 - Sair\n");
			printf("\nDIGITE UMA OPCAO:");
			scanf("%i", &opcao);
			
			flush_in(); // evitar bug com gets(), ele limpa o teclado após o scanf()
			
			switch (opcao) {
				case 1:			
					//novo alocamento
					proximo_aluno->proximo = (info *)malloc(sizeof(info));
					proximo_aluno = proximo_aluno->proximo;	
							
					printf("\n->NOVO CADASTRO: ");
					
					//nome
					printf("\nDigite o nome: ");
					gets(buffer);
					if (strlen(buffer) > 50) {
						printf("\nVoce ultrapassou o limite de 50 caracteres para o nome!");
						break;
					}
					strcpy(proximo_aluno->nome, buffer);
					
					//altura
					printf("Digite a altura: ");
					scanf("%f", &proximo_aluno->altura);
					
					//peso
					printf("Digite o peso: ");
					scanf("%f", &proximo_aluno->peso);
					
					//altura
					printf("Digite a idade: ");
					scanf("%i", &proximo_aluno->idade);
					break;
					
				case 2:
					printf("\n->EXCLUIR CADASTRO: ");
					printf("\nDigite o nome do aluno: ");
					gets(buffer);
					if (strlen(buffer) > 50) {
						printf("\nVoce ultrapassou o limite de 50 caracteres para o nome!");
						break;
					}
					proximo_aluno->proximo = NULL; //para ajudar a indicar quando se deve parar
					ultimo_aluno = proximo_aluno; //guardar o ultimo aluno
					proximo_aluno = ini_aluno; //voltar para o inicio, para iniciar a varredura
				
					while (proximo_aluno != NULL){ //enquanto nao chegar ao final
						if ((proximo_aluno->proximo != NULL) && !strcmp(buffer, proximo_aluno->proximo->nome)){ //se a comparação do nome dado for igual ao nome do proximo elemento
							if (proximo_aluno->proximo->proximo == NULL) ultimo_aluno = proximo_aluno; //se esse elemento for o ultimo
							free(proximo_aluno->proximo); //libera memoria
							proximo_aluno->proximo = proximo_aluno->proximo->proximo; //o proximo será pulado
						}
						proximo_aluno = (proximo_aluno == NULL)? NULL : proximo_aluno->proximo; //se por acaso houver um pulo para NULL, não deverá indicar para o proximo, e sim para o mesmo NULL
					}
					proximo_aluno = ultimo_aluno; //proximo aluno volta a ser o ultimo, como antes indicado
					ultimo_aluno = NULL;
					break;
	
				case 3:	
					//Imprime todos os alunos salvos
					proximo_aluno->proximo = NULL;
					ultimo_aluno = proximo_aluno;
					proximo_aluno = ini_aluno->proximo;
					printf("\nLISTA DE ALUNOS:\n");
					while (proximo_aluno != NULL){
						printf("\nNome: ");
						puts(proximo_aluno->nome);
						printf("Altura: %.2f \nPeso: %.2f \nIdade: %i \n", proximo_aluno->altura, proximo_aluno->peso, proximo_aluno->idade);
						proximo_aluno = proximo_aluno->proximo;
					}
					proximo_aluno = ultimo_aluno;
					ultimo_aluno = NULL;
					break;
				case 4:
					//Imprime todos os alunos salvos por ordem Alfabética
					proximo_aluno->proximo = NULL;
					printf("\nLISTA DE ALUNOS POR ORDEM ALFABETICA:\n");
					for (j1 = 65, j2 = 97; j1 <= 90; j1++, j2++){
						ultimo_aluno = proximo_aluno;
						proximo_aluno = ini_aluno->proximo;
						while (proximo_aluno != NULL){			
							if ((int)(proximo_aluno->nome[0]) == j1 || (int)(proximo_aluno->nome[0]) == j2){
								printf("\nNome: ");
								puts(proximo_aluno->nome);
								printf("Altura: %.2f \nPeso: %.2f \nIdade: %i \n", proximo_aluno->altura, proximo_aluno->peso, proximo_aluno->idade);
							}
							proximo_aluno = proximo_aluno->proximo;
						}
						proximo_aluno = ultimo_aluno;
						ultimo_aluno = NULL;
					}
					break;
				case 5:
					
					printf("\n\n->SELECIONAR ALUNOS\n");
					printf("1 - Altura maior que\n");
					printf("2 - Altura menor que\n");
					printf("3 - Peso acima de\n");
					printf("4 - Peso abaixo de\n");
					printf("5 - Idade maior que\n");
					printf("6 - Idade menor que\n");
					printf("7 - Nome\n");
					printf("\nDIGITE UMA OPCAO:");
					scanf("%i", &opcao4);
					float altura, peso;
					int idade;
					char nome[50];
					switch (opcao4){
						case 1:
							printf("\nBusca por altura maior que: ");
							scanf("%f", &altura);
							proximo_aluno->proximo = NULL;
							ultimo_aluno = proximo_aluno;
							proximo_aluno = ini_aluno->proximo;
							while (proximo_aluno != NULL){
								if (proximo_aluno->altura > altura){
									printf("\nNome: ");
									puts(proximo_aluno->nome);
									printf("Altura: %.2f\n", proximo_aluno->altura);
								}
								proximo_aluno = proximo_aluno->proximo;
							}
							proximo_aluno = ultimo_aluno;
							ultimo_aluno = NULL;
							break;
						case 2:
							printf("\nBusca por altura menor que: ");
							scanf("%f", &altura);
							proximo_aluno->proximo = NULL;
							ultimo_aluno = proximo_aluno;
							proximo_aluno = ini_aluno->proximo;
							while (proximo_aluno != NULL){
								if (proximo_aluno->altura < altura){
									printf("\nNome: ");
									puts(proximo_aluno->nome);
									printf("Altura: %.2f\n", proximo_aluno->altura);
								}
								proximo_aluno = proximo_aluno->proximo;
							}
							proximo_aluno = ultimo_aluno;
							ultimo_aluno = NULL;
							break;
						case 3:
							printf("\nBusca por peso maior que: ");
							scanf("%f", &peso);
							proximo_aluno->proximo = NULL;
							ultimo_aluno = proximo_aluno;
							proximo_aluno = ini_aluno->proximo;
							while (proximo_aluno != NULL){
								if (proximo_aluno->peso > peso){				
									printf("\nNome: ");				
									puts(proximo_aluno->nome);
									printf("Peso: %.2f\n", proximo_aluno->peso);
								}
								proximo_aluno = proximo_aluno->proximo;
							}
							proximo_aluno = ultimo_aluno;
							ultimo_aluno = NULL;
							break;
						case 4:
							printf("\nBusca por peso menor que: ");
							scanf("%f", &peso);
							proximo_aluno->proximo = NULL;
							ultimo_aluno = proximo_aluno;
							proximo_aluno = ini_aluno->proximo;
							while (proximo_aluno != NULL){
								if (proximo_aluno->peso < peso){
									printf("\nNome: ");
									puts(proximo_aluno->nome);
									printf("Peso: %.2f\n", proximo_aluno->peso);
								}
								proximo_aluno = proximo_aluno->proximo;
							}
							proximo_aluno = ultimo_aluno;
							ultimo_aluno = NULL;
							break;
						case 5:
							printf("\nBusca por idade maior que: ");
							scanf("%i", &idade);
							proximo_aluno->proximo = NULL;
							ultimo_aluno = proximo_aluno;
							proximo_aluno = ini_aluno->proximo;
							while (proximo_aluno != NULL){
								if (proximo_aluno->idade > idade){
									printf("\nNome: ");
									puts(proximo_aluno->nome);
									printf("Idade: %i\n", proximo_aluno->idade);
								}
								proximo_aluno = proximo_aluno->proximo;
							}
							proximo_aluno = ultimo_aluno;
							ultimo_aluno = NULL;
							break;
						case 6:
							printf("\nBusca por idade menor que: ");
							scanf("%i", &idade);
							proximo_aluno->proximo = NULL;
							ultimo_aluno = proximo_aluno;
							proximo_aluno = ini_aluno->proximo;
							while (proximo_aluno != NULL){
								if (proximo_aluno->idade < idade){
									printf("\nNome: ");
									puts(proximo_aluno->nome);
									printf("Idade: %i\n", proximo_aluno->idade);
								}
								proximo_aluno = proximo_aluno->proximo;
							}
							proximo_aluno = ultimo_aluno;
							ultimo_aluno = NULL;
							break;
						case 7:
							printf("\nBusca por nome: ");
							flush_in();
							gets(nome);
							if (strlen(nome) > 50) {
								printf("\nVoce ultrapassou o limite de 50 caracteres para o nome!");
								break;
							}
							proximo_aluno->proximo = NULL;
							ultimo_aluno = proximo_aluno;
							proximo_aluno = ini_aluno->proximo;
							while (proximo_aluno != NULL){
								if (!strcmp(nome, proximo_aluno->nome)) {
									printf("\nNome: ");
									puts(proximo_aluno->nome);
									printf("Altura: %.2f - Peso: %.2f - Idade: %i \n", proximo_aluno->altura, proximo_aluno->peso, proximo_aluno->idade);
								}
								proximo_aluno = proximo_aluno->proximo;
							}
							proximo_aluno = ultimo_aluno;
							ultimo_aluno = NULL;
							break;
					}
					
					break;
				}
			
		} while (opcao != 6);
	}


	return 0;
}
