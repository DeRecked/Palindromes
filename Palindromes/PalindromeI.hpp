// palindromei.hpp -- iterative palindrome tester
// c. 2015 A. Deeter

#ifndef PALINDROMEI_HPP
#define PALINDROMEI_HPP

#include <string>

using namespace std;

class PalindromeI 
{

	public:
  	
  	PalindromeI() {}
  	int test_string(const string& str); 
};

// Dynamic Stack class
template <class T>
class PStack
{

	private:

	// Node struct
	struct Node
	{
		T data;							// Data to be held
		Node *next;						// Pointer to next node
	};

	Node *topPtr;						// Pointer to top node
	
	public:

	// Constructor
	PStack();
	
	// Destructor
	~PStack();
	
	// Stack functions
	void push(T);						// Add item to the stack
	T pop();							// Remove item from the stack
	bool isEmpty();						// Check if stack is empty
};

// Static Queue class
template <class T>
class PQueue
{
	private:
	
	T *array;							// Pointer to array
	int arrSize;							// Size of array
	int numItems;						// Number of used elements in array
	int front;							// First used element in array
	int back;							// Last used element in array
	
	public:
	
	// Constructor
	PQueue(int);
	
	// Destructor
	~PQueue();
	
	// Queue functions
	void enqueue(T);					// Add item to the queue
	T dequeue();						// Remove item from the queue
	bool isEmpty();						// Check if queue is empty
};

#endif
