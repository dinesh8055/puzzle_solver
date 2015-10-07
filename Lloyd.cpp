/**
 * Lloyd.cpp
 *
 * @ Version:
 *     $Id: Lloyd.cpp , Version 1.2 12/4/2014 $
 *
 */

#include<iostream>
#include<fstream>
#include "Mylloyd.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <cassert>
#include <unistd.h>

using namespace std;

/**
 * This program solves Lloyd's puzzle
 *
 * @author      Rithvik Gambhir
 * @author      Dinesh Gudi
 */

int solve(Mylloyd&);
void display(vector<char>,int,int);

/**
 * The following takes in the input from the file and calls the solver
 *
 * @param       argc        Stores the number of string arguments given as inputs
 * @param       argv        Stores the filename with relative path
 *
 * @return                  Returns integer value 0
 */

int main(int argc, char** argv){
    if(argc != 2)
    {
	cerr << "Illegal number of arguments.\n"
	     << "Input in following format:\n"
	     << "./a.out <input-file> <output-file>\n"
	     <<endl;
	exit(1);
    }
    string x,y,file;
    int width,height,size;
    vector<char> init_cfg;
    vector<char> final_cfg;
    ifstream myfile(argv[1]);
    myfile>>x;
    myfile>>y;
    width=atoi(x.c_str());
    height=atoi(y.c_str());
    size=width*height;
    init_cfg.resize(size);
    final_cfg.resize(size);
    for(int i=0;i<height;i++){
	for(int j=0;j<width;j++){
            myfile>>init_cfg[i*width+j];
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
	    myfile>>final_cfg[i*width+j];
        }
    }

    Mylloyd l(height,width,init_cfg,final_cfg);
    cout<<endl<<"Please wait...."<<endl;
    solve(l);
    return(0);
}

/**
 * The following method displays the vector configuration of given width and height
 *
 * @param       config      Stores the configuration
 * @param       height      Stores the height
 * @param       width       Stores the width
 */

void display(vector<char> config,int height,int width){
    for(int i=0;i<height;i++){
	for(int j=0;j<width;j++){
	    cout<<config[i*width+j];
	    cout<<" ";
	}
	cout<<endl;
    }
}

/**
 * The following method solves the puzzle
 * It uses the following algorithm:
 * 1. Start configuration in the given file is pushed onto a list
 * 2. The next possible configurations for the start configuration is then
 *    returned from getNext and is checked one at a time if it meets the
 *    goal configuration.
 * 3. The successful configurations leading to the goal are stored in a map
 *    and pushed onto a stack for displaying
 *
 * @param       puzzle      Stores the Lloyd puzzle to be solved
 *
 * @return                  Returns the integer value 0 if goal is not met
 *                          to come out of the function else the method
 *                          continues to print the result from the stack
 *
 */

int solve(Mylloyd& puzzle){
    int flag=0;
    vector<char>* config;
    vector<char> desired;
    list< vector<char> > configs;
    stack< vector<char> > output;
    map< vector<char>,vector<char> > path_map;
    path_map[puzzle.start_config]=puzzle.start_config;
    configs.push_back(puzzle.start_config);
    while(!configs.empty()){
	vector< vector<char> > nextConfigs=puzzle.getNext(configs.front());
	vector<char> currentConfig=configs.front();
        configs.pop_front();
        for(vector< vector<char> >::iterator it=nextConfigs.begin();it!=nextConfigs.end();++it){
	        path_map.insert(make_pair(*it, currentConfig));
                if(puzzle.isDesired(*it)){
	            flag=1;
	            desired=*it;
	            break;
	        }
	        configs.push_back(*it);
	    }
        if(flag==1) break;
    }
    if(!flag){
	cout<<"Not possible!"<<endl;
	return(0);
    }
    config=&desired;
    while(*config!=puzzle.start_config){
	output.push(*config);
	config=&path_map[*config];
    }
    output.push(*config);

    while(!output.empty()){
        cout<<endl;
        display(output.top(),puzzle.height,puzzle.width);
        cout<<endl;
        output.pop();
    }
    return (0);
}

/** Revisions:
 *
 * $Log: Lloyd.cpp,v $
 * Revision 1.2    2014/12/04 11:31:59  Dinesh
 * Added condition to check for invalid arguments
 *
 * Revision 1.1    2014/12/01 01:29:29  Dinesh
 * Added display method
 *
 * Initial Version 2014/11/20 10:32:08 Dinesh
 *
 */
