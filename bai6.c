#include "utils.c"

int main(){
	BIGNUM* pubKey = BN_new();
	BIGNUM* m = BN_new();
	BIGNUM* BN = BN_new();
	BIGNUM* d = BN_new();

	BN_hex2bn(&pubKey, "8032ce5e0bdd6e5a0d0aafe1d684cbc08efa8570edda5db30cf72b7540fe850afaf33178b7704b1a8958ba80bdf36b1de97ecf0bba589c59d490d3fd6cfdd0986db771825bcf6d0b5a09d07bdec443d82aa4de9e41265fbb8f99cbddaee1a86f9f87fe74b71f1b20abb14fc6f5675d5d9b3ce9ff69f7616cd6d9f3fd36c6ab038876d24b2e7586e3fcd8557d26c21177df3e02b67cf3ab7b7a86366fb8f7d89371cf86df7330fa7babed2a59c842843b11171a52f3c90e147da25b7267ba71ed574766c5b8024a65345e8bd02a3c209c51994ce7529ef76b112b0d927e1de88aeb36164387ea2a63bf753febdec403bb0a3cf730efebaf4cfc8b3610733ef3a4");
	BN_hex2bn(&m, "010001");
	BN_hex2bn(&BN, "aa9fbe5d911bade44e4ecc8f07644435b4ad3b133fc129d8b4abf3425149463bd6cf1e4183e10b572f83697965076f59038c51948918103e1e5cedba3d8e4f1a1492d32bffd498cba7930ebcb71b93a4424246d9e5b11a6b682a9b2e48a92f1d2ab0e3f820945481502eeed7e0207a7b2e67fbfad817a45bdcca0062ef23af7a58f07a740cbd4d43f18c0287dce3ae09d2f7fa373cd24bab04e543a5d255110e41875f38a8e57a5e4c46b8b6fa3fc34bcd4035ffe0a471740ac1208be3544784d518bd519b405ddd423012d13aa5639aaf9008d61bd1710b067190ebaeadafba5fc7db6b1e78a2b4d10623a763f3b543fa568c50177b1c1b4e106b220e845294");
    
	d = rsa_decrypt(BN, m, pubKey);

	printBN("The result is: ", d);
	printf("\n");

    return 0;
}