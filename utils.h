#ifndef __UTIL_H_
#define __UTIL_H_
#endif

#include <stdio.h>
#include <string.h>
#include <openssl/bn.h>

int hex_to_int(char c);
int hex_to_ascii(const char c, const char d);
void printHX(const char* st);
void printBN(char* msg, BIGNUM* a);

BIGNUM* rsa_encrypt(BIGNUM* message, BIGNUM* mod, BIGNUM* pub_key);
BIGNUM* rsa_decrypt(BIGNUM* encrypted_message, BIGNUM* priv_key, BIGNUM* pub_key);