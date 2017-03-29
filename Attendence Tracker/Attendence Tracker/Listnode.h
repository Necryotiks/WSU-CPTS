#pragma once
#include "Master.h"
class Listnode
{
public:
	Listnode();
	~Listnode();
	
	static std::unique_ptr<Listnode> getNextPtr();

	void setRecord(int &data);
	int getRecord() const;

	void setID(int &ID);
	int getID() const;

	void setName(string &Ndat);
	string getName() const;

	void setEmail(string &Edat);
	string getEmail() const;
	
	void setCreds(int &creds);
	int getCreds() const;

	void setProgram(string &prog);
	string getProgram() const;

	void setLevel(string &lev);
	string getLevel() const;
private:
	std::unique_ptr<Listnode> nextptr;
	int Record;
	int idNum;
	string name;
	string email;
	int credits;
	string program;
	string level;
};

