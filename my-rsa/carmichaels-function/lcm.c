#include"bn.h"
void lcm(struct bn* a, struct bn* b, struct bn* gcd, struct bn* result)
{
  struct bn temp;bignum_init(&temp);
  bignum_mul(a,b,result);
  //bignum_div(&temp, gcd, result);
}
