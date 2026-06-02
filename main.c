#include <stdio.h>
#include "estructuras_banco.h"

int countPersons = 0;
int countAccounts = 0;
int countTransfers = 0;

enum OptionMenu{
  GOOUT = 0,
  CREATEPERSON,
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
  JUMPSPACE();
  JUMPSPACE();
  JUMPSPACE();
  printf("\n          BANCO NEOBANCK          \n");
  printf(" _________________________________________");
  JUMPSPACE();
  printf(" |                                        |\n");
  printf(" |  1.  CREAR PERSONA                     |");
  JUMPSPACE();
  printf(" |  2.  ACTUALIZAR DATOS DE PERSONA       |\n");
  printf(" |  3.  CREAR CUENTA                      |\n");
  printf(" |  4.  ACTUALIZAR DATOS DE CUENTA        |\n");
  printf(" |  5.  VISUALIZAR PERSONAS               |\n");
  printf(" |  6.  VER MOVIMIENTOS                   |\n");
  printf(" |  7.  VER SALDOS                        |\n");
  printf(" |  8.  TRANSFERIR                        |\n");
  printf(" |  9.  RETIRAR                           |\n");
  printf(" |  10. CONSIGNAR                         |\n");
  printf(" |  0.  SALIR                             |\n");
  printf(" |________________________________________|\n\n");
  printf("  Ingrese un opcion:  ");

}

void main(){
  Person Persons[20];
  Account Accounts[40];
  Transfer Transfers[120];
  int option = 1;

  while (option != 0 ){
    menu();
    scanf("%d", &option);
    
    switch(option){
      case CREATEPERSON:
        printf("Agregar nueva persona\n");
        Person person = createPerson(Persons);
        Persons[countPersons] = person;
        countPersons = countPersons + 1;
        printf("Persona creada correctamente");
        break;
      case UPDATEPERSON:
        updatePerson(Persons);
        break;
      case CREATEACCOUNT:
        printf("Crear cuenta\n");
        Account account = createAccount(Persons);
        Accounts[countAccounts] = account;
        countAccounts = countAccounts + 1;
        printf("Cuenta creada correctamente");
        break;
      case UPDATEACCOUNT:
    
        break;
      case VIEWPERSONS:
        listPersons(Persons);
        break;
      case VIEWTRANSACTIONS:
        printf("Ver Movimientos");
        showAccountTransfers(Accounts, Transfers);
        break;
      case VIEWBALANCES:
        printf("Ver balances persona");
        JUMPSPACE();
        viewBalances(Accounts, Persons);
        break;
      case TRANSFER:
        Transfer transfer = createTransfer(Accounts);
        Transfers[countTransfers] = transfer;
        countTransfers = countTransfers + 1;
        printf("Transferencia exitosa");
        break;
      case WITHDRAW:
        
        break;
      case DEPOSIT:
        printf("Consignar cuenta\n");
        if(consingAccount(Accounts)){
          printf("Consignacion exitosa");
        }else{
          printf("Consignacion fallida, vuelva a intentarlo");
        }
        break;
      case GOOUT:
        printf("Gracias por usar nuestro sistema");
        break;
      default:
      JUMPSPACE();
      printf(" ¡Opcion invalida!");
      JUMPSPACE();
      break;
      
    }
    
  }   
}