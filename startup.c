#include<stdio.h>
#include<stdlib.h>
#include "dadosFixos.h"
#include "menu.h"
#define max 3// o tanto de projetos que quiser 
int main (){
    system("cls");
    prjt projetos[max];
    //toTest(projetos);//para inserir dados fixos da biblioteca
    inserirPj(projetos);//função para inserir no terminal manualmente
    menu(projetos);
    return 0;
}
