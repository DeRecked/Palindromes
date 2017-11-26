#include "PalindromeI.hpp"

/*** Function implementations for PalindromeI class ***/
int PalindromeI::test_string(const string& s)
{
	int matches = 0;
	
	PStack<char> stk;								// Declare stack object
	PQueue<char> que (s.length());					// Declare queue object with string length
	
	for (int i = 0; i < s.length(); i++)            // Iterate string from 0 -> length-1
        if ( (s[i] >= '0' && s[i] <= '9') ||        // If alphanumeric char
             (s[i] >= 'A' && s[i] <= 'Z') ||
             (s[i] >= 'a' && s[i] <= 'z') )
        {  
            stk.push(tolower(s[i]));                // Push and enqueue
            que.enqueue(tolower(s[i]));
	    }
	
	while (!stk.isEmpty() && !que.isEmpty())        // While stack and queue are not empty
		if (stk.pop() == que.dequeue())             //  If popped value = dequeued value
			matches++;                              //      Increment matches
		else return matches;                        //  Else return matches

	return -1;                                      // Otherwise, return -1
}

/*** Function implementations for Stack class ***/
template <class T>
PStack<T>::PStack() { topPtr = nullptr; }

template <class T>
PStack<T>::~PStack()
{
	Node *topNode = nullptr;						// Ptr for top node
	Node *nextNode = nullptr;						// Ptr for next node
	
	topNode = topPtr;								// Point to top node
	
	while (topNode != nullptr)						// While stack has nodes remaining
	{
		nextNode = topNode->next;					// Point to next node in stack
		delete topNode;								// Delete top node
		topNode = nextNode;							// Move to new top node in stack
	}
}

template <class T>
void PStack<T>::push(T value)
{
	Node *newNode = nullptr;						// Null pointer for new node
	
	newNode = new Node;								// Allocate memory for new node
	newNode->data = value;							// Node data gets value parameter
	
	if (isEmpty())									// Check if Stack is empty
	{
		topPtr = newNode;							// New node is now the top
		newNode->next = nullptr;					// Next ptr points to null
	}		
	else
	{
		newNode->next = topPtr;						// New node next now points to top
		topPtr = newNode;							// Top now points to new node
	}
}

template <class T>
T PStack<T>::pop()
{
	Node *temp = nullptr;							// Temp ptr
	T item;											// Item to pop off stack
	
	if (isEmpty())									// Check if stack is empty
		throw "The Stack is empty.\n";				// Throw error
	else
	{
		item = topPtr->data;						// Item gets data of top node
		temp = topPtr->next;						// Temp points to next node
		
		delete topPtr;								// Delete top node
		topPtr = temp;								// Top points to temp
		
		return item;
	}
}

template <class T>
bool PStack<T>::isEmpty()
{
	return ( topPtr == nullptr );					// If topPtr points to null, return true
}

/*** Function implementations for Queue class ***/
template <class T>
PQueue<T>::PQueue(int size)
{
	array = new T[size];							// Allocate size amount of memory for array
	arrSize = size;									// Array size = size allocated
	numItems = 0;									// Number of items starts at 0
	front = 0;										// Front and back start at 0
	back = 0;
}	

template <class T>
PQueue<T>::~PQueue()
{
	if (numItems > 0)								// If array is used
		delete [] array;							// Delete array
}

template <class T>
void PQueue<T>::enqueue(T value)
{
	if (numItems < arrSize)							// If array is not full
	{
		array[back] = value;        				// Store value in first unused element
		back = (back + 1) % arrSize;				// Increment back and mod with array size
		numItems++;									// Increment number of items in array
	}
	else throw "The queue is full.\n";				// Throw error
}

template <class T>
T PQueue<T>::dequeue()
{
	T item;

	if (isEmpty())									// If queue is empty
		throw "The queue is empty.\n";				// Throw error
	else
	{
		item = array[front];						// Item gets first used element in array
		front = (front + 1) % arrSize;				// Increment front and mod with array size
		numItems--;									// Decrement numbers of items in array
		
		return item;
	}	
}

template <class T>
bool PQueue<T>::isEmpty()
{
	return ( numItems == 0 );						// If number of items = zero, return true
}	
