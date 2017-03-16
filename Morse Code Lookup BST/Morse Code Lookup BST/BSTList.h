#pragma once

#include "BSTNode.h"
#include "Header.h"
#include <fstream>
#include <array>
#include <algorithm>
#include <cctype>

//fix tempates(done)
//**rootNode vs *& rootNode? just use *&
// * vs *&? see below
//transform is a useful function for converting whole strings.
//std::thread takes alot of steps
//REFERENCE EVERYTHING.
template <class T>
class BSTList
{
public:
	BSTList();
	~BSTList();

	void BSTPrint();
	void BSTSearch(vector<char>&convertVector, int &i);
	static void BSTKeycheck(array<string, 56> &morseArray, vector<char>&convertVector);//checks for characters not in morse table.
	void BSTDeleteTree();

	BSTNode<T> *& getRoot();

	void setRoot(BSTNode<T>* const newRoot);
	void insert(BSTNode<T> *&Node);//make this *&?

	void threadedMorseLoop(array<string, 56> &morseArray, std::ifstream &tableFile);
	void threadedInputLoop(vector<char> &convertVector, std::ifstream &inputFile) const;



	static BSTNode<T> * makeNode();
private:
	BSTNode<T> * rootNode;
	void insert(BSTNode<T> *&rootNode, BSTNode<T> *& Node); //**rootNode vs *& rootNode? and make * into a *&?
	void BSTPrint(BSTNode<T> *&rootNode);//ask about pass by reference rootnode.
	bool BSTSearch(BSTNode<T> *&rootNode, vector<char>&convertVector, int &i);
	void BSTDeleteTree(BSTNode<T> *& rootNode);
};

template<class T>
BSTList<T>::BSTList()
{
	rootNode = nullptr;
	std::ifstream tableFile("MorseTable.txt", std::ios::in);
	std::ifstream inputFile("Convert.txt", std::ios::in);
	array<string, 56> morseArray;//replace with vector during optimization pass.
	vector<char>convertVector;
	auto i = 0;
	morseArray[0] = "This is a placeholder for my own sanity.";

	/*threadedMorseLoop(morseArray, tableFile);
	threadedInputLoop(convertVector, inputFile); left for posterity*/
	std::thread mLoop(&BSTList::threadedMorseLoop, this, ref(morseArray), ref(tableFile));//Needs &BSTList:: if done in constructor much like with structs(i.e. not static). also needs keyword:this if refering to a member function.
	std::thread iLoop(&BSTList::threadedInputLoop, this, ref(convertVector), ref(inputFile));//std::ref needed if passing in references
	mLoop.join();
	iLoop.join();
	BSTKeycheck(morseArray, convertVector);
	while (i < convertVector.size())//stops prints on the 5th time through
	{
		BSTSearch(convertVector, i);
	}

}

template<class T>
BSTList<T>::~BSTList()
{
	BSTDeleteTree();
	cout << "Tree deconstructed" << endl;
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
void BSTList<T>::BSTKeycheck(array<string, 56>& morseArray, vector<char>& convertVector)
{
	static auto i = 0;
	while (i != convertVector.size())
	{
		auto j = 0;

		for (j = 0; j < morseArray.size(); j++)
		{
			if(morseArray[j][0]==convertVector[i])
			{
				i++;
				break;
			}
		}
		if(j==morseArray.size())
		{
			convertVector[i] = '?';
		}
	}

}

template<class T>
void BSTList<T>::BSTDeleteTree()
{
	BSTDeleteTree(this->rootNode);
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
void BSTList<T>::insert(BSTNode<T> *& Node)
{
	insert(this->rootNode, Node);
}

template<class T>
void BSTList<T>::threadedMorseLoop(array<string, 56> &morseArray, std::ifstream &tableFile)
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
			if (temp[j] == ' ')//replaces whitespace
			{
				temp[j] = '_';
			}
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
void BSTList<T>::insert(BSTNode<T>*& rootNode, BSTNode<T> *& Node)//make this *&?
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
bool BSTList<T>::BSTSearch(BSTNode<T>*& rootNode, vector<char>& convertVector, int &i)
{

	if (rootNode != nullptr)
	{
		BSTSearch(rootNode->getLeft(), convertVector, i);
		if (i < convertVector.size())
		{
			if (rootNode->getData() == convertVector[i])
			{
				cout << rootNode->getString() << ' ';
				i++;
				if (i == convertVector.size())
				{
					cout << '\n';
					for (auto j = 0; j < convertVector.size(); j++)
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
}

template<class T>
void BSTList<T>::BSTDeleteTree(BSTNode<T>*& rootNode)
{
	if (rootNode != nullptr)
	{
		BSTDeleteTree(rootNode->getLeft());
		BSTDeleteTree(rootNode->getRight());//delete at bottom instead of mid inorder to travers the whole tree.
		delete rootNode;
	}
}


