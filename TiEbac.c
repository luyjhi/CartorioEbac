#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável de cuidar das string

int Registro() //função responsavel por cadastrar os usúarios do sistema
{
	//inicio criação de variáveis/strings 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string

	printf("Digite o  cpf a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Resposnsavel por copia os valores das strings
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
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
	
	printf("Digite o sobre nome a ser Cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado ");
	scanf("%" ,cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int Consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi posssivel abrir o arquivo, não localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int Deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
	
	
}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco+1;laco=1;)
	{
		
	system("cls");
	
    setlocale(LC_ALL, "Portuguese"); // definindo a linguagem 
    
    printf("\tCartorio Da EBAC\n\n");	 //iniciar menu
    printf("Escolha a opção desejada do menu:\n\n");
    printf("\t1 - Registrar nomes.\n");
    printf("\t2 - Consultar nomes.\n");
	printf("\t3 - Deletar nomes.\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("opção: ");	// fim do menu
	
	scanf("%d", &opcao); //armazenando escolha do usuário
	
	system("cls"); //Responsavel por limpar a tela
	
	switch(opcao) //Inicio da seleção do menu
		{
			case 1:
			Registro(); //chanmada de funções
			break;
	 		     
			case 2:
			Consultar();
			break;
		  
			case 3:
			Deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
				
		}	
	}
		
			
			
}
