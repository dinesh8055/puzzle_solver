/**
 * water.h
 *
 * @ Version:
 *     $Id: water.h , Version 1.2 12/4/2014 $
 *
 */
 
#ifndef WATER_H
#define WATER_H
#include<iostream>
#include"puzzle.h"
#include <stdlib.h>

using namespace std;

/**
 * This Header solves Water puzzle
 *
 * @author      Rithvik Gambhir
 * @author      Dinesh Gudi
 */
 

class water:public puzzle< vector<int> >
{
private:
	int goal;
	vector<int> buckets;	
	
public:
	water();

	water(const char** argv,int argc){
	
		
		goal=atoi(argv[1]);		
		for(int i=2;i<argc;i++)
		{
			buckets.push_back(atoi(argv[i]));
		}
	};
	
	bool goalReached(vector<int>&);
	
	vector<int> getInitCongif();	

	vector< vector<int> > getNextAttempts(vector<int>&);
	
};

vector<int> water::getInitCongif()
	{
		vector<int> initconfig;

		for(int i=0;i<buckets.size();i++)
		{		
			
			initconfig.push_back(0);
		}
		
		return initconfig;
	}

/**
 * The following method checks if the current configuration meets the goal and
 * returns true or false
 *
 * @param       it          Stores the iterator to traverse the vector
 * @param       goal        Stores the goal configuration
 *
 * @return                  Returns a boolean value depending on whether the
 *                          current configuration meets the goal or not
 *
 */
bool water::goalReached(vector<int>& config)
	{
		bool result=false;

		for(vector<int>::iterator it=config.begin();it!=config.end();++it)
		{
			if(*it==this->goal)
			{				
				result=true;
			}
		}
			return result;
		
	}

/**
 * The following method generates the next possible configurations for the one passed in the argument
 *
 * @param       config              Stores the vector for which the next possible configurations are
 *                                  needed
 *
 * @return                          Returns the vector consisting of next possible configurations
 */
vector< vector<int> >water::getNextAttempts(vector<int>& config)
	{
		vector< vector<int> > nextTrials;
		vector<int> nextifempty;
		vector<int> nextifnotempty;
		vector<int> next;
		for(int i=0;i<config.size();i++)
		{
			if(config.at(i)==0)
			{
				nextifempty=config;		
				nextifempty.at(i)=buckets.at(i);
				nextTrials.push_back(nextifempty);
			}

			if(config.at(i)!=0)
			{
				nextifnotempty=config;
				nextifnotempty.at(i)=0;
				nextTrials.push_back(nextifnotempty);
			}
		
			for(int j=0;j<config.size();j++)
			{
				next=config;
				int quantity;
				quantity=buckets.at(j)-config.at(j);

					if(quantity<config.at(i))
						{
						next.at(j)=next.at(j)+quantity;						
						next.at(i)=next.at(i)-quantity;
						nextTrials.push_back(next);					
						}

					else
					{
						next.at(j)=next.at(j)+config.at(i);						
						next.at(i)=next.at(i)-config.at(i);
						nextTrials.push_back(next);					
					}
				}
			}	
		return nextTrials;
	}
#endif

