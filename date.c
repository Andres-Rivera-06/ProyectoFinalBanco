#include <stdio.h>
#include <stdbool.h>
#include "estructuras_banco.h"

enum UpdateDateOption{
  GOOUT,
  DAY,
  MONTH,
  YEAR
};

bool checkDayMonth(int day, int month){
  switch (month){
  case 1:
    if(day <= 31){
      return true;
    }
    break;
  case 2:
    if(day <= 28){
      return true;
    }
    break;
  case 3:
    if(day <= 31){
      return true;
    }
    break;
  case 4:
    if(day <= 30){
      return true;
    }
    break;
  case 5:
    if(day <= 31){
      return true;
    }
    break;
  case 6:
    if(day <= 30){
      return true;
    }
    break;
  case 7:
    if(day <= 31){
      return true;
    }
    break;
  case 8:
    if(day <= 31){
      return true;
    }
    break;
  case 9:
    if(day <= 30){
      return true;
    }
    break;
  case 10:
    if(day <= 31){
      return true;
    }
    break;
  case 11:
    if(day <= 30){
      return true;
    }
    break;
  case 12:
    if(day <= 31){
      return true;
    }
    break;
  default:
    break;
  }
  return false;
}

Date createDate(){
  Date date;
  int day = 0, month = 0, year = 0;
  
  while (year < 1900){
    
    printf("Ingrese el anio: ");
    scanf("%d", &year);
    if (year < 1900){
      printf("Ingrese un anio valido");
      JUMPSPACE();
    }
  }
  date.year = year;

  while (month < 1 || month > 12){
    printf("Ingrese el mes: ");
    scanf("%d", &month);
    if(month < 1 || month > 12){
      printf("Ingrese un mes valido");
      JUMPSPACE();
    }
  }
  date.month = month;

  while (day < 1 || day > 31){
    printf("Ingrese el dia: ");
    scanf("%d", &day);
    if (day < 1 || day > 31){
      printf("Ingrese un dia valido");
      JUMPSPACE();
    }else{
      if(!checkDayMonth(day, month)){
        printf("Ingrese un dia valido para el mes seleccionado");
        JUMPSPACE();
        day = 0;
      }else{
        date.day = day;
      }
    }
  }

  return date;
}

void showDate(Date date){
  printf("%d/%d/%d", date.day, date.month, date.year);
  JUMPSPACE();
}

void showMenuEditDate(){
  printf("1. Dia");
  JUMPSPACE();
  printf("2. mes");
  JUMPSPACE();
  printf("3. Anio");
  JUMPSPACE();
}

Date updateDate(Date date){
  int day = date.day;
  int month = date.month;
  int year = date.year;

  bool validDate;
  int option = 1;
  while(option != 0){
    validDate = false;
    printf("Ingrese la opcion: ");
    scanf("%d", &option);
    switch (option){
    case DAY:
      
      while(!validDate){
        printf("Ingrese el dia: ");
        scanf("%d", &day);
        if(checkDayMonth(day, month)){
          validDate = true;
          date.day = day;
          printf("Dia actualizado exitosamente");
          JUMPSPACE();
        }else{
          printf("La fecha ingresada no es valida");
        }
      }
      break;
    case MONTH:
              
      while(!validDate){
        printf("Ingrese el mes: ");
        scanf("%d", &month);
        if(checkDayMonth(day, month)){
          date.month = month;
          validDate = true;
          printf("Mes actualizado exitosamente");
          JUMPSPACE();
        }else{
          printf("La fecha ingresada no es valida");
        }
      }
      break;

    case YEAR:
              
      while(!validDate){
        printf("Ingrese el anio: ");
        scanf("%d", &year);
        if(year < 1900){
          date.year = year;
          validDate = true;
          printf("Anio actualizado exitosamente");
          JUMPSPACE();
        }else{
          printf("La fecha ingresada no es valida");
          JUMPSPACE();
        }
      }
      break;
    case GOOUT:
      break;
    default:
      break;
    }
  }
  return date;
}