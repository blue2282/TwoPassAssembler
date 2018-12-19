//#include <iostream>
//#include <stdlib.h>
//#include <sstream>
//#include <string>
//#include <stdlib.h>
//#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;


void pass2(vector<symbol>optable, vector<symbol>symbolTable, int programLength)
{

	ifstream infile;
	ofstream outfile;
	ofstream outfileListing;
	string label="";
	string opcode="";
	string operand="";
	string input;
	string locationCounter; 
	string currentLocationCounter;// current location counter of the first item after new text record
	string startingAddress;
	string textLength;
	string errors;
	int undefinedSymbol=0;
	string fileName="intermediateFile.txt";
	string outfileName="objectFile.txt";
	string outfileName2="listingFile.txt";
	infile.open(fileName);
	outfile.open(outfileName);
	outfileListing.open(outfileName2);
	
	//read input line from the intermediate file
	getline(infile,input);
	parseThis(input,label,opcode,operand);
	getline(infile,locationCounter);
	getline(infile,errors);

	




	if(opcode == "START")
	{
		//write listing line
		//outfileListing<< input;
		//read next input line
	}

	//write header record to the object file
	outfile<<"H"<<label<<"_"<<setfill('0')<<setw(6)<<right<<locationCounter<<setw(6)<<hex<<programLength<<endl;
	//initialize first text record

	getline(infile,input);
	while(input[0]=='*')
	{
		getline(infile,input);
	}
	label="";
	opcode="";
	operand="";
	parseThis(input,label,opcode,operand);
	getline(infile,locationCounter);
	getline(infile,errors);
	

	
	 do
	{
		//if this is not a comment line then 
		
		// int flag = 0;

		int instructionCount = 0;
		string textrecord="";
		// while the length of the text record is less than 60 bytes characters which is 30
		string initialText;
		initialText="T";		

			for( int j = 0; j < 6- locationCounter.length(); j++)
			{
				initialText.push_back('0');
			}

			for( int i = 0; i < locationCounter.length(); i++)
			{
				initialText.push_back(locationCounter[i]);
			}
	

		while(textrecord.size()<60 && instructionCount<10 && opcode !="END")
		{

		string operandAddress;
		//handle line 2
		//
		//search OPTAB from OPCODE
		int opAddress = optable[symbolHash(opcode,optable.capacity())].address;// convert this to hex
		string ifopcode=optable[symbolHash(opcode,optable.capacity())].label;
		//if found then
		if (ifopcode!="")
		{		
		
		//if there is a symbol in the OPERAND field then
		if(symbolTable[symbolHash(operand,optable.capacity())].label== operand)
		{
			//search SYMTAB for OPERAND
			//if found
			//{
			int x;
			x = symbolTable[symbolHash(operand,optable.capacity())].address;
			stringstream convert;
			convert << hex<< x;
			convert >> operandAddress;
			//}

			
		}

		else 
			{
				//store 0 as operand address
				operandAddress ="0000";
				//set error flag undefined symbol
				undefinedSymbol = 1;
			}



		}

		else if(opcode =="BYTE")
		{
			//convert constant to object code
			if(operand[0]=='C')
			{
				
				for( int i=2; i<operand.size()-1;i++)
					{										
						stringstream hexConvert;
						string carrier;
						int iMyAsciiValue = static_cast<int>(operand[i]);
						
						hexConvert << hex <<iMyAsciiValue;					
						hexConvert>>carrier;
						for( int i =0; i < carrier.length();i++)
						{
						operandAddress.push_back(carrier[i]);
						}					
					}
			}

			else  if(operand[0]=='X')
			{
				string hexString;
				for( int i=2; i<operand.size()-1;i++)
					{										
						hexString.push_back(operand[i]);										
					}
					stringstream hexConvert;
					hexConvert << hex << hexString;
					hexConvert>>operandAddress;
			}

			// else make an illegal operand field error
		}

		else if(opcode =="WORD")
		{
			int temp = atoi(operand.c_str());
					stringstream hexConvert;
					
					hexConvert << hex << temp;
					hexConvert>>operandAddress;
			
		}



		if(operand.find(',')!=string::npos)
		{
			string x = operand.substr(0,operand.find(','));
			//check length if its above 6 characters error
			int addrs;
			addrs = symbolTable[symbolHash(x,symbolTable.size())].address;
			addrs = addrs+32768;
			stringstream converter;
			converter<<setfill('0')<<setw(4)<<right<< hex << addrs;
			converter>>operandAddress;		
			
		}
		


		//if byte

		if(opcode=="BYTE")// add to text record only operand address
		{
			for( int i =0; i< operandAddress.length(); i++)
			{
				textrecord.push_back(operandAddress[i]);
			}

			// write to listing file here
				getline(infile,input);
				while(input[0]=='*')
				{
					getline(infile,input);
				}
				label="";
				opcode="";
				operand="";
				parseThis(input,label,opcode,operand);
				getline(infile,locationCounter);
				getline(infile,errors);
				instructionCount++;
				continue;

		}

		else if( opcode =="RESW" || opcode =="RESB")
		{
			 while( opcode =="RESW" || opcode == "RESB")
			{
				// write to listing file here
				getline(infile,input);
				while(input[0]=='*')
				{
					getline(infile,input);
				}
				label="";
				opcode="";
				operand="";
				parseThis(input,label,opcode,operand);
				getline(infile,locationCounter);
				getline(infile,errors);
			}

			
			break;

			
		}


		

		else
		{
		//build text record
			stringstream converter;
			//text<<"H"<<label<<'_'<<setfill('0')<<setw(6)<<right<<locationCounter<<setw(6)<<hex<<programLength<<endl;
			converter<<setfill('0')<<setw(2)<<right<< hex << opAddress;
			string convertedOpAddress="";
			string x;
			converter>> x;
			for( int i =0; i< x.length(); i++)
			{
				convertedOpAddress.push_back(x[i]);
			}
			
			
			for( int i =0; i< convertedOpAddress.length(); i++)
			{
				textrecord.push_back(convertedOpAddress[i]);
			}

			
			for( int j = 0; j < 4- operandAddress.length(); j++)
			{
				textrecord.push_back('0');
			}

			for( int i =0; i< operandAddress.length(); i++)// push back the operand address thats in hex
			{
			
				textrecord.push_back(operandAddress[i]);
			}

		}

			//write to listing file here. 
			cout<< textrecord<< endl;			

			getline(infile,input);
			while(input[0]=='*')
			{
				getline(infile,input);
			}
			label="";
			opcode="";
			operand="";
			parseThis(input,label,opcode,operand);
			getline(infile,locationCounter);
			getline(infile,errors);


			instructionCount++;

		}

		//write listing line

		//write text record to file

		// if flag == 1
		// dont get line
		// use the address of the current  guy as the start address of the text record

		// else do the regular stuff

		if(opcode =="END")
		{
			// create the last textrecord and 

				string textsize;
				stringstream hexTextLength;
				int textrecordsize = textrecord.size()/2;
				hexTextLength << hex <<textrecordsize;
				hexTextLength>>textsize;

				outfile<<initialText<<setfill('0')<<setw(2)<<right<<textsize<<textrecord<<endl;

				// create the end record
			
				int endAddress = symbolTable[symbolHash(operand,symbolTable.capacity())].address;// convert this to hex		
				outfile<<"E"<<setfill('0')<<setw(6)<<right<<hex<<endAddress;


			
			//outfile<<initialText<<textsize<<textrecord<<endl;
			break;
		}
		else
		{

		string textsize;
		stringstream hexTextLength;
		int textrecordsize = textrecord.size()/2;
		hexTextLength << hex <<textrecordsize;
		hexTextLength>>textsize;

		outfile<<initialText<<setfill('0')<<setw(2)<<right<<textsize<<textrecord<<endl;

		//outfile<<initialText<<textsize<<textrecord<<endl;

		}


		//read next input line 




	}while (opcode!="END");

	//write last text record to object file
	//write end record to object file
	//write last listing line



	
}