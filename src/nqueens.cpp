/********************************************************************************
 *                                                                              *
 * NQueens - Team Satoshi                                                       *
 * Copyright (c) 2021 Adrian Bedregal & Yober Mendoza                           *
 *                                                                              *
 * This software is provided 'as-is', without any express or implied            *
 * warranty. In no event will the authors be held liable for any damages        *
 * arising from the use of this software.                                       *
 *                                                                              *
 * Permission is granted to anyone to use this software for any purpose,        *
 * including commercial applications, and to alter it and redistribute it       *
 * freely, subject to the following restrictions:                               *
 *                                                                              *
 * 1. The origin of this software must not be misrepresented; you must not      *
 *    claim that you wrote the original software. If you use this software      *
 *    in a product, an acknowledgment in the product documentation would be     *
 *    appreciated but is not required.                                          *
 * 2. Altered source versions must be plainly marked as such, and must not be   *
 *    misrepresented as being the original software.                            *
 * 3. This notice may not be removed or altered from any source distribution.   *
 *                                                                              *
 ********************************************************************************/

#include <utils.hpp>
#include <nqueens.hpp>

#include <vector>
#include <iostream>

namespace nq
{
int h(unsigned char** board, int n)
{
    int score {0};
    for(int i {0}; i < n; ++i)
        for(int j {0}; j < n; ++j)
            if(board[i][j])
                ++score;
    return score;
}

void swingBoard(int ammount, int qi, int qj, unsigned char** board, int n)
{
    int oqv {board[qi][qj]};
    for(int i {0}; i < n; ++i)
        board[i][qj] += ammount;
    for(int j {0}; j < n; ++j)
        board[qi][j] += ammount;
    int minOffset {};
    minOffset = std::min(qi, qj);
    for(int i {qi - minOffset}, j {qj - minOffset}; i < n && j < n; ++i, ++j)
        board[i][j] += ammount;
    minOffset = std::min(n - qi - 1, qj);
    for(int i {qi + minOffset}, j {qj - minOffset}; i >= 0 && j < n; --i, ++j)
        board[i][j] += ammount;
    board[qi][qj] = oqv + ammount;
}

bool findRecApproach(int col, bool** qboard, unsigned char** board, int n)
{
    if(col >= n)
        return true;
    for(int i {0}; i < n; ++i)
    {
        // Safe Position for place
        if(!board[i][col])
        {
            qboard[i][col] = true;
            swingBoard(1, i, col, board, n);
            if(findRecApproach(col + 1, qboard, board, n))
                return true;
            qboard[i][col] = false;
            swingBoard(-1, i, col, board, n);
        }
    }
    return false;
}

void allRecApproach(int col, bool** qboard, unsigned char** board, int n,  std::vector<int>& solution, std::vector<std::vector<int>>& solutions)
{
    if(col >= n)
    {
        solutions.push_back(solution);
        return;
    }
    for(int i {0}; i < n; ++i)
    {
        // Safe Position for place
        if(!board[i][col])
        {
            qboard[i][col] = true;
            swingBoard(1, i, col, board, n);
            solution.push_back(i);
            allRecApproach(col + 1, qboard, board, n, solution, solutions);
            qboard[i][col] = false;
            swingBoard(-1, i, col, board, n);
            solution.pop_back();
        }
    }
}

void solveFor(int n, bool all)
{
    bool** qboard {new bool*[n]};
    unsigned char** board {new unsigned char*[n]};
    for(int i {0}; i < n; ++i)
        qboard[i] = new bool[n] {};
    for(int i {0}; i < n; ++i)
        board[i] = new unsigned char[n] {};

    if(all)
    {
        std::vector<int> solution;
        std::vector<std::vector<int>> solutions;
        allRecApproach(0, qboard, board, n, solution, solutions);
        utils::exportSolutions(n, solutions);
    }
    else
        if(findRecApproach(0, qboard, board, n))
            utils::plot(qboard, n);
        else
            std::cout << "Solution not found for " << n << std::endl;

    for(int i {0}; i < n; ++i)
        delete[] qboard[i];
    for(int i {0}; i < n; ++i)
        delete[] board[i];
    delete[] qboard;
    delete[] board;
}

} // namespace nq
