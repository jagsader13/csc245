#include <iostream>
using namespace std;

double convert(double value);

int main ()
{
    double cel;
    cout<< "Please enter a Celsius value: ";
    cin>>cel;
    cout<< cel << " degrees Celsius is " << convert(cel) << " degrees Fahrenheit.";
    
}

double convert(double tmp)
{
    tmp=(1.8*tmp) + 32.0;
    return tmp;

}
