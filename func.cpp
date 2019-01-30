#include "func.h"

void gen_key(unsigned char *k, int r){
    for(int i = 0; i < r; ++i)
        k[i] = rand() % 255;
}


void init(unsigned char *s, unsigned char *k, const int r){
    unsigned char q = 0, temp;

    for(unsigned char i = 0; i < 255; ++i) s[i] = i;
    s[255] = 255;

    for(unsigned char i = 0; i < 255; ++i){
        q += s[i] + k[i % r] ;
        temp = s[i];
        s[i] = s[q];
        s[q] = temp;
    }
    q += s[255] + k[255] % r;
    temp = s[255];
    s[255] = s[q];
    s[q] = temp;
}


unsigned char get_gamma(unsigned char *q1, unsigned char *q2, unsigned char *s){
    unsigned char temp;

    ++(*q1);
    *q2 += s[*q1];

    temp = s[*q1];
    s[*q1] = s[*q2];
    s[*q2] = temp;

    return s[s[*q1] + s[*q2]];
}


void encode(unsigned char *plain_text, int size, unsigned char *k, int r){
    unsigned char s[256];
    unsigned char q1 = 0, q2 = 0;
    init(s, k, r);

    for(int i = 0; i < size; ++i)
        plain_text[i] ^= get_gamma(&q1, &q2, s);
}

void decode(unsigned char *plain_text, int size, unsigned char *k, int r){
    encode(plain_text, size, k, r);
}





















