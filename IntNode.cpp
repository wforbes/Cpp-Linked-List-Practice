#include <iostream>
using namespace std;

#include "IntNode.h"

IntNode::IntNode(int dataInit, IntNode* nextLoc) {
	this->dataVal = dataInit;
	this->nextNodePtr = nextLoc;

	return;
}

void IntNode::InsertAfter(IntNode* nodeLoc) {
	IntNode* tmpNext = nullptr;

	tmpNext = this->nextNodePtr;
	this->nextNodePtr = nodeLoc;
	nodeLoc->nextNodePtr = tmpNext;

	return;
}

void IntNode::PrintNodeData() {
	cout << this->dataVal << endl;

	return;
}

IntNode* IntNode::GetNext() {
	return this->nextNodePtr;
}

void IntNode::SetNext(IntNode* next) {
	this->nextNodePtr = next;
}

int IntNode::GetDataVal() {
	return this->dataVal;
}