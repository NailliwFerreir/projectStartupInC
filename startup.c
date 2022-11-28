#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 30
#define names 50

typedef struct Data//Estrutura de data 
{
    int dia,mes,ano;    
}data;
typedef struct Despesa//Estrutura de despesas
{
    float salario_dev,hrextra,
    deslocReunioes,outrosGastos,receitaDoProjeto;
}despesa;
typedef struct projeto//Projetos da empresa
{
    int codigo;
    char gerente[names];
    char cliente[names];
    data datapj;
    despesa despesas;
}prjt;

void inserirPj (prjt pjt[]){//Funcao para inserir projeto
    
    int i;
    for (i=0;i<max;i++)
    {
    system("cls");
    pjt[i].codigo=i+1;
    printf("\nEste Projeto eh o de codigo numero: %d .",i);
    printf("\nDigite o nome do Gerente:\n");
    fflush(stdin);
    gets(pjt[i].gerente);

    printf("\nDigite o nome do Cliente:\n");
    fflush(stdin);
    gets(pjt[i].cliente);

    print("\nInsira a data de previsão de entrega do projeto\n");
    scanf("%d %d %d",&pjt[i].datapj.dia,&pjt[i].datapj.mes,&pjt[i].datapj.ano);

    system("pause");
    sytem("cls");
    
    printf("\nEste Projeto eh o de codigo numero: %d .",i);
    printf("\nAgora vamos para as despesas do projeto.");

    printf("\n \nDigite o salario dos desenvolvedores: ");
    scanf("%f",&pjt[i].despesas.salario_dev);
    
    printf("\nDigite o valor gasto em horas extras: ");
    scanf("%f",&pjt[i].despesas.hrextra);
    
    printf("\nDigite o valor do deslocamento para as reunioes: ");
    scanf("%f",&pjt[i].despesas.deslocReunioes);
    
    printf("\nDigite os outros gastos do Projeto: ");
    scanf("%f",&pjt[i].despesas.outrosGastos);
    
    printf("\nDigite o valor da receita do Projeto: ");
    scanf("%f",&pjt[i].despesas.receitaDoProjeto);
    }
}

void opcao1 (prjt pjt[]){//Feito...O lucro Total dos projetos em andamento...não entendi como assim projetos em andamento e lucro é a receita - o resto das despesas certo? 
    system("cls");
    float lucro=0;
    int i;
    for ( i = 0; i < max; i++)
    {
        lucro=lucro+((pjt[i].despesas.receitaDoProjeto)-(pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev));
    }
    printf("\nO lucro de todos os projetos em andamentos são:%.2f\n",lucro);
    system("pause");
    system("cls");
    controle(pjt);
}
void opcao2 (prjt pjt[]){//Feito...Quantos projetos estão atrasados
    system("cls");
    int i;
    data data_atual ;
    printf("Digite o dia/mes/ano de atual para fazer a pesquisa dos Projetos atrasados!");
    scanf("%d %d %d", data_atual.dia, data_atual.mes, data_atual.ano);
    for(i=0;i<max;i++){
        if(data_atual.ano<pjt[i].datapj.ano)
        {
            printf("Este projeto de codigo %d esta atrasado do(a) gerente : %s.",pjt[i].codigo,pjt[i].gerente);
        }else if(data_atual.mes<pjt[i].datapj.mes)
        {
            printf("Este projeto de codigo %d esta atrasadodo(a) gerente : %s.",pjt[i].codigo,pjt[i].gerente);
        }else if(data_atual.dia<pjt[i].datapj.dia)
        {
            printf("Este projeto de codigo %d esta atrasadodo(a) gerente : %s.",pjt[i].codigo,pjt[i].gerente);
        }
    }
    
    system("pause");
    system("cls");
    controle(pjt);
}
void opcao3 (prjt pjt[]){//Feito...O código do pjt e o nome do gerente do pjt com maior gasto com horas extras
    system("cls");
    int i=0,pos=0;
    float maior=0;
    maior=pjt[i].despesas.hrextra;
    for ( i = 1; i < max; i++)
    {
        if(maior<pjt[i].despesas.hrextra)
        {
            maior=pjt[i].despesas.hrextra;
            pos=i;
        }
    }
    
    printf("\nO projeto com maior gasto em horas extras eh o projeto de codigo numero: %d.\nE o seu gerente eh : %s",pjt[pos].codigo,pjt[pos].gerente);
    
    system("pause");
    system("cls");
    controle(pjt);
}
void opcao4 (prjt pjt[]){//Feito...O código do pjt e o nome do gerente com o pjt com maior gasto total 
    system("cls");
    int i=0,pos=0;
    float gastottl=0,compare=0;
    gastottl=pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev;

    for (i = 1; i < max; i++)
    {
        compare=pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev;
        if(compare>gastottl)
        {
            gastottl=compare;
            pos=i;
        }
    }

    printf("\nO projeto com maior gasto total eh o projeto de codigo numero: %d.\nE o seu gerente eh : %s",pjt[pos].codigo,pjt[pos].gerente);
    
    system("pause");
    system("cls");
    controle(pjt);
}
void opcao5 (prjt pjt[]){//Dado o nome de um gerente:Código do projeto,Cliente,Data prevista de Entrega,Lucro
    system("cls");
    printf("\n5-Gerenciamento por gerencia\n");
    printf("\nQuinta funcao \n \n");
    system("pause");
    system("cls");
    controle(pjt);
}
void opcao6 (prjt pjt[]){//Dado o nome do cliente imprimir:Código do projeto,Gerente,Data prevista de Entrega,Custo Total
    system("cls");
    printf("\n6-Clientes\n");
    printf("\nSexta funcao p fzr\n \n");
    system("pause");
    system("cls");
    controle(pjt);
}

