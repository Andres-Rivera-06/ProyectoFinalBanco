#include <stdio.h>
#include "estructuras_banco.h"

int countPersons = 0;
int countAccounts = 0;
int countTransfers = 0;

enum OptionMenu{
  CREATEPERSON = 1,
  UPDATEPERSON,
  CREATEACCOUNT,
  UPDATEACCOUNT,
  VIEWPERSONS,
  VIEWTRANSACTIONS,
  VIEWBALANCES,
  TRANSFER,
  WITHDRAW,
  DEPOSIT
};



void menu(){
   
  printf("\n          BANCO NEOBANCK          \n");
  printf("  _______________________________________\n");
  printf(" |                                       |\n\n");
  printf(" |  1. CREAR PERSONA                     |\n");
  printf(" |  2. ACTUALIZAR DATOS DE PERSONA       |\n");
  printf(" |  3. CREAR CUENTA                      |\n");
  printf(" |  4. ACTUALIZAR DATOS DE CUENTA        |\n");
  printf(" |  5. VISUALIZAR PERSONAS               |\n");
  printf(" |  6. VER MOVIMIENTOS                   |\n");
  printf(" |  7. VER SALDOS                        |\n");
  printf(" |  8. TRANSFERIR                        |\n");
  printf(" |  9. RETIRAR                           |\n");
  printf(" |  10. CONSIGNAR                        |\n");
  printf(" |  0. SALIR                             |\n");
  printf(" |_______________________________________|\n\n");
  printf("  Ingrese un opcion:  ");

}

void main(){
  Person Persons[20];
  Account Accounts[50];
  Transfer Transfers[100];
  int option = 1;

  while (option != 0 ){
    menu();
    scanf("%d", &option);
    
    switch(option){
      case CREATEPERSON:
        printf("Agregar nueva persona\n");
        Person person = createPerson();
        printf("%s", person.name);
        Persons[countPersons] = person;
        countPersons = countPersons + 1;
        printf("Persona creada correctamente");
        break;
      case UPDATEPERSON:
  
        break;
      case CREATEACCOUNT:
        printf("Crear cuenta\n");
        Account account = createAccount(Persons);
        Accounts[countAccounts] = account;
        countAccounts = countAccounts + 1;
        printf("Cuenta creada correstamente");
        break;
      case UPDATEACCOUNT:
    
        break;
      case VIEWPERSONS:
        listPersons(Persons);
        break;
      case VIEWTRANSACTIONS:
        
        break;
      case VIEWBALANCES:
        
        break;
      case TRANSFER:
        
        break;
      case WITHDRAW:
        
        break;
      case DEPOSIT:
        
        break;
      default:
      printf("\n ¡Opcion invalida!\n");
      break;
      
    }
    
  }   
}