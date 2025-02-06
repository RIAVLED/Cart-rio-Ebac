#include <stdio.h> //BIBLIOTECA DE COMUNICA��O COM O USU�RIO
#include <stdlib.h> //BIBLIOTECA DE ALOCA��O DE ESPA�O EM MEM�RIA
#include <locale.h> //BIBLIOTECA DE ALOCA��ES DE TEXTO POR REGI�O
#include <string.h> // BIBLIOTECA RESPONS�VEL POR CUIDAR DAS STRING

int registrar()//FUN��O RESPONS�VEL POR CADASTRAR OS USU�RIOS NO SISTEMA
{
	//IN�CIO CRIA��O DE VARI�VEIS
	char arquivo[50];
	char cpf[50];
	char nome[50]; 
	char sobrenome[50];
	char cargo[50];
	//FINAL DA CRIA��O DE VARI�VEIS
	
	printf("Digite o CPF para cadastrar:"); //COLETANDO INFORMA�AO DO USU�RIO
	scanf("%s", cpf);//%s REFERE-SE A STRING
	
	strcpy(arquivo, cpf); // RESPONS�VEL POR COPIAR OS VALORES DAS STRING
	
	FILE *file; // CRIA O ARQUIVO
	file = fopen(arquivo, "w"); // CRIA O ARQUIVO E O "W" SIGNIFICA ESCREVER
	fprintf(file,cpf); // SALVA O VALOR DA VARI�VEL 
	fclose(file); // FECHA O ARQUIVO
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome para cadastrar:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome para cadastrar:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo para cadastrar:");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese");//DEFININDO A LINGUAGEM
	
	char cpf[50];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf ("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[50];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s, cpf");
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}


int main()
{
	
	int opcao=0; // DEFININDO VARI�VEIS 
	int x=1;
	
	for(x=1;x=1;)//OPERADOR DE REPETI��O
	{
		
		system("cls");// RESPONS�VEL POR LIMPAR A TELA
	
	
      setlocale(LC_ALL,"Portuguese");//DEFININDO A LINGUAGEM
	
	  printf("\tCart�rio da EBAC\n\n");//INICIO DO MENU
	  printf("ESCOLHA A OP��O A SEGUIR\n\n\n");
	  printf("Registrar aluno\t\tConsultar aluno\t\tDeletar aluno\n\n\n\n");
	  printf("Op��o: "); //FIM DO MENU
	
	
	  scanf("%d", &opcao); // ARMAZENANDO A ESSCOLHA DO USU�RIO 
	
	  system("cls");
	  
	  switch(opcao)//IN�CIO DA SELE��O DO MENU
	  {
	  	case 1://CHAMADA DE FUN��ES
	  	registrar();
	    break;
	    
	    case 2://CHAMADA DE FUN��ES
	    consultar();
		break;
		
		case 3:// CHAMADA DE FUN��ES
		deletar();
		break;
		
		default: 
		printf("Op��o inexistente\n");
		system("pause");
		break;
	  }
	
	}
}

