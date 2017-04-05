#include "Listnode.h"



Listnode::Listnode(string Record , string idNum , string name , string email , string credits , string numAbs , string program, string level)
{
	nextptr = nullptr;
}


Listnode::~Listnode()
{
}

std::shared_ptr<Listnode> &Listnode::getNextPtr()
{
	return nextptr;
}

void Listnode::setRecord(string &data)
{
	Record = data;
	assert(Record == data);
}

string Listnode::getRecord() const
{
	return Record;
}

void Listnode::setID(string & ID)
{
	idNum = ID;
	assert(idNum == ID);
}

string Listnode::getID() const
{
	return idNum;
}

void Listnode::setName(string & Ndat)
{
	name = Ndat;
	assert(name == Ndat);
}

string Listnode::getName() const
{
	return name;
}

void Listnode::setEmail(string & Edat)
{
	email = Edat;
	assert(email == Edat);
}

string Listnode::getEmail() const
{
	return email;
}

void Listnode::setCreds(string & creds)
{
	credits = creds;
	assert(credits == creds);
}

string Listnode::getCreds() const
{
	return credits;
}

void Listnode::setProgram(string & prog)
{
	program = prog;
	assert(program == prog);
}

string Listnode::getProgram() const
{
	return program;
}

void Listnode::setLevel(string & lev)
{
	level = lev;
	assert(level == lev);
}

string Listnode::getLevel() const
{
	return level;
}

void Listnode::setNumAbs(string & numabs)
{
	if (numAbs == "0" || numAbs == "")
	{
		numAbs = numabs;
	}
	else
	{
		auto z = stoi(numabs);
		z++;
		numAbs = std::to_string(z);
	}
}

string Listnode::getNumAbs() const
{
	return numAbs;
}

void Listnode::setAbsDate(string & absdate)
{
	absences.push_back(absdate);
}

string Listnode::getAbsDate() const //nned marker for new node.
{
	static auto j = 0;
	string temp;
	if(j < absences.size())
	{
		temp = absences[j];
		j++;
	}
	return temp;

}

string Listnode::getAbsDate(int i) const //ask josh
{
	auto j = i;
	string temp;
	if (j < absences.size())
	{
		temp = absences[j];
	}
	return temp;
}
