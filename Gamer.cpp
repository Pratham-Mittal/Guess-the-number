#include <string>
#include "Gamer.h"
#include "Person.h"
using namespace std;

Gamer::Gamer(const string &name, int regNo):Person(name)
{
	this->name = name;
	this->regNo = regNo;
    this->scores = scores;
}

Gamer::getRegNo() const
{
	int r = this->regNo;
	return r;
}
void Gamer::addScore(float score, string difficulty) 
{
	float s = score;
	string dif = difficulty;
	
	//adding into map
	scores[dif] = s;  //overwrites
}
float Gamer::getHighestScore(string difficulty) const
{
	
	string scr;
	if(scr == " ")
	{
		exception();
	}
}

void NoScoreException::	NoScoreException(int s) 
{
	try{
	this->scores=scores;
	throw 404;
}
catch(int num)
{
	cout<<"err: "<<num;
}
}
