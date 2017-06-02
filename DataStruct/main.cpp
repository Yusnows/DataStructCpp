#include "main.h"

using namespace std;

#define SIZE 100

int main()
{
	SortTest();
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
	int array[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = SIZE - i;
		if (i % 20 == 0)
			cout << endl;
		cout << array[i] << "  ";
	}
	cout << endl;
	Sort<int>::InsertMergeSort(array, SIZE, UP);
//	Sort<int>::MergeSort(array, SIZE, DOWN);
//	Sort<int>::InsertSort(array, SIZE, UP);
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 20 == 0)
			cout << endl;
		cout << array[i] << "  ";
	}

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


