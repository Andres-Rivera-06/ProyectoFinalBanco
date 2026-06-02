#include <stdio.h>
#include "estructuras_banco.h"
#include <stdbool.h>
#include <string.h>


Transfer createTransfer(Account Accounts[]){
  Transfer transfer;

  char destinyAccount[20];
  char originAccount[20];
  float amount = 0;
  float shippingCost = 0;

  // pedir datos de transfrencia 
  
  bool existAccount = false;
  while(!existAccount){
    printf(" Ingrese el numero de cuenta de origen: ");
    scanf("%s", originAccount);
    if(verifyExistAccount(Accounts, originAccount)){
      existAccount = true;
    }else{
      printf(" No se encontro esta cuenta. \n");
    }
  }
  
  existAccount = false;
  while(!existAccount){
    printf(" Ingrese el numero de cuenta de destino: ");
    scanf("%s", destinyAccount);
    if(verifyExistAccount(Accounts, destinyAccount)){
      if(strcmp(originAccount, destinyAccount) == 0){
        printf(" La cuenta origen y destino no pueden ser la misma.\n");
      }else{
        existAccount = true;
      }
    }else{
      printf(" No se encontro esta cuenta. \n");
      JUMPSPACE();
    }
  }

  bool validAmount = false;
  while(!validAmount){
    printf(" Ingresa el valor a trasnferir :\n ");
    if(scanf("%f", &amount) != 1){
        printf(" Debe ingresar un numero valido.\n");
        while(getchar() != '\n');
        continue;
    }
    if(amount <= 0){
      printf(" El monto debe ser mayor que cero.\n");
    }else{
      shippingCost = TAX(amount);
      if(verifyBalanceAccount(Accounts, amount + shippingCost, originAccount)){
        for(int i = 0; i < countAccounts; i++){
          if(strcmp(Accounts[i].nAccount,originAccount)==0){
          Accounts[i].balance = Accounts[i].balance - amount - shippingCost;
          validAmount = true;
          break;
          }
        }
      }else{
      printf(" Saldo insuficiente.\n");
      }
    }
  }
  for(int i = 0; i < countAccounts; i++){
    if(strcmp(Accounts[i].nAccount,destinyAccount)==0){
      Accounts[i].balance = Accounts[i].balance + amount;
      break;
    }
  }
  Date date = createDate();
  transfer.amount = amount;
  transfer.dateTransfer = date;
  transfer.shippingcost = shippingCost;
  strcpy(transfer.originAccount, originAccount);
  strcpy(transfer.destinyAccount, destinyAccount);
  return transfer;
}


void showTransfer(Transfer transfer){
  printf("Numero de cuenta de origen: %s\n", transfer.originAccount);
  printf("Numero de cuenta de destino: %s\n", transfer.destinyAccount);
  printf("Monto de la tranferencia: %f\n", transfer.amount);
  printf("Impuesto por tranferencia:: %f\n", transfer.shippingcost);
  printf("Fecha de la tranferencia: ");
  showDate(transfer.dateTransfer);
}