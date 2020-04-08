#include <stdio.h>
#include "atm.h"

void print_denominations(unsigned int notes)
{
  int denomination[size] = {2000, 500, 100, 50, 20, 10, 5, 1} ;
  int no_of_notes = 0;
  for(int count =0;count < size ; count++){
    no_of_notes = (notes >> 28) | 0;
  if(no_of_notes){
      printf("%u %s of Rs %d\n", no_of_notes, no_of_notes == 1 ? "note" : "notes", denomination[count]);
    }
    notes = notes << sizeof(int);
  }
}

unsigned int get_money(unsigned short int money)
{
  unsigned short int amount = money;
  unsigned int notes = 0,total_notes = 0x00000000;
  int denomination[size] = {2000, 500, 100, 50, 20, 10, 5, 1} ;
  int max_allowed_amount = 31999;
  if(amount == notes || amount > max_allowed_amount){
    return 0;
  }

  for(int count = 0; count < size; count++)
  {
    notes = amount / denomination[count] ;
    amount = amount % denomination[count];
    total_notes = total_notes << sizeof(int);
    total_notes = total_notes | notes;
  }
  return total_notes;
};