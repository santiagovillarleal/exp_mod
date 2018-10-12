#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <limits.h>

#define ERR_USO 1
#define ERR_RANGO 2

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

int main(int argc, char *argv[])
{
  unsigned long long int p, x, n, res;
  double pow_p_x = 0;

  p = x = n = res = 0;
  if (argc != 4)
  {
    imprimir_uso(argv[0]);
    exit(ERR_USO);
  }
  p = obter_ulong_long_int(argv[1], "p");
  x = obter_ulong_long_int(argv[2], "x");
  n = obter_ulong_long_int(argv[3], "n");

  pow_p_x = pow(p*1.0,x*1.0);
  if (errno == ERANGE)
  {
    printf("p^x fóra de rango.\n");
    exit(ERR_RANGO);
  }

  if (pow_p_x > ULLONG_MAX*1.0)
  {
    printf("(unsigned long long int)p^x fóra de rango.\n");
    exit(ERR_RANGO);
  }

  res = (unsigned long long int)pow_p_x;
  printf("p^x   : %llu\n", res);
  res = res % n;
  printf("(%llu^%llu) mod %llu = %llu\n", p, x, n, res);

  return 0;
}

