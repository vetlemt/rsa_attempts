#include <stdio.h>
#include <stdbool.h>

long my_mod(long B, long n){
    if (n == 0){return B;} 
    long carry = B;
    long carry_nxt = carry;
    long k = 0;
    int i = 0;
    long nn = n;
    while(nn>0){
        if (nn & 1 == 1)
            k += (B>>i);
        nn = nn>>1;
        i++;
    }
    bool finished = false;
    while (!finished){ 
        k < 1 ? k = 1 : 0;
        carry_nxt = carry - n*k;
        if (carry_nxt < 0){
            carry = carry;
            k = k >> 1;
        }
        else{
            carry_nxt < n ? finished = true : 0;
            carry = carry_nxt;
            k = k << 1;
        }
        printf("C(i) = %ld, C(i+1) = %ld, k = %ld \n", carry_nxt, carry, k);
    }
return carry;
}


void main(){
    long B = 177;
    long n = 6;
    long ans = my_mod(B,n);
    printf("my: %ld mod %ld = %ld\n", B, n, ans);
    printf("C: %ld mod %ld = %ld\n", B, n, B%n);
}

