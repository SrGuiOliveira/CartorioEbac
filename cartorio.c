#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings
int main()
{
	int opcao=0;//definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	 
	 system("cls");//limpar tela
	 
	 setlocale(LC_ALL,"portuguese");//definindo a linguagem
	
	 printf("### Cartório da EBAC ###\n\n");//inicio do menu
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n");
	 printf("\t4 - Sair do sistema\n\n");
	 printf("Digite sua opção:");//fim do menu
	
	 scanf("%d", &opcao);//armazenando a escolha do usuario
	
	 system("cls");//limpar tela
	
	 switch(opcao)
	 {
	
		case 1:
	 	registro();
	    break;
	    
	    case 2:
	    consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("\n\n\tObrigado por utilizar nosso sistema!\n\n");
		return 0;
		system("pause");
		break;
		
		default:
		printf("Esta opção não está disponível!\n");
		system("pause");//pausar tela
		break;
	 }
    }
} 

int registro()//função responsável por cadastrar os usuarios
{
	//inicio da criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	
	printf("Digite o CPF a ser cadastrado:");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file= fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("\n\nUsuário cadastrado com sucesso!\n\n");
	system("pause");
	system("cls");
	
	printf("\t\n Escolha uma das opções abaixo:\n");
	printf("\t\n 1 - Registrar mais um usuário");
	printf("\t\n 2 - Voltar ao menu principal");
	printf("\t\n 3 - Sair do sistema\n\n");
	printf("Digite sua opção:");
	
	int decisao=0;
	scanf("%d", &decisao);
	
	switch(decisao)
	{
		case 1:
		system("cls");
		return registro();
		break;
		
		case 2:
		return main();
		break;
		
		case 3:
		system("cls");
		printf("\n\n\tObrigado por utilizar nosso sistema!\n\n");
		exit(0);
		break;
		
		default:
		printf("\t\n Opção inválida! \n");
		system("pause");
		return main();
		break;	
	 
	}
	
	
}


	
int consulta()
{
	setlocale(LC_ALL,"portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL,"portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s", cpf);
	
	
	FILE *file;
	file= fopen(cpf,"r");


	if(file!=NULL)
	{
		fclose(file);
		remove (cpf);
		printf("Usuário deletado!\n");
	    system("pause");		
	}
	else
	{
		fclose(file);
		printf("Usuário não encontrado!\n");
		system("pause");
	}
	
	
	
		
}



