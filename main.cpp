#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;
#include "Phase 1.h";
#include "Phase2.h";
#include "Phase3.h";



int main()
{

	while(true)
	{

	string com="";
	string param="";
	string param2="";
	int numParams=0;

	string x;


	cout<<"Command:";
	getline(cin,x);

	// call two pointers a start and an end
	split(x,com,param,param2,numParams);
	compareInput(com,numParams,param,param2);



	if (com =="exit" && numParams == 0)
	{
		break;
	}

	cout << endl;

	}
	
	

	

	// make end traverse through the character array and if it hits something that is not a character  break out
	// else if it hits a character keep traversing until a white space is hit 
	// once a white space is hit take that set of characters and check them against the command list.







	//system ("pause");
	return 0;

}