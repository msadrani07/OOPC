#include<iostream>
#include<iomanip>
using namespace std;

class employee {
private:
    int id;
    string name, qual;
    float exp;
    string mo_no; // Change type to string
    static int count_call;
    static float total_experience;
protected:
    void getempdata();
    void putempydata();
public:
    static float avgexp();
};

void employee::getempdata() {
    cout << "Please Enter the Name of the Employee:" << endl;
    cin >> name;
    cout << "Please Enter the Qualification of the Employee:" << endl;
    cin >> qual;
    cout << "Please Enter the Experience of the Employee:" << endl;
    cin >> exp;
    total_experience += exp;
    cout << "Please Enter the Mobile Number of the Employee:" << endl;
    cin >> mo_no;
    count_call++;
}

void employee::putempydata() {
    cout << "Employee Name" << setw(6) << ":" << name << endl;
    cout << "Qualification" << setw(6) << ":" << qual << endl;
    cout << "Experience" << setw(9) << ":" << exp << endl;
    cout << "contact Number" << setw(5) << ":" << mo_no << endl;
}

class teachingemployee : public employee {
private:
    string designation;
    string specialization;
    string payscale;
public:
    void getempdata();
    void putempydata();
};

void teachingemployee::getempdata() {
    employee::getempdata();
    cout << "Enter designation :" << endl;
    cin >> designation;
    cout << "Enter specialization :" << endl;
    cin >> specialization;
    cout << "Enter pay scale :" << endl;
    cin >> payscale;
}

void teachingemployee::putempydata() {
    employee::putempydata();
    cout << "Designation" << setw(8) << ":" << designation << endl;
    cout << "Specialization" << setw(5) << ":" << specialization << endl;
    cout << "Payscale" << setw(11) << ":" << payscale << endl;
}

class nonteachingemployee : public employee {
private:
    int salary;
public:
    void getempdata();
    void putempydata(); //
};

void nonteachingemployee::getempdata() {
    employee::getempdata();
    cout << "Enter salary of Employee :" << endl;
    cin >> salary;
}

void nonteachingemployee::putempydata() {
    employee::putempydata();
    cout << "Salary" << setw(13) << ":" << salary << endl;
}

int employee::count_call = 0;
float employee::total_experience = 0;

float employee::avgexp() {
    if (count_call == 0) return 0;
    return total_experience / count_call;
}

int main() {
    int temp;
    int ntemp;
    cout << "Enter the number of Teaching employees you want to enter data for: ";
    cin >> temp;
    teachingemployee *teachingemployees = new teachingemployee[temp];

    cout << "Enter the number of Non Teaching employees you want to enter data for: ";
    cin >> ntemp;
    nonteachingemployee *nonteachingemployees = new nonteachingemployee[ntemp];

    cout << "Enter data of Teaching Employees." << endl;
    for (int i = 0; i < temp; i++) {
        cout << "Please Enter the Data for employee " << (i + 1) << ":" << endl;
        teachingemployees[i].getempdata();
    }

    cout << "Enter data of Non Teaching Employees." << endl;
    for (int i = 0; i < ntemp; i++) {
        cout << "Please Enter the Data for employee " << (i + 1) << ":" << endl;
        nonteachingemployees[i].getempdata();
    }

    delete[] teachingemployees;
    delete[] nonteachingemployees;

    return 0;
}
