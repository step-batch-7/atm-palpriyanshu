#include <stdio.h>
#include "atm.h"

void print_denominations(unsigned short int money)
{
  unsigned short int amount = money;
  int denomination[8] = {2000, 500, 100, 50, 20, 10, 5, 1} ;
  for(int count =0;count < 8 ; count++){
    unsigned int notes = amount / denomination[count] ;
    amount = amount % denomination[count];
    notes && printf("%u %s of Rs %d\n",notes ,notes == 1 ? "note" : "notes", denomination[count]);
  }
}

unsigned int get_money(unsigned short int money)
{
  unsigned short int amount = money;
  unsigned int notes =0,total_notes = 0x00000000;
  int denomination[8] = {2000, 500, 100, 50, 20, 10, 5, 1} ;
  int bit_to_shift = 28, max_allowed_amount = 31999;
  if(amount < 1 || amount > 31999){
    return 0;
  }

  for(int count =0; count < 8; count++)
  {
    notes = amount / denomination[count] ;
    amount = amount % denomination[count];
    total_notes = (total_notes >> bit_to_shift) | notes ;
    total_notes = (total_notes << bit_to_shift);
    bit_to_shift = bit_to_shift - 4;
  }
  return total_notes;
};