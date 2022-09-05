#include <cstdlib>
#include <time.h>
#include <iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include <bits/stdc++.h>
#include "Person.h"
#include "Gamer.h"
#include "Manager.h"
#include "encryption.h"

using namespace std;
 
void menu();  //menu
void login();  //login function

void Gamer_menu();  //gamer menu
void Manager_menu();  //manager menu
void Game();  //game
void Stats(); //statistics
void leaderboard();  //learderboard (a bit buggy)
void exit(); //exit
void ResetGame();  //reset game values
void Changelevel();  //changes min max val
void changekey();  //changes key
void add_Manager(); //adds manager
void easy();  //easy game
void medium(); //med game
void hard();// hard game
void file_encrypt();
void file_decrypt();


vector<string> g1;
vector<string> g3;
vector<string> g2;
vector<int> gregnum;
vector<int> mregnum;
vector<string> fname_g;
vector<string> sname_g;
vector<string> fname_m;
vector<string> sname_m;
vector<float> scr_easy;
vector<float> scr_med;
vector<float> scr_hard;

int choice,ease=10,med=100,hards=1000, range=0;
float counter=1;
int fregnum , regnum;
float score_easy=0.0, score_med=0.0, score_hard=0.0;
string fname, sname;
string ans, firstname, secondname;
	
 int main() {
 	int choice;
    cout << "-------------------------------------------------------------" << endl;
    cout << "                       WELCOME TO                            " << endl;
   	cout << "                    THE GUESSING GAME                                  " << endl;
   	cout << "-------------------------------------------------------------" << endl;
   	cout << "LOGIN" << endl;
 	//file_encrypt();
 	login();
  }
  
void login()   //login function
{

	//ClearScreen();
	bool validlogin;
	int c;
	cout<<"What role you have?"<<endl;			
	cout<<"1. \t GAMER"<<endl;
	cout<<"2. \t MANAGER"<<endl;
	cout<<"Enter your choice(1-2)"<<endl;
	cin>>choice;
	while (choice <0 || choice >3) // Validate input
    {
        cout << "INVALID INPUT, PLEASE ENTER 1 OR 2 ONLY\n";
        cin >> choice;
    }
    if(choice==1)
    {
		
			cout << "ARE YOU A NEW GAMER? (ENTER 1 FOR YES 2 FOR NO) \n";
			cout<<"Enter your choice(1-2)"<<endl;
			cin>>c;
		    if(c==1)								//makes Gamer
			{
				ofstream fs;						//file handler
				fs.open("gamers.txt",ios::app);     //opens file
				cout<<"Enter Registeration number : \n";
				cin>>regnum;
				cout<<"Enter fullname : \n";
				getline(cin,firstname);
				getline(cin,firstname);
			
				//string fullname = firstname+" " + secondname ;
	
				fs << "\n"+to_string(regnum) + " " + firstname + "\n" <<endl;    // enters to file
				cout<<"Gamer Created"<<endl;
				fs.close();
				Gamer_menu();	
					
			}
			else if(c==2)					//login gamer
			{ 
			string w;
			do{
				bool valid;
				ifstream ifs;
				ifs.open("gamers.txt");
				if(ifs.is_open())     //while file is open
				{
					string tp;
					
					while(getline(ifs, tp))    
					{
						
						
						istringstream ss(tp);
						string word;
						
						while(ss>>word)			//gets the text in file
						{
							
						    g1.push_back(word);
							//cout<<word<<endl;   //unfortunetly only takes the first line
						}
		
				}
	
				
						string b = g1[0];
						int b1 = stoi(b);
						gregnum.push_back(b1);   //pushes regnum in vector
						 
						string fn = g1[1];
						fname_g.push_back(fn);  //pushes firstname
						
						string sn = g1[2];
						sname_g.push_back(sn);   //pushes last name
						
						
					
	
						g1.clear();
					
						cout<<"Enter regiteration number: \n";
						cin>>regnum;
			
						cout<<"Enter Firstname : \n";
						getline(cin,firstname);
						getline(cin,firstname);
						
						if(fn == firstname && b1 == regnum )  //checks for values
						{
							validlogin = true;
							Gamer_menu();
						}
						else
						{
							cout<<"Invalid input (Ps. unfortunetley my func only validates first name in the list and not the rest )"<<endl;
							cout<<"Please continue to use the rest of the program"<<endl;
							Gamer_menu();   //unfortunetley my func only validates first name in the list and not the rest 
							
						}
					
					}
					}
			
			while(!validlogin);
			}
			
			else
			{
				cout<<"INVALID INPUT ENTER 1 OR 2";
			}
		}
		
		
if(choice==2)
	{
		do
		{   
		
			bool valids;
			ifstream ifs;
			ifs.open("managers.txt");
			if(ifs.is_open())
		{
			string tp;
					
			while(getline(ifs, tp))
			{
				istringstream ss(tp);
				string word;
						
				while(ss >> word)   //get text
				{
					g2.push_back(word);
						
					//cout<<word<<endl; 
				}
				string m = g2[0];
				int m1 = stoi(m);
				mregnum.push_back(m1);
				
				string fn = g2[1];
				fname_m.push_back(fn);
						
				string sn = g2[2];
				sname_m.push_back(sn);
				
				string fullname = fn + " "+ sn;
				
				g2.clear();
				
				
				cout<<"Enter regiteration number: \n";
				cin>>regnum;
			
				cout<<"Enter Firstname : \n";
				getline(cin,firstname);
				getline(cin,firstname);
				
					if(fn == firstname && m1 == regnum)
				{
					validlogin = true;
					Manager_menu();
				}
				else
				{
					
					cout<<"Invalid input (Ps. unfortunetley my func only validates first name in the list and not the rest )"<<endl;
					cout<<"Please continue to use the rest of the program"<<endl;
					Manager_menu();
					
				}
			}
					
					
		}
						
	}
		while(!validlogin);	
	
	}
}

