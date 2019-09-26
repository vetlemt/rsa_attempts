#include <stdio.h>
#include <math.h>
int M = 10;
int n = 17;
int e = 5;
long exponent = 1;
long result = 1;

int main(){
printf("%d^%d mod %d = \n",M,e,n);
	M %= n;
	for (int i = 0; i < 32; i++){
		if (e >> i & 1 == 1 ){
			result *= M % n;
			printf("%ld\n",result);
		}
	M *= M % n;	
	}
// long true_result = pow(M,e);
// true_result %= n;
// hei

printf("my rsa: %ld \n",result);
return 0;
}
