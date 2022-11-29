#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 3
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

void toTest(prjt *pjto[max])//ja deixa os projetos criados 
{
    prjt pjt[max];
    int i=0;
    //Código do Projeto
    pjt[i].codigo=i++;
    //Gerente
    strcpy(pjt[i].gerente,"Brasil");
    //Data de entrega prevista para o projeto.
    pjt[i].datapj.dia= 24;
    pjt[i].datapj.mes= 11;
    pjt[i].datapj.ano= 2022;
    //Cliente
    strcpy(pjt[i].cliente,"Servia");
    //Despesas associadas com o projeto, sendo as principais:
    //Salário com Desenvolvedores
    pjt[i].despesas.salario_dev=20000;
    //Valor pago em Horas extras
    pjt[i].despesas.hrextra=3000;
    //Valor pago para o Deslocamento de reuniões
    pjt[i].despesas.deslocReunioes=7000;
    //Outros Gastos
    pjt[i].despesas.outrosGastos=15000;
    //Receita do Projeto
    pjt[i].despesas.receitaDoProjeto=150000;
    i++;
//-------------------------------------------------------------------------------------------------
    //Código do Projeto
    pjt[i].codigo=i++;
    //Gerente
    strcpy(pjt[i].gerente,"Brasil");
    //Data de entrega prevista para o projeto.
    pjt[i].datapj.dia= 28;
    pjt[i].datapj.mes= 11;
    pjt[i].datapj.ano= 2022;
    //Cliente
    strcpy(pjt[i].cliente,"Suica");
    //Despesas associadas com o projeto, sendo as principais:
    //Salário com Desenvolvedores
    pjt[i].despesas.salario_dev=15000;
    //Valor pago em Horas extras
    pjt[i].despesas.hrextra=9000;
    //Valor pago para o Deslocamento de reuniões
    pjt[i].despesas.deslocReunioes=6000;
    //Outros Gastos
    pjt[i].despesas.outrosGastos=1500;
    //Receita do Projeto
    pjt[i].despesas.receitaDoProjeto=120000;
    i++;    //Código do Projeto
    pjt[i].codigo=i++;
    
//-------------------------------------------------------------------------------------------------
    //Gerente
    strcpy(pjt[i].gerente,"lucia");
    //Data de entrega prevista para o projeto.
    pjt[i].datapj.dia= 4;
    pjt[i].datapj.mes= 12;
    pjt[i].datapj.ano= 2022;
    //Cliente
    strcpy(pjt[i].cliente,"Alunos");
    //Despesas associadas com o projeto, sendo as principais:
    //Salário com Desenvolvedores
    pjt[i].despesas.salario_dev=17000;
    //Valor pago em Horas extras
    pjt[i].despesas.hrextra=15000;
    //Valor pago para o Deslocamento de reuniões
    pjt[i].despesas.deslocReunioes=10000;
    //Outros Gastos
    pjt[i].despesas.outrosGastos=1200;
    //Receita do Projeto
    pjt[i].despesas.receitaDoProjeto=140000;
    i++;    //Código do Projeto
    pjt[i].codigo=i++;
//-------------------------------------------------------------------------------------------------
    *pjto=pjt;
}

