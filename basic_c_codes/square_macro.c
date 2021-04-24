#include <stdio.h>
#define SQUARE(n) n*n

int main()
{
  int x = 3;
  int y = SQUARE(x);
  printf("%d\n",y);
  return 0;
  
}
