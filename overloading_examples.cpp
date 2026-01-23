#include <iostream>
#include <string>

using namespace std;

// 1. Number of parameters alag hain
void add(int a) {
    cout << "Function with 1 parameter: " << a << endl;
}
void add(int a, int b) {
    cout << "Function with 2 parameters: " << a + b << endl;
}

// 2. Type of parameters alag hain
void print(int i) {
    cout << "Printing Integer: " << i << endl;
}
void print(string s) {
    cout << "Printing String: " << s << endl;
}

// 3. Sequence of parameters alag hai
void process(int a, double b) {
    cout << "Sequence: Int (" << a << ") then Double (" << b << ")" << endl;
}
void process(double a, int b) {
    cout << "Sequence: Double (" << a << ") then Int (" << b << ")" << endl;
}

int main() {
    add(5);             // Calls 1 parameter version
    add(5, 10);         // Calls 2 parameter version
    
    print(100);         // Calls int version
    print("Hello");     // Calls string version
    
    process(10, 5.5);   // Calls int, double
    process(5.5, 10);   // Calls double, int
    
    return 0;
}