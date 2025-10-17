/*
 * Problem statement: Need to create following pattern
 *  1   2   3       1   2   3   4       1   2   3   4   5
 *  8   9   4       12  13  14  5       16  17  18  19  6
 *  7   6   5       11  16  15  6       15  24  25  20  7
 *                  10  9   8   7       14  23  22  21  8
 *                                      13  12  11  10  9
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void print(const vector<vector<int>>& fullSquare)
{
    for (const auto& row : fullSquare)
    {
        for (const auto& element : row)
        {
            cout << element << "\t";
        }
        cout << "\n";
    }
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Usage: <program> <square_size>\n";
        exit(1);
    }

    int reqdSquareSize = atoi(argv[1]);

    vector<vector<int>> fullSquare(reqdSquareSize, vector<int>(reqdSquareSize, 0));

    enum class Direction
    {
        Right,
        Down,
        Left,
        Up
    };

    Direction currDir = Direction::Right;
    int currMaxRowCol = reqdSquareSize;
    int currSquareSize = reqdSquareSize;

    int currNmbr = 1;
    /*
     * This loop represents number of concentric squares
     * concentric squares will always be half of required square size
     */
    int maxSquares =  reqdSquareSize/ 2;
    for (int squareNmbr = 1 ; squareNmbr <= maxSquares ; ++squareNmbr)
    {
        /*
         * row and col here represents starting location of each square
         * each square will always start with (1,1) or (2,2) or (3,3) ...
         */
        int row = squareNmbr;
        int col = squareNmbr;

        int currMaxElements = 4 * (currSquareSize - 1); // same as n^2 - (n-2)^2

        for (int j = 1 ; j <= currMaxElements ; ++j)
        {
            fullSquare[row - 1][col - 1] = currNmbr++;

            switch (currDir)
            {
                case Direction::Right: ++col; break;
                case Direction::Down: ++row; break;
                case Direction::Left: --col; break;
                case Direction::Up: --row; break;
            }

            if (col == currMaxRowCol && currDir == Direction::Right)
            {
                currDir = Direction::Down;
            }

            if (col == squareNmbr && currDir == Direction::Left)
            {
                currDir = Direction::Up;
            }

            if (row == currMaxRowCol && currDir == Direction::Down)
            {
                currDir = Direction::Left;
            }

            if (row == squareNmbr && currDir == Direction::Up)
            {
                currDir = Direction::Right;
            }
        }
        currMaxRowCol--;
        currSquareSize -= 2;
    }

    /*
     * Special condition for odd square size to put the center value
     */
    if (reqdSquareSize % 2 != 0)
    {
        const int center = (1 + reqdSquareSize) / 2;
        fullSquare[center - 1][center - 1] = pow(reqdSquareSize, 2);
    }

    print(fullSquare);
}
