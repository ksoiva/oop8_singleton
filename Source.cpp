#include <iostream>
#include <string>
#define N 20
using namespace std;


class UkrString {
private:

    static UkrString* singleObj;
    static int count;

    string str;
    string substr;

public:

    UkrString(string n, string sn) {
        str = n;
        substr = sn;
        count++;
    }

    UkrString() {
        str = {};
        substr = {};
    }

    static UkrString& getInstance(string n, string sn) {

        if (count == 0) {
            singleObj = new UkrString(n, sn);
        }
        return *singleObj;
    };

    bool operator * () {
        if (str.find(substr) != string::npos) {
            return true;
        }
        else return false;
    }


    string Getstr() {
        return str;
    }

    string Getsubstr() {
        return substr;
    }

    ~UkrString() {
    }
};

int UkrString::count = 0;
UkrString* UkrString::singleObj = 0;

int main() {
    system("chcp 1251");
    cout << endl;

    string cop;
    string subcop;

    cout << "Enter string: ";
    getline(cin, cop);

    cout << "Enter substring: ";
    getline(cin, subcop);

    UkrString& str = UkrString::getInstance(cop, subcop);

    cout << endl;

    cout << "Your string: " << str.Getstr() << endl;
    cout << "Substring: " << str.Getsubstr() << endl;


    if (str.operator*() == true) {
        cout << "String includes substring" << endl;
    }

    cout << endl;

    str = UkrString::getInstance("Hi Mary", "Mary");
    cout << "Your string: " << str.Getstr() << endl;
    cout << "Substring: " << str.Getsubstr() << endl;

    cout << endl;

    return 0;
}

/*
Мама мила раму
мила
*/