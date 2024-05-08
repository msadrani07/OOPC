#include <iostream>
#include <string>
using namespace std;
//
class product
{
    protected:
    int id;
    string name;
    string manuf;
    float price;
    public:
    product()
    {
    }
    //
    product(int id1,string name1,string manuf1,float price1)
    {
        id=id1;
        name=name1;
        manuf=manuf1;
        price=price1;
    }
    //
    virtual putdata()=0;
};
//
class smartwatch:public product
{
    float dial;
    public:
    smartwatch()
    {
    }
    //
    smartwatch(int id1,string name1,string manuf1,float price1,float dial1):product(id1,name1,manuf1,price1)
    {
        dial=dial1;
    }
    //
    putdata()
    {
        cout<<endl;
        cout<<"Product ID: "<<id<<endl;
        cout<<"Product Name: "<<name<<endl;
        cout<<"Product Manufacturer: "<<manuf<<endl;
        cout<<"Product Price: "<<price<<endl;
        cout<<"Dial Size: "<<dial<<endl;
        cout<<endl;
    }
};
//
class bedsheet:public product
{
    float width;
    float height;
    public:
    bedsheet()
    {
    }
    //
    bedsheet(int id1,string name1,string manuf1,float price1,float h1,float w1):product(id1,name1,manuf1,price1)
    {
        height=h1;
        width=w1;
    }
    //
    putdata()
    {
        cout<<endl;
        cout<<"Product ID: "<<id<<endl;
        cout<<"Product Name: "<<name<<endl;
        cout<<"Product Manufacturer: "<<manuf<<endl;
        cout<<"Product Price: "<<price<<endl;
        cout<<"Height of product: "<<height<<endl;
        cout<<"Width of product: "<<width<<endl;
        cout<<endl;
    }
};
//
int main()
{
    int id;
    string name,manuf;
    float price,dial,width,height;
    int ch;
    cout<<"Enter 1 to input smartwatch details."<<endl;
    cout<<"Enter 2 to input bedsheet details."<<endl;
    cout<<"Enter choice:"<<endl;
    cin>>ch;
    cout<<endl;
    //
    switch(ch)
    {
        case 1:
        cout<<"Enter product id:"<<endl;
        cin>>id;
        cout<<"Enter product name:"<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"Enter product manufacturer:"<<endl;
        cin>>manuf;
        cout<<"Enter product price:"<<endl;
        cin>>price;
        cout<<"Enter size of dial:"<<endl;
        cin>>dial;
        smartwatch *p1;
        p1 = new smartwatch(id,name,manuf,price,dial);
        p1->putdata();
        break;
        //
        case 2:
        cout<<"Enter product id:"<<endl;
        cin>>id;
        cout<<"Enter product name:"<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"Enter product manufacturer:"<<endl;
        cin>>manuf;
        cout<<"Enter product price:"<<endl;
        cin>>price;
        cout<<"Enter height of product:"<<endl;
        cin>>height;
        cout<<"Enter width of product:"<<endl;
        cin>>width;
        bedsheet *p2;
        p2 = new bedsheet(id,name,manuf,price,height,width);
        p2->putdata();
        break;
        //
        default:
        cout<<"Error - Wrong Choice"<<endl;
    }
}