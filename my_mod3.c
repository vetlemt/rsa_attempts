#include <stdio.h>
#include <stdbool.h>

long my_mod(long B, long n){
    if (n == 0){return B;} 
    int i = 0;
    long carry = B;
    long carry_nxt = carry;
    long k = 1;
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
        printf("C(%d) = %ld, \t C(%d+1) = %ld, \t k = %ld \n",i, carry_nxt, i, carry, k);
    }
return carry;
}


void main(){
    long B = 177e5;
    long n = 6;
    long ans = my_mod(B,n);
    printf("my: %ld mod %ld = %ld\n", B, n, ans);
    printf("C: %ld mod %ld = %ld\n", B, n, B%n);
}

