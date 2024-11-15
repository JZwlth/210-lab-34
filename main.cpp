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

    while (!carQueue.empty()) {
        int operation = rand() % 100 + 1;  // Random number between 1 and 100
        
        if (operation <= 55) {
            // 55% chance for the car at the head of the queue to pay and leave
            cout << "Time: " << time << " Operation: Car paid: ";
            carQueue.front().print();
            carQueue.pop_front();
        } else {
            // 45% chance for a new car to join the line
            Car newCar;
            cout << "Time: " << time << " Operation: Joined lane: ";
            newCar.print();
            carQueue.push_back(newCar);
        }

        cout << "Queue:\n";
        if (carQueue.empty()) {
            cout << "    Empty\n";
        } else {
            for (auto &car : carQueue) {
                car.print();
            }
        }
        cout << endl;

        time++; // Increment time for each cycle
    }

    return 0;
}