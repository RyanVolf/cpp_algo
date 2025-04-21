#include <iostream>
#include <string>

using namespace std;

// ======== Caesar Cipher =========
string caesarEncrypt(const string& text, int shift) {
    string result;
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            result += (ch - base + shift + 26) % 26 + base;
        }
        else {
            result += ch;
        }
    }
    return result;
}

// ======== Vigenere Cipher ========
string vigenereEncrypt(const string& text, const string& key, bool decrypt = false) {
    string result;
    int keyIndex = 0;
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int k = toupper(key[keyIndex % key.length()]) - 'A';
            if (decrypt) k = -k;
            result += (ch - base + k + 26) % 26 + base;
            keyIndex++;
        }
        else {
            result += ch;
        }
    }
    return result;
}

// ======== XOR Cipher =========
string xorEncryptDecrypt(const string& text, char key) {
    string result = text;
    for (char& ch : result) {
        ch ^= key;
    }
    return result;
}

int main() {
    int choice;
    cout << "=== Encryptor / Decryptor ===\n";
    cout << "1. Caesar Cipher\n";
    cout << "2. Vigenere Cipher\n";
    cout << "3. XOR Cipher\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;
    cin.ignore();

    if (choice == 0) return 0;

    string text;
    cout << "Enter text: ";
    getline(cin, text);

    if (choice == 1) {
        int shift;
        char mode;
        cout << "Shift amount: ";
        cin >> shift;
        cout << "Mode (e = encrypt, d = decrypt): ";
        cin >> mode;
        if (mode == 'd') shift = -shift;
        cout << "Result: " << caesarEncrypt(text, shift) << endl;

    }
    else if (choice == 2) {
        string key;
        char mode;
        cout << "Keyword: ";
        cin >> key;
        cout << "Mode (e = encrypt, d = decrypt): ";
        cin >> mode;
        cout << "Result: " << vigenereEncrypt(text, key, mode == 'd') << endl;

    }
    else if (choice == 3) {
        char key;
        cout << "Single character key: ";
        cin >> key;
        string result = xorEncryptDecrypt(text, key);
        cout << "Result: " << result << endl;
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
