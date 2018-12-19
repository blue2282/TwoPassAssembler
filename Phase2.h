#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
using namespace std;
void parseThis(string, string&, string&, string&);
int symbolHash(string,int);
int hashfunction(int);
string checkLabel(string);
void deleteEndLines(string&, string&, string&);



class symbol
{
public:
	string label;
	int address; // from the location counter
	symbol()
	{
		label="";
		address=NULL;
	}
	symbol(string name,int adrs)
	{
		label =name;
		address =adrs;
	}

};



int hashThisSymbol(string lab,vector<symbol>x)// for quadratic probing
{
	int count = 1;
	int hash = symbolHash(lab,x.capacity());
	// if the vector at that hash function plus the count has an empty label and a NULL number
	if(x[hash].address==NULL && x[hash].label=="")// if its not empty
	{
		return hash;
	}
	else if(x[hash+ count].address!=NULL && x[hash+count].label!="")
	{
		return hash+count%x.capacity();// else if add one to it and mod by the cap and try again
	}
	else	
	{
		while(true)// else square it and do it again
		{
			count=count*count;
			if(x[hash+count].address==NULL && x[hash+count].label=="")
			{
				return hash+count%x.capacity();
			}
		}
	}
}

void makeOptable(vector<symbol>&opT)
{
	symbol temp;
	int a;int b;int c;int d;int e;int f;int g;int h;int i;int j;int k;int l;int m;int n;
	int o;int p;int q;int r;int s;int t;int u;int v;int w;int x; int y; int z;

	stringstream as;stringstream bs;stringstream cs;stringstream ds;stringstream es;stringstream fs;stringstream gs;
	stringstream hs;stringstream is;stringstream js;stringstream ks;stringstream ls;stringstream ms;
	stringstream ns;stringstream os;stringstream ps;stringstream qs;stringstream rs;stringstream ss;
	stringstream ts;stringstream us;stringstream vs;stringstream ws;stringstream xs;stringstream ys;stringstream zs;

	int counter=0;
	counter=hashThisSymbol("ADD",opT);

			
			as << std::hex << "18";// converts a hex string to int
			as >> a;
			opT[counter].label="ADD";
			opT[counter].address=a;


			counter=hashThisSymbol("AND",opT);
			
			bs <<  std::hex << "58";// converts a hex string to int
			bs >> b;
			opT[counter].label="AND";
			opT[counter].address=b;

			counter=hashThisSymbol("COMP",opT);

			cs <<  std::hex << "28";// converts a hex string to int
			cs >> c;
			opT[counter].label="COMP";
			opT[counter].address=c;

			counter=hashThisSymbol("DIV",opT);

			ds <<  std::hex << "24";// converts a hex string to int
			ds >> d;
			opT[counter].label="DIV";
			opT[counter].address=d;

			counter=hashThisSymbol("J",opT);

			es <<  std::hex << "3C";// converts a hex string to int
			es >> e;
			opT[counter].label="J";
			opT[counter].address=e;

			counter=hashThisSymbol("JEQ",opT);

			fs <<  std::hex << "30";// converts a hex string to int
			fs >> f;
			opT[counter].label="JEQ";
			opT[counter].address=f;

			counter=hashThisSymbol("JGT",opT);

			gs <<  std::hex << "34";// converts a hex string to int
			gs >> g;
			opT[counter].label="JGT";
			opT[counter].address=g;

			counter=hashThisSymbol("JLT",opT);

			hs <<  std::hex << "38";// converts a hex string to int
			hs >> h;
			opT[counter].label="JLT";
			opT[counter].address=h;

			counter=hashThisSymbol("JSUB",opT);

			is <<  std::hex << "48";// converts a hex string to int
			is >> i;
			opT[counter].label="JSUB";
			opT[counter].address=i;


			counter=hashThisSymbol("LDA",opT);

			js <<  std::hex << "00";// converts a hex string to int
			js >> j;
			opT[counter].label="LDA";
			opT[counter].address=j;

			counter=hashThisSymbol("LDCH",opT);

			ks <<  std::hex << "50";// converts a hex string to int
			ks >> k;
			opT[counter].label="LDCH";
			opT[counter].address=k;


			counter=hashThisSymbol("LDL",opT);

			ls <<  std::hex << "08";// converts a hex string to int
			ls >> l;
			opT[counter].label="LDL";
			opT[counter].address=l;


			counter=hashThisSymbol("LDX",opT);

			ms <<  std::hex << "04";// converts a hex string to int
			ms >> m;
			opT[counter].label="LDX";
			opT[counter].address=m;

			counter=hashThisSymbol("MUL",opT);

			ns <<  std::hex << "20";// converts a hex string to int
			ns >> n;
			opT[counter].label="MUL";
			opT[counter].address=n;

			
			counter=hashThisSymbol("OR",opT);

			ps <<  std::hex << "44";// converts a hex string to int
			ps >> p;
			opT[counter].label="OR";
			opT[counter].address=p;


			counter=hashThisSymbol("RD",opT);

			qs <<  std::hex << "D8";// converts a hex string to int
			qs >> q;
			opT[counter].label="RD";
			opT[counter].address=q;


			counter=hashThisSymbol("RSUB",opT);

			rs <<  std::hex << "4C";// converts a hex string to int
			rs >> r;
			opT[counter].label="RSUB";
			opT[counter].address=r;

			counter=hashThisSymbol("STA",opT);

			ss <<  std::hex << "0C";// converts a hex string to int
			ss >> s;
			opT[counter].label="STA";
			opT[counter].address=s;

			counter=hashThisSymbol("STCH",opT);

			ts <<  std::hex << "54";// converts a hex string to int
			ts >> t;
			opT[counter].label="STCH";
			opT[counter].address=t;

			counter=hashThisSymbol("STL",opT);

			us <<  std::hex << "14";// converts a hex string to int
			us >> u;
			opT[counter].label="STL";
			opT[counter].address=u;

			counter=hashThisSymbol("STX",opT);

			vs <<  std::hex << "10";// converts a hex string to int
			vs >> v;
			opT[counter].label="STX";
			opT[counter].address=v;

			counter=hashThisSymbol("SUB",opT);

			ws <<  std::hex << "1C";// converts a hex string to int
			ws >> w;
			opT[counter].label="SUB";
			opT[counter].address=w;

			counter=hashThisSymbol("TD",opT);

			xs <<  std::hex << "E0";// converts a hex string to int
			xs >> x;
			opT[counter].label="TD";
			opT[counter].address=x;

			counter=hashThisSymbol("TIX",opT);

			ys <<  std::hex << "2C";// converts a hex string to int
			ys >> y;
			opT[counter].label="TIX";
			opT[counter].address=y;

			counter=hashThisSymbol("WD",opT);

			zs <<  std::hex << "DC";// converts a hex string to int
			zs >> z;
			opT[counter].label="WD";
			opT[counter].address=z;
			
			



}

