#ifndef ESTRUCTURAS_BANCO_H_
#define ESTRUCTURAS_BANCO_H_
#include <stdbool.h>

extern int countPersons;
extern int countAccounts;
extern int countTransfers;

#define tax(amount) ((amount) * 0.004)

typedef struct {
  int day;
  int month;
  int year; 
} Date;

typedef struct {
  char id[30];
  char name[30];
  char lastname[30];
  Date dateOfBirth;
  char nationality[30];
  char phone[20];
  char email[50];
} Person;


typedef struct {
  char nAccount[20];
  char idPerson[30];
  float balance;
} Account;

typedef struct{
  char originAccount[20];
  char destinyAccount[20];
  float amount;
  float shippingcost;
  Date dateTransfer;
} Transfer;


Person createPerson();
Date createDate();
bool checkDayMonth(int day, int month);
void showDate(Date date);
bool verifyExistPerson(Person persons[], char idPerson[]);
Account createAccount(Person persons[]);
bool verifyExistAccount(Account accounts[], char nAccount[]);
void showTransfer(Transfer transfer);
void listPersons(Person persons[]);
bool verifyBalanceAccount(Account Accounts[], float amount, char nAccount[]);
bool consingAccount(Account accounts[]);
#endif