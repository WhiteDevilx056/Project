#include<iostream>
using namespace std;

// void pattern1(int n) {
//     // Step 1: Focus on the number of rows (outer loop): n rows
//     for (int i = 0; i <= n; i++) {
//         // Step 2: Focus on the number of columns (inner loop): n columns
//         for (int j = 0; j<= n-i+1; j++) {
//             // Step 3: Printing ' * ' in the inner loop
//             cout<< j;
//         }
//         cout<<endl;
//         // Step 4: Observing Symmetry: NOT REQUIRED
//    }
// }
// int main() {
//     int n;
//     cout << "Enter the number of rows/columns for the pattern: ";
//     cin >> n;
//     pattern1(n);
//     return 0;
// }

/*
void pattern7(int n) {
    // Step 1: Number of rows: n
    for (int i = 0; i < n; i++) {
        // Step 2.1: Spaces - Number of columns: n - i - 1, e.g. if n = 4, step 1: 3, step 2: 2, step 3: 1, step 4: 0
        for (int j = 0; j < n-i-1; j++) {
            // Step 3.1: Printing spaces n-i-1 times
            cout<<"  ";
        }

        // Step 2.2: Stars - Number of columns: 2 * i + 1, e.g. step 1: 1, step 2: 3, step 3: 5, step 4: 7
        for (int j = 0; j < 2*i+1 ; j++) {
            // Step 3.1: Printing stars 2*i+1 times
            cout<<"* ";
        }
        cout<<endl;
        // Step 4: Observing Symmetry: NOT REQUIRED
    }
}
*/

void patternNew(int n) {
    // Step 1: Number of rows: n
    for (int i = 0; i < n; i++) {
        // Step 2.1: Spaces - Number of columns: n - i - 1
        for (int j = 0; j < n-i-1; j++) {
            // Step 3.1: Printing spaces n-i-1 times (Single space for alignment)
            cout<<" ";
        }

        // Step 2.2: Stars - Number of columns: i + 1
        for (int j = 0; j <= i ; j++) {
            // Step 3.1: Printing stars i+1 times
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows for the pattern: ";
    cin >> n;
    patternNew(n);
    return 0;
}

