#include "main.h"
#include<vector>
using namespace std;

#define SIZE 10000000

int main()
{
	SortTest();
	vector<int> a;
	a.push_back(1);
	return 0;
}

void StackTest()
{
	ArrayStack<string>AStack;
	AStack.push("hello");
	AStack.push("to");
	AStack.push("you");
	AStack.push("!");
	cout << "stack's size is: " << AStack.whatSize() << endl;
	cout << "stack's top element is: " << AStack.Top() << endl;
	string e;
	while (!AStack.isEmpty())
	{
		AStack.pop(e);
	}
	cout << "stack's size is: " << AStack.whatSize() << endl;
	if (!AStack.isEmpty())
		cout << "stack's top element is: " << AStack.Top() << endl;
}

void SortTest()
{
	int *array = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = SIZE - i;
	/*	if (i % 20 == 0)
			cout << endl;
		cout << array[i] << "  ";*/
	}
	cout << endl;
	Sort<int>::InsertMergeSort(array, SIZE, UP);
	Sort<int>::MergeSort(array, SIZE, DOWN);
	Sort<int>::BublleSort(array, SIZE, DOWN);
/*	for (int i = 0; i < SIZE; i++)
	{
		if (i % 20 == 0)
			cout << endl;
		cout << array[i] << "  ";
	}*/

	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		array[i] =  i;
		if (i % 20 == 0)
			cout << endl;
		cout << array[i] << "  ";
	}
	cout << endl;
	Sort<int>::MergeSort(array, SIZE, DOWN);
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 20 == 0)
			cout << endl;
		cout << array[i] << "  ";
	}
}


