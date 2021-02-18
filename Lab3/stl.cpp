#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void Initialize(vector<int> &vect)
    {
        for(int i = 0; i < 5; i++)
	{
		int num;
        cin >> num;
		vect.push_back(num);
	}	
    cout << endl;
    }

    void Print(vector<int> &vect)
    {
        for(int i = 0; i < 5; i++)
	{
		cout << vect[i] << '\t' ;
	}	
    cout << endl;
    }

    void Reverse(vector<int> &vect)
    {
        for(int i = 0; i<5; i++)
	{
		reverse(vect.begin(), vect.end());
	}	
    cout << endl;
    }

int main ()
{
      stack<string> s1, s2;
      s1.push("Hi there");
      s2.push("Go away");
    if(s1==s2)
    {
        cout << "They are equal!" << endl;
    };
    if(s1<s2)
    {
        cout << "s1 is less than s2!" << endl;
    };
    if(s2<s1)
    {
        cout << "s2 is less than s1!" << endl;
    };

    vector<int> v; 
    Initialize(v);
    Print(v);
    Reverse(v);
    Print(v);
    sort(v.begin(), v.end());
    cout << endl;
    Print(v);

}