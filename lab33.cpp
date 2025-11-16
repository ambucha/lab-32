// COMSC-210 | Lab 33 | Andrei Buchatskiy
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
const int NUM_OF_LANES = 4;
const int PAY_CHANCE = 46;
const int JOIN_CHANCE = 39;
const int SHIFT_CHANCE = 15; 
const int MAX = 100;
const int MIN = 1;
const int TIME = 20;


int main(){
    // ssed a rand
    srand(time(0));

    // create an array of deques with 2 cars in each lane
    deque<Car> toll[NUM_OF_LANES];
    for(auto& lane : toll){
        lane = deque<Car>(STARTING_SIZE);
    }

    // variable for if the car pays or if a car joins
    int chance;

    // ok so we see there are two cars per lane
    // lets check the initial state to see that cars are random
    int lanes = 0;
    cout << "Initial queue:" << endl;
    for(auto& lane : toll){
        lanes++;
        cout << "Lane " << lanes << ":" << endl;
        for(auto& car : lane){
            cout << "\t";
            car.print();
        }
    }

    // loop for twenty time periods
    for(int i = 1; i <= TIME; i++){
        // output what time period we are on
        lanes = 0;
        cout << "Time: " << i << endl;

        // we now want it to be 50 50 for this mielstone not the actual percentages yet so i need to change my consts firsy
        for(auto& lane : toll){
            // create a percentage chance for this time period, for this toll
            chance = rand() % (MAX - MIN + 1) + MIN;
            lanes++;

            if(chance > CHANCE){
                // create a Car var and then push it back in the queue
                Car newCar;
                lane.push_back(newCar);
                
                // print out the operation
                cout << "Lane: " << lanes << " Joined: ";
                lane.back().print();
            }

            // now check if probability is for the car to pay, and if there are cars in the lane to pay
            else if(chance <= CHANCE && !lane.empty()){
                cout << "Lane: " << lanes << " Paid: ";
                lane.front().print();
                lane.pop_front();
            }

            // if neither condition is met nothing happens in that toll in this time period
            else{
                cout << "Lane: " << lanes << "Nothing happened" << endl;
            }
        }
        
        lanes = 0;
        // print out each lane queue
        for(auto& lane : toll){
        lanes++;
        cout << "Lane " << lanes << " Queue:" << endl;
            for(auto& car : lane){
                cout << "\t";
                car.print();
            }
        }
    }

    // create a while loop to run until there are no cars at the toll booth
    /*
    while(!toll.empty()){
        // create a percentage chance for this time period
        chance = rand() % (MAX - MIN + 1) + MIN;

        // count up the time
        time++;
        cout << "Time: " << time << " Operation: ";

        // 45% chance its a new car joining
        if(chance > CHANCE){
            // create a Car var and then push it back in the queue
            Car newCar;
            toll.push_back(newCar);

            // print out that a car joined the lane then peek at the back to see which car joined
            cout << "Joined lane: ";
            toll.back().print();
        }
        // 55% chance the car at the front pays
        else{
            // first print out what car is payign before popping it out
            cout << "Car paid: ";
            toll.front().print();
            toll.pop_front();
        }

        // end of each time period print out what the toll looks like 
        cout << "Queue: " << endl;
        if(toll.empty()){
            cout << "\tEmpty" << endl;
        }
        else{
            for(auto car : toll){
                cout << "\t";
                car.print();
            }
        }
    }
        */

    return 0;
}