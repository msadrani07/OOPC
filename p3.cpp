#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


struct Car {
    int number;
    string modelName;
    string fuelType;
    float showroomPrice;
    float mileage;
    string transmission;
    float tankCapacity;
    int seating;
    string airbags;
};


void displayCarDetails(const Car& car) {
    cout << "\nDetails for Car #" << car.number << ":" << endl;
    cout << "Model Name: " << car.modelName << endl;
    cout << "Fuel Type: " << car.fuelType << endl;
    cout << "Showroom Price: " << fixed << setprecision(2) << car.showroomPrice << endl;
    cout << "Mileage: " << car.mileage << endl;
    cout << "Transmission: " << car.transmission << endl;
    cout << "Tank Capacity: " << car.tankCapacity << endl;
    cout << "Seating: " << car.seating << endl;
    cout << "Airbags: " << car.airbags << endl;
}

int main() {
    const int MAX_CARS = 5;

    Car cars[MAX_CARS];
    int numCars;

    cout << "Enter the number of cars: ";
    cin >> numCars;


    for (int i = 0; i < numCars; ++i) {
        cout << "\nEnter details for Car #" << i + 1 << ":" << endl;

        cout << "Number: ";
        cin >> cars[i].number;

        cout << "Model Name: ";
        cin.ignore();
        getline(cin, cars[i].modelName);

        cout << "Fuel Type: ";
        cin >> cars[i].fuelType;

        cout << "Showroom Price: ";
        cin >> cars[i].showroomPrice;

        cout << "Mileage: ";
        cin >> cars[i].mileage;

        cout << "Transmission: ";
        cin >> cars[i].transmission;

        cout << "Tank Capacity: ";
        cin >> cars[i].tankCapacity;

        cout << "Seating: ";
        cin >> cars[i].seating;

        cout << "Airbags (Yes/No): ";
        cin >> cars[i].airbags;
    }


    cout << "\nRetrieval Options:\n";
    cout << "1. Model Name\n";
    cout << "2. Fuel Type\n";
    cout << "3. Price Range\n";

    int option;
    cout << "\nEnter your choice (1-3): ";
    cin >> option;

    switch (option) {
        case 1:
            {
                string modelName;
                cout << "Enter Model Name: ";
                cin.ignore();
                getline(cin, modelName);


                cout << "\nCars with Model Name '" << modelName << "':";
                for (int i = 0; i < numCars; ++i) {
                    if (cars[i].modelName == modelName) {
                        displayCarDetails(cars[i]);
                    }
                }
            }
            break;

        case 2:
            {
                string fuelType;
                cout << "Enter Fuel Type: ";
                cin >> fuelType;


                cout << "\nCars with Fuel Type '" << fuelType << "':";
                for (int i = 0; i < numCars; ++i) {
                    if (cars[i].fuelType == fuelType) {
                        displayCarDetails(cars[i]);
                    }
                }
            }
            break;

        case 3:
            {
                float minPrice, maxPrice;
                cout << "Enter Min Price: ";
                cin >> minPrice;
                cout << "Enter Max Price: ";
                cin >> maxPrice;


                cout << "\nCars within Price Range $" << minPrice << " - $" << maxPrice << ":";
                for (int i = 0; i < numCars; ++i) {
                    if (cars[i].showroomPrice >= minPrice && cars[i].showroomPrice <= maxPrice) {
                        displayCarDetails(cars[i]);
                    }
                }
            }
            break;

        default:
            cout << "Invalid option. Exiting.\n";
    }

    return 0;
}
