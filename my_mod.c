#include <stdio.h>
#include <stdbool.h>

long my_mod(long B, long n){
    long carry = B;
    long carry_nxt = carry;
    long k = B >> (n-1);
    bool finished = false;
    while (!finished){ 
        k < 1 ? k = 1 : 0;
        carry_nxt = carry - n*k;
        if (carry_nxt < 0){
            carry = carry;
        }
        else{
            carry_nxt < n ? finished = true : 0;
            carry = carry_nxt;
        }
        printf("C(i) = %ld, C(i+1) = %ld, k = %ld \n", carry_nxt, carry, k);
        k = k>>1;
    }
return carry;
}


void main(){
    long B = 10;
    long n = 3;
    long ans = my_mod(B,n);
    printf("my: %ld mod %ld = %ld\n", B, n, ans);
    printf("C: %ld mod %ld = %ld\n", B, n, B%n);
}

