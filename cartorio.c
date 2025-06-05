
#include <locale.h> //biblioteca de alocação de texto por região
#include <stdio.h> // Biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // função responsavel por cadastrar os usuarios no sistema
{
	// inicio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string - salvando a string
	
	strcpy(arquivo, cpf); // responsável por criar os valores das string
	
	FILE *file; 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" signifia escrever 
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o serviço
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o cargo a ser cadastrado");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
 
	
}

int consulta ()
{
		setlocale (LC_ALL, "PORTUGUESE"); // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file; 
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não foi localizado!. \n");		
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		}	

	system("pause");
	
	}

int deletar ()
{

	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL )
	{
		printf("O usuario não se encontra no sistema! . \n");
		system("pause");
		
	}
	system("pause"); 

}


int main () 
{
		int opcao=0;//definindo as variaveis
		int laco=1; 
		
		
		for(laco=1;laco=1;)
	{
	
			system("cls");	//responsavel por limpar a tela 
	
			setlocale (LC_ALL, "PORTUGUESE");
			
			
	
			printf(".   CARTÓRIO DA EBAC   .\n\n");
			printf("Escolha a opção desejada: \n\n");
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - consultar nomes\n");
			printf("\t3 - deletar nomes\n\n\n\n");
			printf("\t4 - sair do sistema\n\n");
			printf("opção: ");//fim do menu
	
			scanf("%d", &opcao);
	
			system("cls");
			
			switch(opcao) // inicio da seleção do menu
			{
				case 1: // chamada de funções 
				registro();
				break;
				
				case 2:
				consulta();
			    break;
			    
			    case 3:
				deletar();	    
				break;
				
				case 4:
				printf("Obrigada por utilizar o sistema!\n");
				return 0; 
				break; 
				
				default:
				printf("Essa opção não esta disponivel\n");
				system ("pause");
 	
			}

   }

}

