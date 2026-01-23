#include<iostream>

// void printnum();
// int main(){


//     int mynum = 1;
//     printnum();

//     return 0;
// }

// void printnum(){
//      int mynum = 5;
//     std:: cout<<mynum;
// }

// int mynum = 8;
// void printnum();
// int main(){

// int mynum = 1;
   
//     printnum();
//  std:: cout<<mynum;
//     return 0;
// }

// void printnum(){
//     int mynum = 5;
//     std:: cout<<mynum;
// }

int mynum = 8;
void printnum();
int main(){

int mynum = 1;
   
    printnum();
 std:: cout << " Main Local: " << mynum << " Global: " << ::mynum << "\n";
    return 0;
}

void printnum(){
    int mynum = 5;
    std:: cout << " Func Local: " << mynum << " Global: " << ::mynum << "\n";
}