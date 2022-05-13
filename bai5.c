#include "utils.c"

int main(){
	BIGNUM* n = BN_new();
	BIGNUM* m = BN_new();
    BIGNUM* d = BN_new();
	BIGNUM* S = BN_new();

	BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
	BN_hex2bn(&m, "010001");
	BN_hex2bn(&S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");
	
	d = rsa_decrypt(S, m, n);
	printf("The result is: ");
	
	printHX(BN_bn2hex(d));
	printf("\n");

    return 0;
}