/**
 * clock.cpp
 *
 * @ Version:
 *     $Id: clock.cpp , Version 1.2 12/4/2014 $
 *
 */
 
#include<iostream>
#include"Solver.h"
#include "clock.h"
#include<cstdlib>

using namespace std;

/**
 * This program solves clock puzzle
 *
 * @author      Rithvik Gambhir
 * @author      Dinesh Gudi
 */
 
	int main(int argc, const char * argv[])
	{		
		if(argc!=4)
		{			
			cout<<"error"<<endl;
		}
		else
		{	
			vector<int> sol;			
			Clock ck(atoi(argv[1]) , atoi(argv[2]) , atoi(argv[3]));
			sol=Solver::solve(ck);
			
			if(!sol.empty())
			{
				for(int i=0;i<sol.size();i++)
				{
					cout<<"step "<<i<<" "<<sol.at(i)<<endl;
					
				}
			}
			else
			{
				cout<<"No Solution Found for the entered configuration"<<endl;
				
			}
		}
		
	};
