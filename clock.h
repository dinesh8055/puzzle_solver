/**
 * clock.h
 *
 * @ Version:
 *     $Id: clock.h , Version 1.2 12/4/2014 $
 *
 */
 
#ifndef CLOCK_H
#define CLOCK_H
#include <vector>
#include<iostream>
#include"puzzle.h"
#include<cstdlib>

using namespace std;

/**
 * This Header solves clock puzzle
 *
 * @author      Rithvik Gambhir
 * @author      Dinesh Gudi
 */
 

class Clock :public puzzle<int>
{
	
private:
	int num_of_hours;
	int current_time;
	int goal_time;
	
public:

	 Clock(int total,int currtime,int goal):num_of_hours(total),current_time(currtime),
		goal_time(goal){};

	bool goalReached(int&);
	
	int getInitCongif();	

	vector<int> getNextAttempts(int&);
	
};

int Clock::getInitCongif()
	{
		if(this->current_time<=this->num_of_hours && this->current_time>0)
		{
			return (this->current_time);
		}
		else
		{
			cout<<"Invalid input time"<<endl;
			exit(1);
		}
		
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
bool Clock::goalReached(int& config)
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
vector<int>Clock::getNextAttempts(int& config)
	{
		vector<int> trials;
		int subsol1,subsol2;
		if(config>1 && config< num_of_hours)
		{
			subsol1=config-1;
			subsol2=config+1;
		}
		else
		{
			if(config==1)
			{
				subsol1=num_of_hours;
				subsol2=config+1;
			}
			else
			{
				subsol1=config-1;
				subsol2=1;
			}
		}

		trials.push_back(subsol1);
		trials.push_back(subsol2);
		return trials;
	}

#endif