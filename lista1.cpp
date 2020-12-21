#include <iostream>

/*
	MIGUEL HELLMANN PREUSS (18200573)
	PROGRAMAÇÃO DE SISTEMAS AUTOMATIZADOS 2020.1
	LISTA 1
*/

int main(int argc, char** argv) {
	
	int questao = 3;
	
	if (questao == 1){
		char caractere = 'a'; 									// -2^7 a (2^7) - 1
		signed char caractereSigned = 'b'; 						// -2^7 a (2^7) - 1
		unsigned char caractereUnsigned = 'c'; 					//0 a (2^8) - 1
		
		int inteiro = 10; 										//-2^15 a (2^15) - 1
		signed int inteiroSigned = -831; 						//-2^15 a (2^15) - 1
		unsigned int inteiroUnsigned = 831; 					// 0 a (2^16) - 1
		short int inteiroCurto = 1; 							//-2^15 a (2^15) - 1
		long int inteiroLongo = 1021092; 						//-2^31 a (2^31) - 1
		signed short int inteiroCurtoSigned = -30000;			//-2^15 a (2^15) - 1
		unsigned short int inteiroCurtoUnsigned = 60000;		//0 a (2^16) - 1
		signed long int inteiroLongoSigned = -2000000000;		//-2^31 a (2^31) - 1
		unsigned long int inteiroLongoUnsigned = 2000000000;	//0 a (2^32) - 1
		
		float flutuante = 81.31;								//3.4 e-38 a 3.4 e+38
		double duplo_flutuante = 99.99;							//1.7 e-308 a 1.7 e+308
		long double duplo_flutuanteLongo = 416437837546.21; 	//3.4 e-4932 a 1.1 e+4932
		
		printf("caractere: %c \n", caractere);
		printf("caractere c sinal: %c\n", caractereSigned);
		printf("caractere s sinal: %c\n", caractereUnsigned);
		printf("inteiro: %d\n", inteiro);
		printf("inteiro c sinal: %i\n", inteiroSigned);
		printf("inteiro s sinal: %u\n", inteiroUnsigned);
		printf("inteiro curto: %hi\n", inteiroCurto);
		printf("inteiro longo: %li\n", inteiroLongo);
		printf("inteiro curto c sinal: %hi\n", inteiroCurtoSigned);
		printf("inteiro curto s sinal: %hu\n", inteiroCurtoUnsigned);
		printf("inteiro longo c sinal: %li\n", inteiroLongoSigned);
		printf("inteiro longo s sinal: %lu\n", inteiroLongoUnsigned);
		printf("flutuante: %f\n", flutuante);
		printf("flutuante duplo : %lf\n", duplo_flutuante);
		printf("flutuante duplo longo: %Lf\n", duplo_flutuanteLongo);
		
		printf("> %i\n", sizeof(caractere));
		printf("> %i\n", sizeof(caractereSigned));
		printf("> %i\n", sizeof(caractereUnsigned));
		printf("> %i\n", sizeof(inteiro));
		printf("> %i\n", sizeof(inteiroSigned));
		printf("> %i\n", sizeof(inteiroUnsigned));
		printf("> %i\n", sizeof(inteiroCurto));
		printf("> %i\n", sizeof(inteiroLongo));
		printf("> %i\n", sizeof(inteiroCurtoSigned));
		printf("> %i\n", sizeof(inteiroCurtoUnsigned));
		printf("> %i\n", sizeof(inteiroLongoSigned));
		printf("> %i\n", sizeof(inteiroLongoUnsigned));
		printf("> %i\n", sizeof(flutuante));
		printf("> %i\n", sizeof(duplo_flutuante));
		printf("> %i\n", sizeof(duplo_flutuanteLongo));
	}
	else if (questao == 2){
		unsigned short int agencia;
		unsigned short int conta;
		unsigned short int cartao;
		unsigned short int senha;
		
		printf("Digite a agencia: ");
		scanf("%u", &agencia);
		
		printf("Digite a conta: ");
		scanf("%u", &conta);
		
		printf("Digite a cartao: ");
		scanf("%u", &cartao);
		
		printf("Digite a senha: ");
		scanf("%u", &senha);
		
		printf("\nAgencia: %u", agencia);
		printf("\nConta: %u", conta);
		printf("\nCartao: %u", cartao);
		printf("\nSenha: %u", senha);
	}
	else if (questao == 3){
		unsigned short int ano;
		printf("Digite o ano: ");
		scanf("%u", &ano);
		printf(((!(ano % 400) || !(ano % 4)) && ano % 100) ? "Bissexto" : "Nao-Bissexto" );
	}
	return 0;
}