void Gamer_menu()
{
	int ch;
    cout << "-------------------------------------------------------------" << endl;
    cout << "                       GAME MENU                           " << endl;
   	cout << "-------------------------------------------------------------" << endl;
   	cout << "1. \t Play Game"<<endl;
   	cout << "2. \t Your statistics"<<endl;
   	cout << "3. \t Display top 10"<<endl;
   	cout << "4. \t Exit Game"<<endl;
   	cout << "Enter your choice (1-4)" << endl;
   	cin>>ch;
   	while (ch <0 || ch >5) // Validate input
    {
        cout << "INVALID INPUT, PLEASE ENTER 1 to 4 ONLY\n";
        cin >> ch;
    }
    switch (ch) {
        case 1:  Game(); // if user input '1' then call function
            break;
        case 2: Stats(); // if user input '2' then call function 
            break;
        case 3: leaderboard();  //leaderboard
        	break;
        case 4: exit();
        	break;

    }
    
   	
}
void Manager_menu()
{
		int ch;
    cout << "-------------------------------------------------------------" << endl;
    cout << "                       MANAGER MENU                           " << endl;
   	cout << "-------------------------------------------------------------" << endl;
   	cout << "1. \t Reset Game"<<endl;
   	cout << "2. \t Change Game Level"<<endl;
   	cout << "3. \t Change security Key"<<endl;
   	cout << "4. \t Add another Manager"<<endl;
   	cout << "5. \t Exit Game"<<endl;
   	cout << "Enter your choice (1-5)" << endl;
   	cin>>ch;
   	while (ch <0 || ch >6) // Validate input
    {
        cout << "INVALID INPUT, PLEASE ENTER 1 to 5 ONLY\n";
        cin >> ch;
    }
    switch (ch) {
        case 1:  ResetGame(); // if user input '1' then call function
            break;
        case 2: Changelevel(); // if user input '2' then call function 
            break;
        case 3: changekey();  //if user input is 3 change key
        	break;
        case 4: add_Manager();  // adds manager
        	break;
        case 5: exit();
        	break;

    }
}
void add_Manager()
{ 	
	ofstream fs;
	fs.open("managers.txt",ios::app);
	cout<<"Enter Registeration number : \n";
	cin>>regnum;
	cout<<"Enter Fullname : \n";
	getline(cin,firstname);
	getline(cin,secondname);
			
	string fullname = firstname+" " + secondname ;

     fs << to_string(regnum) + " " + fullname;  //adds manager to the file
	cout<<"Manager Created"<<endl;
	fs.close();
	exit();
	
					
}
void Game()
{

	cout << "-----------------------------------------------------------------" << endl;
    cout << "                       LETS PLAY THE GUESSING GAME               " << endl;
   	cout << "-----------------------------------------------------------------" << endl;
   	cout <<"CHOOSE DIFFICULTY"<<endl;
   	cout<<" 1.\t EASY"<<endl;
   	cout<<" 2.\t MEDIUM"<<endl;
   	cout<<" 3.\t HARD"<<endl;
   	cout<<"ENTER NUMBER BETWEEN 1-3 TO CHOOSE DIFFICULTY"<<endl;
   	cin>>choice;
   	while (choice <0 || choice >4) // Validate input
    {
        cout << "INVALID INPUT, PLEASE ENTER 1 to 3 ONLY\n";
        cin >> choice;
    }
    
     switch (choice) {
        case 1:  easy(); // if user input '1' then call function
            break;
        case 2: medium(); // if user input '2' then call function 
            break;
        case 3: hard();
        	break;

    }
    
}
void easy()
{
	int numeasy;
	srand(time(0));   //random number
	
	numeasy = rand() % ease + 1;  //sets random value upto 10
	int guess;

	  
	do {
	    cout << "Enter your estimate(the number is between "<<range<<" and "<<ease<<" ): "<<endl;	      
		cin >> guess;
		if(guess > ease && guess < range)
		cout<<" ENTER NUMBER BETWEEN THE GIVEN RANGE"<<endl;
		else if (guess < numeasy)
	  	{
		 cout << "Your estimate is less, than the number " << endl;
		 counter++;
		}
	  	else if (guess > numeasy)
	  	{
	  	cout << "Your estimate is more, than the secret number " << endl;
	  	counter++;
	   }
	  	else
	  	cout << "Your guess is right!" << endl;
	  	cout << "Your Score is : "<<counter<<endl;
	  	/*Gamer g = Gamer(firstname, regnum);
	  	
	  	g.addScore(counter,"easy"); */

      }
	  while (guess != numeasy);
	  system("PAUSE");
	  
}
void medium()
{
	int nummed;
	srand(time(0));  //randon num

    nummed = rand() % med + 1; //sets random value upto 100
    int guess;

	  
	do {
	    cout << "Enter your estimate(the number is between "<<range<<" and "<<med<<" ): ";	      
		cin >> guess;
		if(guess > med && guess < range)
		cout<<" ENTER NUMBER BETWEEN THE GIVEN RANGE"<<endl;
		else if (guess < nummed)
		{
			cout << "Your estimate is less, than the number "<< endl;
			counter++;
		}
	  
	  	else if (guess > nummed)
	  	{
	  	cout << "Your estimate is more, than the number " << endl;
	  	counter++;
	    }
	  	else
	  	cout << "Your guess is right!" << endl;
	  	cout << "Your Score is : "<<counter<<endl;

      }
	  while (guess != nummed);
	  system("PAUSE");
	  
}
void hard()
{
	int numhard;
	srand(time(0));  //randon num
	
	numhard = rand() % hards + 1;//sets random value upto 1000
	int guess;

	  
	do {
	    cout << "Enter your estimate(the number is between "<<range<<" and "<<hards<<" ):  ";	      
		cin >> guess;
		if(guess > hards && guess < range)
		cout<<" ENTER NUMBER BETWEEN THE GIVEN RANGE"<<endl;
		else if (guess < numhard)
		{
	  	cout << "Your estimate is less, than the secret number " << endl;
	  	counter++;
	   }
	  	else if (guess > numhard)
	  	{
		  
	  	cout << "Your estimate is more, than the secret number " << endl;
	  	counter++;
	    }
	  	else
	  	cout << "Your guess is right!" << endl;
	  	cout << "Your Score is : "<<counter<<endl;
	  //	Gamer gamer = Gamer (string &firstname, int regnum);
	//gamer.addScore(counter,"hard"); 

      }
	  while (guess != numhard);
	  system("PAUSE");
	  
}
void Stats()
{   
    
	ifstream ifs;
	ifs.open("gamers.txt",ios::in);  //open file
	while(!ifs.eof())   //check end of file
	{	
			for(int i = 0; i<10;i++)
	    	{
	    	
	    		ifs >>fregnum;
				ifs >> fname;
				ifs>> sname;
				ifs >> score_easy;
				ifs >> score_med;
				ifs>>score_hard;
			
				cout << fregnum<<" "<<fname<<" "<<sname<<" "<<score_easy<<" "<<score_med<<" "<<score_hard<<endl;
				
			
			}
			Gamer_menu();
			exit();

 		//}
	}
	ifs.close();  //buuged
	
}
void leaderboard()
{   
	float score;
	ifstream ifs;
	ifs.open("gamers.txt");  //open file
	if(ifs.is_open())
	{
		string t;
					
		while(getline(ifs, t))
		{
		istringstream ss(t);
		string word;
		float easyscr, medscr, hardscr;
						
		while(ss>>word)
		{
			g1.push_back(word);
			//cout<<word+" "<<endl;
		}
			string e = g1[3];   //gets from file
			float e1 = stof(e);
			scr_easy.push_back(e1);
			
						 
			string med = g1[4];   //gets from file
			float med1 = stof(med);
			scr_med.push_back(med1);
						
			string hard = g1[5];   //gets from file
			float hard1 = stof(hard);
			scr_hard.push_back(hard1);
			
	float temp;
	cout<<"WELCOME TO LEADERBOARD"<<endl;
	cout<<"Which leaderboard you want to see?"<<endl;
	cout<<"1. Easy"<<endl;
	cout<<"2. Medium"<<endl;
	cout<<"3. Hard"<<endl;
	cin>>choice;
	if(choice==1)
	{
		for(int i = 0; i<10;i++)
	    {
	        sort(scr_easy.begin(), scr_easy.end());  //sorting
	    	cout<<scr_easy[i]<<endl;
	    }
	    break;
	}
	if(choice==2)
	{
		for(int i = 0; i<10;i++)
	    {
	    	sort(scr_med.begin(), scr_med.end());   //sorting
	    	cout<<scr_med[i]<<endl;
	    }
	     break;
	}
	if(choice==3)
	{
		for(int i = 0; i<10;i++)
	    {
	    	sort(scr_hard.begin(), scr_hard.end());   //sorting
	    	cout<<scr_hard[i]<<endl;
	    }
	     break;
	}
}
	
}
Gamer_menu();
}
void ResetGame()   //resets game level min and max to defualt
{
	ease=10;
	med=100;
	hards=1000;
 	range=0;
 	cout<<"Game Level Reset";
 	
 	Gamer_menu();
}
void Changelevel()   //chamge min and max vakues in levels
{   
	cout <<"CHOOSE LEVEL WHICH YOU WANT TO CHANGE"<<endl;
   	cout<<" 1.\t EASY"<<endl;
   	cout<<" 2.\t MEDIUM"<<endl;
   	cout<<" 3.\t HARD"<<endl;
   	cout<<"ENTER NUMBER BETWEEN 1-3 TO CHOOSE DIFFICULTY"<<endl;
   	cin>>choice;	
   	if(choice==1)
   	{   range=0;
   		cout<<"This level crrently as range of "<<range<<" to "<<ease<<endl;
   		cout<<"What would you like to change it to?"<<endl;
   		cout<<"Enter Starting number : ";
   		cin>>range;
   		cout<<"Enter Ending number : ";
   		cin>>ease;
   		cout<<"Range changed"<<endl;
	}
	else if(choice==2)
   	{   range=0;
   		cout<<"This level crrently as range of "<<range<<" to "<<medium<<endl;
   		cout<<"What would you like to change it to?"<<endl;
   		cout<<"Enter Starting number : ";
   		cin>>range;
   		cout<<"Enter Ending number : ";
   		cin>>ease;
   		cout<<"Range changed"<<endl;
	}
	else if(choice==3)
   	{   range=0;
   		cout<<"This level crrently as range of "<<range<<" to "<<hards<<endl;
   		cout<<"What would you like to change it to?"<<endl;
   		cout<<"Enter Starting number : ";
   		cin>>range;
   		cout<<"Enter Ending number : ";
   		cin>>ease;
   		cout<<"Range changed"<<endl;
	}
	cout<<"DO YOU WANT TO MANAGE OR CHANGE MORE THINGS? (y/n) : "<<endl;
	cin>>ans;
	if(ans == "y")
	{
		Manager_menu();
	}
	else
	{
		cout<<"DO YOU WANT TO EXIT?(y/n) : "<<endl;
		cin>>ans;
		if(ans=="y")
		{
			exit(0);
		}
		if(ans=="n")
		{
			cout<<"Taking you back to menu then"<<endl;
			Manager_menu();
			
		}
	}
}
void changekey()
{
	int val;
    //Encryption encrypt;      //object not bieng created for some reason
	//en.Encryption(int key); 
	cout<<"Not working";
	cout<<"What is the value of key you want to change? (by default key is 5)";
	cin>>val;
	//encrypt.Encryption(val);
	cout<<"key changed"; 
	
	
}

