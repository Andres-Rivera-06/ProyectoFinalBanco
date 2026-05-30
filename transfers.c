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


void showTransfer(Transfer transfer){
  printf("Numero de cuenta de origen: %s\n", transfer.originAccount);
  printf("Numero de cuenta de destino: %s\n", transfer.destinyAccount);
  printf("Monto de la tranferencia: %f\n", transfer.amount);
  printf("Impuesto por tranferencia:: %f\n", transfer.shippingcost);
  printf("Fecha de la tranferencia: ");
  showDate(transfer.dateTransfer);
}