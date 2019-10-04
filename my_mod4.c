#include <stdio.h>
#include <stdbool.h>

long my_mod(long B, long n){
    if (n == 0){return B;} 
    long carry = B;
    long carry_nxt = carry;
    long error;
    long k = 1;
    bool finished = false;
    while (!finished){ 
        k < 0 ? k = 0 : 0;
        error = n-carry_nxt;
        k = msbSize(error);
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
        printf("C(i) = %ld, C(i+1) = %ld, k = %ld \n", carry_nxt, carry, k);
    }
return carry;
}

int msbSize(long a){
    int b = 1;
    int i = 0;
    int msb = 0;
    while(b  ){
        b & 1 == 1 ? msb = i : 0; 
        b = b >> 1;
        i++;
    }
    return msb;
}


void main(){
    long B = 177;
    long n = 6;
    long ans = my_mod(B,n);
    printf("my: %ld mod %ld = %ld\n", B, n, ans);
    printf("C: %ld mod %ld = %ld\n", B, n, B%n);
}

