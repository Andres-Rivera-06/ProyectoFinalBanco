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


Person createPerson(){
  Person person;
  
  printf("Ingrese la identificacion: ");
  scanf("%s", person.id);

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
        prinf("Ingrese una opcion ");
        scanf("%d", &option);

        switch (option)
        {
        case NAME:
          printf("Ingrese el numero nombre: ");
          scanf("%s", name);
          for(int i = 0; i < countPersons; i++){
            if(stricmp(Persons[i].id, idPerson) == 0){
              strncpy(Persons[i].name, name, sizeof(Persons[i].name) - 1);
              printf("Cambio de nombre exitoso");
            }
          }
          break;
        
        default:
          break;
        }
      }
      
    }else{
      printf("\nNo se encontro esta persona");
    }
  }

}

void showMenuEditPerson(){
  printf(" 1. Nombre\n");
  printf(" 2. Apellido\n");
  printf(" 3. Fecha de nacimiento\n");
  printf(" 4. Numero de telefono\n");
  printf(" 5. Correo electronico\n");
}

void showPerson(Person person){
  printf("Identificacion: %s\n", person.id);
  printf("Nombre: %s\n", person.name);
  printf("Apellido: %s\n", person.lastname);
  printf("Fecha de nacimiento: ");
  showDate(person.dateOfBirth);
  printf("Nacionalidad: %s\n", person.nationality);
  printf("Telefono: %s\n", person.phone);
  printf("Correo: %s\n", person.email);
}


void listPersons(Person persons[]){
  printf("holin in list persons");
  for (int i = 0; i < countPersons; i++){
    printf("Nombre en list persons: %s", persons[i].name);
    showPerson(persons[i]);
    printf("\n");
  }
}

bool verifyExistPerson(Person persons[], char idPerson[]){
  for(int i = 0; i < countPersons; i++){
    if(strcmp(persons[i].id, idPerson)){
      return true;
    }
  }
  return false;
}