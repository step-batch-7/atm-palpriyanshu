#include <stdio.h>
#include "atm.h"

int is_amount_validate(Cash amount){
  return amount == 0 || amount > MAX_ALLOWED_AMOUNT ;
}

void print_denominations(Cash_notes notes)
{
  int denomination[SIZE] =DENOMINATION_LIST;
  int no_of_notes = 0;

  DO_EIGHT_TIMES
  {
    no_of_notes = notes >> SEVEN_LSB_OF_HEX_DIGITS;
    no_of_notes && printf("%u %s of Rs %d\n", no_of_notes, no_of_notes ? "note" : "notes", denomination[count]);
    notes = notes << MSB_OF_HEX_DIGITS;
  }
}

Cash_notes get_money(Cash money)
{
  Cash amount = money;
  Cash_notes no_of_notes = 0, total_notes = 0x00000000;
  int denomination[SIZE] = DENOMINATION_LIST ;
  if(is_amount_validate(amount))
  {
    return 0;
  }

  DO_EIGHT_TIMES
  {
    no_of_notes = amount / denomination[count] ;
    amount %= denomination[count];
    total_notes = total_notes << MSB_OF_HEX_DIGITS | no_of_notes;
  }
  return total_notes;
};