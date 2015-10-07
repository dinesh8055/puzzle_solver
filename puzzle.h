/**
 * clock.h
 *
 * @ Version:
 *     $Id: clock.h , Version 1.2 12/4/2014 $
 *
 */

#ifndef PUZZLE_H
#define PUZZLE_H
#include<vector>

using namespace std;

/**
 * This header contains the design template for puzzle solver
 *
 * @author      Rithvik Gambhir
 * @author      Dinesh Gudi
 */
 
template <class T>
class puzzle
{
	
public:
	typedef T config;
	virtual vector<config> getNextAttempts(config&)=0; 	
	virtual bool goalReached(config&)=0;
	virtual config getInitCongif()=0;
	virtual ~puzzle() {};
	
};
#endif