
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;


int getMax(const vector<int>& v);
int maxElemLength(const vector<int>& v);
int GetNumDigits(int num);
int GetDigit(int num, int k);
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k);
vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals);
void RadixSort(vector<int>& L, int numDigits);
void PrintVector(const vector<int>& L);

int main()
{
	vector<int> L; // the list to be sorted
	vector<queue<int> > QA(10); //vector of queues indexed 0-9
	int i = 0;
	
	//inserting the values into the vector
	L.push_back(380);
	L.push_back(95);
	L.push_back(345);
	L.push_back(382);
	L.push_back(260);
	L.push_back(100);
	L.push_back(492);
	
	cout << "List before Pass: " << endl;
	PrintVector(L);
	RadixSort(L, maxElemLength(L));

	cout << "List after Pass III and Step 2: " << endl;
	PrintVector(L);	
	return 0;
}

int getMax(const vector<int>& v)
{
	int max = v[0];
	for(int i=0;i<v.size();i++)
	{
		if (v[i] > max) { max = v[i]; }
	}
	return max;
}

int maxElemLength(const vector<int>& v)
{

	int max = 0;
	int digits = 0;
	while(max!=0)
	{
		max /= 10;
		digits++;
	}
	return digits;
}

int GetNumDigits(int num)
{
	int numDigits = 0;
	while(num != 0)
	{
		num /= 10;
		numDigits++;
	}
	return numDigits;
}
int GetDigit(int num, int k)
{
	int numDigits = 0;
	int i = 0;
	int digValue[245];
	numDigits = GetNumDigits(num);
	if (k == 0) {
		while (num != 0) {
			num %= 10;
			return num;
		}
	}
	else if ((k < numDigits) && (k != 0)) {
		while (num) {
			digValue[i] = num % 10;
			i++;
			num/= 10;
		}
		return digValue[k];
	}
	if (k >= numDigits)
		return 0;

		return 0;

}
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k)
{
	vector<queue<int> > QA(10);
	int currDigit = 0;
	
	for(int i = 0; i < L.size(); i++){
		currDigit = GetDigit(L[i], k);
		QA[currDigit].push(L[i]);
	}
	return QA;

}

vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals)
{
	vector<int> L;

	for(int i = 0; i < QA.size(); i++){
		numVals++;
	}
	
	for(int j = 0; j < numVals; j++){
		while(!QA[j].empty()){
			L.push_back(QA[j].front());
			QA[j].pop();
		}
	}	
	return L;	
}

void RadixSort(vector<int>& L, int numDigits)
{
	vector<queue<int> > QA(10);
	for(int k = 0; k < numDigits; k++){
		QA = ItemsToQueues(L,k);
		L = QueuesToArray(QA, L.size());
	}
}

void PrintVector(const vector<int>& L)
{
	for (int i = 0; i < L.size(); i++){ cout << L.at(i) << endl; }
		
}
