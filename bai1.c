#include "utils.c"

int main(){
    BIGNUM *p = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM* p1 = BN_new();
	BIGNUM* q1 = BN_new();
	BIGNUM* one = BN_new();
	BIGNUM* t = BN_new();
	BN_CTX *ctx = BN_CTX_new();
	
	BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
	BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
	BN_hex2bn(&e, "0D88C3");
	
	BN_dec2bn(&one, "1");
	BN_sub(p1, p, one);
	BN_sub(q1, q, one);
	BN_mul(t, p1, q1, ctx);

	BIGNUM* pKey = BN_new();
	BN_mod_inverse(pKey, e, t, ctx);

	BN_CTX_free(ctx);
	printBN("The private key is:", pKey);

    return 0;
}