#include <stdio.h>
#include "estructuras_banco.h"
#include <string.h>

enum UpdatePersonOption{
  GOOUT = 0,
  NAME,
  LASTNAME,
  DATEOFBIRTH,
  NATIONALITY,
  PHONE,
  EMAIL
};


Person createPerson(Person Persons[]){
  Person person;
  
  char idPerson[30];
  bool existPerson = false;
  while (!existPerson){
    printf("Ingrese la identificacion: ");
    scanf("%s", idPerson);
    if(verifyExistPerson(Persons, idPerson)){
      printf("Ya existe una persona con esa identificacion");
    }else{
      strcpy(person.id, idPerson);
      existPerson = true;
    }
  }

  printf("Ingrese el nombre: ");
  scanf("%s", person.name);

  printf("Ingrese el apellido: ");
  scanf("%s", person.lastname);

  printf("Fecha de nacimiento \n");
  person.dateOfBirth = createDate();

  printf("Ingrese la nacionalidad: ");
  scanf("%s", person.nationality);

  printf("Ingrese el telefono: ");
  scanf("%s", person.phone);

  printf("Ingrese el correo electronico: ");
  scanf("%s", person.email);

  return person;
}


void showMenuEditPerson(){
  printf(" 1. Nombre");
  JUMPSPACE();
  printf(" 2. Apellido");
  JUMPSPACE();
  printf(" 3. Fecha de nacimiento");
  JUMPSPACE();
  printf(" 4. Numero de telefono");
  JUMPSPACE();
  printf(" 5. Correo electronico");
  JUMPSPACE();
}

bool updatePerson(Person Persons[]){
  char idPerson[30];
  bool existAccount = false;
  int option = 1;
  char name[30];
  char lastname[30];
  Date dateOfBirth;
  char nationality[30];
  char phone[20];
  char email[50];


  while(!existAccount){
  
    printf("Ingrese el numero de cuenta de la que desea modificar los datos: ");
    scanf("%s", idPerson);
    if(verifyExistPerson(Persons, idPerson)){
      
      while(option != 0){
        showMenuEditPerson();
        printf("Ingrese una opcion ");
        scanf("%d", &option);

        switch (option){
        case NAME:
          printf("Ingrese el nuevo nombre: ");
          scanf("%s", name);
          for(int i = 0; i < countPersons; i++){
            if(stricmp(Persons[i].id, idPerson) == 0){
              strncpy(Persons[i].name, name, sizeof(Persons[i].name) - 1);
              printf("Cambio de nombre exitoso");
            }
          }
          break;

        case LASTNAME:
          printf("Ingrese el nuevo apellido: ");
          scanf("%s", lastname);
          for(int i = 0; i < countPersons; i++){
            if(stricmp(Persons[i].id, idPerson) == 0){
              strncpy(Persons[i].lastname, lastname, sizeof(Persons[i].lastname) - 1);
              printf("Cambio de apellido exitoso");
            }
          }
          break;

        case DATEOFBIRTH:
          printf("Modificar fecha de nacimiento");
          dateOfBirth = createDate();
          for(int i = 0; i < countPersons; i++){
            if(stricmp(Persons[i].id, idPerson) == 0){
              Persons[i].dateOfBirth = dateOfBirth;
              printf("Cambio de fecha de nacimiento exitoso");
            }
          }
          break;

        case NATIONALITY:
          printf("Ingrese la nacionalidad");
          scanf("%s", nationality);
          for(int i = 0; i < countPersons; i++){
            if(stricmp(Persons[i].id, idPerson) == 0){
              strncpy(Persons[i].nationality, nationality, sizeof(Persons[i].nationality) - 1);
              printf("Cambio de nacionalidad exitoso");
            }
          }
          break;

        case PHONE:
          printf("Ingrese el nuevo numero de telefono");
          scanf("%s", phone);
          for(int i = 0; i < countPersons; i++){
            if(stricmp(Persons[i].id, idPerson) == 0){
              strncpy(Persons[i].phone, phone, sizeof(Persons[i].phone) - 1);
              printf("Cambio de telefono exitoso");
            }
          }
          break;

        case EMAIL:
          printf("Ingrese el nuevo correo");
          scanf("%s", email);
          for(int i = 0; i < countPersons; i++){
            if(stricmp(Persons[i].id, idPerson) == 0){
              strncpy(Persons[i].email, email, sizeof(Persons[i].email) - 1);
              printf("Cambio de telefono exitoso");
            }
          }
          break;

        default:
          break;
        }
      }
      
    }else{
      JUMPSPACE();
      printf("No se encontro esta persona");
      JUMPSPACE();
    }
  }
  return true;
}


void showPerson(Person person){
  printf("Identificacion: %s", person.id);
  JUMPSPACE();
  printf("Nombre: %s", person.name);
  JUMPSPACE();
  printf("Apellido: %s", person.lastname);
  JUMPSPACE();
  printf("Fecha de nacimiento: ");
  showDate(person.dateOfBirth);
  printf("Nacionalidad: %s", person.nationality);
  JUMPSPACE();
  printf("Telefono: %s", person.phone);
  JUMPSPACE();
  printf("Correo: %s", person.email);
  JUMPSPACE();
}

bool readPerson(Person Persons[]){
  char idPerson[30];
  bool existPerson = false;
  while(!existPerson){
    printf("Ingrese la identificacion de la persona de la que desea ver los saldos: ");
    scanf("%s", idPerson);
    if(verifyExistPerson(Persons, idPerson)){ 
      for (int i = 0; i < countPersons; i++){
        if(strcmp(Persons[i].id, idPerson)){
          showPerson(Persons[i]);
          return true;
        }
      }
    }else{
      printf("No se encontro una persona con esa identificacion");
      return false;
    }
  }
  return false;
}

void listPersons(Person persons[]){
  for (int i = 0; i < countPersons; i++){
    showPerson(persons[i]);
    printf("\n");
  }
}

bool verifyExistPerson(Person persons[], char idPerson[]){
  for(int i = 0; i < countPersons; i++){
    if(strcmp(persons[i].id, idPerson) == 0){
      return true;
    }
  }
  return false;
}

void viewBalances(Account Accounts[], Person Persons[]){
  char idPerson[30];
  bool existPerson = false;
  while(!existPerson){
    printf("Ingrese la identificacion de la persona de la que desea ver los saldos: ");
    scanf("%s", idPerson);
    if(verifyExistPerson(Persons, idPerson)){
      int countAccountsPerson = 0;
      for(int i = 0; i < countAccounts; i++){
        if(strcmp(Accounts[i].idPerson, idPerson)){
          printf("Numero de cuenta: %s", Accounts[i].nAccount);
          JUMPSPACE();
          printf("Balance: %f", Accounts[i].balance);
          JUMPSPACE();
          countAccountsPerson++;
        }
      }
      if(countAccountsPerson == 0){
        printf("No se encontraron cuentas asociadas a la persona ingresada");
        JUMPSPACE();
      }
    }else{
      JUMPSPACE();
      printf("No se encontro una persona con ese numero");
    }
  }
}