int symbolHash(string label ,int size)
{
	int sum = 0;
	for( int i = 0; i<label.length();i++)
	{
		sum+= (i+1) * toascii(label[i]);	
	}

	return (sum  % size);
}

bool hasDuplicate(string input,vector<symbol> symbolT)
{
	for( int i=0; i< symbolT.capacity();i++)
	{
		if(symbolT[i].label==input)
		{
			return true;
		}
	}
	return false;
}


void pass2(vector<symbol>optable, vector<symbol>symbolTable, int programLength);

void readSource(string source)
{
	/////////////////// error flags /////////////////////////
	int missingStart=0;
	int dup =0;
	int invalidLabel=0;
	int illegalOperation=0;
	/////////////////////////////////////////////////////////

	ifstream infile;
	ofstream outfile;
	string input;
	int programLength;
	int locationCounter=0;// make it global
	int startingAddress=0;// starting address
	vector<symbol>optable;
	vector<symbol> symbolT;
	symbolT.reserve(1001);
	optable.reserve(1001);
	symbol def("",NULL);

		for(int i =0;i<symbolT.capacity();i++)// initializing the vector for the optable and the operand
		{
			optable.push_back(def);
			symbolT.push_back(def);
		}

		makeOptable(optable);



	string fileName =source;// opens the file
	string outfileName="intermediateFile.txt";// outfile intermediate file
	infile.open(source.c_str());
	outfile.open(outfileName.c_str());


	

	while(!infile.eof())
	{
		string label="";
		string opcode="";
		string operand="";
		string secondLabel="";
		string secondOpcode="";
		string secondOperand="";
		getline(infile,input);
		parseThis(input,label,opcode,operand);

	
		if( opcode =="START") 
		{
			//save transform the operand and use it as the starting address
			

			
			string secondInput;
			//locationCounter=0;
			std::stringstream ss;
			ss << std::hex << operand;
			ss >> startingAddress;
			locationCounter= locationCounter+startingAddress;//initialize the Location counter to the starting address
			outfile<<input<<endl;
			outfile<<hex<<locationCounter<<endl;
			outfile<<missingStart<<dup<<invalidLabel<<illegalOperation<<endl;
			outfile<<"***************************************"<<endl;
			//read the next input line and write to the intermediate file
			getline(infile,secondInput);
			label="";
			opcode="";
			operand="";
			parseThis(secondInput,label,opcode,operand);
			outfile<<label<<"\t"<<opcode<<"\t"<<operand<<endl;

		}
		else{ 
			missingStart =1;
			outfile<<input<<endl;// missing start
			outfile<<hex<<locationCounter<<endl;/////////////
			outfile<<missingStart<<dup<<invalidLabel<<illegalOperation<<endl;///////////////
			outfile<<"***************************************"<<endl;
			missingStart =0;
			label="";
			opcode="";
			operand="";
			string secondInput;
			getline(infile,secondInput);
			parseThis(secondInput,label,opcode,operand);
			outfile<<label<<"\t"<<opcode<<"\t"<<operand<<endl;			
		}
				// set location counter to equal zero
				//locationCounter=0;
				  do
					{
						int symbolCounter= locationCounter;
						
						if(label=="" && opcode=="" && operand=="")// if the string is a comment
						{
							// skip it
						}

						else{
							string secondInput;
							//handle line 1**************************************************************************
							
							//if the label is not blank
							
							//search the opcodeTable for opcode
							int opcodeIndex=hashThisSymbol(opcode,symbolT);
							//if you find it 
							if(opcode==optable[opcodeIndex].label)
							{
								locationCounter+=3;// add 3 to location counter
							}	
							//else if opcode=="WORD"
							else if(opcode=="WORD")								
							{
								locationCounter+=3;// add 3 to location counter
							}
							//else if opcode=="RESB"
							else if(opcode=="RESB")	
							{
								// add the (operand which is already in decimal) to the location counter
								int resultRESB;
								stringstream (operand)>>resultRESB;
								locationCounter+=resultRESB;
							}
							//else if opcode=="RESW"
							else if(opcode=="RESW")	
							{
								// add the (operand which is already in decimal)*3 to the location counter
								int resultRESW;
								stringstream (operand)>>resultRESW;
								locationCounter+=resultRESW*3;
							}
							//else if opcode=="BYTE
							else if(opcode=="BYTE")	{
								//get the operand if the first letter is C
								// read count the number of characters in between the apostrapies and add that number to the
								//location counter
								if(operand[0]=='C')
								{
									int byteCounter=0;
									for( int i=2; i<operand.size()-1;i++)
									{
										byteCounter++;
									}
									locationCounter+=byteCounter;
								}

								else if(operand[0]=='X')
								{//if its X read in the characters in between the apostrapies and convert the hex string to int
									// add it to the location counter


									int byteCounter=0;
									for( int i=2; i<operand.size()-1;i++)
									{
										byteCounter++;
									}
									locationCounter+=byteCounter/2;
									
								}							
							}
							else{
								//set error flag, invalid operation
								illegalOperation =1;
								//call in check error function
							}	

							if(label!="")
							{
							//check to see if it does exists
								if(hasDuplicate(label,symbolT)==true)
								{//if found error flag, has duplicate label
									//push in duplicate error
									dup =1;
								}
								else{//else push the label and the location counter to the symbol table									
									// check if the label is wrong 									
									string check = checkLabel(label);
									// if the string is not null									
									//outfile the error
									int y=hashThisSymbol(label,symbolT);
									symbolT[y].label=label;
									symbolT[y].address=symbolCounter;
									
									if (check!="")
									{
										invalidLabel =1;
									}
									

								}							
							}



						outfile<<hex<<symbolCounter<<endl;/////////////
						outfile<<missingStart<<dup<<invalidLabel<<illegalOperation<<endl;///////////////
						outfile<<"***************************************"<<endl;

						}
							//read the next input line and write to the intermediate file				
							
							
							missingStart = 0;
							dup =0;
							invalidLabel =0;
							illegalOperation =0;

							string tempInput;
							getline(infile,tempInput);
							label="";
							opcode="";
							operand="";
							parseThis(tempInput,label,opcode,operand);
							if(tempInput[0]=='.')
							{
							}
							else
							{
							outfile<<tempInput<<endl;
							}
							

							

							if(infile.eof())
							{
								//call error message there is no exit
								//outfile<<"error misspelled or no exit"<<endl;
								outfile<<"error:missing or mispelled END"<<endl;
								break;
							}



					}while (opcode!="END");
						outfile<<hex<<locationCounter<<endl;/////////////
						outfile<<missingStart<<dup<<invalidLabel<<illegalOperation<<endl;///////////////
						outfile<<"***************************************"<<endl;


				// locationCounter - startingaddress as the program length*/
					programLength=locationCounter-startingAddress;
					// if program length is bigger than the limit output program too long
					cout<<endl;
					cout<<"Program Length:"<< hex<< programLength<<endl;
					int symbolCount=0;
					for(int i =0;i<symbolT.capacity();i++)// initializing the vector for the optable and the operand
						{
							if(symbolT[i].label=="")
							{

							}

							else{
								symbolCount++;
							}
						}

					


					// count the number of symbols in the symbol table
					if(symbolCount>500)
					{
						outfile<<"error:too many symbols"<<endl;
					}

					// if its more than 500				

					// flag that it has too many symbols

					break;
				
		//}
	}
		
	cout<<endl;

	for(int i =0;i<symbolT.capacity();i++)// checks if it works
	{
		if(symbolT[i].address==NULL && symbolT[i].label=="")
		{
			continue;
		}
		else
		{
			cout<< symbolT[i].label <<"|"<<hex<< symbolT[i].address<<endl;
		}
	}

	cout<<"**************************************************************"<<endl;

	for(int i =0;i<optable.capacity();i++)// checks if it works
	{
		if(optable[i].address==NULL && optable[i].label=="")
		{
			continue;
		}
		else
		{
			cout<< optable[i].label <<"|"<< optable[i].address<<endl;
		}
	}
		

	infile.close();


	pass2(optable,symbolT,programLength);
	
}


