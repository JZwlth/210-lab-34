#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_SIZE = 2;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));
    
    deque<Car> carQueue;

    for (int i = 0; i < INITIAL_SIZE; i++) {
        carQueue.push_back(Car());
    }

    // Display the initial queue
    cout << "Initial queue:\n";
    for (auto &car : carQueue) {
        car.print();
    }
    cout << endl;

    int time = 1; 

    return 0;
}