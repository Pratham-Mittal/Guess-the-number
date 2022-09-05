#include <string>
#include <vector>
#include <stdexcept>
#include "Person.h"
#include "Manager.h"

using namespace std;

Manager::Manager(const string &name, int regNo):Person(name)
{
	this->name = name;
	this->regNo = regNo;
}
	
Manager::getRegNo() const
{
	return regNo;
}