void parseThis(string input, string &label, string &opcode,string &operand)
{
	int count = 0;
	
	for( int i = 0; i < input.length(); i++)
	{
		if(input[0]=='.')
		{
			break;
		}

		else{

		if(i == 0 && !isalpha(input[i]))// if the first part of your line is not alpha 
		{
			count++;// skip label
		}

		if(input[i] ==' ' || input[i]== 9)
		{
			continue;
		}
		else
		{
			if(count == 0)
			{
				label+=input[i];
			}
			else if(count == 1)
			{
				opcode+=input[i];
			}

			else if(count==2)
			{
				operand+=input[i];
			} 

			if(input[i+1]==' ' || input[i+1]==9)
				{
					count++;
			}// is a space or a tab
			//increase parameter by one
		}
		}
		// check for \r in label opcode or operand 
		// and remove them if found
		
	}

	//deleteEndLines(label,opcode,operand);
}


string checkLabel(string label)
{
	// string has to have less than or equal to 6 characters in length
	if(label.length()<7)
	{

	}

	else
	{
		return "error:label too long";
	}
	// first character must be a letter
	if(!isalpha(label[0]))
	{
		return "error:label has wrong format";
	}
	// must be alpha or numeric

	for(int i =1; i < label.length();i++)
	{
		if(!isalnum(label[i]))
		{
			 return "error:label has the wrong format";
		}
	}

	return "";
}


void deleteEndLines(string &label, string &opcode, string &operand)
{
	
	if(operand.find(',')!=string::npos)
	{
		int labelLocation = label.find('\r');
		label.erase(labelLocation);
	}

	if(opcode.find('\r')!=string::npos)
	{
		int opcodeLocation = opcode.find('\r');
		opcode.erase(opcodeLocation);
	}
	
	
	if(operand.find('\r')!=string::npos)
	{
		int operandLocation = operand.find('\r');
		operand.erase(operandLocation);
	}	

}












