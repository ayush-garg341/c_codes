#include <stdio.h>

int main(void) {

  char s[] = "This is a string";
  printf("Original String: %s\n", s);
  
  //Change the contents of the string
  s[2] = 'a';
  s[3] = 't';
  printf("Modified String: %s\n", s);
  
  //Shorten the string
  s[7] = '\0';
  printf("Shortened String: %s\n", s);

  return 0;
}
