#include "func.h"


using namespace std;

int main()
{
    int r;
    int s[256];
    int q1 = 0, q2 = 0;
    std::string plain_text, ciphertext;

    cout << "enter len of key: 16 or 32\n";
    cin >> r;

    if(r != 16 && r != 32){
        cerr << "len incorrect\n";
        return 0;
    }
    int k[r];

    cout << "enter k_i with space or enter:\n";
    for(unsigned char i = 0; i<r; ++i) cin >> k[i];


    init(s, k, r);

    cout << "enter plain text\n";
    cin >> plain_text;

    ciphertext = encode(plain_text, s, &q1, &q2);

    cout << ciphertext << '\n';

    init(s, k, r);
    q1 = 0; q2 = 0;
    cout << decode(ciphertext, s, &q1, &q2);


    return 0;
}
