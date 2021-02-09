#include <stdio.h>
#include <string.h>
#include <conio.h>
int main() {

FILE *fp;

char message[1000];
int secretKey=0;


fp = fopen("message.txt", "r");
fscanf(fp,"%s", message);
printf("Message read on the file: %s", message);

printf("\nEnter the Secret Key to Decrypt:");
scanf("%d", &secretKey);
int length=0;
length = strlen(message);
int ctr=0;
char temp[length-2];
while (ctr<length)
{
    temp[ctr] = secretKey^message[ctr];
    ctr++;
}

printf("Encrypted Message: %s",temp);

 
   return 0;
}