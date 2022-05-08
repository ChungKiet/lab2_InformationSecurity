#include "utils.h"

int hex_to_int(char c)
{
    if (c >= 97)
        c = c - 32;
    int first = c / 16 - 3;
    int second = c % 16;
    int result = first * 10 + second;
    if (result > 9) result--;
    return result;
}

int hex_to_ascii(const char c, const char d)
{
	int a = hex_to_int(c) * 16;
	int b = hex_to_int(d);
	return a + b;
}

void printHX(const char* st)
{
	int length = strlen(st);
	char buf;

	for(int i = 0; i < length; i++) {
		if(i % 2 != 0)
			printf("%c", hex_to_ascii(buf, st[i]));
		else
		    buf = st[i];
	}
}

void printBN(char* msg, BIGNUM * a)
{
    char * number_str = BN_bn2hex(a);
    printf("%s 0x%s\n", msg, number_str);
    OPENSSL_free(number_str);
}

BIGNUM* rsa_encrypt(BIGNUM* msg, BIGNUM* m, BIGNUM* pubKey)
{
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM* e = BN_new();
	BN_mod_exp(e, msg, m, pubKey, ctx);
	BN_CTX_free(ctx);
	return e;
}

BIGNUM* rsa_decrypt(BIGNUM* e, BIGNUM* pKey, BIGNUM* pubKey)
{
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM* d = BN_new();
	BN_mod_exp(d, e, pKey, pubKey, ctx);
	BN_CTX_free(ctx);
	return d;
}