#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define LEN 50

typedef struct {
	char plainTxt[LEN];
	char cipherTxt[LEN];
	int sig[LEN];
} cipher;

uint32_t randomArray[LEN] = {240,248,124,190,95,175,87,171,213,234,117,186,221,238,119,59,157,78,39,147,73,164,210,233,
	244,250,125,190,223,111,55,27,141,70,35,17,136,196,98,177,88,172,214,107,181,218,237,246,123,189};
	
cipher encrypt(cipher text) {   //Create a Cipher function
	int i; 	//Create iteration variable
	int cipherNum[LEN];	//Create an integer array
	fgets(text.plainTxt,LEN,stdin); // Get the plain text input (element of the structure) using fgets
	
	if(text.plainTxt[strlen(text.plainTxt) -1 ] == '\n') { //DO NOT FORGET TO REMOVE tail end whitespaces
		text.plainTxt[strlen(text.plainTxt) -1] = '\0';
	}
	
		for(i=0;i<strlen(text.plainTxt);++i) { //Array Operation use loops (DO NOT USE LEN for array length - may result in divide by zero error
		cipherNum[i] = text.plainTxt[i] - 64; //Subtract each input character by 64 and assign it to an integer array
		cipherNum[i] *= randomArray[i]; //Multiply each character by the random number array (pre-declared in template)
		
		if(text.plainTxt[i] == 32) { //If plain text is a space
			text.sig[i] = 0; //Set signature to 0
		}
		else {
			text.sig[i] = cipherNum[i] / 26; //Else: Divide the result by 26 assign quotient to signature element of the structure
		} 
		cipherNum[i] = cipherNum[i] % 26; //Modulo the result by 26 and assign it back
		text.cipherTxt[i] = cipherNum[i] + 65; //Add 65 to the above result and assign it to the cipher text element of the structure
	}
	
	text.cipherTxt[strlen(text.cipherTxt) + 1] = '\0'; //Add the Null character to the end of the character array	
	return text; //Return the structure
}

int main(void) {
	cipher encryptTxt = encrypt(encryptTxt);
	int i;

	printf("%s", encryptTxt.cipherTxt);
	printf("\n");
	
	for (i=0;i<strlen(encryptTxt.cipherTxt);i++) {
	printf("%d ", encryptTxt.sig[i]);
	}
	
	return 0;
}