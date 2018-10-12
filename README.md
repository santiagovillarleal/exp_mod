Programo en C diferentes versións da exponenciación modular.

Na versión 1.0 programo a versión máis sinxela e menos útil, porque permite valores pequenos.
Compilación:

gcc -Wall exp_mod.c -o exp_mod -lm

Execución:
./exp_mod <p> <x> <n>

O resultado será (p^x) mod n. //Enténdase ^ como "elevado a".

Valores máximos de p, x, n: 2^63-1 = 9223372036854775807

Valor máximo de p^x:        2^64   = 18446744073709551616

