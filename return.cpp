#include<iostream>

// std:: string fullname(std:: string string1, std:: string string2);

// int main(){
//     std:: string first_name = "Sahil";
//     std:: string last_name = "Kumar";

// std:: string proper_name = fullname(first_name, last_name);

//     std:: cout<< "Full name is: " << proper_name;

//     return 0;


// }

// std:: string fullname(std:: string string1, std:: string string2){

//     return string1+ " " +string2;
// }



// double addt(double y, double z);


// int main(){

//  double a= 65;
//  double b=98;
// double sum= addt(a,b);

// std:: cout<< "The sum is : "<< sum;
// return 0;

// }

// double addt(double y, double z){
//     return y+z;
// }

// int total(int a1, int a2);
// int main(){



//     int radius=5;
//     int pi=3.14;

//     int area= total(radius, pi);
//     std:: cout<< "The area of cricle is: " << area;
// }
// int total(int a1, int a2){
//     return a1*a1*a2;
// }


std:: string info(std:: string name1, std:: string a1, std:: string name2);

int main(){


   std:: string diff = "You are ";
   std:: string od = " years old.";
   std:: string age;
std:: cout<< "Enter your age: ";
std:: cin>>age;


   std:: string details = info(diff, age, od);
   std:: cout<<details;
   return 0;

}
std:: string info(std:: string name1, std:: string a1, std:: string name2){
    return name1+ a1 + name2;
}