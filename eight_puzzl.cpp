

#include<iostream>
#include<fstream>
#include<math.h>

//Beyond Classical search-Steepest hill climbing
using namespace std;

// Move function, To move blocks                                                   
void Moved(int** st, int move)
{
    int i, j;
    // Locate the position of '0' in the 3x3 grid
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (st[i][j] == 0)
                break;
        }
        if (j < 3) break;  // Ensure we break out of both loops once '0' is found
    }
    
    // Make moves based on the 'move' direction
    if (move == 1 && i > 0)  // Move Up
    {
        st[i][j] = st[i - 1][j];
        st[i - 1][j] = 0;
    }
    else if (move == 2 && i < 2)  // Move Down
    {
        st[i][j] = st[i + 1][j];
        st[i + 1][j] = 0;
    }
    else if (move == 3 && j > 0)  // Move Left
    {
        st[i][j] = st[i][j - 1];
        st[i][j - 1] = 0;
    }
    else if (move == 4 && j < 2)  // Move Right
    {
        st[i][j] = st[i][j + 1];
        st[i][j + 1] = 0;
    }
}


// To print best move result
void Moved_Result(int** st, int move)
{
    int g = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (*(*(st + i) + j) == 0)
            {
                if (move == 1)
                {
                    cout << *(*(st + (i - 1)) + j) << " down" << endl;
                    *(*(st + i) + j) = *(*(st + (i - 1)) + j);
                    *(*(st + (i - 1)) + j) = 0;
                    g = 1;
                    break;
                }
                else if (move == 2)
                {
                    cout << *(*(st + (i + 1)) + j) << " up" << endl;
                    *(*(st + i) + j) = *(*(st + (i + 1)) + j);
                    *(*(st + (i + 1)) + j) = 0;
                    g = 1;
                    break;
                }
                else if (move == 3)
                {
                    cout << *(*(st + i) + (j - 1)) << " right" << endl;
                    *(*(st + i) + j) = *(*(st + i) + (j - 1));
                    *(*(st + i) + (j - 1)) = 0;
                    g = 1;
                    break;
                }
                else
                {
                    cout << *(*(st + i) + (j + 1)) << " left" << endl;
                    *(*(st + i) + j) = *(*(st + i) + (j + 1));
                    *(*(st + i) + (j + 1)) = 0;
                    g = 1;
                    break;
                }
            }
        }

        if (g == 1)
        {
            break;
        }
    }
}

// To calculate Manhattan Distance
int manhattan_dist(int** i, int** j)
{
    int m = 0;
    for (int p = 0; p < 3; p++)
    {
        for (int q = 0; q < 3; q++)
        {
            if (*(*(i + p) + q) > 0)
            {
                for (int u = 0; u < 3; u++)
                {
                    for (int v = 0; v < 3; v++)
                    {
                        if (*(*(j + u) + v) == *(*(i + p) + q))
                        {
                            m = m + (abs(p - u) + abs(q - v));
                        }
                    }
                }
            }
        }
    }

    return m;
}

// To traverse the parent
int TraverseSuccessor(int** a, int** b, int move)
{
    int** st = new int* [3];

    for (int p = 0; p < 3; p++)
    {
        st[p] = new int[3];

        for (int q = 0; q < 3; q++)
        {
            *(*(st + p) + q) = *(*(a + p) + q);
        }
    }

    Moved(st, move);

    int m = manhattan_dist(st, b);

    for (int p = 0; p < 3; p++)
    {
        delete[] st[p];
    }

    delete[] st;
    return m;
}

// To print each state
void PrintStates(int** arr)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Steepest Hill Climbing Function
void Hill_Climbing(int** src, int** des, int p)
{
    int array[4] = { 555,555,555,555 };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (*(*(src + i) + j) == 0)
            {
                if (i > 0 && p != 2)
                {
                    array[0] = TraverseSuccessor(src, des, 1);
                }
                if (i < 2 && p != 1)
                {
                    array[1] = TraverseSuccessor(src, des, 2);
                }
                if (j > 0 && p != 4)
                {
                    array[2] = TraverseSuccessor(src, des, 3);
                }
                if (j < 2 && p != 3)
                {
                    array[3] = TraverseSuccessor(src, des, 4);
                }
            }
        }
    }

    int k = 555;
    int x = 0;

    for (int i = 0; i < 4; i++)
    {
        if (array[i] < k)
        {
            k = array[i];
            x = i + 1;
        }
    }

    Moved_Result(src, x);

    PrintStates(src);

    if (k == 0)      // Checking whether we reach the goal or not
    {
        cout << "Goal state found." << endl;

        return;
    }
    else
        Hill_Climbing(src, des, x);
}

int main()
{
    int** initial = new int* [3];
    int** goal = new int* [3];

    for (int a = 0; a < 3; a++)
    {
        initial[a] = new int[3];
    }

    for (int a = 0; a < 3; a++)
    {
        goal[a] = new int[3];
    }

    // Input the initial state
    cout << "Enter the initial state (3x3 grid):" << endl;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            cin >> initial[a][b];
        }
    }

    // Input the goal state
    cout << "Enter the goal state (3x3 grid):" << endl;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            cin >> goal[a][b];
        }
    }

    // Print the initial state
    cout << "Initial State: " << endl;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            cout << *(*(initial + a) + b) << " ";
        }

        cout << endl;
    }

    cout << endl;

    // Perform Hill Climbing
    Hill_Climbing(initial, goal, 0);

    // Cleanup dynamic memory
    for (int a = 0; a < 3; a++)
    {
        delete[] initial[a];
        delete[] goal[a];
    }

    delete[] initial;
    delete[] goal;

    return 0;
}
