
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int maxElemLength(const vector<string>& v);
int GetLetter(string letter, int k);
void padWord(vector<string> v, int o);
void unpadWord(vector<string> v, int o);
vector<queue<string> > ItemsToQueues(const vector<string>& L, int k);
vector<string> QueuesToArray(vector<queue<string> >& QA, int numVals);
void RadixSort(vector<string>& L, int numDigits);
void PrintVector(const vector<string>& L);


int main() {

	vector<string> L;
	vector<queue<string> > QA(128); 
	string a[] = { "zebra", "apple", "orange", "can", "candy", "a",
			"top", "pumpkin", "today", "parade" };
	int size = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < size; i++){ L.push_back(a[i]); }
	cout << "List before Pass: " << endl;
	PrintVector(L);

	int R = maxElemLength(L);
	padWord(L, R);
	RadixSort(L, R);

	cout << "List after Pass III and Step 2: " << endl;
	PrintVector(L);
	return 0;
}


int maxElemLength(const vector<string>& v)
{
	int max = v[0].length();
	for (int i = 1; i < v.size(); i++) 
	{
		if (v[i].length() > max){max = v[i].length();}
	}
	return max;
}

int GetLetter(string letter, int k)
{
	return letter[letter.length() - 1 - k];
}


void padWord(vector<string> v, int k)
{
	for (int i = 0; i < v.size(); i++) 
	{
		if (v[i].length() < maxElemLength(v)) 
		{
			for (int j = v[i].length(); j < maxElemLength(v); j++) { v[i] = v[i] + "x"; }
		}
	}
}


void unpadWord(vector<string> v, int k)
{
	for (int i = 0; i < v.size(); i++) 
	{
		while (v[i].at(v[i].length() - 1) == ' ') { v[i] = v[i].substr(0, v[i].length() - 1); }
	}
}
			


vector<queue<string> > ItemsToQueues(const vector<string>& L, int k)
{
	vector<queue<string> > QA(256);
	for (int i = 0; i < L.size(); i++) 
	{
		QA[GetLetter(L[i], k)].push(L[i]);
	}
	return QA;

}


vector<string> QueuesToArray(vector<queue<string> >& QA, int numVals)
{
	vector<string> L(numVals);
	int e = 0;

	for (int j = 0; j < 256; j++) 
	{
		while (!QA[j].empty()) 
		{
			L[e] = QA[j].front();
			QA[j].pop();
			e++;
		}
	}
	return L;
}


void RadixSort(vector<string>& L, int numDigits)
{
	vector<queue<string> > QA(256);
	for (int k = 0; k < numDigits; k++) 
	 {
		QA = ItemsToQueues(L, k);
		L = QueuesToArray(QA, L.size());
	}
}

void PrintVector(const vector<string>& L)
{
	for (int i = 0; i < L.size(); i++){ cout << L.at(i) << endl; }
		
}
