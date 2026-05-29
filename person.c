#include <stdio.h>
#include "estructuras_banco.h"

Person createPerson(){
  Person person;
  
  printf("Ingrese la identificacion: ");
  scanf("%s", person.id);

  printf("Ingrese el nombre: ");
  scanf("%s", person.name);

  printf("Ingrese el apellido: ");
  scanf("%s", person.lastname);

  printf("Ingrese la fecha de nacimiento: \n");
  person.dateOfBirth = createDate();

  printf("Ingrese la nacionalidad: ");
  scanf("%s", person.nationality);

  printf("Ingrese el telefono: ");
  scanf("%s", person.phone);

  printf("Ingrese el correo: ");
  scanf("%s", person.email);

  return person;
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


void listPersons(Person persons[], int countPersons){
  for (int i = 0; i < countPersons; i++){
    showPerson(persons[i]);
    printf("\n");
  }
}

bool existPerson(Person persons, int countPersons, char idPerson[]){
  for(int i = 0; i < countPersons; i++){
    
  }
}