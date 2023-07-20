#include <iostream>
#include <fstream>
using namespace std;

void encryptFile(const string& inputFile, const string& outputFile, char key) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    char ch;
    while (inFile.get(ch)) {
        ch = ch ^ key;
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();
}

void decryptFile(const string& inputFile, const string& outputFile, char key) {
    encryptFile(inputFile, outputFile, key); // Decryption is the same as encryption using XOR
}

int main() {
    string inputFile, encryptedFile, decryptedFile;
    char key;

    cout << "Enter the name of the input file: ";
    cin >> inputFile;

    cout << "Enter the name of the encrypted output file: ";
    cin >> encryptedFile;

    cout << "Enter the name of the decrypted output file: ";
    cin >> decryptedFile;

    cout << "Enter the encryption/decryption key (a single character): ";
    cin >> key;

    // Encrypt the file
    encryptFile(inputFile, encryptedFile, key);
    cout << "File encrypted successfully!" << endl;

    // Decrypt the file
    decryptFile(encryptedFile, decryptedFile, key);
    cout << "File decrypted successfully!" << endl;

    return 0;
}