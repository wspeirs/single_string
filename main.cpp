#include <iostream>
#include <functional>
#include "single_string.h"

using namespace std;

int main() {
    single_string b1("blah");
    single_string b2("blah");
    single_string b3(string("blah"));

    if(b1 == b2 && b2 == b3) {
        cout << "EQUAL" << endl;
    }

    cout << hash<single_string>()(b1) << endl;
    cout << hash<single_string>()(b2) << endl;
    cout << hash<single_string>()(b3) << endl;

    single_string::free_all();

    return 0;
}