#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define LEN 50 //Length of all the array

uint32_t randomArray[LEN] = {240,248,124,190,95,175,87,171,213,234,117,186,221,238,119,59,157,78,39,147,73,164,210,233,
	244,250,125,190,223,111,55,27,141,70,35,17,136,196,98,177,88,172,214,107,181,218,237,246,123,189};
	
typedef struct {
	char plainTxt[LEN];
	char cipherTxt[LEN];
	int sig[LEN];
} cipher;

cipher decipher(cipher text) { 
	int i; 
	
	int cipherNum[50]; // integer array
	
	fgets(text.cipherTxt,LEN,stdin); // gets cypher text from the terminal
	 if (text.cipherTxt[strlen(text.cipherTxt) - 1] == '\n') { //use this to remove extra space at the end
			text.cipherTxt[strlen(text.cipherTxt)-1] = '\0';
	}
	
	
	for(i=0; i < strlen(text.cipherTxt); ++i) {
	scanf("%d",&text.sig[i]);  // gets signature from the terminal 
	}
	
	
	
	for(i=0; i < strlen(text.cipherTxt); ++i) { 
		cipherNum[i] = text.cipherTxt[i] - 65; //subtracts each input character by 65 and assigns it to cipherNum (integer array)
		
	}
		

	for (i = 0; i < strlen(text.cipherTxt); ++i) {
		if(text.sig[i] == 0) {
			text.plainTxt[i] = 32;
			continue;
		}
		else { 
			cipherNum[i] += text.sig[i] * 26;
			text.plainTxt[i] = (cipherNum[i] / randomArray[i]) + 64;
		}
	}
	
	text.plainTxt[strlen(text.cipherTxt) + 1] = '\0'; //adds null character to the end of the deciphered text
	
	return text;
	
}
	
int main(void) {
	cipher decriptTxt = decipher(decriptTxt);
	int i;
	
	
	
	printf("%s", decriptTxt.plainTxt);
	
	
	return 0;
	
}
