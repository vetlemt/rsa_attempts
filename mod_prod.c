#include <stdio.h>
#include <math.h>


__uint128_t modProd( __uint128_t  A,__uint128_t B,__uint128_t n){
    __uint128_t P = 0;
    for (int i = 0; i < 128; i++){
        P = 2*P + A * ((B >> (128 - i)) & 1);
        P = P % n;
    }
return P;
}

