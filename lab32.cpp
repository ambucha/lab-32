// COMSC-210 | Lab 32 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

// create the const variables, such as starting cars in toll ammount, also probabilities
const int STARTING_SIZE = 2;
const int PAYS = 55;
const int JOINS = 45;


int main(){
    // start by declaring a deque that will store cars, initialize to size 2
    deque<Car> toll(STARTING_SIZE);

    // test to see if the cars are in the toll
    for(auto car : toll){
        car.print();
    }

    return 0;
}