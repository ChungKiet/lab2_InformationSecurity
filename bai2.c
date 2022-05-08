// #include "utils.c"
#include "utils.c"

int main(){
    BIGNUM* e = BN_new();
    BIGNUM* pKey = BN_new();
	BIGNUM* pubKey = BN_new();
	BIGNUM* m = BN_new();
	BIGNUM* message = BN_new();
    
	BN_hex2bn(&pKey, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
	BN_hex2bn(&pubKey, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&m, "010001");
	BN_hex2bn(&message, "4120746f702073656372657421");

	e = rsa_encrypt(message, m, pubKey);

	printBN("The result is: ", e);
	printf("\n");

    return 0;
}