void exit()
{
	exit(0);
}

void file_encrypt()
{
	//Encryption encryption;
	ifstream input;
	ofstream output;
	string w;
	input.open("gamer.txt");
				
	output.open("gamers.txt");
	if(output.is_open())     //while file is open
	{
					
		while(getline(input, w))    
		{
		istringstream ss(w);
		string word;
						
		while(ss>>word)			//gets the text in file
		{
				
		  //cout<<word<endl;
		  
		//encryption.encrypt(word); //this would have worked if object would have been created
		}
	    }
   }
   output.open("manager.txt");
	if(output.is_open())     //while file is open
	{
					
		while(getline(input, w))    
		{
		istringstream ss(w);
		string word;
						
		while(ss>>word)			//gets the text in file
		{
				
		  //cout<<word<endl;
		  
		//encryption.encrypt(word); //this would have worked if object would have been created
		}
	    }
   }
   cout<<"encrypted";
}
void file_decrypt()
{
	//Encryption encryption;
	ifstream input;
	ofstream output;
	string w;
	input.open("gamer.txt");
				
	output.open("gamers.txt");
	if(output.is_open())     //while file is open
	{
					
		while(getline(input, w))    
		{
		istringstream ss(w);
		string word;
						
		while(ss>>word)			//gets the text in file
		{
				
		  //cout<<word<endl;
		  
		//encryption.decrypt(word); //this would have worked if object would have been created
		}
	    }
   }
   output.open("manager.txt");
	if(output.is_open())     //while file is open
	{
					
		while(getline(input, w))    
		{
		istringstream ss(w);
		string word;
						
		while(ss>>word)			//gets the text in file
		{
				
		  //cout<<word<endl;
		  
		//encryption.decrypt(word); //this would have worked if object would have been created
		}
	    }
   }
   cout<<"decrypted";
}






    
