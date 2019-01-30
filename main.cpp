#include "func.h"

using namespace std;

int main()
{
    unsigned char r;
    unsigned char s[256];
    unsigned char q1 = 0, q2 = 0;
    unsigned char plain_text[512] = "", ciphertext[512] = "";

    cout << "Enter len of key: 16 or 32\n";
    cin >> r;

    if(r != 16 && r != 32){
        cerr << "Len incorrect\n";
        return 0;
    }
    unsigned char k[r];

    cout << "Enter k_i with space or enter:\n";
    for(unsigned char i = 0; i<r; ++i) cin >> k[i];



    cout << "enter plain text\n";
    fgets((char*)plain_text, sizeof (plain_text), stdin);
    memcpy(ciphertext, plain_text, sizeof (plain_text));

    init(s, k, r);
    encode(ciphertext, sizeof (plain_text), s, &q1, &q2);
    cout << "Encrypted: " << ciphertext << '\n';
    memcpy(plain_text, ciphertext, sizeof (ciphertext));

    init(s, k, r);
    q1 = 0; q2 = 0;
    decode(plain_text, sizeof(plain_text), s, &q1, &q2);
    cout << "Decrypted: " << plain_text << '\n';

    return 0;
}
