# Eight-puzzle-solver
    bfs   Breadth-First Search
    dfs   Depth-First Search
    aman  A-Star Search using Manhattan distance heuristic
    aeuc  A-Star Search using Euclidean distance heuristic
    amis  A-Star Search using misplaced tiles count heuristic

    This C++ program implements a Steepest Hill Climbing algorithm to solve a 3x3 sliding puzzle (8-puzzle). The objective is to find a sequence of moves that transforms a given initial state of the puzzle into a goal state.

Key Components:
Move Function (Moved):

Moves the blank tile (represented by 0) in the specified direction (up, down, left, right).
Updates the state of the puzzle based on the move direction and ensures boundaries are respected to avoid out-of-bounds errors.
Move Result Function (Moved_Result):

Performs a move and prints the tile being moved and its direction.
Updates the state of the puzzle and prints it.
Manhattan Distance Function (manhattan_dist):

Computes the Manhattan distance between the current state and the goal state.
The Manhattan distance is the sum of the absolute differences between the current positions and goal positions of all non-zero tiles.
Traverse Successor Function (TraverseSuccessor):

Creates a copy of the current state, applies a move, and calculates the Manhattan distance of the resulting state from the goal state.
Hill Climbing Function (Hill_Climbing):

Executes the steepest hill climbing algorithm to find the goal state.
Evaluates all possible moves, chooses the one with the smallest Manhattan distance, and performs that move iteratively until the goal state is reached.
Main Function:

Initializes the puzzle's initial and goal states.
Reads input from the user for these states.
Calls the hill climbing function to start the solving process.



Output


Enter the initial state (3x3 grid):
3 4 8
1 5 6
7 2 0
Enter the goal state (3x3 grid):
1 2 3
4 5 6
7 8 0
Initial State: 
3 4 8 
1 5 6 
7 2 0 

6 down
3 4 8 
1 5 0 
7 2 6 

8 down
3 4 0 
1 5 8 
7 2 6 

4 right
3 0 4 
1 5 8 
7 2 6 

3 right
0 3 4 
1 5 8 
7 2 6 

1 up
1 3 4 
0 5 8 
7 2 6 

7 up
1 3 4 
7 5 8 
0 2 6 

2 left
1 3 4 
7 5 8 
2 0 6 

5 down
1 3 4 
7 0 8 
2 5 6 

8 left
1 3 4 
7 8 0 
2 5 6 

4 down
1 3 0 
7 8 4 
2 5 6 

3 right
1 0 3 
7 8 4 
2 5 6 

8 up
1 8 3 
7 0 4 
2 5 6 

5 up
1 8 3 
7 5 4 
2 0 6 

2 right
1 8 3 
7 5 4 
0 2 6 

7 down
1 8 3 
0 5 4 
7 2 6 

1 down
0 8 3 
1 5 4 
7 2 6 

8 left
8 0 3 
1 5 4 
7 2 6 

5 up
8 5 3 
1 0 4 
7 2 6 

2 up
8 5 3 
1 2 4 
7 0 6 

7 right
8 5 3 
1 2 4 
0 7 6 

1 down
8 5 3 
0 2 4 
1 7 6 

8 down
0 5 3 
8 2 4 
1 7 6 

5 left
5 0 3 
8 2 4 
1 7 6 

2 up
5 2 3 
8 0 4 
1 7 6 

8 right
5 2 3 
0 8 4 
1 7 6 

5 down
0 2 3 
5 8 4 
1 7 6 

2 left
2 0 3 
5 8 4 
1 7 6 

8 up
2 8 3 
5 0 4 
1 7 6 

5 right
2 8 3 
0 5 4 
1 7 6 

1 up
2 8 3 
1 5 4 
0 7 6 

7 left
2 8 3 
1 5 4 
7 0 6 

5 down
2 8 3 
1 0 4 
7 5 6 

8 down
2 0 3 
1 8 4 
7 5 6 

2 right
0 2 3 
1 8 4 
7 5 6 

1 up
1 2 3 
0 8 4 
7 5 6 

7 up
1 2 3 
7 8 4 
0 5 6 

5 left
1 2 3 
7 8 4 
5 0 6 

8 down
1 2 3 
7 0 4 
5 8 6 

4 left
1 2 3 
7 4 0 
5 8 6 

6 up
1 2 3 
7 4 6 
5 8 0 

8 right
1 2 3 
7 4 6 
5 0 8 

5 right
1 2 3 
7 4 6 
0 5 8 

7 down
1 2 3 
0 4 6 
7 5 8 

4 left
1 2 3 
4 0 6 
7 5 8 

5 up
1 2 3 
4 5 6 
7 0 8 

8 left
1 2 3 
4 5 6 
7 8 0 

Goal state found.
