/**
 * water.cpp
 *
 * @ Version:
 *     $Id: water.cpp , Version 1.2 12/4/2014 $
 *
 */
 
#include<iostream>
#include"Solver.h"
#include<cstdlib>
#include "water.h"

using namespace std;

/**
 * This program solves Water puzzle
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
		if(argc<3)
		{			
			cout<<"Invalid number of inputs"<<endl;
		}
		else
		{
			vector< vector<int> > sol;

			water wt( argv,argc);
			sol=Solver::solve(wt);		
			
			if(!sol.empty())
			{				

				for(int i=0;i<sol.size();i++)
				{
					cout<<"step "<<i<<endl;
					for(int j=0;j<sol.at(i).size();j++)
					{					
						cout<<sol.at(i).at(j)<<" ";
											
					}
					cout<<endl;
				}
			}
			else
			{				
				cout<<"no solution found for the provided configuration"<<endl;
				
			}
		}
		
	};
