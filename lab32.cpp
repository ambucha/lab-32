// COMSC-210 | Lab 32 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

// create the const variables, such as starting cars in toll ammount, also probabilities
// since pays and joins add up to 100 (55% for pays 45% for joins) and there are only two i can just use the same variable and use greater than or less than for the probabilities
const int STARTING_SIZE = 2;
const int CHANCE = 55;
const int MAX = 100;
const int MIN = 1;


int main(){
    // ssed a rand
    srand(time(0));

    // start by declaring a deque that will store cars, initialize to size 2
    deque<Car> toll(STARTING_SIZE);

    // variable for if the car pays or if a car joins
    int chance;

    // create a while loop to run until there are no cars at the toll booth
    while(toll.size() != 0){
        // create a percentage chance for this time period
        chance = rand() % (MAX - MIN + 1) + MIN;

        // 45% chance its a new car joining
        if(chance > CHANCE){
            // create a Car var and then push it back in the queue
            Car newCar;
            toll.push_back(newCar);
        }
        // 55% chance the car at the front pays
        else{
            toll.pop_front();
        }

        // end of each time period print out what the toll looks like
        for(auto car : toll){
            car.print();
        }
    }

    return 0;
}