#include"bn.h"
#include<stdio.h>
#include"preprocessorOptions.h"
void gcd(struct bn* aa, struct bn* bb, struct bn* final)
{
  int size;
  char string[size];
  for(int i = 0; i < size; i++)
    string[i] = '\0';
  /*
  printf("entered gcd\n");
  bignum_to_string(aa,string1,256);
  printf("aa:%s\n", string1);
  bignum_to_string(bb, string2,256);
  printf("bb:%s\n", string2);
  */
  struct bn larger;bignum_init(&larger);
  struct bn smaller;bignum_init(&smaller);
  struct bn mod;bignum_init(&mod);
  //printf("finished initializations\n");
  if(bignum_cmp_1(aa,'>',' ',bb))
  {
    //printf("assign aa to larger\n");
    //printf("assign bb to smaller\n");
    bignum_assign(&larger,aa);
    bignum_assign(&smaller,bb);
  }
  else if(bignum_cmp_1(aa,'<', ' ',bb))
  {
    //printf("assign bb to smaller\n");
    //printf("assign aa to larger\n");
    bignum_assign(&larger,bb);
    bignum_assign(&smaller,aa);
  }

  bignum_to_string(&larger,string, 256);
  //printf("larger:%s\n", string);
  bignum_to_string(&smaller, string, 256);
  //printf("smaller:%s\n", string);

  //printf("enter mod");
  bignum_mod(&larger, &smaller, &mod);
  //printf("enter gcd while loop\n");
  while(!bignum_is_zero(&mod))
  {
      bignum_assign(&larger, &smaller);
      bignum_assign(&smaller, &mod);
      bignum_mod(&larger, &smaller, &mod);
  }
  //printf("exited while loop\n");
  bignum_assign(final, &smaller);
  //bignum_to_string(final, string,256);
  //printf("bb:%s\n", string);

  //printf("end of gcd function\n");
}
