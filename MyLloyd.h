/**
 * Mylloyd.h
 *
 * @ Version:
 *     $Id: Mylloyd.h , Version 1.1 12/4/2014 $
 *
 */

#ifndef MYLLOYD_H
#define MYLLOYD_H
#include <vector>
#include<string>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;

/**
 * This class contains the helper functions to solve Lloyd's puzzle
 *
 * @author      Dinesh Gudi
 * @author      Rithvik Gambhir
 */

class Mylloyd
{
public:
	vector< vector<char> > getNext(vector<char>);
        bool top(int);
        bool bottom(int);
        bool left(int);
        bool right(int);
	bool isDesired(vector<char>&);
	vector<char> getStartConfig();
	string stringFromConfig(vector<char>&);
        Mylloyd(int,int,vector<char>,vector<char>);
	vector<char> start_config;
	vector<char> desired_config;
	int width;
	int height;

private:
	inline void swap(vector<char>& config, int x, int y) const
	{
		char temp = config[x];
		config[x] = config[y];
		config[y] = temp;
	};
};

/**
 * The following constructor assigns the values to the variables
 *
 * @param       height              Stores the height
 * @param       width               Stores the width
 * @param       start_config        Stores the start configuration
 * @param       desired_config      Stores the goal configuration
 */

Mylloyd::Mylloyd(int height,int width,vector<char> start_config,vector<char> desired_config)
{
    this->width=width;
    this->height=height;
    this->start_config=start_config;
    this->desired_config=desired_config;
}

/**
 * The following method returns boolean value true if the element is at the top of the vector, else false
 *
 * @return                          Returns boolean value true if the element is at the top of the vector,
 *                                  else false
 */

bool Mylloyd::top(int index)
{
    bool flag=false;
    for(int i=0;i<width;i++){
	if(i==index){
	    flag=true;
	}
    }
    return flag;
}

/**
 * The following method returns boolean value true if the element is at the bottom of the vector, else false
 *
 * @return                          Returns boolean value true if the element is at the bottom of the vector,
 *                                  else false
 */

bool Mylloyd::bottom(int index){
    bool flag=false;
    for(int i=width*height-1;i>(width*height-1)-width;i--){
	if(i==index) flag=true;
    }
    return flag;
}

/**
 * The following method returns boolean value true if the element is at the left of the vector, else false
 *
 * @return                          Returns boolean value true if the element is at the left of the vector,
 *                                  else false
 */

bool Mylloyd::left(int index){
    bool flag=false;
    for(int i=0;i<width*height;i+=width){
	if(i==index) flag=true;
    }
    return flag;
}

/**
 * The following method returns boolean value true if the element is at the right of the vector, else false
 *
 * @return                          Returns boolean value true if the element is at the right of the vector,
 *                                  else false
 */

bool Mylloyd::right(int index){
    bool flag=false;
    for(int i=width-1;i<width*height;i+=width){
	if(i==index) flag=true;
    }
    return flag;
}

/**
 * The following method generates the next possible configurations for the one passed in the argument
 *
 * @param       config              Stores the vector for which the next possible configurations are
 *                                  needed
 *
 * @return                          Returns the vector consisting of next possible configurations
 */

vector< vector<char> > Mylloyd::getNext(vector<char> config){
    vector< vector<char> > next_configs;
    for(int i=0;i<width*height;i++){
        //cout<<"hi ";
	if(config[i] != '.')
	    continue;
	if(!top(i)){
	    vector<char> next = config;
	    swap(next, i,i-width);
	    next_configs.push_back(next);
        }
	if(!bottom(i)){
       	    vector<char> next = config;
	    swap(next, i, i+width);
	    next_configs.push_back(next);
	}
	if(!left(i)){
   	    vector<char> next = config;
	    swap(next, i, i-1);
	    next_configs.push_back(next);
	}
	if(!right(i))
	{
	    vector<char> next = config;
	    swap(next, i, i+1);
	    next_configs.push_back(next);
	}

    }
    return next_configs;
}

/**
 * The following method checks if the current configuration is the desired one or not
 *
 * @param       config              Stores the current configuration
 *
 * @return                          Returns the boolean value depending on whether the
 *                                  current configuration is the desired one or not.
 */

bool Mylloyd::isDesired(vector<char>& config)
{
    if(stringFromConfig(config).compare(stringFromConfig(desired_config))) return false;
    else return true;
}

/**
 * The following method converts the vector into a string
 *
 * @param       config          Stores the current configuration
 *
 * @return                      Returns the string value
 *
 */

string Mylloyd::stringFromConfig(vector<char>& config)
{
    string str(config.begin(), config.end());
    return str;
}


#endif

/** Revisions:
 *
 * $Log: Mylloyd.h,v $
 * Version 1.1      2014/12/04 04:31:59  Dinesh
 * Added condition to check for invalid arguments
 *
 * Initial Version  2014/11/20 12:55:02  Dinesh
 *
 */
