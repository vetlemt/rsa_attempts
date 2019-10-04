#include <stdio.h>
#include <stdbool.h>

long my_mod(__uint128_t B, __uint128_t n){
    if (n == 0){return B;} 
    int i = 0;
    __uint128_t carry = B;
    __uint128_t carry_nxt = carry;
    __uint128_t k = 1;
    bool finished = false;
    while (!finished){ 
        k < 0 ? k = 0 : 0;
        carry_nxt = carry - (n << k);
        if (carry_nxt < 0){
            carry = carry;
            k--;
        }
        else{
            carry_nxt < n ? finished = true : 0;
            carry = carry_nxt;
            k++;
        }
        i++;
        printf("C(%d) = %g, \t\t C(%d+1) = %g, \t k = %g \n",i, (float)carry_nxt, i, (float)carry, k);
    }
return carry;
}


void main(){
    __uint128_t B = -1;
    __uint128_t n = 3;
    __uint128_t ans = my_mod(B,n);
    printf("my: %g mod %g = %g\n", (float)B, (float)n, (float)ans);
    printf("C: %g mod %g = %g\n", (float)B, (float)n, (float)(B%n));
}

