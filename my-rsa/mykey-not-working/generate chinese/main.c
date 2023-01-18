#include<stdio.h>
#include<stdlib.h>
#include"bn.h"
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
        bignum_sub(&old_gcd, &temp2, &gcd);
        //gcd = old_gcd - quotient*gcd;

        bignum_assign(&old_gcd, &temp);
        //old_gcd = temp;

        // We treat s and t in the same manner we treated r
        bignum_assign(&temp, &x);
        //temp = x;

        bignum_mul(&quotient, &x, &temp2);
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
  int i;
  int size = 3000;
  char string[size];
  FILE* file;
  file = fopen("../prime1.txt", "r");
  for(int i = 0; i < size; i++)string[i] = '\0';
  fread(string, sizeof(char), size, file);
  fclose(file);
  printf("p:%s\n", string);
  struct bn p;bignum_init(&p);
  i = 0;
  for(;string[i];i++);
  bignum_from_string(&p,string, i-1);
  bignum_to_string(&p,string, 256);
  printf("p:%s\n", string);


  file = fopen("../prime2.txt", "r");
  for(int i = 0; i < size; i++)string[i] = '\0';
  fread(string, sizeof(char), size, file);
  fclose(file);
  printf("q:%s\n", string);
  struct bn q;bignum_init(&q);
  i = 0;
  for(;string[i];i++);
  bignum_from_string(&q,string, i);
  bignum_to_string(&p,string, 256);
  printf("q:%s\n", string);


  file = fopen("../private_exponent.txt", "r");
  for(int i = 0; i < size; i++)string[i] = '\0';
  fread(string, sizeof(char), size, file);
  fclose(file);
  printf("d:%s\n", string);
  struct bn d;bignum_init(&d);
  i = 0;
  for(;string[i];i++);
  bignum_from_string(&d,string, i-1);
  bignum_to_string(&d,string, 256);
  printf("d:%s\n", string);



  struct bn temp;bignum_init(&temp);
  struct bn temp0;bignum_init(&temp0);


  struct bn dp;bignum_init(&dp);
  bignum_dec(&p);
  bignum_mod(&d, &p, &dp);
  for(int i = 0; i < size; i++)string[i] = '\0';
  bignum_to_string(&dp, string, 256);
  printf("dp:%s\n", string);
  file = fopen("exponent1.txt", "w");
  fwrite(string, sizeof(char), size, file);
  fclose(file);
  //print to string and file

  struct bn dq;bignum_init(&dq);
  bignum_dec(&q);
  bignum_mod(&d, &q, &dq);
  for(int i = 0; i < size; i++)string[i] = '\0';
  bignum_to_string(&dq, string, 256);
  printf("dq:%s\n", string);
  file = fopen("exponent2.txt", "w");
  fwrite(string, sizeof(char), size, file);
  fclose(file);

  //print to string and file

  struct bn qinv;bignum_init(&qinv);
  extended_euclid_gcd_bn(&p, &q, &temp, &qinv, &temp0);
  for(int i = 0; i < size; i++)string[i] = '\0';
  bignum_to_string(&qinv, string, 256);
  printf("qinv:%s\n", string);
  file = fopen("coefficient.txt", "w");
  fwrite(string, sizeof(char), size, file);
  fclose(file);


}
