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

  verifyExistAccount(,1 , originAccount);
  
  printf(" Numero de cuenta destino : \n");
  scanf("%s", destinyAccount);

}