#include "func.h"

using namespace std;

int main()
{
    int r;
    unsigned char data[512];

    cout << "Enter plain text\n";
    cin.getline((char*)data, sizeof (data), '\n');

    cout << "Enter len of key: 16 or 32\n";
    cin >> r;

    if(r != 16 && r != 32){
        cerr << "Len incorrect\n";
        return 0;
    }

    unsigned char k[r];
    cout << "Enter k_i with space or enter:\n";
    for(int i = 0; i<r; ++i) k[i] = 1;

    encode(data, sizeof (data), k, r);
    cout << "Encrypted: ";
    for(int i = 0; i < sizeof (data); ++i)
        cout << (int)data[i] << ' ';

    decode(data, sizeof(data), k, r);
    cout << "Decrypted: " << data << '\n';

    return 0;
}
