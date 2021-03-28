#include<stdio.h>

void main()
{
  int r=17;
 float q=13.8;
 char i='c';
 void *p;
 p=&r;
 printf("%d\n",*((int*)p));
 p=&q;
 printf("%f\n",*((float*)p));
 p=&i;
 printf("%c\n",*((char*)p));
}
