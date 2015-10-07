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
	
*A sample input file Test.txt is provided. It takes 40 secs to execute.

Changes in water puzzle:
--------------------------
 	
Included a check condition so that the puzzle won't run if the input start time is grater than the maximum time.

Changes in solver:
--------------------------

changed the vector back to queue to improve the performance as the we are deleting the first element every iteration.
	

Note: Compile all the file before running 