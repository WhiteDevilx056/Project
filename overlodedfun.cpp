#include<iostream>


void bakePizza();
void bakePizza( std:: string topping1);
void bakePizza(std:: string topping1, std:: string topping2);
int main (){

    bakePizza();
bakePizza("coockies with cream");
bakePizza("chocolate", "strawberry");
return 0;



}

void bakePizza(){
    std:: cout<< "This is your Pizza. \n";
}

void bakePizza(std:: string topping1){
    std:: cout<< "This is your "<< topping1<< " pizza\n";
}
void bakePizza(std:: string topping1, std:: string topping2){
    std:: cout<< "This is your "<< topping1<< " and "<< topping2<< " pizza\n";
}

