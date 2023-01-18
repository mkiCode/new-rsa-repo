#include"bn.h"
#include<stdio.h>
#include"gcd.h"
#include"lcm.h"
void main(void)
{
  int temp = 3000;
  int size = 3000;
  char string[size];
  char* pt = string;
  for(int i = 0; i < size; i++)pt[i] = '\0';
  char prime_p[size];
  FILE* file;
  file = fopen("prime-p.txt","r");
  fread(prime_p, sizeof(char),temp, file);
  fclose(file);
  printf("%s\n", prime_p);

  char prime_q[size];
  file = fopen("prime-q.txt","r");
  fread(prime_q, sizeof(char),temp, file);
  fclose(file);
  printf("%s\n", prime_q);

  char p_string[size];
  struct bn p;
  bignum_init(&p);
  bignum_from_string(&p,prime_p, 128);
  bignum_to_string(&p, p_string, size);
  printf("p:%s\n",p_string);

  char q_string[size];
  struct bn q;
  bignum_init(&q);
  bignum_from_string(&q,prime_q, 128);
  bignum_to_string(&q, q_string, size);
  printf("q:%s\n",q_string);

  char pq_string[size];
  struct bn pq;
  bignum_init(&pq);
  bignum_mul(&p,&q,&pq);
  bignum_to_string(&pq,pq_string,size);
  printf("pq:%s\n",pq_string);

  file = fopen("n.txt", "w");
  fwrite(pq_string, sizeof(char), size, file);
  fclose(file);

  char p_dec_string[size];
  struct bn p_dec;
  bignum_init(&p_dec);
  bignum_assign(&p_dec,&p);
  bignum_dec(&p_dec);
  bignum_to_string(&p_dec, p_dec_string, size);
  printf("p_dec:%s\n",p_dec_string);

  char q_dec_string[size];
  struct bn q_dec;
  bignum_init(&q_dec);
  bignum_assign(&q_dec,&q);
  bignum_dec(&q_dec);
  bignum_to_string(&q_dec, q_dec_string, size);
  printf("q_dec:%s\n",q_dec_string);

  char eulers_string[size];
  struct bn eulers;
  bignum_init(&eulers);
  bignum_mul(&p_dec,&q_dec,&eulers);
  bignum_to_string(&eulers,eulers_string,size);
  printf("eulers:%s\n",eulers_string);

  file = fopen("eulers.txt", "w");
  fwrite(eulers_string, sizeof(char), size, file);
  fclose(file);

  /*
  char gcd_string[size];
  pt = gcd_string;for(int i = 0; i < size; i++)pt[i] = '\0';
  struct bn gcd_result; bignum_init(&gcd_result);
  gcd(&p_dec, &q_dec, &gcd_result);
  bignum_to_string(&gcd_result, gcd_string, size);
  printf("gcd:%s\n", gcd_string);

  file = fopen("gcd.txt", "w");
  fwrite(gcd_string, sizeof(char), size, file);
  fclose(file);

  char lcm_string[size];
  pt = lcm_string;for(int i = 0; i < size; i++)pt[i] = '\0';
  struct bn lcm_result; bignum_init(&lcm_result);
  lcm(&p_dec, &q_dec, &gcd_result ,&lcm_result);
  bignum_to_string(&lcm_result, lcm_string, size);
  printf("lcm:%s\n", lcm_string);
  */

  /*
  file = fopen("lcm.txt", "w");
  fwrite(lcm_string, sizeof(char), size, file);
  fclose(file);
  */
}
