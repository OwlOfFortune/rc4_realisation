#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <iostream>

void init(int *s, int *k, const int r);

int get_gamma(int *q1, int *q2, int *s);

std::string encode(std::string plain_text, int *s, int *q1, int *q2);

std::string decode(std::string plain_text, int *s, int *q1, int *q2);

#endif // FUNC_H
