#pragma pack(1)

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "bmp.h"

vector<char> buffer;
PBITMAPFILEHEADER file_header;
PBITMAPINFOHEADER info_header;

int main() {
    cout << "Wczytywanie Pliku..." << endl;
    ifstream file("test.bmp");

    if (file) {
        cout << "Plik wczytany.\nOdczyt Danych..." << endl;
        file.seekg(0, std::ios::end);
        streampos length = file.tellg();
        file.seekg(0, std::ios::beg);

        buffer.resize(length);
        file.read(&buffer[0], length);

        file_header = (PBITMAPFILEHEADER)(&buffer[0]);
        info_header = (PBITMAPINFOHEADER)(&buffer[0] + sizeof(BITMAPFILEHEADER));
    }

    cout << "Dane pliku: "<<endl;
    cout << "Rozmiar pliku: " << file_header->bfSize << endl;
    cout << "Wymiary pliku: " << info_header->biWidth << " " << info_header->biHeight << endl;

    return 0;
}
