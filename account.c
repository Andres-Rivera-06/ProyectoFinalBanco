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
    if(existPerson(persons, idPerson)){
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
    }else{
      validAmount = true;
    } 
  }
  int aux = 0;
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(Accounts[i].nAccount, nAccount)){
      Accounts[i].balance = Accounts[i].balance + amount;
      aux = Accounts[i].balance;
    }
  }
  printf("El nuevo monto de la cuenta es: %f", aux);
  return true;
}

bool verifyBalanceAccoun(Account accounts[], float amount, char nAccount[]){
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(accounts[i].nAccount, nAccount) == 0){
      return amount <= accounts[i].balance;
    }
  }
  return false;
}


float retiro (float amount, char nAccount[]){
  if ( strcmp(nAccount[].nAccount)) 
  } float retiro (float amount, char nAccount[]){
    float withdraw;
    printf("Ingrese la cantidad que desea retirar: ");
    scanf("%f", &withdraw);
    if (withdraw > amount){
      printf("fondos insuficientes");
    }else{
      withdraw = amount - calcularImpuesto(withdraw);
      printf("el monto a retirar es: %f", withdraw);) 
    }
}

void showAccountTransfers(Account Accounts[], Transfer transfers[]){

  char nAccount[20];

  bool existAccount = false;
  while(!existAccount){
    printf("Ingrese el numero de cuenta: ");
    scanf("%s", nAccount);
    if(verifyExistAccount(Accounts, nAccount)){
      existAccount = true;
    }else{
      printf("Ingrese un numero de una cuenta existente.");
    }
  }

  for(int i = 0; i < countTransfers; i++){
    if(strcmp(transfers[i].originAccount, nAccount) == 0){
      printf("--Tranferencia Enviada--\n");
      showTransfer(transfers[i]);
    }else if(strcmp(transfers[i].destinyAccount, nAccount) == 0){
      printf("--Tranferencia Recibida--\n");
      showTransfer(transfers[i]);
    }
  }
  
}