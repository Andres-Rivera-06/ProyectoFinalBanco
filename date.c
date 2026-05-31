#include <stdio.h>
#include <stdbool.h>
#include "estructuras_banco.h"

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
      printf("Ingrese un año valido\n");
    }
  }
  date.year = year;

  while (month < 1 || month > 12){
    printf("Ingrese el mes: ");
    scanf("%d", &month);
    if(month < 1 || month > 12){
      printf("Ingrese un mes valido\n");
    }
  }
  date.month = month;

  while (day < 1 || day > 31){
    printf("Ingrese el dia: ");
    scanf("%d", &day);
    if (day < 1 || day > 31){
      printf("Ingrese un dia valido\n");
    }else{
      if(!checkDayMonth(day, month)){
        printf("Ingrese un dia valido para el mes seleccionado\n");
        day = 0;
      }else{
        date.day = day;
      }
    }
  }

  return date;
}

void showDate(Date date){
  printf("%d/%d/%d\n", date.day, date.month, date.year);
}