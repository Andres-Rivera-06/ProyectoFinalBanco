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
  DEPOSIT,
  CALCULATEARNINGS,
  DELETEPERSON
};



void menu(){
  JUMPSPACE();
  JUMPSPACE();
  JUMPSPACE();
  
  SetConsoleOutputCP(CP_UTF8);     //comando que permite caracteres especiales en la consola
  printf("\n");
  printf(" ╔════════════════════════════════════════╗\n");
  printf(" ║             BANCO NEOBANK              ║\n");
  printf(" ╟────────────────────────────────────────╢\n");
  printf(" ║  1.  CREAR PERSONA                     ║\n");
  printf(" ║  2.  ACTUALIZAR DATOS DE PERSONA       ║\n");
  printf(" ║  3.  CREAR CUENTA                      ║\n");
  printf(" ║  4.  VISUALIZAR PERSONAS               ║\n");
  printf(" ║  5.  VER MOVIMIENTOS                   ║\n");
  printf(" ║  6.  VER SALDOS                        ║\n");
  printf(" ║  7.  TRANSFERIR                        ║\n");
  printf(" ║  8.  RETIRAR                           ║\n");
  printf(" ║  9.  CONSIGNAR                         ║\n");
  printf(" ║ 10.  CALCULAR GANANCIAS POR INTERESES  ║\n");
  printf(" ║ 11.  ELIMINAR PERSONA                  ║\n");
  printf(" ╟────────────────────────────────────────╢\n");
  printf(" ║  0.  SALIR                             ║\n");
  printf(" ╚════════════════════════════════════════╝\n");
  JUMPSPACE();
  printf("Ingrese un opcion:  ");

}

void main(){
  Person Persons[20];
  Account Accounts[40];
  Transfer Transfers[120];
                                                           
  countPersons = readPersons(Persons);               
  countAccounts = readAccounts(Accounts);         // carga informacion al iniciar el sistema
  countTransfers = readTransfers(Transfers);       

  int option = 1;
  while (option != 0 ){
    JUMPSPACE();
    printf("Cargando menu..."); // crea un delay antes de mostrar el menu.
    Sleep(4000);
    menu();
    scanf("%d", &option);
    
    switch(option){
      case CREATEPERSON:
        if(countPersons < 20){
        printf("Agregar nueva persona\n");
        Person person = createPerson(Persons);
        Persons[countPersons] = person;                // crea una persona nueva en el sistema e inmediatamente la guarda.
        countPersons = countPersons + 1;
        savePersons(Persons, countPersons);
        printf("Persona creada correctamente");
        }else{

        printf("No hay espacio para mas personas\n");
        }
        break;
      case UPDATEPERSON:
      updatePerson(Persons);                     // actualiza una persona e inmediatamente la guarda.
      savePersons(Persons, countPersons);
        break;
      case CREATEACCOUNT:
        if(countAccounts < 40){
          printf("Crear cuenta\n");
          Account account = createAccount(Persons, Accounts);
          Accounts[countAccounts] = account;                      // crea una cuenta nueva en el sistema e inmediatamente la guarda.
          countAccounts = countAccounts + 1;
          saveAccounts(Accounts, countAccounts);
          printf("Cuenta creada correctamente");
          JUMPSPACE();
        }else{
          printf("No hay espacio para mas cuentas");
          JUMPSPACE();
        }
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
            countTransfers = countTransfers + 1;                // crea una transferencia nueva en el sistema e inmediatamente la guarda.
            saveAccounts(Accounts, countAccounts);
            saveTransfers(Transfers, countTransfers);
            printf("Transferencia exitosa");
          }else{
            printf("No hay espacio para mas transferencias\n");
          }
        break;
      case WITHDRAW:
        withdrawAccount(Accounts);                // retira dinero de una cuenta e inmediatamente la guarda.
        saveAccounts(Accounts, countAccounts);
        break;
      case DEPOSIT:
        printf("Consignar cuenta");
        JUMPSPACE();
        if(consingAccount(Accounts)){
          saveAccounts(Accounts, countAccounts);       // consigna dinero a una cuenta e inmediatamente guarda la cuenta con el nuevo valor.
          printf("Consignacion exitosa");
          JUMPSPACE();
        }else{
          printf("Consignacion fallida, vuelva a intentarlo");
          JUMPSPACE();
        }
        break;
      case CALCULATEARNINGS:
        earnings(Accounts);
        saveAccounts(Accounts, countAccounts);
        break;
      case DELETEPERSON:
        if(deletePerson(Persons, Accounts, Transfers)){
          saveAccounts(Accounts, countAccounts);
          savePersons(Persons, countPersons);
          saveTransfers(Transfers, countTransfers);
        }else{
          printf("No se pudo eliminar la persona");
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