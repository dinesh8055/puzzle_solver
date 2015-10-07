/**
 * Solver.h
 *
 * @ Version:
 *     $Id: Solver.h , Version 1.2 12/4/2014 $
 *
 */

#ifndef SOLVER_H
#define SOLVER_H
#include<vector>
#include<queue>
#include<map>
#include"puzzle.h"

using namespace std;

/**
 * This Header contains functions that solve the puzzle
 *
 * @author      Rithvik Gambhir
 * @author      Dinesh Gudi
 */


namespace Solver{

/**
 * The following method solves the puzzle
 * It uses the following algorithm:
 * 1. Start configuration in the given file is pushed onto a queue
 * 2. The next possible configurations for the start configuration is then
 *    returned from getNext and is checked one at a time if it meets the
 *    goal configuration.
 * 3. The successful configurations leading to the goal are stored in a map
 *    and pushed onto a vector for displaying
 *
 * @param       puzzle      Stores the puzzle to be solved
 *
 * @return                  Returns the integer value 0 if goal is not met
 *                          to come out of the function else the method
 *                          continues to print the result from the stack
 *
 */
	template<typename T>	
	vector<T> solve(puzzle<T> &puzzle)
	{
		typedef typename::puzzle<T>::config config; 
		vector<config> current;
		queue< vector<config> > configQueue;
		map<config,config> visited;
		vector<config> nextConfig;
		vector<config> InitConfig;
		InitConfig.push_back(puzzle.getInitCongif());
		vector<config> subsol;
		vector<config> solution;
		
		configQueue.push(InitConfig);
		visited[puzzle.getInitCongif()]=puzzle.getInitCongif();		
		if(puzzle.goalReached(InitConfig.front()))
		{	
			solution.push_back(InitConfig.front());
			return (solution);
		}
		while(!configQueue.empty())
		{
			current=configQueue.front();
			
			configQueue.pop();

			nextConfig=puzzle.getNextAttempts(current.back());
			
			for(typename vector<config>::iterator it=nextConfig.begin();it!=nextConfig.end();++it)
			{
					
				if(visited.find(*it)==visited.end())
				{
					
					visited[*it]=*it;
					subsol.clear();
					
					subsol.insert(subsol.end(),current.begin(),current.end());
						subsol.push_back(*it);
					
					if(puzzle.goalReached(*it))
					{						
						
						solution.insert(solution.end(),subsol.begin(),subsol.end());
						
						return solution;
						
					}
					else
					{	
						configQueue.push(subsol);
						
					}

				}
			}
			
		}		
		
		return solution;
	}
}
#endif
