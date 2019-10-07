#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int msbSize(long a){
    return (int)log2(a);
}

long my_mod(long B, long n){
    if (n == 0){return B;} 
    long carry = B;
    long k = 0;
    bool finished = false;
    int i = 0;
    int kc = msbSize(n) + 1;
    while (!finished){ 
	k = msbSize(carry) - kc;
	k < 0 ? k = 0 : 0;
        carry -= ( n << k );
        carry < n ? finished = true : 0;
      
        printf("C(%d) = %ld,  k = %ld \n",i, carry, k);
	i++;
    }
return carry;
}


void main(){
<<<<<<< HEAD
    long B = 9e18;
    B+= 1;
    long n = 3;
    printf("msbSize(B) = %d\n",msbSize(B));
=======
    long B = 2e7+1;
    long n = 3;
    printf("msbSize(9) = %d\n",msbSize(9));
>>>>>>> aa3eca8427d06084a6c1a994686ffb64eaba07e5
    long ans = my_mod(B,n);
    printf("my: %ld mod %ld = %ld\n", B, n, ans);
    printf("C: %ld mod %ld = %ld\n", B, n, B%n);
}

