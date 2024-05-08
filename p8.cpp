#include<iostream>
#include<iomanip>
using namespace std;

class employee {
private:
    int id;
    string name, qual;
    float exp;
    long long int mo_no;
    static int count_call;
    static float total_experience;

protected:
    void getempdata();
    void putempydata();
    int searchemp(int temp);

public:
    static void avgexp();

};

void employee::getempdata() {
    cout << "Enter the Employee ID: ";
    cin >> id;
    cout << "Please Enter the Name of the Employee: ";
    cin >> name;
    cout << "Please Enter the Qualification of the Employee: ";
    cin >> qual;
    cout << "Please Enter the Experience of the Employee: ";
    cin >> exp;
    total_experience += exp;
    cout << "Please Enter the Mobile Number of the Employee: ";
    cin >> mo_no;
    count_call++;
}

void employee::putempydata() {
    cout << "\nEmployee Name" << setw(6) << ":" << name << endl;
    cout << "Qualification" << setw(6) << ":" << qual << endl;
    cout << "Experience" << setw(9) << ":" << exp << endl;
    cout << "Contact Number" << setw(5) << ":" << mo_no << endl;
}

int employee::searchemp(int temp) {
    if(id == temp)
        return 1;
    else
        return 0;
}

void employee::avgexp() {
    cout<<"Average Experience"<<setw(1)<<":"<< total_experience / count_call <<endl;
}

int employee::count_call = 0;
float employee::total_experience = 0;

class teachingemployee : public employee {
private:
    string designation;
    string specialization;
    string payscale;

public:
    int searchemptemp(int temp);
    void getempdata();
    void putempydata();
};

void teachingemployee::getempdata() {
    employee::getempdata();
    cout << "Enter designation: ";
    cin >> designation;
    cout << "Enter specialization: ";
    cin >> specialization;
    cout << "Enter pay scale: ";
    cin >> payscale;
}

void teachingemployee::putempydata() {
    employee::putempydata();
    cout << "Designation" << setw(8) << ":" << designation << endl;
    cout << "Specialization" << setw(5) << ":" << specialization << endl;
    cout << "Payscale" << setw(11) << ":" << payscale << endl;
}

int teachingemployee::searchemptemp(int temp) {
    return searchemp(temp);
}

class nonteachingemployee : public employee {
private:
    int salary;

public:
    int searchntemp(int temp);
    void getempdata();
    void putempydata();
};

void nonteachingemployee::getempdata() {
    employee::getempdata();
    cout << "Enter salary of Employee: ";
    cin >> salary;
}

void nonteachingemployee::putempydata() {
    employee::putempydata();
    cout << "Salary" << setw(13) << ":" << salary << endl;
}

int nonteachingemployee::searchntemp(int temp) {
    return searchemp(temp);
}

int main() {
    int temp;
    int ntemp;
    int search;
    int flag = 0;

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

    system("CLS");

    char ch;
    do {
        flag =0;
        for(int i=0;i<60;i++)
        cout<<"*";
        cout <<"\nEnter The Employee ID for information: ";
        cin >> search;
        for(int i=0;i<60;i++)
        cout<<"*";
        for(int i = 0; i < temp; i++) {
            if(teachingemployees[i].searchemptemp(search) == 1) {
                teachingemployees[i].putempydata();
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            for(int i = 0; i < ntemp; i++) {
                if(nonteachingemployees[i].searchntemp(search) == 1) {
                    nonteachingemployees[i].putempydata();
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0) {
            cout << "\nERROR: ENTERED EMPLOYEE ID DOES NOT EXIST" << endl;
        }
        for(int i=0;i<60;i++)
        cout<<"*";
        cout << "\nPress Y to get another employee detail, press N to exit: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    employee::avgexp();

    delete[] teachingemployees;
    delete[] nonteachingemployees;

    return 0;
}
