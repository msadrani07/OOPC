#include<iostream>

using namespace std;

class emp
{
    private:
    float exp;
    int year,month;
public:
    operator float()
    {
        return exp;
    }
    void getdata ()
    {
        cout<<"Enter Employee experience in Year and Month"<<endl;

         cout<<"Enter year"<<endl;
         cin>>year;

        cout<<"Enter month"<<endl;
        cin>>month;

        exp = year+(float)(month)/12;
        }
        void display()
        {
            cout<<"Experience is :"<<exp;
        }
};


int main()
{
    emp e1;
    float temp;
    e1.getdata();
    temp=e1;
    e1.display();

    return 0;

}
