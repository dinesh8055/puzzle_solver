/**
 * water.cpp
 *
 * @ Version:
 *     $Id: water.cpp , Version 1.1 12/1/2014 $
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <stack>
#include <map>

using namespace std;

/**
 * This program takes the number of buckets and their capacities from the user and
 * the goal water quantity to solve the famous water jug puzzle
 *
 * @author      Rithvik Gambhir
 * @author      Dinesh Gudi
 */

void getUserData();
int solve(int, vector <int>);
void display(vector <int>);
vector < vector <int> > getNextConfig(vector <int>, vector <int> );
bool isDesired(vector <int>, int);

/**
 * The following method takes the input from the user. It then calls the method
 * to solve the puzzle
 */

void getUserData()
{
    vector <int> buckets;
    int no_of_buckets, user_input, goal;

    cout << "Enter number of buckets" << endl;
    cin >> no_of_buckets;

    cout << "Enter bucket capacities" << endl;
    for(int i=0; i<no_of_buckets; i++)
    {
        cin >> user_input;
        buckets.push_back(user_input);
    }

    cout << "Bucket Capacities are as follows" << endl;
    display(buckets);

    cout << "Enter the goal quantity" << endl;
    cin  >> goal;

    solve(goal, buckets);
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

bool isDesired(vector <int> it, int goal)
{
    bool found = false;
    vector <int> :: iterator j;
    for (j = it.begin(); j != it.end(); j++)
    {
        if (*j == goal)
        {
            found = true;
            return found;
        }
    }
    return found;
}

/**
 * The following method solves the puzzle
 * It uses the following algorithm:
 * 1. Start configuration with buckets empty is pushed onto a queue
 * 2. The next possible configurations for the start configuration is then
 *    returned from getNextConfig and is checked one at a time if it meets the
 *    goal configuration.
 * 3. The successful configurations leading to the goal are stored in a map
 *    and pushed onto a stack for displaying
 *
 * @param       goal        Stores the goal configuration i.e. water needed
 * @param       buckets     Stores the capacities of individual buckets
 *
 * @return                  Returns the integer value 0 if goal is not met
 *                          to come out of the function else the method
 *                          continues to print the result from the stack
 *
 */

int solve(int goal, vector <int> buckets)
{
    int flag = 0;
    vector <int> *config;
    vector <int> start_config = vector <int> (buckets.size(), 0);
    vector <int> desired;
    queue < vector<int> > configs;
    stack < vector<int> > output;
    map < vector<int>, vector<int> > path_map;
    path_map[start_config] = start_config;
    configs.push(start_config);

    while(!configs.empty())
    {
        vector < vector<int> > nextConfigs=getNextConfig(configs.front(), buckets);
        vector<int> currentConfig=configs.front();
        configs.pop();
        for(vector< vector<int> >::iterator it=nextConfigs.begin();it!=nextConfigs.end();++it){
            path_map.insert(make_pair(*it, currentConfig));
            if(isDesired(*it, goal))
            {
                flag=1;
                desired=*it;
                break;
            }
            configs.push(*it);
        }
        if(flag==1)
            break;
    }

    if(!flag)
    {
        cout<<"Not possible!";
        return 0;
    }

    config=&desired;
    while(*config!=start_config)
    {
        output.push(*config);
        config=&path_map[*config];
    }
    output.push(*config);

    while(!output.empty())
    {
        display(output.top());
        output.pop();
    }
    return 0;
}

/**
 * The following method generated the next possible moves or configurations
 * for the given current configuration. The possible moves are filling the
 * bucket to the top or emptying a non-empty bucket or pouring the contents
 * into another bucket
 *
 * @param       current_config      Stores the current configuration of the buckets
 * @param       buckets             Stores the maximum capacities of the given
 *                                  buckets
 *
 * @return                          Returns a vector < vector <int> > value of the
 *                                  possible configurations generated
 */

vector < vector <int> > getNextConfig(vector <int> current_config, vector <int> buckets)
{
    vector < vector <int> > next_config;
    int size = current_config.size();
    int i = 0;
    int j = 0;
    int diff = 0;
    for(i = 0; i < size; i++)
    {
        vector <int> next = current_config;
        if(next[i] != buckets[i])
        {
            next[i] = buckets[i];
            next_config.push_back(next);
        }
    }

    for(i = 0; i < size; i++)
    {
        vector <int> next = current_config;
        if(next[i] != 0)
        {
            next[i] = 0;
            next_config.push_back(next);
        }
    }

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            vector <int> next = current_config;
            if(i != j)
            {
                diff = buckets[j] - next[j];
                if( (next[i]-diff)<0 )
                {
                    next[j] = next[i];
                    next[i] = 0;
                    if( next != current_config)
                        next_config.push_back(next);
                }
                else
                {
                    next[j] = next[j] + diff;
                    next[i] = next[i] - diff;
                    if( next != current_config)
                        next_config.push_back(next);
                }
            }
        }
    }

    return next_config;
}

/**
 * The following method prints the contents of the vector
 *
 * @param       configuration       Stores the queue for which the printing is
 *                                  required.
 */

void display(vector <int> configuration)
{
    vector <int> :: iterator j;
    cout << "{ " ;
    for (j = configuration.begin(); j != configuration.end(); j++)
    {
        cout << *j << " ";
    }
    cout << "}" << endl;
}

/**
 * The following main method calls the method to take input from the user
 *
 * @return              Returns integer value 0
 */

int main()
{
    getUserData();
    return 0;
}

/** Revisions:
 *
 * $Log: water.cpp,v $
 * Version 1.1    2014/12/1 10:22:19  Rithvik
 * Added the loops to pour the water from one jug to another
 *
 * Initial Version 2014/11/18 02:19:30 Rithvik
 */
