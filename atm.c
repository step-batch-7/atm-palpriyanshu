#include <stdio.h>
#include "atm.h"

void print_denominations(unsigned short int money)
{
  unsigned int notes = get_money(money);
  int denomination[8] = {2000, 500, 100, 50, 20, 10, 5, 1} ;
  for(int count =0;count < 8 ; count++){
    if(notes >> 28){
      printf("%u notes of %d\n",notes >> 28 ,denomination[count]);
    }
    notes = notes << sizeof(int);
  }
}

unsigned int get_money(unsigned short int money)
{
  unsigned short int amount = money;
  unsigned int notes =0,total_notes = 0;
  int denomination[8] = {2000, 500, 100, 50, 20, 10, 5, 1} ;
  int bit_to_shift = 28;
  if(amount/2000 >15){
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