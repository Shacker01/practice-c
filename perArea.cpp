#include <iostream>
using namespace std;
int main()
{
double length;
double width;
double area;
double perimeter;

cout << "Program to compute and output the perimeter and "
<< "area of a rectangle." << endl;
cout<<"Input Length: ";
cin>>length;
cout<<"Input Width: ";
cin>>width;
cout<<"***************************\n";
perimeter = 2 * (length + width);
area = length * width;
cout<<"Length = " << length << endl;
cout<<"Width = " << width << endl;
cout<<"***************************\n";

cout<<"Perimeter = " << perimeter <<" cm2"<< endl;
cout<<"Area      = " <<area<<" cm2"<< endl;
cout<<"***************************\n";

    return 0;
}