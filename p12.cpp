#include <iostream>
#include <iomanip>
using namespace std;

class result; // Forward declaration of the result class

class student
{
private:
    string stu_id;
    string stu_name;
    int sem;
public:
    void getdata_stu();
    void putdata_stu();
    void get_result(result &r); // Pass result object by reference
    void put_result(result &r); // Pass result object by reference
};

void student :: getdata_stu()
{
    cout << "Enter student id  :";
    cin >> stu_id;
    cout << "Enter student name :";
    cin >> stu_name;
    cout << "Enter student semester :";
    cin >> sem;
}

void student :: putdata_stu()
{
    cout << left << setw(20) << "Student ID" << left << ":" << stu_id << endl;
    cout << left << setw(20) << "Student Name" << left << ":" << stu_name << endl;
    cout << left << setw(20) << "Student Semester" << left << ":" << sem << endl;
}

class result
{
private:
    string subject_name[3];
    int th_credit[3];
    int pr_credit[3];
    int th_marks[3];
    int pr_marks[3];
    string th_grade[3];
    string pr_grade[3];
    int th_gp[3];
    int pr_gp[3];
    int sum;
    int total_credit;
    float sgpa;
public:
    void sgpa_cal();
    string convert_to_grade(int marks);
    int convert_to_grade_point(int marks);
    // Add getter functions
    string get_subject_name(int i) const { return subject_name[i]; }
    int get_th_marks(int i) const { return th_marks[i]; }
    int get_pr_marks(int i) const { return pr_marks[i]; }
    string get_th_grade(int i) const { return th_grade[i]; }
    string get_pr_grade(int i) const { return pr_grade[i]; }
    int get_th_credit(int i) const { return th_credit[i]; }
    int get_pr_credit(int i) const { return pr_credit[i]; }
    float get_sgpa() const { return sgpa; }
    friend void student::get_result(result &r); // Declare friend function to access private members
};

void student :: get_result(result &r)
{
    cout << "Enter 3 subject names and credits:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> r.subject_name[i]; // Access result object's members

        cout << "Enter theory and practical marks of " << r.subject_name[i] << "\n";
        cout << "Theory: ";
        cin >> r.th_marks[i];
        cout << "Practical: ";
        cin >> r.pr_marks[i];

        cout << "Enter theory and practical credit of " << r.subject_name[i] << "\n";
        cout << "Theory: ";
        cin >> r.th_credit[i];
        cout << "Practical: ";
        cin >> r.pr_credit[i];

        r.th_grade[i] = r.convert_to_grade(r.th_marks[i]);
        r.pr_grade[i] = r.convert_to_grade(r.pr_marks[i]);

        r.th_gp[i] = r.convert_to_grade_point(r.th_marks[i]);
        r.pr_gp[i] = r.convert_to_grade_point(r.pr_marks[i]);
    }
}

void result :: sgpa_cal()
{
    sum = 0;
    total_credit = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += th_gp[i] * th_credit[i] + pr_gp[i] * pr_credit[i];
        total_credit += th_credit[i] + pr_credit[i];
    }
    sgpa = static_cast<float>(sum) / total_credit; // Type cast the sum to float
}

string result :: convert_to_grade(int marks) {
    if (marks >= 80) {
        return "AA";
    } else if (marks >= 73 && marks < 80) {
        return "AB";
    } else if (marks >= 66 && marks < 73) {
        return "BB";
    } else if (marks >= 60 && marks < 66) {
        return "BC";
    } else if (marks >= 55 && marks < 60) {
        return "CC";
    } else if (marks >= 50 && marks < 55) {
        return "CD";
    } else if (marks >= 45 && marks < 50) {
        return "DD";
    } else {
        return "FF";
    }
}

int result :: convert_to_grade_point(int marks) {
    if (marks >= 80) {
        return 10;
    } else if (marks >= 73 && marks < 80) {
        return 9;
    } else if (marks >= 66 && marks < 73) {
        return 8;
    } else if (marks >= 60 && marks < 66) {
        return 7;
    } else if (marks >= 55 && marks < 60) {
        return 6;
    } else if (marks >= 50 && marks < 55) {
        return 5;
    } else if (marks >= 45 && marks < 50) {
        return 4;
    } else {
        return 0;
    }
}

void student :: put_result(result &r)
{
    system("CLS");
    cout << "\nMark Sheet:\n";
    cout << setw(20) << "Subject Name" << setw(20) << "Theory Grade" << setw(20) << "Practical Grade" << endl;
    for (int i = 0; i < 3; i++) {
        cout << setw(20) << r.get_subject_name(i) << setw(20) << r.get_th_grade(i) << setw(20) << r.get_pr_grade(i) << endl;
    }
    cout << "\nSGPA: " << fixed << setprecision(2) << r.get_sgpa() << endl;
}

int main ()
{
    student s;
    result r;
    s.getdata_stu();
    s.get_result(r);
    r.sgpa_cal();
    s.putdata_stu();
    s.put_result(r);
    return 0;
}
