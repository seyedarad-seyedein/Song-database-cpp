#ifndef HELPER
#define HELPER
#include <iostream>
#include <string>
#include <exception>
using namespace std;


class BacktoMenuException {};
class InputExecption : public exception {
public:
    const char* what() const noexcept override {
        return "invalid input :)";
    }
};
inline int get_int_input() {
    int x;
    cin >> x;
     if (!cin) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw InputExecption();
     }
     if (x == -9){
        throw BacktoMenuException();
       }
    return x;
   }
inline string get_string_input() {
    string s;
    getline(cin >> ws, s);

    if (s == "-9"){
        throw BacktoMenuException();
    }
    if (s.empty()){
        throw InputExecption();
    }
    return s;
}

#endif