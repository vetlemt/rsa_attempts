#include <stdio.h>
#include <math.h>

__uint128_t modProd( __uint128_t  A,__uint128_t B,__uint128_t n){
    __uint128_t P = 0;
    for (int i = 0; i < 128; i++){
        P = 2*P + A * ((B >> (127 - i)) & 1);
        P = P % n;
    }
return P;
}

void main(){
	__uint128_t M = 7;
	__uint128_t n = 15;
	__uint128_t e = 13;
	__uint128_t exponent = 1;
	__uint128_t result = 1;
	__uint128_t Me = M;
	//printf("%d^%d mod %d = \n",M,e,n);
	M %= n;
	while ( e > 0 ){
		if (e & 1 == 1 ){
			result = modProd(result,M,n);
		}
		M = modProd(M,M,n);	
		e = e >> 1;
	}
	printf("Result: %f",(float)result);
 //long true_result = pow(Me,e);
 //true_result %= n;

//printf("my result: %ld \ntrue result: %ld\n The algorithm is ",result,true_result);
//result == true_result ? printf("correct\n") : printf("incorrect\n");
}

