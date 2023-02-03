#include <iostream>

#include<string>
#include"MyQueuePriority.h"

using namespace std;


int main()
{
	MyQueuePriority<string>print(20);
	print.push("Klient 1", 5);
	print.push("Klient 2", 2);
	print.push("Klient 3", 4);
	print.push("Klient 4", 3);

	int pr = 0;

	while (!print.isEmpty()) {
		cout << print.top(pr) << "-" << pr << endl;
		print.pop();
	}
}

