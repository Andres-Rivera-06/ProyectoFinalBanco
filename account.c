#include <stdio.h>
#include <string.h>
#include "estructuras_banco.h"

Account createAccount(Person persons[]){
  Account account;

  printf("Ingrese el numero de cuenta: ");
  scanf("%s", account.nAccount);
  
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
      printf("No existe una cuenta con ese numero de cuenta.");
    }
  }

  float amount = -1;
  bool validAmount = false;
  while(!validAmount){
    printf("Ingrese la cantidad que desea consignar: ");
    scanf("%f", &amount);
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
      printf("No existe una cuenta con ese numero de cuenta.");
    }
  }

  float amount = -1;
  bool validAmount = false;
  while(!validAmount){
    printf("Ingrese la cantidad que desea retirar: ");
    scanf("%f", &amount);
    if(amount < 0){
      printf("El monto a retirar no puede ser menor a 0");
      JUMPSPACE();
    }else{
      validAmount = true;
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
      printf("Ingrese un numero de una cuenta existente.");
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