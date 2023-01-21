#include<stdio.h>
#include<stdlib.h>
#include"bn.h"
void extended_euclid_gcd(long long a, long long b, long long *gcd_result, long long *x_result, long long *y_result)
{
    long long x = 0; long long old_x = 1;
    long long y = 1; long long old_y = 0;
    long long gcd = b; long long old_gcd = a;

    while(gcd != 0) {

        long long quotient = old_gcd/gcd;
        // We are overriding the value of r, before that we store it"s current
        // value in temp variable, later we assign it to old_r
        long long temp = gcd;
        gcd = old_gcd - quotient*gcd;
        old_gcd = temp;

        // We treat s and t in the same manner we treated r
        temp = x;
        x = old_x - quotient*x;
        old_x = temp;

        temp = y;
        y = old_y - quotient*y;
        old_y = temp;
    }
    *gcd_result = old_gcd;
    *x_result   = old_x;
    *y_result   = old_y;
}
void extended_euclid_gcd_bn(struct bn* a, struct bn* b, struct bn* gcd_result, struct bn* x_result, struct bn*y_result)
{
    struct bn x;       bignum_init(&x);       bignum_from_int(&x, 0);
    struct bn old_x;   bignum_init(&old_x);   bignum_from_int(&old_x, 1);
    struct bn y;       bignum_init(&y);       bignum_from_int(&y, 1);
    struct bn old_y;   bignum_init(&old_y);   bignum_from_int(&old_y, 0);
    struct bn gcd;     bignum_init(&gcd);     bignum_assign(&gcd, b);
    struct bn old_gcd; bignum_init(&old_gcd); bignum_assign(&old_gcd, a);
    struct bn quotient;bignum_init(&quotient);
    struct bn temp;    bignum_init(&temp);
    struct bn temp2;   bignum_init(&temp2);
    while(!bignum_is_zero(&gcd)) {

        bignum_div(&old_gcd, &gcd, &quotient);
        // We are overriding the value of gcd, before that we store it"s current
        // value in temp variable, later we assign it to old_gcd
        bignum_assign(&temp, &gcd);

        bignum_mul(&quotient, &gcd, &temp2);
        //if(bignum_cmp_1(&old_gcd, '<', ' ', &temp2))
          //printf("1 bignum is going negative\n");
        bignum_sub(&old_gcd, &temp2, &gcd);
        //gcd = old_gcd - quotient*gcd;

        bignum_assign(&old_gcd, &temp);
        //old_gcd = temp;

        // We treat s and t in the same manner we treated r
        bignum_assign(&temp, &x);
        //temp = x;

        bignum_mul(&quotient, &x, &temp2);
        //if(bignum_cmp_1(&old_gcd, '<', ' ', &temp2))
          //printf("1 bignum is going negative\n");
        bignum_sub(&old_x, &temp2, &x);
        //x = old_x - quotient*x;
        bignum_assign(&old_x, &temp);
        //old_x = temp;

        bignum_assign(&temp, &y);
        //temp = y;

        bignum_mul(&quotient, &y, &temp2);
        bignum_sub(&old_y, &temp2, &y);
        //y = old_y - quotient*y;
        bignum_assign(&old_y, &temp);
        //old_y = temp;
    }
    *gcd_result = old_gcd;
    *x_result   = old_x;
    *y_result   = old_y;
}
void main(void)
{
  FILE* file;
  file = fopen("lcm.txt", "r");


  int size = 3000;
  char string[size];
  for(int i = 0; i < size; i++)string[i] = '\0';

  fread(string, sizeof(char), size, file);
  fclose(file);

  printf("1 lcm:%s\n", string);
  struct bn lcm; bignum_init(&lcm);
  bignum_from_string(&lcm, string, 256);
  bignum_to_string(&lcm, string, 256);
  printf("2 lcm:%s\n", string);


  struct bn e;bignum_init(&e);
  bignum_from_int(&e, 65537);
  bignum_to_string(&e, string, 256);
  fopen("e.txt", "w");
  fwrite(string, sizeof(char), size, file);

  struct bn d;bignum_init(&d);
  bignum_from_int(&d, 0);

  struct bn tmp;bignum_init(&tmp);


  struct bn a;bignum_init(&a); bignum_from_int(&a, 95642);
  struct bn b; bignum_init(&b); bignum_from_int(&b, 1681);
  struct bn gcd_result; bignum_init(&gcd_result);
  struct bn x_result; bignum_init(&x_result);
  struct bn y_result; bignum_init(&y_result);
  extended_euclid_gcd_bn(&e,&lcm,&gcd_result,&x_result,&y_result);
  //uint64_t gcd_int;uint64_t x_int;uint64_t y_int;

  bignum_to_string(&x_result, string, 256);
  printf("x:%s\n", string);
  bignum_to_string(&y_result, string, 256);
  printf("y:%s\n", string);

  bignum_assign(&d, &x_result);

  //FILE* file;
  file = fopen("d.txt", "w");
  fwrite(string,sizeof(char),size,file);
  fclose(file);
  //OUTPUT TO FILE
  /*
  gcd_int = bignum_to_int(&gcd_result);
  x_int   = bignum_to_int(&x_result);
  y_int   = bignum_to_int(&y_result);
  printf("gcd:%lld\n",gcd_int);
  printf("x:%lld\n",x_int);
  printf("y:%lld\n",y_int);
  */

  //d*e = 1 mod lcm
  //a*x = 1 mod m
  //y = -1
  //(d*e)+(lcm*-y) = 1
  //d = (1-(lcm*y))-e;
  /*
  struct bn i; bignum_init(&i); //bignum_cmp_1();
  for(bignum_from_int(&d,1);bignum_cmp_1(&d,'<',' ',&e);bignum_inc(&d))
  {
    if(d = (1-(lcm*y))-e;)
  }
  */
  //for (;;)
    //int A = 3, M = 11;

    // Function call
    //modInverse(A, M);
    //return 0;


  //d = (1+lcm)/e

  //de%lcm = 1;
  //(d*e) + (lmc*y) = gcd(a, m) = 1
  //(d*e) + (lmc*y) = 1
  //de-1 = -y(lcm)
  //de == 1 (mod lcm);
  //de

}
