#include<queue>
#include<string>
#include<iostream>
using namespace std;

void FillQueue(priority_queue<string>& pq)
{
	pq.push("Odera");	
	pq.push("Colton");	
	pq.push("Troy");	
	pq.push("TJ");	
	pq.push("Matthew");	
	pq.push("Lauren");	
	pq.push("Red");	
	pq.push("Ehlam");	
	pq.push("Isaiah");	
	pq.push("Nina");	

}
void PrintQueue(priority_queue<string>& pq)
{
	priority_queue<string> localpq = pq;

	for(int i = 0; i < pq.size(); i+=0)
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}
int main()
{
	priority_queue<string> pq;

	FillQueue(pq);

	PrintQueue(pq);

	return 0;
}