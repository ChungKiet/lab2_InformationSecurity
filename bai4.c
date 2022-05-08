#include "utils.c"

int main(){
    BIGNUM* e = BN_new();
	BIGNUM* d = BN_new();
	BIGNUM* m = BN_new();
	BIGNUM* pubKey = BN_new();
	BIGNUM* pKey = BN_new();
    BIGNUM* plt = BN_new();

	BN_hex2bn(&m, "010001");
	BN_hex2bn(&pubKey, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&pKey, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
	BN_hex2bn(&plt, "49206f776520796f75203030302e");
	
	e = rsa_encrypt(plt, pKey, pubKey);
	d = rsa_decrypt(e, m, pubKey);

	printf("The result is: ");
	printHX(BN_bn2hex(d));
	printf("\n");

    return 0;
}