void inserirPj (prjt pjt[]){//Funcao para inserir projeto
    
    int i;
    for (i=0;i<max;i++)
    {
    system("cls");
    pjt[i].codigo=i+1;
    printf("\nEste Projeto eh o de codigo numero: %d .",pjt[i].codigo);
    char gerente[100];
    do{
        printf("\nDigite o nome do Gerente:\n");
        fflush(stdin);
        gets(gerente);
        if(strlen(gerente)>50)
        {
            printf("\nAbrevie o nome (maximo de 50 caracteres)\n");
        }
    }while(strlen(gerente)>50);
    strcpy(pjt[i].gerente,gerente);

    char cliente[100];
    do  
    {
        printf("\nDigite o nome do Gerente:\n");
        fflush(stdin);
        gets(cliente);
        if(strlen(cliente)>50)
        {
            printf("\nAbrevie o nome (maximo de 50 caracteres)\n");
        }
    }while(strlen(cliente)>50);
    strcpy(pjt[i].cliente,cliente);

    print("\nInsira a data de previsão de entrega do projeto\n");
    scanf("%d %d %d",&pjt[i].datapj.dia,&pjt[i].datapj.mes,&pjt[i].datapj.ano);

    system("pause");
    sytem("cls");
    
    printf("\nEste Projeto eh o de codigo numero: %d .",pjt[i].codigo);
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
    sytem("cls");
    }
    controle(pjt);
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
    int i,cont=0;
    data data_atual ;
    printf("Digite o dia/mes/ano de atual para fazer a pesquisa dos Projetos atrasados!");
    scanf("%d %d %d", data_atual.dia, data_atual.mes, data_atual.ano);
    for(i=0;i<max;i++){
        if(data_atual.ano<pjt[i].datapj.ano)
        {
            printf("Este projeto de codigo %d esta atrasado do(a) gerente : %s.",pjt[i].codigo,pjt[i].gerente);
            cont++;
        }else if(data_atual.mes<pjt[i].datapj.mes)
        {
            printf("Este projeto de codigo %d esta atrasado do(a) gerente : %s.",pjt[i].codigo,pjt[i].gerente);
            cont++;
        }else if(data_atual.dia<pjt[i].datapj.dia)
        {
            printf("Este projeto de codigo %d esta atrasado do(a) gerente : %s.",pjt[i].codigo,pjt[i].gerente);
            cont++;
        }
    }
    printf("\nNo total sao %d projetos com atraso.\n",cont);
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
    int i,retorno=0,cont=0;
    char gerente[100];

        printf("\nDigite o nome do Gerente:\n");
        fflush(stdin);
        gets(gerente);
        for (i=0;i<max;i++)
        {
            retorno=strcmp(gerente,pjt[i].gerente);
            if(retorno){
                printf("\nEste eh o projeto de numero: %d\n\nNome do cliente: %s .\nData prevista de entrega: %d/%d/%d\nO lucro deste projeto eh cerca de R$%f reais.",pjt[i].codigo,pjt[i].cliente,pjt[i].datapj.dia,pjt[i].datapj.mes,pjt[i].datapj.ano,((pjt[i].despesas.receitaDoProjeto)-(pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev)));
            }
            cont+=retorno;
        }
        if(cont==0){
            printf("\nOps nao achei este gerente!!\n");
        }
    system("pause");
    system("cls");
    controle(pjt);
}

void opcao6 (prjt pjt[]){//Dado o nome do cliente imprimir:Código do projeto,Gerente,Data prevista de Entrega,Custo Total
    system("cls");
    int i,retorno=0,cont=0;
    char cliente[100];

        printf("\nDigite o nome do Gerente:\n");
        fflush(stdin);
        gets(cliente);
        for (i=0;i<max;i++)
        {
            retorno=strcmp(cliente,pjt[i].cliente);
            if(retorno){
                printf("\nEste eh o projeto de numero: %d\n\nNome do gerente: %s .\nData prevista de entrega: %d/%d/%d\nO lucro deste projeto eh cerca de R$%f reais.",pjt[i].codigo,pjt[i].gerente,pjt[i].datapj.dia,pjt[i].datapj.mes,pjt[i].datapj.ano,((pjt[i].despesas.receitaDoProjeto)-(pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev)));
            }
            cont+=retorno;
        }
        if(cont==0){
            printf("\nOps nao achei este cliente!!\n");
        }
    system("pause");
    system("cls");
    controle(pjt);
}

void controle (prjt pjt[]){//Funcao para retornar ao Menu ou sair

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
    toTest(projetos);
    menu(projetos);
    printf("\nAte mais!!!\n \n");
    return 0;
}
