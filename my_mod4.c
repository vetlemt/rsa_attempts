#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int msbSize(long a){
    int b = abs(a);
    int i = 0;
    int msb = 0;
    while(b > 0){
        b & 1 == 1 ? msb = i : 0; 
        b = b >> 1;
        i++;
    }
    return msb;
}


long my_mod(long B, long n){
    if (n == 0){return B;} 
    long carry = B;
    long carry_nxt = carry;
    long k = 0;
    bool finished = false;
    while (!finished){ 
        k < 0 ? k = 0 : 0;
        carry_nxt = carry - ( n << k );//(n << k);
        if (carry_nxt < 0){
            carry = carry;
            k -= msbSize(carry_nxt) - msbSize(n);
        }
        else{
            carry_nxt < n ? finished = true : 0;
            carry = carry_nxt;
            k += msbSize(carry_nxt) - msbSize(n);
        }
        printf("C(i) = %ld, C(i+1) = %ld, k = %ld \n", carry_nxt, carry, k);
    }
return carry;
}


void main(){
    long B = 2e7+1;
    long n = 3;
    printf("msbSize(9) = %d\n",msbSize(9));
    long ans = my_mod(B,n);
    printf("my: %ld mod %ld = %ld\n", B, n, ans);
    printf("C: %ld mod %ld = %ld\n", B, n, B%n);
}

