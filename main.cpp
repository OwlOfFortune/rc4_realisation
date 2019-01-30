#include "func.h"

using namespace std;

int main()
{
    int r, temp;
    unsigned char data[512];

    cout << "Enter plain text\n";
    cin.getline((char*)data, sizeof (data), '\n');

    cout << "Enter len of key r (8 | r): \n";
    cin >> r;

    if(r % 8 != 0 || r == 0){
        cerr << "Len incorrect\n";
        return 0;
    }
    unsigned char *k = new unsigned char[r];

    cout << "Generate key or no? (0 - yes; 1 - no)\n";
    cin >> temp;

    if(temp != 0 && temp != 1){
        cerr << "Input incorrect\n";
        return 0;
    }

    if(temp == 1){
        cout << "\nEnter k_i with space or enter:\n";
        int temp;
        for(int i = 0; i < r; ++i){
            cin >> temp;
            if(temp < 256 && temp > 0) k[i] = (unsigned char)temp;
        }
    } else gen_key(k, r);

    cout << "\nKey (hex): ";
    for(int i = 0; i<r; ++i) cout << std::hex << (int)k[i] << ' ';

    encode(data, strlen((char*)data), k, r);
    cout << "\n\nEncrypted: " << data << '\n';
    cout << "      hex: ";
    for(int i = 0; i < strlen((char*)data); ++i)
        cout << std::hex << (int)data[i] << ' ';

    decode(data, strlen((char*)data), k, r);
    cout << "\n\nDecrypted: " << data << '\n';

    delete [] k;

    return 0;
}
