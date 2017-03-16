#pragma once

#include "BSTNode.h"
#include "Header.h"
#include <fstream>
#include <array>
#include <algorithm>
#include <cctype>

//fix tempates
//**rootNode vs *& rootNode?
// * vs *&?
//transform is a useful function
template <class T>
class BSTList
{
public:
	BSTList();
	~BSTList();

	void BSTPrint();
	void BSTSearch(vector<char>&convertVector, int &i);

	BSTNode<T> *& getRoot();

	void setRoot(BSTNode<T>* const newRoot);
	void insert(BSTNode<T> *Node);//make this *&?

	void threadedMorseLoop(array<string, 40> &morseArray, std::ifstream &tableFile);
	void threadedInputLoop(vector<char> &convertVector, std::ifstream &inputFile) const;
	static BSTNode<T> * makeNode();
private:
	BSTNode<T> * rootNode;
	void insert(BSTNode<T> *&rootNode, BSTNode<T> * Node); //**rootNode vs *& rootNode? and make * into a *&?
	void BSTPrint(BSTNode<T> *&rootNode);//ask about pass by reference rootnode.
	bool BSTSearch(BSTNode<T> *&rootNode, vector<char>&convertVector, int &i);
};

template<class T>
BSTList<T>::BSTList()
{
	rootNode = nullptr;
	std::ifstream tableFile("MorseTable.txt", std::ios::in);
	std::ifstream inputFile("Convert.txt", std::ios::in);
	array<string, 40> morseArray;//
	vector<char>convertVector;
	static auto i = 0;
	morseArray[0] = "This is a placeholder for my own sanity.";

	threadedMorseLoop(morseArray, tableFile);
	threadedInputLoop(convertVector, inputFile);
	//std::thread mLoop(&BSTList::threadedMorseLoop, std::ref(morseArray), tableFile);//Needs &BSTList:: if done in constructor much like with structs
	//std::thread iLoop(&BSTList::threadedInputLoop, std::ref(convertVector), inputFile);//why do you NEED A POINTER DURING LIST DECLARATION(i.e BSTList<char> *OBJ;)
	//mLoop.join();
	//iLoop.join();
	while (i < convertVector.size())
	{
		BSTSearch(convertVector, i);
	}

}

template<class T>
BSTList<T>::~BSTList()
{
	//need to deconstruct tree
}

template<class T>
void BSTList<T>::BSTPrint()
{
	BSTPrint(this->rootNode);
}


template<class T>
void BSTList<T>::BSTSearch(vector<char>& convertVector, int &i)
{
	BSTSearch(this->rootNode, convertVector, i);
}

template<class T>
BSTNode<T>*& BSTList<T>::getRoot()
{
	return rootNode;
}

template<class T>
void BSTList<T>::setRoot(BSTNode<T>* const newRoot)
{
	rootNode = newRoot;
}

template<class T>
void BSTList<T>::insert(BSTNode<T> * Node)
{
	insert(this->rootNode, Node);
}

template<class T>
void BSTList<T>::threadedMorseLoop(array<string, 40> &morseArray, std::ifstream &tableFile)
{
	auto i = 0;
	while (!tableFile.eof())//maybe thread
	{
		i++;
		BSTNode<T>* Node = new BSTNode<T>;
		getline(tableFile, morseArray[i]);//reads whole line.
		morseArray[i].erase(remove_if(morseArray[i].begin(), morseArray[i].end(), isspace), morseArray[i].end());//removes whitespace and then shrinks string length(sourced from Stack Overflow).Remove_if removes predicate value and shuffles data around and returns a pointer to where the end should be.
		Node->setData(morseArray[i][0]);//Reads first character in each string.
		Node->setString(morseArray[i].substr(1, string::npos));//reads morse characters excluding alpha characters.
		insert(Node);
	}
}

template<class T>
void BSTList<T>::threadedInputLoop(vector<char> &convertVector, std::ifstream &inputFile) const
{
	while (!inputFile.eof())//reads input string
	{
		string temp;
		getline(inputFile, temp);
		for (auto j = 0; j < temp.length(); j++)
		{
			convertVector.push_back(toupper(temp[j]));
		}
	}
}

template<class T>
BSTNode<T>* BSTList<T>::makeNode()
{
	return new BSTNode<T>;
}

template<class T>
void BSTList<T>::insert(BSTNode<T>*& rootNode, BSTNode<T> * Node)//make this *&?
{
	if (rootNode == nullptr)
	{
		rootNode = Node;
	}
	else if (Node->getData() < rootNode->getData())
	{
		insert(rootNode->getLeft(), Node);
	}
	else if (Node->getData() > rootNode->getData())
	{
		insert(rootNode->getRight(), Node);
	}
	else
	{
		cout << "duplicate" << endl;
	}
}

template<class T>
void BSTList<T>::BSTPrint(BSTNode<T>* &rootNode)
{
	if (rootNode != nullptr)
	{
		BSTPrint(rootNode->getLeft());
		cout << rootNode->getString() << endl;
		BSTPrint(rootNode->getRight());

	}
}

template<class T>
bool BSTList<T>::BSTSearch(BSTNode<T>*& rootNode, vector<char>& convertVector, int &i)//this needs fixing
{

	if (rootNode != nullptr)
	{
		BSTSearch(rootNode->getLeft(), convertVector, i);//only goes through tree once
		if (rootNode->getData() == convertVector[i])
		{
			cout << rootNode->getString() << ' ';
			i++;
			if (i == convertVector.size())
			{
				cout << '\n';
				for (auto j = 0; j < convertVector.size();j++)
				{
					cout << convertVector[j] << ' ';
				}
				cout << '\n';
				return true;
			}
		}
		BSTSearch(rootNode->getRight(), convertVector, i);
	}
}


