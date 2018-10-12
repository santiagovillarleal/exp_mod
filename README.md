Programo en C diferentes versións da exponenciación modular.

Na versión 1.0 programo a versión máis sinxela e menos útil, porque permite valores pequenos.
Compilación:

gcc -Wall exp_mod.c -o exp_mod -lm

Execución:
./exp_mod <p> <x> <n>

O resultado será (p^x) mod n. //Enténdase ^ como "elevado a".

- Valores máximos de p, x, n: 2^63-1 =  9223372036854775807
- Valor máximo de p^x:        2^64   = 18446744073709551616

A versión 1.1 utiliza a propiedade transitiva da exponenciación modular:
  //p mod n = r => p = n*k + r
  //p*q mod n = (n*k + r)*q mod n = r*q mod n
  //p*q mod n = [(p mod n)*q] mod n
  //p*p mod n = r*r mod n
  //p^x mod n = r^x mod n

Isto permítenos utilizar valores máis grandes, pero non moito:

 - Valores máximos de p, x, n: 2^63-1 =  9223372036854775807
 - Sendo r tal que p mod n = r, 
    valor máximo de r^x:        2^64   = 18446744073709551616

Na versión 1.2 faigo a exponenciación de forma iterativa: en cada iteración reduzo o resultado intermedio utilizando o resto
 en vez de utilizar a multiplicación completa.

 - Valores máximos de p, x, n: 2^63-1 =  9223372036854775807
 - Xa non hai límite superior da exponenciación porque en cada iteración o resultado intermedio sempre será estrictamente menor que n:

  r = p % n;
  for (i=0;i<x;i++)
  {
    res *= r;
    if (res >= n) res %= n;
  }
  return res;

