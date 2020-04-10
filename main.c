#include <stdio.h>
#include "atm.h"

int main(void)
{
  Cash amounts[] = {1, 10, 39, 589, 2590, 31999};
  DO_SIX_TIMES
  {
    Cash_notes no_of_notes = get_money(amounts[count]);
    print_denominations(no_of_notes);
    printf("%5u %08x\n\n", amounts[count], no_of_notes);
  }

  return 0;
}
