// Abigail Culkin 
//Secure Hash ALgorithm
//https://ws680.nist.gov/publication/get_pdf.cfm?pub_id=919060

#include <stdio.h>
#include <stdint.h>

void sha256();

//see section 4.1.2 & 4.1.3 for standard
uint32_t sig0(uint32_t x);
uint32_t sig1(uint32_t x);

//See section 3.2 for standard
uint32_t rotr(uint32_t n, uint32_t x);
uint32_t shr(uint32_t n, uint32_t x);

//See section 4.1.2 for standard
uint32_t SIG0(uint32_t x);
uint32_t SIG1(uint32_t x);

uint32_t Ch(uint32_t x,uint32_t y, uint32_t z);
uint32_t Maj(uint32_t x, uint32_t y, uint32_t z);

//The K Constants
  uint32_t K[]={
  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 
  0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 
  0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 
  0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 
  0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 
  0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 
  0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 
  0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
  0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 
  0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
  0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 
  0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 
  0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 
  0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
  0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 
  0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 
  };

int main(int argc, char *argv[]){

  sha256();

  return 0;
}

void sha256(){
  
  //Message schedule (Section 6.2) - 64 in length 32 bit words
  uint32_t W[64];
  //Working Variables - Section 6.2 
  uint32_t a, b, c, d, e, f, g, h;
  //Temparary Variables - Section 6.2 
  uint32_t T1, T2;

  // The hash Values come from section 5.3.3 of standard
  // H array . length 8 - 32 bit unsigned integers
  // 
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

  //Message Block 16 element array of 32 bit unsigned int
  uint32_t M[16]={0,0,0,0,0,0,0,0};
  //from page 22, W[t] = M[t] for 0 <= t <=15. 
  int i,t;
  // Loop Through the message block(page 22)
  for(i=0; i<1; i++){ 

	  //first 16 elements of w
  for (t =0; t< 16; t++)


   W[t] = M[t];

  // 4.1.2 4.2.2 sig0 and sig1  
  for (t = 16; t < 64; t++)
   W[t] = sig1(W[t-2])+ W[t-7] + sig0(W[t-15]) + W[t-16];

   // Initialise a,b, c, d and e as per Step 2, page 19 Section 6.2.2
   a = H[0]; b= H[1]; c = H[2]; d = H[3]; 
   e = H[4]; f= H[5]; g = H[6]; h= H[7];

   // Step 3.
   for (t =0; t < 64; t++){
    T1 = h + SIG1(e) + Ch(e,f,g) + K[t] + W[t];
    T2 = SIG0(a) + Maj(a,b,c);
    h = g;
    g = f;
    f = e;
    e = d + T1;
    d = c;
    c = b;
    b = a;
    a = T1 + T2;
    }

   //Step 4.
   H[0] = a + H[0];
   H[1] = b + H[1];
   H[2] = c + H[2];
   H[3] = d + H[3];
   H[4] = e + H[4];
   H[5] = f + H[5];
   H[6] = g + H[6];
   H[7] = h + H[7];
  }
  printf("%x %x %x %x %x %x %x %x",H[0], H[1],H[2],H[3], H[4], H[5], H[6],  H[7]);
 }
uint32_t sig0(uint32_t x){
  //See Section 3.2 & NUMBER 4 for definitions
  return (rotr(7,x) ^ rotr(18, x) ^ shr(3,x));


}
uint32_t sig1(uint32_t x){
  //See Section 3.2 for definitions
  return (rotr(17,x) ^ rotr(19,x) ^ shr(10,x));
}

//see section 4.1.2 & 4.1.3 for defentions 
uint32_t rotr(uint32_t n, uint32_t x){
  return(x >> n) | (x << (32 - n));
}
uint32_t shr(uint32_t n, uint32_t x){
  return(x >> n);
}
 
//See section 4.1.2 for definition
uint32_t SIG0(uint32_t x){
  return (rotr(2,x) ^ rotr(13,x) ^ rotr(22,x));
}
uint32_t SIG1(uint32_t x){
  return (rotr(6,x) ^ rotr(11,x) ^ rotr(25,x));
}
 
uint32_t Ch(uint32_t x,uint32_t y, uint32_t z){
  return((x & y) ^ ((!x) & z));
}
uint32_t Maj(uint32_t x, uint32_t y, uint32_t z){
  return((x & y) ^ (x & z) ^ (y & z));
}
