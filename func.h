#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <cstring>

void init(unsigned char *s, unsigned char *k, const unsigned char r);

unsigned char get_gamma(unsigned char *q1, unsigned char *q2, unsigned char *s);

void encode(unsigned char *plain_text, int size, unsigned char *s, unsigned char *q1, unsigned char *q2);

void decode(unsigned char *plain_text, int size, unsigned char *s, unsigned char *q1, unsigned char *q2);

#endif // FUNC_H
