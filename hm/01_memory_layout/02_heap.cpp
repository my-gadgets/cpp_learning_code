#include <iostream>
using namespace std;

int* func() {
    // object stores in heap area, won't be free by function
    // pointer a is itself a local var
    // but pointee of a is in heap area
    int* a = new int(10);
    return a;
}

int main() {
    int *p = func();
    cout << *p << endl;

    return 0;
}

