#include <stdio.h>
#include "estructuras_banco.h"

enum OptionMenu{
  CREATEPERSON = 1,
  CREATEACCOUNT,
  VIEWPERSONS,
  VIEWTRANSACTIONS,
  VIEWBALANCES,
  TRANSFER,
  WITHDRAW,
  DEPOSIT,
  UPDATEDATA
};

Person Persons[20];
Account Accounts[50];
Movement Movements[100];

int countPersons = 0;
int countAcconts = 0;
int countMovements = 0;



void menu(){
   
    printf("\n          BANCO NEOBANCK          \n");
    printf("  _____________________________________\n");
    printf(" |                                     |\n\n");
    printf(" |  1. CREAR PERSONA                   |\n");
    printf(" |  2. CREAR CUENTA                    |\n");
    printf(" |  3. VISUALIZAR PERSONAS             |\n");
    printf(" |  4. VER MOVIMIENTOS                 |\n");
    printf(" |  5. VER SALDOS                      |\n");
    printf(" |  6. TRANSFERIR                      |\n");
    printf(" |  7. RETIRAR                         |\n");
    printf(" |  8. CONSIGNAR                       |\n");
    printf(" |  9. ACTUALIZAR DATOS                |\n");
    printf(" |  0. SALIR                           |\n");
    printf(" |_____________________________________|\n\n");
    printf("  Ingrese un opcion:  ");

}       
    
void main(){
    
  int option = 1;

  while (option != 0 ){
    menu();
    scanf("%d", &option);
    
    switch(option){
      case CREATEPERSON:
  
        break;
      case CREATEACCOUNT:

        break;
      case VIEWPERSONS:
      
        break;
      case VIEWTRANSACTIONS:
        
          break;
      case VIEWBALANCES:
        
          break;
      case TRANSFER:
        
          break;
      case WITHDRAW:
        
          break;
      case DEPOSIT:
        
          break;
      case UPDATEDATA:
        
        break;

    default:
      printf("\n ¡Opcion invalida!\n");
      break;
      
    }
    
  }
      
    
}