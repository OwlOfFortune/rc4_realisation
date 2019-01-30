#include "func.h"


void init(unsigned char *s, unsigned char *k, const unsigned char r){
    unsigned char q = 0;
    unsigned char temp;
    for(int i = 0; i != 255; ++i) s[i] = i;
    for(int i = 0; i != 255; ++i){
        q = (q + s[i] + k[i] % r) % 256;

        temp = s[i];
        s[i] = s[q];
        s[q] = temp;
    }
}


unsigned char get_gamma(unsigned char *q1, unsigned char *q2, unsigned char *s){
    unsigned char temp;

    *q1 = (*q1 + 1) % 256;
    *q2 = (*q2 + s[*q1]) % 256;

    temp = s[*q1];
    s[*q1] = s[*q2];
    s[*q2] = temp;

    return s[(s[*q1] + s[*q2]) % 256];
}


void encode(unsigned char *plain_text, int size, unsigned char *s, unsigned char *q1, unsigned char *q2){
    for(int i = 0; i < size; ++i)
        plain_text[i] ^= get_gamma(q1, q2, s);
}

void decode(unsigned char *plain_text, int size, unsigned char *s, unsigned char *q1, unsigned char *q2){
    encode(plain_text, size, s, q1, q2);
}





















