

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<cstdlib>

#define max 10

void decToBin(int n, char s[]) {
    for (int i = 0; i < 6; i++) {
        s[5 - i] = (n % 2) + '0';
        n /= 2;
    }
}

int binToDec(char bin[]) {
    int decimal = 0;
    int base = 1; 

    int length = strlen(bin);
    for (int i = length - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            decimal += base; 
        }
        base *= 2; 
    }

    return decimal;
}

int sbox[4][16] = {
    { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
    { 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
    { 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
    { 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }
};

void sbox_transform(char input[], char output[]) {
	char row[max] = {input[0], input[5]};
	char col[max] = {input[1], input[2], input[3], input[4]};
    decToBin(sbox[binToDec(row)][binToDec(col)],output); 
}

char myXor(char a, char b){
	int x,y;
	if(a=='1')
		x=1;
	else
		x=0;
	if(b=='1')
		y=1;
	else
		y=0;
	return (x ^ y) ? '1' : '0';
}

void luiBit(char k[]){
	char l = k[0];
    char r = k[4];
    for (int i = 0; i < 3; i++) {
        k[i] = k[i + 1];
        k[i + 4] = k[i + 5];
    }
    k[3] = l;
    k[7] = r;
}

void tinyDES(char p[], char k[]){
	for(int n = 1; n <= 3; n++){
		char l[max] = {p[0],p[1],p[2],p[3]};
		
		for(int i = 0; i<4; i++){
			p[i] = p[i+4];
		}

		luiBit(k);
		if(n==2){
			luiBit(k);
		}
		
		char x[] = "000000";
		x[0] = myXor(p[6], k[5]);
		x[1] = myXor(p[7], k[1]);
		x[2] = myXor(p[5], k[3]);
		x[3] = myXor(p[6], k[2]);
		x[4] = myXor(p[5], k[7]);
		x[5] = myXor(p[4], k[0]);
		
		char s[] = "000000";
		sbox_transform(x,s);
		p[4] = myXor(l[0], s[4]);
		p[5] = myXor(l[1], s[2]);
		p[6] = myXor(l[2], s[5]);
		p[7] = myXor(l[3], s[3]);
	}
}

int main(){
	printf("		MA HOA TINYDES\n");
	char p[max];
//	p = "01011100";
	char k[max];
//	k = "10011010";
	printf("Nhap ban ro (8 bit): ");
	scanf("%s",&p);
	printf("Nhap khoa (8 bit): ");
	scanf("%s",&k);

	tinyDES(p,k);
	printf("Ket qua ban ma: %s\n",p);
	
	system("pause");
	return 0;
}

	
