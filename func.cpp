#include "func.h"


void init(int *s, int *k, const int r){
    unsigned  q = 0;
    int temp;
    for(int i = 0; i != 255; ++i) s[i] = i;
    for(int i = 0; i != 255; ++i){
        q = (q + s[i] + k[i] % r) % 256;

        temp = s[i];
        s[i] = s[q];
        s[q] = temp;
    }
}


int get_gamma(int *q1, int *q2, int *s){
    int temp;

    *q1 = (*q1 + 1) % 256;
    *q2 = (*q2 + s[*q1]) % 256;

    temp = s[*q1];
    s[*q1] = s[*q2];
    s[*q2] = temp;

    return s[(s[*q1] + s[*q2]) % 256];
}


std::string encode(std::string plain_text, int *s, int *q1, int *q2){
    std::string ciphertext = "";
    for(std::size_t i = 0; i < plain_text.length(); ++i)
        ciphertext += plain_text[i] ^ get_gamma(q1, q2, s);
    return ciphertext;
}

std::string decode(std::string plain_text, int *s, int *q1, int *q2){
    return encode(plain_text, s, q1, q2);
}





















