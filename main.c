#include <stdio.h>
#include "estructuras_banco.h"
#include <string.h>
#include <windows.h>

int countPersons = 0;
int countAccounts = 0;
int countTransfers = 0;

enum OptionMenu{
  GOOUT,
  CREATEPERSON,
  UPDATEPERSON,
  CREATEACCOUNT,
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
  printf(" _________________________________________\n");
  printf(" |                                        |\n");
  printf(" |  1.  CREAR PERSONA                     |\n");
  printf(" |  2.  ACTUALIZAR DATOS DE PERSONA       |\n");
  printf(" |  3.  CREAR CUENTA                      |\n");
  printf(" |  4.  VISUALIZAR PERSONAS               |\n");
  printf(" |  5.  VER MOVIMIENTOS                   |\n");
  printf(" |  6.  VER SALDOS                        |\n");
  printf(" |  7.  TRANSFERIR                        |\n");
  printf(" |  8.  RETIRAR                           |\n");
  printf(" |  9.  CONSIGNAR                         |\n");
  printf(" |  0.  SALIR                             |\n");
  printf(" |________________________________________|\n\n");
  JUMPSPACE();
  printf("  Ingrese un opcion:  ");

}

void main(){
  Person Persons[20];
  Account Accounts[40];
  Transfer Transfers[120];

  countPersons = readPersons(Persons);
  countAccounts = readAccounts(Accounts);
  countTransfers = readTransfers(Transfers);

  int option = 1;
  while (option != 0 ){
    JUMPSPACE();
    printf("Cargando menu...");
    Sleep(4000);
    menu();
    scanf("%d", &option);
    
    switch(option){
      case CREATEPERSON:
        if(countPersons < 20){
        printf("Agregar nueva persona\n");
        Person person = createPerson(Persons);
        Persons[countPersons] = person;
        countPersons = countPersons + 1;
        savePersons(Persons, countPersons);
        printf("Persona creada correctamente");
        }else{

        printf("No hay espacio para mas personas\n");
        }
        break;
      case UPDATEPERSON:
      updatePerson(Persons);
      savePersons(Persons, countPersons);
        break;
      case CREATEACCOUNT:
        if(countAccounts < 40){
        printf("Crear cuenta\n");
        Account account = createAccount(Persons, Accounts);
        Accounts[countAccounts] = account;
        countAccounts = countAccounts + 1;
        saveAccounts(Accounts, countAccounts);
        printf("Cuenta creada correstamente");
        }else{

        printf("No hay espacio para mas cuentas\n");
        }
        printf("Cuenta creada correctamente");
        break;
      case VIEWPERSONS:
        listPersons(Persons);
        break;
      case VIEWTRANSACTIONS:
        printf("Ver Movimientos");
        JUMPSPACE();
        showAccountTransfers(Accounts, Transfers);
        break;
      case VIEWBALANCES:
        printf("Ver balances persona");
        JUMPSPACE();
        viewBalances(Accounts, Persons);
        break;
      case TRANSFER:
          if(countTransfers < 120){
            Transfer transfer = createTransfer(Accounts);
            Transfers[countTransfers] = transfer;
            countTransfers = countTransfers + 1;
            saveAccounts(Accounts, countAccounts);
            saveTransfers(Transfers, countTransfers);
            printf("Transferencia exitosa");
          }else{
            printf("No hay espacio para mas transferencias\n");
          }
        break;
      case WITHDRAW:
        withdrawAccount(Accounts);
        saveAccounts(Accounts, countAccounts);
        break;
      case DEPOSIT:
        printf("Consignar cuenta");
        JUMPSPACE();
        if(consingAccount(Accounts)){
          saveAccounts(Accounts, countAccounts);
          printf("Consignacion exitosa");
          JUMPSPACE();
        }else{
          printf("Consignacion fallida, vuelva a intentarlo");
          JUMPSPACE();
        }
        break;
      case GOOUT:
        printf("Gracias por usar nuestro sistema");
        break;
      default:
      JUMPSPACE();
      printf("¡Opcion invalida!");
      JUMPSPACE();
      break;
      
    }
    
  }   
}