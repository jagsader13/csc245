#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

struct RecType
{
    int age;
    float weight;
    char gender;
};


int main ()
{
    int num=5;
    int *intPtr=new int;
    intPtr=NULL;
    intPtr=&num;
    cout << "intPtr points to: " << '\t' << '\t' << '\t' <<*intPtr*10 << endl;
    
    RecType *recPtr=new RecType;
    recPtr -> age=25;
    recPtr -> weight=190;
    recPtr -> gender='M';
    cout << "Three Fields Pointed to By recPtr: " << '\t' << recPtr -> age + 5 << " " << recPtr -> weight << " " << recPtr -> gender << endl; 
    delete recPtr;
    recPtr=NULL;

    char *strPtr= new char[50];
    strcpy(strPtr, "Operating Systems");
    cout << "strPtr points to : " << '\t' << '\t' << '\t' <<strPtr << endl;
    int count=0;
    for(int i=0;i<strlen(strPtr);i++)
    {
        if(islower(*(strPtr + i)))
        {
           count++;
        }
    };
    cout << "LowerCase Letters Pointed To By strPtr: " << count << endl;
    strPtr+=10;
    cout << "Printing strPtr after adding 10 : " << '\t' << strPtr << endl;
    strPtr-=10;
    delete strPtr;
    
}



