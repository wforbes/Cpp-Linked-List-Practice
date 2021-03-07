#pragma once
#ifndef INTNODE_H
#define INTNODE_H

class IntNode {
public:
	IntNode(int dataInit = 0, IntNode* nextLoc = nullptr);
	void InsertAfter(IntNode* nodePtr);
	IntNode* GetNext();
	void SetNext(IntNode* next);
	void PrintNodeData();
	int GetDataVal();
private:
	int dataVal;
	IntNode* nextNodePtr;
};

#endif
