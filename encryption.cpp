#include <string>
#include <list>
#include "encryption.h"

using namespace std;


Encryption::Encryption (int key)
{
	this->key = key;
	
}

bool Encryption::isEncrypted(string enc_message)
{
	return true;
}


void Encryption :: encrypt(string message)
{	string res = " ";
	this->key=key;
	key = 5;
	for(int i = 0; i<message.length(); i++)
	{
		//do transformation to characters
		//encrypt uppercase
		
		if(isupper(message[i]))
		{
			res += char(int(message[i] + key -65)%26+65);
		}
		else if(islower(message[i]))
		//encrypt lowercase
		{
			res+= char(int(message[i] + key -97)%26+97);
		}
		
	}
} 

void Encryption:: decrypt(string message)
{
	string res = " ";
	this->key=key;
	key = 5;
	for(int i = 0; i<message.length(); i++)
	{
		//do transformation to characters
		//decrypt uppercase
		
		if(isupper(message[i]))
		{
			res += char(int(message[i] - key -65)%26+65);
		}
		else if(islower(message[i]))
		//decrypt lowercase
		{
			res+= char(int(message[i] - key -97)%26+97);
		}
		
	}
}
