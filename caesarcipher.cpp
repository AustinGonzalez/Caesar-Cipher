// This is a c++ implementation of Caesar's cipher
// The program takes string input and converts it into a ciphered string.
// By Austin Gonzalez


#include "header.h"
using namespace std;
class Caesar {
    int caesar_cipher(int p){
    if (p == 26) return p; 
    p = ((p+3) % 26); 
    return p;
}
int decrypt_caesar(int p){
    if (p == 26) return p;
    p = ((p - 3) % 26);
    if (p < 0) p += 26;
    return p;
}
public:   
int letter_to_number(char c){
    int number;
    string caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha = "abcdefghijklmnopqrstuvwxyz ";
    
    for(int i = 0; i < alpha.size(); ++i){
        if(c == alpha[i]){
            number = i;
        }
        else if(c == caps[i]){
            number = i;
        }
        
    }
    return number;
}

char number_to_letter(int n){
    string alpha = "abcdefghijklmnopqrstuvwxyz ";
    char c = alpha[n];
    return c;
}

void encryption(string message){
    vector<int> v;
    for(int i = 0; i < message.size(); ++i){
        v.push_back(letter_to_number(message[i]));
    }
    vector<int> encrypted;
    for(int j = 0; j < v.size(); ++j){
        encrypted.push_back(caesar_cipher(v[j]));
    }
    vector<char> characters;
    for(int k = 0; k < encrypted.size(); ++k){
        
        characters.push_back(number_to_letter(encrypted[k]));
    }
    string jamble = string(characters.begin(), characters.end() );
    cout << jamble << endl;
    cout << "Decrypted message: \n";
    decryption(jamble);
}

void decryption(string &message){
    vector<int> v;
    for(int i = 0; i < message.size(); ++i){
        v.push_back(letter_to_number(message[i]));
    }
    vector<int> encrypted;
    for(int j = 0; j < v.size(); ++j){
        encrypted.push_back(decrypt_caesar(v[j]));
    }
    vector<char> characters;
    for(int k = 0; k < encrypted.size(); ++k){
        
        characters.push_back(number_to_letter(encrypted[k]));
    }
    string unjamble = string(characters.begin(), characters.end() );
    cout << unjamble << endl;
}
};
int main(){
    cout << "Caesar Cipher" << endl;
    string input;
    cout << "Enter your message: ";
    getline(cin, input);
    Caesar caesar;
    caesar.encryption(input);
    
    return 0;
}