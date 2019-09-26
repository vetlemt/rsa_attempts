#include <stdio.h>
#include <math.h>
int M = 4;
int n = 3;
int e = 2;
long exponent = 1;
long exp_M = 0;
long result = 1;
long mod_exp_M = 0;

int main(){
	for (int i = 0; i < 32; i++){
		if ((e>>i) && 1 == 1){
			mod_exp_M = M % n;
			result *= mod_exp_M;
		}
	M *= M % n;	
	exponent = 1 << i;
	}
//long true_result = pow(M,e);
//true_result %= n;

printf("my rsa: %ld \n%d^%d mod %d \n",result,M,e,n);
return 0;
}
