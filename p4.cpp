#include<iostream>
using namespace std;
float area(float r)
{
    return 3.14*r*r;
}
float area(float h,float w)
{
    return h*w;
}
float area(float h,float w,float d)
{
    return h*w*d;
}

int main()
{
    float r,h,w,d;
    float area_circle,area_rectangle,area_cuboid;
    cout<<"Enter radius of circle."<<endl;
    cin>>r;
    area_circle =area(r);
    cout<<"The area of circle is :"<<area_circle<<endl;
    cout<<"Enter the height of rectangle : "<<endl;
    cin>>h;
    cout<<"Enter the width of rectangle : "<<endl;
    cin>>w;
    area_rectangle = area(h,w);
    cout<<"The area of rectangle is :"<<area_rectangle<<endl;
    cout<<"Enter the height of cuboid : "<<endl;
    cin>>h;
    cout<<"Enter the width of rectangle : "<<endl;
    cin>>w;
    cout<<"Enter the depth of rectangle : "<<endl;
    cin>>d;
    area_cuboid = area(h,w,d);
    cout<<"The area of cuboid is :"<<area_cuboid<<endl;
    }
