#include <iostream>
#include <time.h>
using namespace std;

#include "IntNode.h"
#include "IntList.h"

int main() {
	cout << " ---- " << endl;
	cout << "Example 1" << endl;
	cout << "Basic linked List w/ pointers" << endl;
	cout << " ---- " << endl;
	IntNode* headObj = nullptr;
	IntNode* nodeObj1 = nullptr;
	IntNode* nodeObj2 = nullptr;
	IntNode* nodeObj3 = nullptr;
	IntNode* currObj = nullptr;

	headObj = new IntNode(-1);

	nodeObj1 = new IntNode(555);
	headObj->InsertAfter(nodeObj1);

	nodeObj2 = new IntNode(999);
	nodeObj1->InsertAfter(nodeObj2);

	nodeObj3 = new IntNode(777);
	nodeObj1->InsertAfter(nodeObj3);

	currObj = headObj;
	while (currObj != nullptr) {
		currObj->PrintNodeData();
		currObj = currObj->GetNext();
	}
	
	cout << " ---- " << endl;
	cout << "Example 2" << endl;
	cout << "Linked List w/ random numbers using head and tail pointers" << endl;
	cout << " ---- " << endl;
	headObj = nullptr;
	currObj = nullptr;
	IntNode* lastObj = nullptr;

	headObj = new IntNode(-1);
	lastObj = headObj;

	//Append 20 random nums
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		currObj = new IntNode(rand());

		lastObj->InsertAfter(currObj);
		lastObj = currObj;
	}

	currObj = headObj;

	while (currObj != nullptr) {
		currObj->PrintNodeData();
		currObj = currObj->GetNext();
	}

	cout << " ---- " << endl;
	cout << "Example 3" << endl;
	cout << "Finding the minimum value in that list" << endl;
	cout << " ---- " << endl;
	
	currObj = headObj->GetNext();
	int minVal = currObj->GetDataVal();
	while (currObj != nullptr) {
		if (currObj->GetDataVal() < minVal) {
			minVal = currObj->GetDataVal();
		}
		currObj = currObj->GetNext();
	}
	cout << "Minimum Value: " << minVal << endl;

	cout << " ---- " << endl;
	cout << "Example 4" << endl;
	cout << "Use IntList class to manage a list of nodes" << endl;
	cout << " ---- " << endl;
	
	cout << "(Add sequential values from 3 to 12 to the list)" << endl;
	IntList* list = new IntList(new IntNode(-1));
	list->AddSequentialValues(3, 12);
	list->PrintList();

	cout << " ---- " << endl;
	cout << "(find node '4' and insert '142' after it)" << endl;
	IntNode* insNode = list->GetNodeByVal(4);
	list->InsertAfter(insNode, new IntNode(142));
	list->PrintList();

	cout << " ---- " << endl;
	cout << "(find node '7' and delete it from the list)" << endl;
	IntNode* delNode = list->GetNodeByVal(7);
	list->DeleteNode(delNode);
	list->PrintList();

	cout << " ---- " << endl;
	cout << "(add '69' to the front of the list)" << endl;
	list->PushFront(new IntNode(69));
	list->PrintList();

	cout << " ---- " << endl;
	cout << "(add '42' to the end of the list)" << endl;
	list->PushBack(new IntNode(42));
	list->PrintList();

	cout << " ---- " << endl;
	cout << "(Get the list's size)" << endl;
	cout << "List Size: " << list->GetSize() << endl;

	cout << " ---- " << endl;
	cout << "(clear the list)" << endl;
	list->ClearList();
	list->PrintList();

	cout << " ---- " << endl;
	cout << "(Get the list's size)" << endl;
	cout << "List Size: " << list->GetSize() << endl;

	cout << " ---- " << endl;
	cout << "(Populate the list with 20 random values)" << endl;
	list->AddRandomValues(20);
	list->PrintList();

	cout << " ---- " << endl;
	cout << "(Get the list's minimum value)" << endl;
	cout << "List Size: " << list->GetMinValue() << endl;

	cout << " ---- " << endl;
	cout << "(Get the list's maximum value)" << endl;
	cout << "List Size: " << list->GetMaxValue() << endl;

	cout << " ---- " << endl;
	cout << "(Get the median in the list)" << endl;
	cout << "Median: " << list->GetMedianValue() << endl;

	return 0;
}