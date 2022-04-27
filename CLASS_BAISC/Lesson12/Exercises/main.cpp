#include <iostream>
#include "Queue.h"
#include "Stack.h"

int main()
{
	LinkedList* stack = new Stack;

	stack->Info();


	LinkedList* queue = new Queue;
	queue->Info();

	delete queue;
	delete stack;
}
