#include "utils.c"

int main(){
	BIGNUM* pubKey = BN_new();
	BIGNUM* pKey = BN_new();
    BIGNUM* C = BN_new();
	BIGNUM* d = BN_new();

	BN_hex2bn(&pubKey, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&pKey, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
	BN_hex2bn(&C, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
	
	d = rsa_decrypt(C, pKey, pubKey);

	printf("The result is: ");
	printHX(BN_bn2hex(d));
	printf("\n");

    return 0;
}