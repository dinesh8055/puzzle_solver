/**
 * clock.cpp
 *
 * @ Version:
 *     $Id: clock.cpp , Version 1.2 12/4/2014 $
 *
 */

#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

/**
 * This program takes the present clock hand reading and maximum number
 * of hours and shows the shortest path to the goal configuration
 *
 * @author      Rithvik Gambhir
 * @author      Dinesh Gudi
 */

void getUserData();
int solve(int, int, int);
queue <int> getClockwise(int, int, int);
queue <int> getAntiClockwise(int, int, int);
void display(queue <int>);

/**
 * The following method takes the input from the user and checks of the inputs
 * are invalid or not. It then calls the method to solve the puzzle
 */

void getUserData()
{
    int clock, start, goal;

    cout << "Enter number of hours in clock" << endl;
    cin >> clock;

    cout << "Enter the present clock hour" << endl;
    cin >> start;

    cout << "Enter the goal hour" << endl;
    cin  >> goal;

    if (     (start > clock) || (goal > clock) || (start <= 0) || (clock <= 0) || (goal <= 0)     )
    {
        cout << "Invalid inputs, terminating program" << endl;
        exit(0);
    }

    solve(clock, start, goal);
}

/**
 * The following method solves the clock puzzle
 * The algorithm is as follows:
 * 1. Start configuration is checked if it's the required goal.
 * 2. If not, clockwise rotations and anti-clockwise configurations are generated and stored in a queue.
 * 3. Shortest path is the one with the smaller queue
 * 4. The shorter queue is then displayed as the required steps to reach the goal configuration.
 *
 * @param       clock       Stores the maximum hours in the clock
 * @param       start       Stores the start configuration
 * @param       goal        Stores the final/goal configuration
 *
 * @return                  Returns an integer value 0 when the method is executed or when the start is the
 *                          goal configuration.
 */

int solve(int clock, int start, int goal)
{
    if(start == goal)
    {
        cout << "Success! Already set!" << endl;
        return 0;
    }

    queue <int> clockwise = getClockwise(clock, start, goal);
    queue <int> anti_clockwise = getAntiClockwise(clock, start, goal);

    if(clockwise.size() < anti_clockwise.size())
    {
        cout << "Using clockwise rotations" << endl;
        display(clockwise);
    }

    else if(clockwise.size() > anti_clockwise.size())
    {
        cout << "Using anti-clockwise rotations" << endl;
        display(anti_clockwise);
    }

    else
    {
        cout << "You can turn either clockwise or anti-clockwise for minimum turns" << endl;
        cout << "Using clockwise rotations" << endl;
        display(clockwise);
    }
    return 0;
}

/**
 * The following method generates the possible clockwise rotations for the given start configuration
 * and returns the queue of configurations.
 *
 * @param       clock       Stores the maximum hours in the clock
 * @param       start       Stores the start configuration
 * @param       goal        Stores the final/goal configuration
 *
 * @return                  Returns the queue consisting of generated clockwise configurations
 */

queue <int> getClockwise(int clock, int start, int goal)
{
    queue <int> clockwise;

    if(start > goal)
    {
        for(int i = start; i <= clock; i++)
            clockwise.push(i);

        for(int i = 1; i <= goal; i++)
            clockwise.push(i);
    }

    for(int i = start; i <= goal; i++)
    {
        clockwise.push(i);
    }

    return clockwise;
}

/**
 * The following method generates the possible anti-clockwise rotations for the given start configuration
 * and returns the queue of configurations.
 *
 * @param       clock       Stores the maximum hours in the clock
 * @param       start       Stores the start configuration
 * @param       goal        Stores the final/goal configuration
 *
 * @return                  Returns the queue consisting of generated anti-clockwise configurations
 */

queue <int> getAntiClockwise(int clock, int start, int goal)
{
    queue <int> anti_clockwise;

    if(start < goal)
    {
        for(int i = start; i > 0; i--)
            anti_clockwise.push(i);

        for(int i = clock; i >= goal; i--)
            anti_clockwise.push(i);
    }

    for(int i = start; i >= goal; i--)
    {
        anti_clockwise.push(i);
    }

    return anti_clockwise;
}

/**
 * The following method prints the contents of the queue
 *
 * @param       output      Stores the queue for which the printing is required
 */

void display(queue <int> output)
{
    while(output.size() != 0)
    {
        cout << output.front() << endl;
        output.pop();
    }
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
 * $Log: clock.cpp,v $
 * Version 1.2    2014/12/2 13:42:57  Rithvik
 * Added method getUserData();
 *
 * Version 1.1    2014/11/30 04:49:35 Rithvik
 * Added condition to deal with 0 in anti-clockwise rotations
 *
 * Initial Version 2014/11/24 02:19:30 Rithvik
 */
