#include <stdio.h>      
#include <string.h>   
#include <stdlib.h>
#define SIZE 200

char nome[SIZE][50];
char email[SIZE][50];
int NIF [SIZE];
int op; 

void cadastro();
void pesquisa();
void lista();

int main(void) {
  do{
    system("cls"); 
     printf("-----MENU-----\n1 - cadastrar\n2 - Listar todos\n3 - pesquisar\n4 - sair \n Selecione uma opcao: ");
    scanf("%d", &op);
    switch(op){
      case 1 :
        cadastro();
        break;
      case 2 :
        lista();
        break;
      case 3 :
        pesquisa();
        break;
      case 4 :
        system("exit");
        break;
      default:
      printf("ivalido");
      break;

    }
  }while(op != 4);
  return 0;
}

void lista(){
  int i ; 
  for(i = 0; i<SIZE; i++){
    if(NIF[i]> 0){
      printf("\nNome: %s \nEmail: %s \nNIF: %d\n-----------------------", nome[i], email[i], NIF[i]);
    }else{
      break;
    }
    
  }
  getchar();
  getchar();
}

void cadastro(){
  static int linha;
  do{
    printf("\n Digite o nome: "); 
    scanf("%s",&nome[linha] ); 
    printf("\n Digite o email: "); 
    scanf("%s",&email[linha] ); 
    printf("\n Digite o NIF: "); 
    scanf("%d",&NIF[linha] ); 


    printf("\n Digite 1 para continuar ou outro valor para sair");
    scanf("%d", &op);

    linha++;
  }while(op == 1);
}

void pesquisa(){ 
  int NIFpesquisa;
  char emailpesquisa[50];
  int i;
  do{
    printf("\n Digite 1 para pesquisar por  NIF ou 2 para pesquisar por email"); 
    scanf("%d", &op);

    switch(op){
      case 1: 
        printf("\n Digite o NIF: ");
        scanf("%d",&NIFpesquisa);
        for(i = 0; i<SIZE; i++ ){
          if(NIF[i] == NIFpesquisa ){
            printf("\n Nome: %s \nEmail: %s \nNIF: %d", nome[i], email[i], NIF[i]);
          }
        }
        break;
      case 2:
        printf("\n Digite o email: ");
         scanf("%s",&emailpesquisa);
         for(i = 0; i<SIZE; i++ ){
          if(strcmp(email[i], emailpesquisa)){
            printf("\n Nome: %s \nEmail: %s \nNIF: %d", nome[i], email[i], NIF[i]);
          }
        }
        break;
      default:
           printf("\n Opcao invalida");
    }
     printf("\n Digite 1 para continuar pesquisando");
           scanf("%d", &op);
  }while(op == 1);
}
