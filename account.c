#include <stdio.h>
#include <string.h>
#include "estructuras_banco.h"

Account createAccount(Person persons[], Account Accounts[]){
  Account account;

  char nAccountAux[30];
  bool existNAccount = false;
  while (!existNAccount){
    printf("Ingrese el numero de cuenta: ");
    scanf("%s", nAccountAux);
    if(verifyExistAccount(Accounts, nAccountAux)){
      printf("Este numero de cuenta ya existe");
      JUMPSPACE();
    }else{
      strcpy(account.nAccount, nAccountAux);
      existNAccount = true;
    }
  }
  
  char idPerson[30];
  bool existPersonAccount = false;
  while (!existPersonAccount){
    printf("Ingrese la identificacion de la persona: ");
    scanf("%s", idPerson);
    if(verifyExistPerson(persons, idPerson)){
      existPersonAccount = true;
      strcpy(account.idPerson, idPerson);
    }else{
      printf("No se encontro una persona con ese numero de cedula\n");
    }
  }
  
  float balance = -1;
  while(balance < 0){
    printf("Ingrese el balance inicial de la cuenta: ");
    scanf("%f", &balance);
    if(balance < 0){
      printf("El balance inicial no puede ser menor a 0");
    }
  }
  account.balance = balance;
  
  return account;

}

bool verifyExistAccount(Account Accounts[], char nAccount[]){ 
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(Accounts[i].nAccount, nAccount) == 0){
      return true;
    }
  }
  return false;
}

bool consingAccount(Account Accounts[]){
  printf("Consignar dinero a una cuenta");
  JUMPSPACE();

  char nAccount[20];

  bool existAccount = false;
  while(!existAccount){
    printf("Ingrese el numero de cuenta: ");
    scanf("%s", nAccount);
    if(verifyExistAccount(Accounts, nAccount)){
      existAccount = true;
    }else{
      printf("No existe una cuenta con ese numero de cuenta. \n");
    }
  }

  float amount = -1;
  bool validAmount = false;
  while(!validAmount){
    printf("Ingrese la cantidad que desea consignar: ");
    if(scanf("%f", &amount) != 1){
        printf(" Debe ingresar un numero valido.\n");
        while(getchar() != '\n');
        continue;
    }
    if(amount < 0){
      printf("El monto no debe ser menor a 0");
    }else if(amount == 0){
      printf("El monto no debe ser cero");
      JUMPSPACE();
    }else{
      validAmount = true;
    } 
  }

  float aux = 0;
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(Accounts[i].nAccount, nAccount) == 0){
      Accounts[i].balance = Accounts[i].balance + amount;
      aux = Accounts[i].balance;
    }
  }
  printf("El nuevo monto de la cuenta es: %f", aux);
  return true;
}

bool verifyBalanceAccount(Account Accounts[], float amount, char nAccount[]){
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(Accounts[i].nAccount, nAccount) == 0){
      return amount <= Accounts[i].balance;
    }
  }
  return false;
}

bool withdrawAccount(Account Accounts[]){
  printf("Retirar dinero de la cuenta");

  char nAccount[20];

  bool existAccount = false;
  while(!existAccount){
    printf("Ingrese el numero de cuenta: ");
    scanf("%s", nAccount);
    if(verifyExistAccount(Accounts, nAccount)){
      existAccount = true;
    }else{
      printf("No existe una cuenta con ese numero de cuenta. \n");
    }
  }

  float amount = -1;
  bool validAmount = false;
  while(!validAmount){
    printf("Ingrese la cantidad que desea retirar: ");
    if(scanf("%f", &amount) != 1){
        printf(" Debe ingresar un numero valido.\n");
        while(getchar() != '\n');
        continue;
    }
    if(amount <= 0){
      printf("El monto a retirar debe ser mayor a cero");
      JUMPSPACE();
    }else{
      for(int i = 0; i < countAccounts; i++){
        if(strcmp(Accounts[i].nAccount, nAccount) == 0){
          if (Accounts[i].balance >= (amount + tax(amount))){
            validAmount = true;
          }
          else{
            printf("Fondos insuficientes");
            JUMPSPACE();
          }
        }
      }
    } 
  }
  float aux = 0;
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(Accounts[i].nAccount, nAccount) == 0){
      Accounts[i].balance = Accounts[i].balance - (amount + tax(amount));
      aux = Accounts[i].balance;
    }
  }
  printf("El nuevo monto de la cuenta es: %f", aux);
  return true;
}  


void showAccountTransfers(Account Accounts[], Transfer Transfers[]){

  char nAccount[20];

  bool existAccount = false;
  while(!existAccount){
    printf("Ingrese el numero de cuenta: ");
    scanf("%s", nAccount);
    if(verifyExistAccount(Accounts, nAccount)){
      existAccount = true;
    }else{
      printf("Ingrese un numero de una cuenta existente. \n");
      JUMPSPACE();
    }
  }

  for(int i = 0; i < countTransfers; i++){
    if(strcmp(Transfers[i].originAccount, nAccount) == 0){
      printf("--Tranferencia Enviada--\n");
      showTransfer(Transfers[i]);
    }else if(strcmp(Transfers[i].destinyAccount, nAccount) == 0){
      printf("--Tranferencia Recibida--");
      JUMPSPACE();
      showTransfer(Transfers[i]);
    }
  }
  
}

//Esta funcion solo se debe llamar si se esta seguro que la cuenta existe
Account getAccount(Account Accounts[], char nAccount[]){
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(Accounts[i].nAccount, nAccount) == 0){
      return Accounts[i];
    }
  }
  Account account;
  return account;
}

//funcion recursiva para calcular el interes que va a obtener una cuenta pasado x dias 
float calculate(float amount, int days){
  if(days == 1){
    return amount * 0.005;
  }
  return (amount * 0.005) + calculate(amount * 1.005, days - 1);
}

void earnings(Account Accounts[]){
  printf("Calcular ganacias por intereses");

  char nAccount[20];
  int days = 0;

  bool existAccount = false;
  while(!existAccount){
    printf("Ingrese el numero de cuenta: ");
    scanf("%s", nAccount);
    if(verifyExistAccount(Accounts, nAccount)){
      existAccount = true;
    }
  }

  while(days < 1){
    printf("Ingrese la cantidad de dias que desea calcular las ganancias");
    scanf("%d", &days);
    if(days < 1){
      printf("La cantidad de dias no puede ser menor a 1");
    }
  }

  Account account = getAccount(Accounts, nAccount);
  float amountEarnings = calculate(account.balance, days);

  printf("Las ganancias de la cuenta son de %f", amountEarnings);
  JUMPSPACE();
  printf("El total de la cuenta aplicando las ganacias seria %f", account.balance + amountEarnings);
  JUMPSPACE();

  int option = 0;
  while(option != 1 && option != 2){
    printf("Desea aplicar las ganancias a la cuenta?");
    JUMPSPACE();
    printf("1. Aplicar");
    JUMPSPACE();
    printf("2. Cancelar");
    JUMPSPACE();
    printf("Ingrese la opcion: ");
    scanf("%d", &option);
    if(option == 1){
      for(int i = 0; i < countAccounts; i++){
        if(strcmp(Accounts[i].nAccount, nAccount) == 0){
          Accounts[i].balance = Accounts[i].balance + amountEarnings;
        }
      }
    }else if(option == 2){
      JUMPSPACE();
    }else{
      printf("Ingrese una de las opciones");
      JUMPSPACE();
    }
  }
}