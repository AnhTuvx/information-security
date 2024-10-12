	#include <stdio.h>
	#include <string.h>
	#include <ctype.h>
	
	void toLowerCase(char *str) {
	    for (int i = 0; str[i]; i++) {
	        str[i] = tolower(str[i]);
	    }
	}
	
	void vigenereEncrypt(char *plaintext, char *key, char *ciphertext) {
	    int keyLength = strlen(key);
	    int j = 0;
	
	    for (int i = 0; plaintext[i]; i++) {
	        if (isalpha(plaintext[i])) {
	            char shift = tolower(key[j % keyLength]) - 'a';
	            char base = islower(plaintext[i]) ? 'a' : 'A';
	            ciphertext[i] = (plaintext[i] - base + shift) % 26 + base;
	            j++;
	        } else {
	            ciphertext[i] = plaintext[i];
	        }
	    }
	    ciphertext[strlen(plaintext)] = '\0';
	}
	
	void vigenereDecrypt(char *ciphertext, char *key, char *plaintext) {
	    int keyLength = strlen(key);
	    int j = 0;
	
	    for (int i = 0; ciphertext[i]; i++) {
	        if (isalpha(ciphertext[i])) {
	            char shift = tolower(key[j % keyLength]) - 'a';
	            char base = islower(ciphertext[i]) ? 'a' : 'A';
	            plaintext[i] = (ciphertext[i] - base - shift + 26) % 26 + base;
	            j++;
	        } else {
	            plaintext[i] = ciphertext[i];
	        }
	    }
	    plaintext[strlen(ciphertext)] = '\0'; 
	}
	
	int main() {
	    char plaintext[100], key[100], ciphertext[100], decrypted[100];
	
	    printf("nhap ban chinh: ");
	    fgets(plaintext, sizeof(plaintext), stdin);
	    plaintext[strcspn(plaintext, "\n")] = 0; 
	
	    printf("khoa: ");
	    fgets(key, sizeof(key), stdin);
	    key[strcspn(key, "\n")] = 0;
	
	    vigenereEncrypt(plaintext, key, ciphertext);
	    printf("ban ma: %s\n", ciphertext);
	
	    return 0;
	}
