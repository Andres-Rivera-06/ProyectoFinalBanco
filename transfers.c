#include <stdio.h>
#include <estructuras_banco.h>
#include <stdbool.h>


bool transfers(Account Accounts[]){
  Account transfers;

  char originAccount[20];
  char destinyAccount[20];
  float amount;
  float availableBalance;
  float shippingCost;

  // pedir datos de transfrencia 

  printf(" Numero de cuenta origen : \n");
  scanf("%s", originAccount);

  verifyExistAccount(Accounts, originAccount);
  
  printf(" Numero de cuenta destino : \n");
  scanf("%s", destinyAccount);

  verifyExistAccount(Accounts, destinyAccount);

  printf(" El saldo de la cuenta origen es : %f");

}