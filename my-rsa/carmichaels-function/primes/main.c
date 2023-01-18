#include<stdio.h>
void main(void)
{
  FILE* file;
  file = fopen("prime-p.txt","w");
  char prime_p[] = "fb8ad1c7cbafe70622be6c1ca3f4ea914679a7259cb887aa9a6d89c05f6081ec9de35c79c1c652c9d621d94a2109c63960b1f52714ddf8b01b4c7d83d3b0dc1";
  //get size
  fwrite(prime_p,sizeof(char),128, file);
  fclose(file);

  file = fopen("prime-q.txt","w");
  char prime_q[] = "4002dfb21b5508cc07aa8daea40ccc7bd4b86eb7ace61f970caf78f6197f0eccfe3ba57cdbe118abf96cd633b87ff5d8ae64d25f7fedc35d288a6bf113aeed77";
  //get size
  fwrite(prime_q,sizeof(char),129, file);
  fclose(file);

}
