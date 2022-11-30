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

prjt toTest(prjt pjt[max])//ja deixa os projetos criados
{
    int i=0;
    //Código do Projeto
    pjt[i].codigo=i+1;
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
    pjt[i].despesas.salario_dev=2000;
    //Valor pago em Horas extras
    pjt[i].despesas.hrextra=3000;
    //Valor pago para o Deslocamento de reuniões
    pjt[i].despesas.deslocReunioes=700;
    //Outros Gastos
    pjt[i].despesas.outrosGastos=1500;
    //Receita do Projeto
    pjt[i].despesas.receitaDoProjeto=15000;
    i++;
//-------------------------------------------------------------------------------------------------
    //Código do Projeto
    pjt[i].codigo=i+1;
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
    pjt[i].despesas.salario_dev=1500;
    //Valor pago em Horas extras
    pjt[i].despesas.hrextra=900;
    //Valor pago para o Deslocamento de reuniões
    pjt[i].despesas.deslocReunioes=600;
    //Outros Gastos
    pjt[i].despesas.outrosGastos=150;
    //Receita do Projeto
    pjt[i].despesas.receitaDoProjeto=12000;
    i++;    
//-------------------------------------------------------------------------------------------------
    
    
    //Código do Projeto
    pjt[i].codigo=i+1;
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
    pjt[i].despesas.salario_dev=1700;
    //Valor pago em Horas extras
    pjt[i].despesas.hrextra=1500;
    //Valor pago para o Deslocamento de reuniões
    pjt[i].despesas.deslocReunioes=1000;
    //Outros Gastos
    pjt[i].despesas.outrosGastos=120;
    //Receita do Projeto
    pjt[i].despesas.receitaDoProjeto=14000;
//-------------------------------------------------------------------------------------------------
}

void opcao1 (prjt pjt[]){//Feito...O lucro Total dos projetos em andamento...não entendi como assim projetos em andamento e lucro é a receita - o resto das despesas certo? 
    system("cls");
    float lucro=0;
    int i;
    for ( i = 0; i < max; i++)
    {
        lucro=lucro+((pjt[i].despesas.receitaDoProjeto)-(pjt[i].despesas.deslocReunioes+pjt[i].despesas.hrextra+pjt[i].despesas.outrosGastos+pjt[i].despesas.salario_dev));
    }
    printf("\nO lucro de todos os projetos em andamentos sao:R$%.2f\n",lucro);
    system("pause");
    system("cls");
}

int main (){
    system("cls");
    prjt projetos[max];
    toTest(projetos);
    opcao1(projetos);

    printf("\nAte mais!!!\n \n");
    return 0;
}
