#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Car {
    public:
    string name;
    string fuelType;
    double mileage;
    double price;
    string transmission;
    int tankCapacity;
    int seatingCapacity;
    string isAutomatic;
};

Car readCarFromFile(ifstream& file) {
    Car car;
    string line;
    if (getline(file, line, ';')) {
        stringstream ss(line);
        getline(ss, car.name, ',');
        getline(ss, car.fuelType, ',');
        ss >> car.mileage;
        ss.ignore(); // Ignore the comma
        ss >> car.price;
        ss.ignore(); // Ignore the comma
        getline(ss, car.transmission, ',');
        ss >> car.tankCapacity;
        ss.ignore(); // Ignore the comma
        ss >> car.seatingCapacity;
        ss.ignore(); // Ignore the comma
        getline(ss, car.isAutomatic, ',');
    }
    return car;
}

void displayCarDetails(const Car& car) {
    cout << "Name: " << car.name << endl;
    cout << "Fuel Type: " << car.fuelType << endl;
    cout << "Mileage: " << car.mileage << " kmpl" << endl;
    cout << "Price: $" << car.price << endl;
    cout << "Transmission: " << car.transmission << endl;
    cout << "Tank Capacity: " << car.tankCapacity << " liters" << endl;
    cout << "Seating Capacity: " << car.seatingCapacity << " persons" << endl;
    cout << "Automatic: " << car.isAutomatic << endl;
}

void retrieveCarByModel(ifstream& file, const string& modelName) {
    file.clear(); // Clear eof flag
    file.seekg(0, ios::beg); // Rewind file
    Car car;
    while ( file) {
        car = readCarFromFile(file);
        if (car.name == modelName) {
            cout << "Details of " << modelName << ":\n";
            displayCarDetails(car);
        }
    }
    }


void retrieveCarByFuelType(ifstream& file, const string& fuelType) {
    file.clear(); // Clear eof flag
    file.seekg(0, ios::beg); // Rewind file
    Car car;
    cout << "Cars with fuel type " << fuelType << ":\n";
    while (file) {
        car = readCarFromFile(file);
        if (car.fuelType == fuelType) {
            displayCarDetails(car);
            cout << "----------------------\n";
        }
    }
}

void retrieveCarByPriceRange(ifstream& file, double minPrice, double maxPrice) {
    file.clear(); // Clear eof flag
    file.seekg(0, ios::beg); // Rewind file
    Car car;
    cout << "Cars within price range $" << minPrice << " - $" << maxPrice << ":\n";
    while (file) {
        car = readCarFromFile(file);
        if (car.price >= minPrice && car.price <= maxPrice) {
            displayCarDetails(car);
            cout << "----------------------\n";
        }
    }
}

int main() {
    ifstream file("cardata.txt");
    if (!file.is_open()) {
        cout << "Error opening file cardata.txt" << endl;
        return 1;
    }

    cout << "Data loaded successfully.\n";

    int option;
    cout << "Choose an option:\n";
    cout << "1. Retrieve car details by model\n";
    cout << "2. Retrieve car details by fuel type\n";
    cout << "3. Retrieve car details by price range\n";
    cin >> option;

    switch (option) {
        case 1: {
            string modelName;
            cout << "Enter the model name: ";
            cin >> modelName;
            retrieveCarByModel(file, modelName);
            break;
        }
        case 2: {
            string fuelType;
            cout << "Enter the fuel type: ";
            cin >> fuelType;
            retrieveCarByFuelType(file, fuelType);
            break;
        }
        case 3: {
            double minPrice, maxPrice;
            cout << "Enter the minimum price: ";
            cin >> minPrice;
            cout << "Enter the maximum price: ";
            cin >> maxPrice;
            retrieveCarByPriceRange(file, minPrice, maxPrice);
            break;
        }
        default:
            cout << "Invalid option!\n";
    }

    file.close();
    return 0;
}
