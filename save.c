#include <stdio.h>
#include "estructuras_banco.h"
#include <string.h>

void savePersons(Person persons[], int countPersons){
    FILE *file = fopen("persons.dat", "wb");
    if(file == NULL){
        printf("Error al abrir el archivo persons.dat\n");
        return;
    }
    fwrite(persons, sizeof(Person), countPersons, file);
    fclose(file);
}

int readPersons(Person persons[]){
    FILE *file = fopen("persons.dat", "rb");
    int countPersons = 0;
    if(file == NULL){
        return 0;
    }
    while(
        fread(&persons[countPersons],sizeof(Person),1,file) == 1){
        countPersons++;
    }
    fclose(file);
    return countPersons;
}

void saveAccounts(Account accounts[], int countAccounts){
    FILE *file = fopen("accounts.dat", "wb");
    if(file == NULL){
        printf("Error al abrir el archivo accounts.dat\n");
        return;
    }
    fwrite(accounts, sizeof(Account), countAccounts, file);
    fclose(file);
}

int readAccounts(Account accounts[]){
    FILE *file = fopen("accounts.dat", "rb");
    int countAccounts = 0;
    if(file == NULL){
        return 0;
    }
    while(
        fread(&accounts[countAccounts],sizeof(Account),1,file) == 1){
        countAccounts++;
    }
    fclose(file);
    return countAccounts;
}

void saveTransfers(Transfer transfers[], int countTransfers){
    FILE *file = fopen("transfers.dat", "wb");
    if(file == NULL){
        printf("Error al abrir el archivo transfers.dat\n");
        return;
    }
    fwrite(transfers, sizeof(Transfer), countTransfers, file);
    fclose(file);
}

int readTransfers(Transfer transfers[]){
    FILE *file = fopen("transfers.dat", "rb");
    int countTransfers = 0;
    if(file == NULL){
        return 0;
    }
    while(
        fread(&transfers[countTransfers],sizeof(Transfer),1,file) == 1){
        countTransfers++;
    }
    fclose(file);
    return countTransfers;
}