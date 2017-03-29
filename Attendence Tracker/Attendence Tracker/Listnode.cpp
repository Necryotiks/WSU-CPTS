#include "Listnode.h"



Listnode::Listnode()
{
	nextptr = nullptr;
	Record = 0;
	idNum = 0;
	name = "";
	email = "";
	credits = 0;
	program = "";
	level = "";
}


Listnode::~Listnode()
{
}

std::unique_ptr<Listnode> Listnode::getNextPtr()
{
	return std::unique_ptr<Listnode>();
}

void Listnode::setRecord(int &data)
{
	Record = data;
	assert(Record == data);
}

int Listnode::getRecord() const
{
	return Record;
}

void Listnode::setID(int & ID)
{
	idNum = ID;
	assert(idNum == ID);
}

int Listnode::getID() const
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

void Listnode::setCreds(int & creds)
{
	credits = creds;
	assert(credits == creds);
}

int Listnode::getCreds() const
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
