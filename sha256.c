// Abigail Culkin 
//Secure Hash ALgorithm
//https://ws680.nist.gov/publication/get_pdf.cfm?pub_id=919060

#include <stdio.h>
// using fixed bit length integers
#include<stdint.h>
 
//
void sha256();

int main(int argc, char *argv[]){

	sha256();
   return 0;
}

// return back the 256 bit message digest
// an array of 32 bit integers
void sha256(){

	// message schedule (6.2)
	uint32_t w[64];
	//working variables (section 6.2)
	uint32_t a, b, c, d, e, f, g, h;

	//Two temporary variables (6.2)
	uint32_t T1, T2;

	//The hash value (6.2)
	//The values come from 5.3.3
	uint32_t H[8]={
		0x6a09e667
		, 0xbb67ae85
		, 0x3c6ef372
		, 0xa54ff53a
		, 0x510e527f
		, 0x9b05688c
		, 0x1f83d9ab
		, 0x5be0cd19
	};

}
