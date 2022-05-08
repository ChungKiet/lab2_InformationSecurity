#include "utils.c"

int main(){
	BIGNUM* pubKey = BN_new();
	BIGNUM* m = BN_new();
    BIGNUM* d = BN_new();
	BIGNUM* mes = BN_new();

	BN_hex2bn(&pubKey, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
	BN_hex2bn(&m, "010001");
	BN_hex2bn(&mes, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");
	
	d = rsa_decrypt(mes, m, pubKey);
	printf("The result is: ");
	
	printHX(BN_bn2hex(d));
	printf("\n");

    return 0;
}