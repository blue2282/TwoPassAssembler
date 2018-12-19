#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <fstream>
void readSource(string);




void compareInput(string command,int numParams,string param1,string param2)
{

	if (command == "load")
	{
		if(numParams > 1)
		{
			cout<< "Too many parameters";
			
		}

		else if(numParams < 1)
		{
			cout<< "Needs a file ";
			
		}

		else
		{
		cout<< "Loading file";
		readSource(param1);
		// take in parameter one into the load function
		}

		
		
	}

	

	else if (command == "execute")
	{
		

		if(numParams > 0)
		{
			cout<< "Too many parameters";
			
		}
		
		else{
		cout<< "execute";
		// run execute
		}
		
	}

	else if (command == "debug")
	{

		if(numParams > 0)
		{
			cout<< "Too many parameters";
			
		}

		else{
		cout<< "debug";
		}
	
	}

	
	else if (command == "dump")
	{
		if(numParams > 2)
		{
			cout<< "Too many parameters";
			
		}

		else if(numParams < 2)
		{
			cout<< "Missing parameters";
			
		}
		else
		{
		cout<< "dump";
		}
		
	}

	
	else if (command == "help")
	{
		if(numParams > 0)
		{
			cout<< "Too many parameters";
			
		}
		else{
		cout << endl;
		cout<< "load filename: calls the load function to load a specific file. \n";
		cout << endl;
		cout<< "execute: will call the computer simulation program to execute the program that was previously load memory. \n";
		cout << endl;
		cout<< "debug: allows execution in debug mode. \n";
		cout << endl;
		cout<< "help: prints a list of available commands \n";
		cout << endl;
		cout<< "assemble filename: will assemble an SIC assembly language program into a load module and store it ina file. \n";
		cout << endl;
		cout<< "directory: shos a list of files stored in the current directory \n";
		cout << endl;
		cout<< "exit: terminates simulator. \n";
		cout << endl;
		}
		
		
	}


	else if (command == "assemble")
	{
		if(numParams > 1)
		{
			cout<< "Too many parameters";
			
		}

		else if(numParams < 1)
		{
			cout<< "Needs a parameter";
		}

		else
		{
		cout<< "assemble";
		}
		
	}


	else if (command == "directory")
	{

		if(numParams > 0)
		{
			cout<< "Too many parameters";
			
		}
		else{
		system("ls");
		}
		
	}

	
	else if (command == "exit")
	{
		if(numParams > 0)
		{
			cout<< "Too many parameters";
			
		}
		else{
		 system("exit");
		}
		
	}


	else
	{
		cout<< "Do it again";
	}




	cout << endl;





} 


	 void split(string &input,string &com,string &param1,string &param2,int &paramCount)
	 {
		 // while not end of string read until you hit the first character

	

		 int flag = 0;
		 for ( int i= 0; i < input.length(); i++)
		 {
		 // set flag to 1 when it hits the first character
			 if((input[i] == ' '||input[i]==9) && flag == 0 )
			 {
				 continue;
			 }

			 else if (flag == 0 && isalpha(input[i]))
			 {
				 com+= input[i];
				 flag++;

			 }

			 else if(flag == 1 && isalpha(input[i]))// in word
			 {
				 com+= input[i];
			 }

			else if(input[i] == ' ' && flag == 1 )// exiting first word flag is now 2
			 {
				 flag++;
			 }


			
			else if(input[i] == ' ' && flag == 2 )// still out of word  
			 {
				 continue;
			 }

			else if(flag == 2 && isalpha(input[i])) // entering word2 flag is turned to 3
			 {
				 param1+= input[i];
				 flag++;
			 }

			else if(flag == 3 && isalpha(input[i])||input[i]=='.'||input[i]=='/') // still in word 2
			 {
				 param1+= input[i];
				
			 }

			else if(input[i] == ' ' && flag == 3 )// exiting word 2
			 {
				 flag++;
			 }


			else if(input[i] == ' ' && flag == 4 )// still out of word  
			 {
				 continue;
			 }

			else if(flag == 4 && isalpha(input[i]))// entering word3 flag is turned to 5
			 {
				 param2+= input[i];
				 flag++;
			 }

			else if(flag == 5 && isalpha(input[i])) // still in word 3
			 {
				 param2+= input[i];
				
			 }

			else if(input[i] == ' ' && flag == 5 )// exiting word 3 now flag 6 
			 {
				 flag++;
			 }

			else if(input[i] == ' ' && flag == 6 )// still out of word  
			 {
				 continue;
			 }


			else if(flag == 6 && isalpha(input[i])) // still in word 3
			 {
				 paramCount++;
				 break;

				
			 }

		// push each character into input until it hits a space and set flag to 2
		//ignore space until it hits a character and the set flag to 3 
		 // keep reading characters and pushing it into paramater1 until white space
		 // when white space is hit set flag to 4
		 // keep ignoring spaces until next character and set flag to 5
		 // push characters into parameter2  until next white space
		 // when white space is hit set flag to 6

		 // when flag is 6 or end of string quit

		 }		 

		 //count the number of parameters and pass it to the command checking function

		 // if parameter 1 isnt empty add one to param count
		 if (param1.empty() != true)
		 {
			 paramCount++;
		 }

		 // if parameter 2 isnt empty add another to param count

		 // call check function


		 if (param2.empty() != true)
		 {
			 paramCount++;
		 }

		/* input = com;
		 parameter1 = param1;
		 parameter2= param2;
		 numParams = paramCount;*/

		 
	 }



	