void controle (prjt pjt[]){ //Funcao para retornar ao Menu ou sair

    int contrl= 0;
    printf("\nDigite o numero correspondente ao comando para executa-lo!\n");
    printf("\n1-Retornar ao menu inicial\n2-Sair do Programa\n\n");
    scanf("%d",&contrl);
        if((contrl>2)||(contrl<1))
    {
        printf("\nOps acho que nao conheco essa opcao...\nDigite uma opcao valida!!\n\n");
        system("pause");
    }
    switch (contrl)
    {
        case 1:menu(pjt);
        break; 
        case 2:system("cls");
            exit;
        break;
        default: system("cls");
            controle(pjt);
        break;
    }
}
void menu (prjt pjt[]){//Menu inicial
    int comando=0;
    system("cls");
    printf("\nDigite o numero correspondente ao comando para executa-lo!\n");
    printf("\n1-Lucro Total dos Projetos em andamento.\n2-Projetos Atrasados\n3-Projeto com maior gasto com horas extras.\n4-Projeto de maior gasto\n5-Gerenciamento por gerencia\n6-Clientes\n7-Sair\n");
    scanf("%d",&comando);
    if((comando>7)||(comando<1))
    {
        printf("\nOps acho que nao conheco essa opcao...\nDigite uma opcao valida!!\n\n");
        system("pause");
    }
    switch (comando)
    {
        case 1: opcao1(pjt);
        break;
        case 2: opcao2(pjt);
        break;
        case 3: opcao3(pjt);
        break;
        case 4: opcao4(pjt);
        break;
        case 5: opcao5(pjt);
        break;
        case 6: opcao6(pjt);
        break;
        case 7: system("cls");
            exit;
        break;
        default:menu(pjt);
        break;
    }

}

int main (){  
    system("cls");
    prjt projetos[max];
    menu(projetos);
    printf("\nAte mais!!!\n \n");
    return 0;
}/*int i = 0 ;
    projetos[i].codigo=i+2;
    strcpy(projetos[i].gerente,"Tadeu");
    printf("o nome do gerente eh : %s.\nO codigo do projeto eh: '%d'.\n",projetos[i].gerente,projetos[i].codigo);*/