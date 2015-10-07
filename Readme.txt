Project 1
The program solves the clock puzzle. It takes the present clock hand reading and maximum number of hours and shows the shortest 
path to the goal configuration. 

The following algorithm is used to solve the puzzle:
 1. Start configuration is checked if it's the required goal.
 2. If not, clockwise rotations and anti-clockwise configurations are generated and stored in a queue.
 3. Shortest path is the one with the smaller sized queue.
 4. The shorter queue is then displayed as the required steps to reach the goal configuration.

 
Project 2
The program solves the water puzzle. It takes the number of buckets and their capacities from the user and the goal water quantity 
to solve the famous water jug puzzle.

The following algorithm is used to solve the puzzle:
 1. Start configuration with buckets empty is pushed onto a queue.
 2. The next possible configurations for the start configuration is then returned from getNextConfig and is checked one at a time 
    if it meets the goal configuration.
 3. The successful configurations leading to the goal are stored in a map and pushed onto a stack for displaying.
 

Project 3
The program solves Lloyd's puzzle. The start and goal configurations are given in the form of a file as command line arguments.

The following algorithm is used to solve the puzzle:
 1. Start configuration in the given file is pushed onto a list
 2. The next possible configurations for the start configuration is then
    returned from getNext and is checked one at a time if it meets the
    goal configuration.
 3. The successful configurations leading to the goal are stored in a map
    and pushed onto a stack for displaying


The first puzzle is a clock. The clock only has an hour hand, where N is the number of hours, which can be turned 
forward or backward one hour at a time (called a step). There are three parameters associated with the clock:

    The number of hours, an integer N
    The start time, an integer from 1..N
    The goal time, an integer from 1..N

The program is run from the command line as:

    -> g++ clock.cpp
	->./a.out {hours} {start} {goal}

The program displays,the shortest number of steps it takes to get from the start to the goal
time. For example:

    ->./a.out 15 2 14
    Step 0:  2
    Step 1:  1
    Step 2:  15
    Step 3:  14

Changes in Solver:
--------------------
Changed vector to queue and implemented map in order to avoid the repeated iterations

Water Puzzle:

Water puzzle accepts 3 arguments from command line.

first argument: goal quantity
second argument: quantity of container 1
third argument: quantity of container 2

The program is run from the command line as:

    -> g++ water.cpp
	->./a.out {goal} {quantity of jug1} {quantity of jug2} . . . 


submission 4:
	
LLoyd puzzle:

Lloyd accepts an input file which has input configuration and goal configuration given as first argument and writes to output file given as second argument.

If the first argument is "-" then input is read from from console.
If the second argument is "-" then output is displayed on console.
If the both the arguments are "-" then input and output is read and displayed by console.

The program is run from the command line as:

    -> g++ lloyd.cpp
	->./a.out inputfile outputfile
	
Changes in water puzzle:
--------------------------
 	
Included a check condition so that the puzzle won't run if the input start time is grater than the maximum time.

Changes in solver:
--------------------------

changed the vector back to queue to improve the performance as the we are deleting the first element every iteration.
	