#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

bool identical(double *ptr1,double *ptr2)
    {
        if(*ptr1 == *ptr2)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
bool address(double *ptr1,double *ptr2)
{
    if(ptr1 == ptr2)
        {
            return true;
        }
        else
        {
            return false;
        }
}


int main ()
{
    double data1=3.5;
    double data2=3.0;
    double &var1=data1;
    double &var2=data1;
    cout << identical(&var1,&var2) << endl;
    cout << address(&var1,&var2) << endl;  
    
}