#include <stdio.h> //BIBLIOTECA DE COMUNICAÇÃO COM O USUÁRIO
#include <stdlib.h> //BIBLIOTECA DE ALOCAÇÃO DE ESPAÇO EM MEMÓRIA
#include <locale.h> //BIBLIOTECA DE ALOCAÇÕES DE TEXTO POR REGIÃO
#include <string.h> // BIBLIOTECA RESPONSÁVEL POR CUIDAR DAS STRING

int registrar()//FUNÇÃO RESPONSÁVEL POR CADASTRAR OS USUÁRIOS NO SISTEMA
{
	//INÍCIO CRIAÇÃO DE VARIÁVEIS
	char arquivo[50];
	char cpf[50];
	char nome[50]; 
	char sobrenome[50];
	char cargo[50];
	//FINAL DA CRIAÇÃO DE VARIÁVEIS
	
	printf("Digite o CPF para cadastrar:"); //COLETANDO INFORMAÇAO DO USUÁRIO
	scanf("%s", cpf);//%s REFERE-SE A STRING
	
	strcpy(arquivo, cpf); // RESPONSÁVEL POR COPIAR OS VALORES DAS STRING
	
	FILE *file; // CRIA O ARQUIVO
	file = fopen(arquivo, "w"); // CRIA O ARQUIVO E O "W" SIGNIFICA ESCREVER
	fprintf(file,cpf); // SALVA O VALOR DA VARIÁVEL 
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
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf ("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[50];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s, cpf");
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
}


int main()
{
	
	int opcao=0; // DEFININDO VARIÁVEIS 
	int x=1;
	
	for(x=1;x=1;)//OPERADOR DE REPETIÇÃO
	{
		
		system("cls");// RESPONSÁVEL POR LIMPAR A TELA
	
	
      setlocale(LC_ALL,"Portuguese");//DEFININDO A LINGUAGEM
	
	  printf("\tCartório da EBAC\n\n");//INICIO DO MENU
	  printf("ESCOLHA A OPÇÃO A SEGUIR\n\n\n");
	  printf("Registrar aluno\t\tConsultar aluno\t\tDeletar aluno\n\n\n\n");
	  printf("Opção: "); //FIM DO MENU
	
	
	  scanf("%d", &opcao); // ARMAZENANDO A ESSCOLHA DO USUÁRIO 
	
	  system("cls");
	  
	  switch(opcao)//INÍCIO DA SELEÇÃO DO MENU
	  {
	  	case 1://CHAMADA DE FUNÇÕES
	  	registrar();
	    break;
	    
	    case 2://CHAMADA DE FUNÇÕES
	    consultar();
		break;
		
		case 3:// CHAMADA DE FUNÇÕES
		deletar();
		break;
		
		default: 
		printf("Opção inexistente\n");
		system("pause");
		break;
	  }
	
	}
}

