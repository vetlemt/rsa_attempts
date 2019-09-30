#include <stdio.h>
#include <math.h>
int M = 7;
int n = 15;
int e = 13;
long exponent = 1;
long result = 1;

void main(){
	int Me = M;
	printf("%d^%d mod %d = \n",M,e,n);
	M %= n;
	for (int i = 0; i < 32; i++){
		if (e >> i & 1 == 1 ){
			result = (result*M) % n;
		}
	M *= M % n;	
	}
 long true_result = pow(Me,e);
 true_result %= n;

printf("my result: %ld \ntrue result: %ld\n",result,true_result);
}

