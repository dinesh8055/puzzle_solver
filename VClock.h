/**
 * VClock.h
 *
 * @ Version:
 *     $Id: VClock.h , Version 1.2 12/4/2014 $
 *
 */

#ifndef VCLOCK_H
#define VCLOCK_H
#include <vector>
#include<iostream>
#include"puzzle.h"

using namespace std;

/**
 * This header solves VClock puzzle
 *
 * @author      Rithvik Gambhir
 * @author      Dinesh Gudi
 */

class VClock :public puzzle<int>
{
	
private:
	int num_of_hours;
	int current_time;
	int goal_time;
	vector<int> var;
	
public:

	 VClock(int total,int currtime,int goal, vector<int>& var):num_of_hours(total),current_time(currtime),
		goal_time(goal),var(var){};

	bool goalReached(int&);
	
	int getInitCongif();	

	vector<int> getNextAttempts(int&);
	
};

int VClock::getInitCongif()
	{
		return (this->current_time);
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

bool VClock::goalReached(int& config)
	{
	
		if(this->goal_time==config)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
/**
 * The following method generates the next possible configurations for the one passed in the argument
 *
 * @param       config              Stores the vector for which the next possible configurations are
 *                                  needed
 *
 * @return                          Returns the vector consisting of next possible configurations
 */

vector<int>VClock::getNextAttempts(int& config)
	{
		vector<int> trials;
		int subsol1,subsol2;
		for(int i=0;i<var.size();i++)
		{			
			if(config>1 && config< num_of_hours)
			{
				
				subsol1=config+var[i];

				if(subsol1==0)
				{
					subsol1=num_of_hours;
				}
				
			}
			else
			{
				if(config==1)
				{
					if(var[i]>0)
					{								
						subsol1=config+var[i];										
					
					}
					else
					{
						subsol1=num_of_hours;															
					
					}
				}
				else
				{	
					if(var[i]>0)
					{					
						subsol1=var[i];
					
					}
					else
					{						
						subsol1=config+var[i];
						
					}			
					
				}
			}			
			trials.push_back(subsol1);
			}

		return trials;
	}

#endif