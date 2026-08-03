#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, word = "", longest = "";

    getline(cin, s);
    s += ' ';

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ')
         word += s[i];
    
        else {
            if (word.length() > longest.length())
                longest = word;
            word = "";
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << longest.length()<<endl;
    cout<<"total:-  "<<s.length();

    return 0;
}