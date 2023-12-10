#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car {
    string name;
    int speed;
};


int main() {
    vector<Car> cars = {
            {"kalina", 150},
            {"CIvic",  220},
            {"niva",   140},
            {"camaro", 280}
    };


    sort(cars.begin(), cars.end(), [](Car o1, Car o2) {
        if (o1.speed != o2.speed)
            return o1.speed < o2.speed;
        return o1.name < o2.name;
    });

    for (auto n: cars) {
        cout << n.name << "\n";
    }

}