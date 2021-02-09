#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {

long long int g=0;
long long int p=0;
long long int aliceN=0;
long long int bobN=0;
long long int bobS=0;
long long int aliceS=0;
long long int sKeyAlice=0;
long long int sKeyBob=0;
long long int secretKey=0;
char message[1000];

FILE *fp;

fp = fopen("message.txt", "w+");


printf("Enter the Public value for g: ");
scanf("%lld", &g);
printf("Enter the Public value for p: ");
scanf("%lld", &p);
printf("Enter the private key of Alice: ");
scanf("%lld",&aliceN);
printf("Enter the private key of Bob: ");
scanf("%lld",&bobN);


aliceS = (int)pow(g,aliceN) % p ;
bobS = (int)pow(g,bobN) % p ;

printf("Alice public key: %lld\n", aliceS);
printf("Bob public key: %lld\n", bobS);

sKeyAlice = (int)pow(bobS, aliceN) % p;
sKeyBob = (int)pow(aliceS, bobN)   % p;

if (sKeyAlice == sKeyBob){
  secretKey = sKeyAlice;
  printf("Secret Key: %ld\n", secretKey);  

printf("Enter your message: ");
scanf(" %[^\n]", message);
int length=0;
int ctr=0;
length =strlen(message);
char temp[length-1];
while (ctr<length)
{
    temp[ctr] = message[ctr]^secretKey;
    ctr++;
}


printf("\nEncrypted Message: %s",temp);
fprintf(fp ,"%s", temp);


}
else{
    printf("Bob and Alice are not match\n");
}




fclose(fp);


   return 0;
}