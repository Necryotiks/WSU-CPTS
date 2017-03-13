#pragma once
#include "Header.h"

//use UserErrorCorrection with template
template <class T>//maybe make string generic vector?
class BSTNode
{
public:
	explicit BSTNode(T target, string targetStr="");
	~BSTNode();
	static T getData();//maybe static
	BSTNode *& getLeft();
	BSTNode *& getRight();
	static string getString();
	static bool setData(T &newData);
	static bool setString(string &newString);
private:
	T data;
	string compareStr;
	BSTNode * LPTR;
	BSTNode * RPTR;
};

template<class T>
BSTNode<T>::BSTNode(T target, string targetStr)
{
	data = target;
	compareStr = targetStr;
	LPTR = nullptr;
	RPTR = nullptr;
}

template<class T>
BSTNode<T>::~BSTNode()
{
}

template<class T>
T BSTNode<T>::getData()
{
	return T(data);
}

template<class T>
BSTNode<T> *& BSTNode<T>::getLeft()
{
	return LPTR;
}

template<class T>
BSTNode<T> *& BSTNode<T>::getRight()
{
	return RPTR;
}

template<class T>
string BSTNode<T>::getString()
{
	return string(compareStr);
}

template<class T>
bool BSTNode<T>::setData(T &newData)
{
	data = newData;
	if(data != newData)
	{
		return false;
	}
	return true;
}

template<class T>
bool BSTNode<T>::setString(string & newString)
{
	compareStr = newString;
	if (compareStr != newString)
	{
		return false;
	}
	return true;
}
