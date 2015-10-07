/**
 * lloyd.cpp
 *
 * @ Version:
 *     $Id: lloyd.cpp , Version 1.2 12/4/2014 $
 *
 */

#include<iostream>
#include<fstream>
#include"Solver.h"
#include<cstdlib>
#include "lloyd.h"

using namespace std;

/**
 * This program solves Lloyd's puzzle
 *
 * @author      Rithvik Gambhir
 * @author      Dinesh Gudi
 */


 /**
 * The following takes in the input from the file and calls the solver
 *
 * @param       argc        Stores the number of string arguments given as inputs
 * @param       argv        Stores the filename with relative path
 *
 * @return                  Returns integer value 0
 */

int main(int argc, const char * argv[])
	{			
		vector< vector< vector<char> > > sol;

		ifstream ifs;		
		ofstream wr;
		char c;		
		int sizecount=0;
		int width=0;
		int height=0;
		vector<char> subinput;
		vector<char> subgoal;
		vector< vector<char> > input (height, vector<char>(width) );
		vector< vector<char> > goalinput (height, vector<char>(width) );
		bool readinput=true;				
		vector<char> goal;
		const char * filename;
		int widthcheck=0;
		int heightcheck=0;		
		
		if(argc!=3)
		{
			cout<<"please check the number of arguments";
		}
		else
		{			
			if(argv[1][0]=='-')
			{
				cout<<"enter $ to end the input"<<endl;

				int readsize=0;				
				int readwh=0;
				int heightcount=0;
				int widthcount=0;
				int loopcount=0;
				
				cout<<"enter initial config"<<endl;
				char ch;
				while(ch!='$')
				{
				ch=getchar();
				
				if(!iswspace(ch))
					{
						
					if(sizecount==0)
					{				
						width=ch-'0';
						
					}
					
					if(sizecount==1)
					{	
						height=ch-'0';					
					}
					
					if(sizecount==2)
					{				
						vector< vector<char> > input (height, vector<char>(width) );
						vector< vector<char> > goalinput (height, vector<char>(width) );										
						sizecount++;											
					}				
					
					if((widthcheck==width) && sizecount>2)
					{	
						if(readinput)
						{							
							input.push_back(subinput);				
							subinput.clear();
							heightcheck++;
						}
						else
						{							
							if(subgoal.size()>0)
							{
								
							goalinput.push_back(subgoal);
							subgoal.clear();
							heightcheck++;
							}
						}
					
						if(heightcheck==height)
						{						
							readinput=false;
							heightcheck=0;
						}
						widthcheck=0;
					}				
				
					if(sizecount>2 && heightcheck<=height)
					{					
					
						if(readinput)
						{						
							subinput.push_back(ch);
							widthcheck++;
						}
						else
						{								
							subgoal.push_back(ch);
							widthcheck++;							
						}
					}
					
					sizecount++;			
				}	
			}			

		}
			else
			{				
				filename=argv[1];			
			
				ifs.open(filename,ios::in);
				
				if(!ifs.is_open())
				{			
					cout<<"Something wrong with the file/Reading from console"<<endl;
					
				}
			
				else
				{
				while(ifs.good())
				{					
					ifs.get(c);
				
					if(!iswspace(c))
					{
						
					if(sizecount==0)
					{				
						width=c-'0';							
					}
					
					if(sizecount==1)
					{	
						height=c-'0';					
					}
					
					if(sizecount==2)
					{				
						vector< vector<char> > input (height, vector<char>(width) );
						vector< vector<char> > goalinput (height, vector<char>(width) );				
						sizecount++;					
					}				
					
					if((widthcheck==width) && sizecount>2)
					{	
						if(readinput)
						{							
							input.push_back(subinput);				
							subinput.clear();
							heightcheck++;
						}
						else
						{							
							if(subgoal.size()>0)
							{
								
							goalinput.push_back(subgoal);
							subgoal.clear();
							heightcheck++;
							}
						}
					
						if(heightcheck==height)
						{						
							readinput=false;
							heightcheck=0;
						}
						widthcheck=0;
					}				
					if(heightcheck>height)
					{
						cout<<"Entered more than size"<<endl;
						break;
					}
					if(sizecount>2 && heightcheck<=height)
					{					
					
						if(readinput)
						{						
							subinput.push_back(c);
							widthcheck++;
						}
						else
						{								
							subgoal.push_back(c);
							widthcheck++;							
						}
					}
					if(widthcheck>width)
					{
						cout<<"Entered more than size"<<endl;
						break;
					}
					sizecount++;			
				}					
			}
				
			ifs.close();			
		}
	}
				
			
			lloyd ll( input,goalinput);
		
			sol=Solver::solve(ll);
			bool tofile=false;
			const char * outputfile;
			outputfile=argv[2];
			if(argv[2][0]!='-')
			{			
				wr.open(outputfile,ofstream::out);
				tofile=true;
			}

			if(!sol.empty())
			{			
				for(int i=0;i<sol.size();i++)
				{	
					if(tofile)
					{							
						wr<<"Step "<<i<<endl;
						wr<<"-------"<<endl;
					}
					else
					{
						cout<<"Step "<<i<<endl;
						cout<<"-------"<<endl;
					}
					for(int j=0;j<sol.at(i).size();j++)
					{					
						for(int k=0;k<sol.at(i).at(j).size();k++)
						{	
							if(tofile)
							{
								wr<<sol[i][j][k]<<" ";
							}
							else
							{
								cout<<sol[i][j][k]<<" ";
							}
						}
						if(tofile)
							{
								wr<<endl;
							}
						else
						{
							cout<<endl;
						}
						
					}
					if(tofile)
					{
					wr<<endl;
					wr<<endl;
					}

					else
					{
						cout<<endl;
						cout<<endl;
					}
				}
			}

			else
			{
				cout<<"no solution"<<endl;
			}

			}
		
	
		
};


