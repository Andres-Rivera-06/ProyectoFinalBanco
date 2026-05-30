#include <stdio.h>
#include <string.h>
#include "estructuras_banco.h"

Account createAccount(Person persons[], int countPersons){
  Account account;

  printf("Ingrese el numero de cuenta: ");
  scanf("%s", account.nAccount);
  
  char idPerson[30];
  bool existPersonAccount = false;
  while (!existPersonAccount){
    printf("Ingrese la identificacion de la persona: ");
    scanf("%s", idPerson);
    if(existPerson(persons, countPersons, idPerson)){
      existPersonAccount = true;
      strcpy(account.idPerson, idPerson);
    }
  }
  
  float balance = -1;
  while(balance < 0){
    print("Ingrese el balance inicial de la cuenta: ");
    scanf("%f", &balance);
    if(balance < 0){
      print("El balance inicial no puede ser menor a 0");
    }
  }
  account.balance = balance;
  
  return account;

}

bool verifyExistAccount(Account accounts[], char nAccount[]){ 
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(accounts[i].nAccount, nAccount) == 0){
      return true;
    }
  }
  return false;
}

bool consingAccount(Account accounts[], int countAccount){
  printf("Consignar dinero a una cuenta");

  char nAccount[30];

  bool existAccount = false;
  while(!existAccount){
    printf("Ingrese el numero de cuenta: ");
    scanf("%s", nAccount);
    if(verifyExistAccount(accounts, countAccount, nAccount)){
      existAccount = true;
    }else{
      printf("Ingrese un numero de una cuenta existente.");
    }
  }

  float amount = -1;
  bool validAmount = false;
  while(!validAmount){
    printf("Ingrese la cantidad que desea consignar: ");
    scanf("%f", amount);
    if(amount < 0){
      printf("El monto no debe ser menor a 0");
    }else{
      validAmount = true;
    }
  }
  
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(accounts[i].nAccount, nAccount)){
      accounts[i].balance = accounts[i].balance + amount;
    }
  }

  return true;
}

bool verifyBalanceAccoun(Account accounts[], float amount, char nAccount){
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(accounts[i].nAccount, nAccount) == 0){
      return amount <= accounts[i].balance;
    }
  }
  return false;
}


float retiro (float amount, char nAccount[]){
}

void showAccountTransfers(Account Accounts){

  char nAccount[30];

  bool existAccount = false;
  while(!existAccount){
    printf("Ingrese el numero de cuenta: ");
    scanf("%s", nAccount);
    if(verifyExistAccount(accounts, countAccount, nAccount)){
      existAccount = true;
    }else{
      printf("Ingrese un numero de una cuenta existente.");
    }
  }
  
}