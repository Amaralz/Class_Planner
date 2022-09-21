#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <windows.h>

struct alunoficha
{
    char nome[101];
    char comp[80];
    char mat[50];
    char curso [50];
    int idade, hcom,hcom2;
}; struct alunoficha aluno;

void cadastro ()
{
    printf("<===================== Class Planner ====================>\n");
    printf("Digite seu nome:");
    gets(aluno.nome);
    printf("Digite sua idade:");
    scanf("%d",&aluno.idade);
    system("CLS");
}

int menu ()
{
    int op;
    do{
    printf("<===================== Class Planner ====================>\n");
    printf("escolha o que deseja fazer\n");
    printf("\t[1] Curso\n");
    printf("\t[2] Calcular média da sua AV1,AV2,AVD:\n");
    printf("\t[3] Agenda:\n");
    printf("\t[4] Cronometro:\n");
    printf("\t[5] Ficha do aluno:\n");
    scanf("%d",&op);
    system("CLS");
    }while(op < 1 || op > 5);
    system("CLS");
    return op;
}

void curso ()
{
printf("<===================== Class Planner ====================>\n");
int cc,estudo;
char mat[50];
char curso[50];

	  printf("\n[1] Ciências da Computação");
	  printf("\n[2] Engenharia da Computação.\n");
	  printf("\nEscolha a opção do curso:");
	  scanf("%d", &cc);
	  strcpy(aluno.curso,"Ciências da Computação.");
	  strcpy(aluno.curso,"Engenharia da Computação.");
  
switch (cc)
    {
    case 1:{printf("\nEscolha a matéria que deseja estudar:"); 
	printf("\n[1] Introdução a programação com estrutura em C.");
	printf("\n[2] Fundamentos de rede de computadores.");
	printf("\n[3] Introdução a segurança da informação.");
	printf("\n[4] Introdução a arquitetura de computadores.");
	scanf("%d",&estudo);
	switch(estudo)
	{
		case 1:strcpy(aluno.mat,"Introdução a programação com estrutura em C");break;
   		case 2:strcpy(aluno.mat,"Fundamentos de rede de computadores.");break;
   		case 3:strcpy(aluno.mat,"Introdução a segurança da informação.");break;
   		case 4:strcpy(aluno.mat,"Introdução a arquitetura de computadores.");break;
    }}break;
    case 2:printf("\nEscolha a matéria que deseja estudar:"); 
	printf("\n[1] Introdução a programação com estrutura em C.");
	printf("\n[2] Engenharia, sociedade e sustentabilidade.");
	printf("\n[3] Introdução a arquitetura de computadores.");
	printf("\n[4] Princípios de gestão.");
	scanf("%d",&estudo);
    
    switch(estudo)
	{
		case 1:strcpy(aluno.mat,"Introdução a programação com estrutura em C.");break;
   		case 2:strcpy(aluno.mat,"Engenharia, sociedade e sustentabilidade.");break;
   		case 3:strcpy(aluno.mat,"Introdução a arquitetura de computadores.");break;
   		case 4:strcpy(aluno.mat,"Princípios de gestão.");break;
	}break;
  }
}

void media (float *med){
    float av[3],medr=0,avd;
    int i;
    printf("<===================== Class Planner ====================>\n");
    printf("<========== Cálculo da media ==========>\n\n");
    for( i = 0; i < 2; i++)
    {
        printf("Digite sua nota da AV%d:",i+1);
        scanf("%f",&av[i]);
    }
    printf("Digite sua nota da AVD:");
    scanf("%f",&avd);

    *med = (av[0] + av[1] + avd) / 3;
    medr = *med;
    printf("Sua média:%.1f", *med);
    if (medr >= 6)
    {
        printf("\n\nPARABÉNS! Você se livrou dessa matéria nesse semestre!\n\n");
    }   
    if (medr >= 4 && medr < 6 ) 
    {
        printf("\n\nVocê está na AV3! :c\n\n");
        
    }else if( medr < 4)
    {
        printf("\n\nVoce foi reprovado:(\n\n");
    }
}
  
void agenda ()
{
    printf("<===================== Class Planner ====================>\n");
 	printf("Digite seu compromisso do dia:\n");
  	getchar();
    gets(aluno.comp);
 	printf("\nDigite o horário do seu compromisso:\n\n");
  	scanf("%d", &aluno.hcom);
  printf("e\n");
    scanf("%d",&aluno.hcom2);
}

void cronometro ()
{
   int sec=0,seg;
    int min=0,mini;
    int hr=0,hra;
    int i=0;
    char yes[5];
    int result;
    printf("<===================== Class Planner ====================>\n");
     printf("Insira quanto tempo vc quer estudar? Considere a sequencia de HORAS;MINUTOS;SEGUNDOS\n");
    printf("\nHoras:\n");
    scanf("%d",&hra);
    printf("==============================");
    printf("\nMinutos:\n");
    scanf("%d",&mini);
    printf("==============================");
    printf("\nSegundos:\n");
    scanf("%d",&seg);
    printf("você deseja ter uma pausa a cada 60s?\n");
    scanf("%s",yes);
    result = strcmp(yes,"sim");
   do {
        system("cls");
        
        printf("\n\t\t\t\tCRONOMETRO\n\n");
        printf("\n\t\t\t\t%dh:%dm:%ds\n\n", hr,min,sec);
       if(sec==60){
            sec=0;
            min++;
            if (result == 0 )
            {
                system("pause"); 
            }
            
        }
        if(min==60){
           min=0;
            hr++;
        }
        if(hr==24){
           hr=0;
           break;
        }
        Sleep(10);
       sec++;
       if (sec == seg && min == mini && hr == hra)
        {   system("CLS");
            printf("\n\t\t\t\tCRONOMETRO\n\n");
            printf("\n\t\t\t\t%dh:%dm:%ds\n\n", hr,min,sec); 
        }
    }while (sec != seg || min != mini || hr != hra);
    system("pause");
    
}

void result (float med)
{
    printf("\n<========== Class Planner ==========>\n");
    printf("Aluno: %s\nIdade: %d", aluno.nome,aluno.idade);
    printf("\nCurso escolhido:%s",aluno.curso);
    printf("\nMatéria escolhida:%s",aluno.mat);
	printf("\nNota de media: %.1f\n",med);
    printf("Seus compromisso do dia:%s, as %d horas e %d minutos\n", aluno.comp, aluno.hcom,aluno.hcom2);
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
    system("CLS");
    int op,resp;
    float med;
    cadastro();
    do{
    op = menu ();

    switch (op)
    {
    case 1:curso();break;
    case 2:media(&med);break;
    case 3:agenda();break;
    case 4:cronometro();break;
    case 5:result(med);break;
    default:
        break;
    }
    do{
        printf("\nDeseja encerrar o programa? [1] Sim // [0] Não:\n");
        scanf("%d",&resp);
        system("CLS");
    }while(resp > 1 || resp < 0);
    }while (resp == 0);

    return 0;
    
}