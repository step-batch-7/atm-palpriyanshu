#include "atm.h"

unsigned short int deduct_amount(unsigned short int, int, unsigned int); 

unsigned short int deduct_amount(unsigned short int amount, int denomination, unsigned int notes)
{
   return amount - denomination * notes;
};

unsigned int get_money(unsigned short int money)
{
  unsigned short int amount = money;
  unsigned int notes =0,total_notes = 0;
  int denomination[8] = {2000, 500, 100, 50, 20, 10, 5, 1} ;
  int bit_to_rotate = 28;

  for(int count =0; count < 8; count++){
     notes = amount /denomination[count] ;
     if(notes > 0 && notes < 16){
      total_notes = (total_notes >> bit_to_rotate) | notes ;
      total_notes = (total_notes << bit_to_rotate);
     }
    bit_to_rotate = bit_to_rotate - 4;
    amount = deduct_amount(amount, denomination[count], notes);
  }
  return total_notes;
};