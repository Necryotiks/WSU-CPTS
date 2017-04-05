#pragma once
#include "Master.h"
class Listnode
{
public:
	explicit Listnode(string Record = "NULL",string idNum = "",string name = "",string email = "",string credits = "",string numAbs = "",string program = "",string level = "");
	~Listnode();
	
	std::shared_ptr<Listnode> &getNextPtr(); //list was the reason list wasnt linking and should not have been static.

	void setRecord(string &data);
	string getRecord() const;

	void setID(string &ID);
	string getID() const;

	void setName(string &Ndat);
	string getName() const;

	void setEmail(string &Edat);
	string getEmail() const;
	
	void setCreds(string &creds);
	string getCreds() const;

	void setProgram(string &prog);
	string getProgram() const;

	void setLevel(string &lev);
	string getLevel() const;

	void setNumAbs(string &numabs);//
	string getNumAbs() const;

	void setAbsDate(string &absdate);
	string getAbsDate() const;
	string getAbsDate(int i) const;

private:
	std::shared_ptr<Listnode> nextptr;
	string Record;
	string idNum;
	string name;
	string email;
	string credits;
	string program;
	string level;
	string numAbs;
	vector<string> absences;
};

