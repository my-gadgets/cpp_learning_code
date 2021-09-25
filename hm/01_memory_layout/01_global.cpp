#include <iostream>
using namespace std;

// global vars
int g_a = 10;
int g_b = 10;

// const + global vars
const int c_g_a = 10;
const int c_g_b = 10;

int main() {
    // global area stores: global vars, static vars, consts
    
    // local vars
    int a = 10;
    int b = 10;
    
    // (long) to convert to 10-based numbers, default is 16-based
    cout << "a's address: " << (long)&a << endl;
    cout << "b's address: " << (long)&b << endl;

    cout << "g_a's address: " << (long)&g_a << endl;
    cout << "g_b's address: " << (long)&g_b << endl;

    // static vars
    static int s_a = 10;
    static int s_b = 10;
    cout << "s_a's address: " << (long)&s_a << endl;
    cout << "s_b's address: " << (long)&s_b << endl;

    // consts
    // string literals
    cout << "address of string literals: " << (long)&"hello world" << endl;

    // consts + global vars
    cout << "c_g_a's address: " << (long)&c_g_a << endl;
    cout << "c_g_b's address: " << (long)&c_g_b << endl;

    // consts + local vars
    // !!! this vars are stored in stack instead of global area
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "c_l_a's address: " << (long)&c_l_a << endl;
    cout << "c_l_b's address: " << (long)&c_l_b << endl;

    return 0;
}

