#include"bn.h"
#include<stdio.h>
//#define AAA INT_MAX - 1
//#define BBB INT_MAX - 2


//int bignum_cmp_1(struct bn* a,char cmp1,char cmp2 struct bn* b);
void main(void)
{
  //with alloction
  //get_bignum function
  int aint = 1337;
  int bint = 2111;
  struct bn a;bignum_init(&a);bignum_from_int(&a,aint);
  struct bn b;bignum_init(&b);bignum_from_int(&b,bint);

  char gt[]    = ">";
  char lt[]    = "<";
  char gtoet[] = "=>";
  char ltoet[] = "<=";
  char e[]     = "==";
  printf("is %d >= %d?\n",aint,bint);
  //if(bignum_cmp_1(&a,'>','=',&b))
  printf("%c\n", bignum_cmp_1(&a,'>','=',&b)?'y':'n');
  printf("is %d >= %d?\n",aint,bint);
  printf("%c\n", bignum_cmp_1(&a,'>','=',&b)?'y':'n');

}
