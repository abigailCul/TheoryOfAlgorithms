# TheoryOfAlgorithms
A project as part of my final year module Theory of ALgorithms. 

## Description
My project aim was to write a program in the C programming language that calculates the SHA-256 check sum of an input. I am using the secure Hash document supplied by the National Institute of Standards and Technology. I have adapted the code from different sections in the secure hash document which are labbeled in the comments of my code. I have taken I have used a text file to test the algorithm called Sha256Test.txt which is in my github repository. If the file does not exist you are prompted that there is no file recognised. The program also checks if your system is big or little endian. Sha256 implements in big endian so had to be converted to match your system. The code was implemented on a google cloud linux based virtual machine. 


## Prerequisites

I used github for my project so it would not be lost and be easy for other people to access.

### Push to Github:

In order to submit my project changes to github from my github folder i used the following commands:
git add .
git commit -m "Initial commit"
git push

### Download from github:
For you to download my project you must clone my repository link from the command promp:

git clone "example.github/project"

### Running the project
To compile the program you run ```gcc -o sha256 sha256.c```
To run the sha file or specific file you would like you run ```./sha256 "name of file```

This will run the has values like following:
```
This is little-endian
54b0d90a 2c9af5d0 de241fae 45684df7 ac20b06e 0b7a4617 456ae584 e22532da
```

## Coding Syle

In my project I am using C. 

My main program is the file sha256.c

This next snippet of code helps determone which system you are running big endian or little endian
```
int big_endian(void){
        union{
                uint32_t i;
                char c[4];
        } e = {0x01000000};

        return e.c[0] ==1;
        }
```
You print the output of the system type
```
printf("This is %s-endian\n", big_endian() ? "big" : "little");
```

I also have the K constants. These 32bit word hexidecimal numbers. They are the cube roots of the first 64 primes.
```
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

```
The hash values are declared in the H array. They are 8, 32 bit unsigned integers from the secure hash standard
```
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
```
I have convert little to big endian. The if else will print depending on your system type.
```
#define LittleToBig(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
#define IS_BIG_ENDIAN (*(uint16_t *)"\0\xff" < 0x100)

H[1] >> (24 - i *8) & 0x000000ff;
	H[2] >> (24 - i *8) & 0x000000ff;
	H[3] >> (24 - i *8) & 0x000000ff;
	H[4] >> (24 - i *8) & 0x000000ff;
	H[5] >> (24 - i *8) & 0x000000ff;
	H[6] >> (24 - i *8) & 0x000000ff;
H[7] >> (24 - i *8) & 0x000000ff;
```

## Resources i used for my project.
https://www.ibm.com/support/knowledgecenter/en/linuxonibm/com.ibm.linux.z.lxci/lxci_xmp_sha256.html
https://stackoverflow.com/questions/12791864/c-program-to-check-little-vs-big-endian
https://stackoverflow.com/questions/6269719/little-endian-data-and-sha-256
http://www.firmcodes.com/write-c-program-convert-little-endian-big-endian-integer/
https://www.di-mgt.com.au/sha_testvectors.html
http://cs-fundamentals.com/tech-interview/c/c-program-to-check-little-and-big-endian-architecture.php
https://github.com/switchbrew/switch-tools
## License

This project is licensed under the Apache License- see the LICENSE.md file for details

  
