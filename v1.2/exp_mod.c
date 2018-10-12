#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <limits.h>

#define ERR_USO 1
#define ERR_RANGO 2
#define ERR_X_NEG 3

void imprimir_uso(char *prog)
{
  printf("%s <p> <x> <n>\n", prog);
  printf("Output: (p^x) mod n\n");
}

unsigned long long int obter_ulong_long_int(char *val_str, char *nome)
{
  unsigned long long int x = atoll(val_str); //atoll convirte a long long int.
  if (errno == ERANGE)
  {
    printf("%s fóra de rango.\n", nome);
    exit(ERR_RANGO);
  }
  return x;
}

unsigned long long int exp_mod_iter(
  unsigned long long int p,
  unsigned long long int x,
  unsigned long long int n)
{
  unsigned long long int i = 0, r = 0, res = 1;
  r = p % n;
  for (i=0;i<x;i++)
  {
    res *= r;
    if (res >= n) res %= n;
  }
  return res;
}


int main(int argc, char *argv[])
{
  unsigned long long int p, x, n, res;
  p = x = n = res = 0;

  if (argc != 4)
  {
    imprimir_uso(argv[0]);
    exit(ERR_USO);
  }

  p = obter_ulong_long_int(argv[1], "p");
  x = obter_ulong_long_int(argv[2], "x");
  n = obter_ulong_long_int(argv[3], "n");

  if (x<0)
  {
    printf("x>0\n");
    exit(ERR_X_NEG);
  }

  //p mod n = r => p = n*k + r
  //p*q mod n = (n*k + r)*q mod n = r*q mod n
  //p*q mod n = [(p mod n)*q] mod n
  //p*p mod n = r*r mod n
  //p^x mod n = r^x mod n

  //Usaremos unha versión iterativa da exponenciación modular.
  res = exp_mod_iter(p, x, n);

  printf("(%llu^%llu) mod %llu = %llu\n", p, x, n, res);

  return 0;
}

