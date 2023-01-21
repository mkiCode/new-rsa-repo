#include<stdio.h>
#include"bn.h"
void modulo(struct bn* base, struct bn* exp,struct bn* mod, struct bn* eulersCritereon)
{
    struct bn x   ;bignum_init(&x)     ;bignum_from_int(&x, 1);
    struct bn y   ;bignum_init(&y)     ;bignum_assign(&y, base);
    struct bn tmp ;bignum_init(&tmp)   ;bignum_from_int(&tmp, 0);

    while(!bignum_is_zero(exp))//while (exponent > 0)
    {
        if(bignum_is_odd(exp))
        {
            //x = (x*y)%mod
            bignum_mul(&x,&y,&tmp);
            bignum_mod(&tmp, mod, &x);
        }
        //y = (y*y)%mod
        bignum_mul(&y,&y,&tmp);
        bignum_mod(&tmp, mod, &y);

        //exponent = exponent / 2;
        bignum_halve(exp);
    }
    bignum_mod(&x, mod, eulersCritereon);
}
