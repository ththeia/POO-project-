#include <iostream>
using namespace std;

class CppProject {
	const int projectId;
	string* members;
	int noMembers;
	int noLinesOfCode;
	enum type { TEAM, INDIVIDUAL };
	type x;
	bool isComplex=false;
	const static int LINES_OF_CODE_PER_HOUR=30;

public:

	CppProject(int projectId, string* members):projectId(projectId)
	{
		this->noMembers = 1;
		this->members = new string[noMembers];
		this->members[0] = members[0];
		this->x = INDIVIDUAL;
	}
	~CppProject() {
		if (this->members != nullptr)
			delete[]members;
	}
	void setNoLinesOfCode(int noLinesOfCode)
	{
		this->noLinesOfCode = noLinesOfCode;
	}
	int getNoLinesOfCode()
	{
		return this->noLinesOfCode;
	}
	string getType()
	{
		if (this->x == 0)
		{
			return "Team";
		}
		else 
		{ 
			return "Individual"; 
		}
	}
	CppProject(int projectId, string* members, int noMembers) :projectId(projectId)
	{
		this->noMembers = noMembers;
		this->members = new string[noMembers];
		for (int i = 0; i < noMembers; i++)
		{
			this->members[i] = members[i];
		}
		this->x = TEAM;
		this->isComplex = true;
	}
	bool isEasy()
	{
		if (this->isComplex)
		{
			return false;
		}
		return true;
	}
	int getId()
	{
		return this->projectId;
	}
	void markAsEasy()
	{
		this->isComplex = false;
	}
	void writeCode(int noLinesOfCode)
	{
		this->noLinesOfCode = this->noLinesOfCode+noLinesOfCode;
	}
	CppProject(CppProject& p):projectId(p.projectId)
	{
		this->noMembers = p.noMembers;
		this->members = new string[p.noMembers];
		for (int i = 0; i < noMembers; i++)
		{
			this->members[i] = p.members[i];
		}
		this->x = p.x;
		this->isComplex = p.isComplex;
		cout << "Const copy";
	}
};


int main()
{
	string members[] = { "John" };
	CppProject prj1(1, members);
	prj1.setNoLinesOfCode(1000);
	cout << prj1.getNoLinesOfCode() << endl;  // prints 1000
	cout << prj1.getType() << endl;           // prints “Individual” or “Team” based on project type
	string members2[] = { "John", "Alice", "Bob" };
	int noPersons = 3;
	CppProject prj2(2, members2, noPersons);
	cout << prj2.getType() << endl;                             // prints Team
	if (!prj2.isEasy())
	{
		cout << endl << "Is complex" << endl;       //prints this message
	}      
	cout << endl << prj2.getId() << endl;        //prints 2
	prj2.markAsEasy();
	prj1.writeCode(1500);                              //adds the lines of code to the existing ones
	cout << prj1.getNoLinesOfCode() << endl;          // prints 2500
	CppProject prj3 = prj2;
	//prj1 = prj2;
	//prj1 = prj1;
	//cout << prj2;
}