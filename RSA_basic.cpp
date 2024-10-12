#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
int p, q, n, e, d;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int size = sizeof(primes) / sizeof(primes[0]);  // So luong so nguyen to trong mang

// Ham tinh uoc chung lon nhat (gcd)
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Ham tinh luy thua modulo
long long luythuaModulo(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Ham tim he so Bezout
void hesoBezout(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1; 
        *y = 0; 
        return;
    }
    int x1, y1;
    hesoBezout(b, a % b, &x1, &y1);
    *x = y1; 
    *y = x1 - (a / b) * y1;
}

// Ham tim nghich dao cua e mod phi(n) (Extended Euclidean)
int nghichdaoE(int e, int m) {
    int x, y;
    int gcdValue = gcd(e, m);
    
    if (gcdValue != 1) {
        printf("Nghich dao khong ton tai\n");
        return -1; // Khong co so nghich dao
    } else {
        hesoBezout(e, m, &x, &y);
        // Dam bao ket qua la so duong(+)
        return (x % m + m) % m;
    }
}

void edGen(int phi){
    int i = 0;
    e=primes[0];
    while(gcd(e, phi) != 1 || nghichdaoE(e, phi) == e){
    	i = i + 1;
    	e = primes[i];
	}
	d = nghichdaoE(e, phi);
}

void rsa(int p, int q){
	n = p * q;  // n = p * q
    int phi = (p - 1) * (q - 1);  // Ham phi Euler
    edGen(phi);
}

int main() {
    
    
    printf("Nhap hai so p va q : ");
    scanf("%d %d", &p, &q);
    
    rsa(p,q);
    
    long long banro, banma;
    
    printf("RSA voi p = %d, q = %d, n = %d, e = %d, d = %d\n", p, q, n, e, d);
    
    printf("Nhap thong diep can ma hoa (So nguyen): ");
    scanf("%lld", &banro);
    banma = luythuaModulo(banro, e, n);  // ma hoa: C = M^e mod n
    printf("Ban ma sau khi ma hoa: %lld",banma);
    
    return 0;
}

