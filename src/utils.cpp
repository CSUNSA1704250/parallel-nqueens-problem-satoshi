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

#include <fstream>
#include <iostream>
#include <algorithm>

#define QUEEN_STR "&#9813; "
#define EMPTY_STR "    "

namespace utils
{
bool isNumber(const std::string& s)
{
    return !s.empty() &&
        std::find_if_not(s.begin(), s.end(),
        [](char c) -> bool {
            return std::isdigit(c);
        }) == s.end();
}

bool parseInput(int argc, char** argv, int& n, bool& all)
{
    if(argc != 5)
        return false;

    int ni, pti;
    std::string argv1 {argv[1]};
    std::string argv3 {argv[3]};
    if( argv1 == "--problemType" &&
        argv3 == "-N")
    {
        ni = 4;
        pti = 2;
    }
    else if(argv1 == "-N" &&
            argv3 == "--problemType")
    {
        ni = 2;
        pti = 4;
    }
    else return false;

    std::string nStr {argv[ni]};
    std::string problemTypeStr {argv[pti]};

    if(isNumber(nStr))
        n = std::stoi(nStr);
    else
        return false;

    if(problemTypeStr == "all")
        all = true;
    else if(problemTypeStr == "find")
        all = false;
    else
        return false;

    return true;
}

void promptUser()
{
    std::cout << "Correct Usage:\n";
    std::cout << "./nqueens --problemType [all, find] -N <number_of_queens>";
    std::cout << "\nor\n";
    std::cout << "./nqueens -N <number_of_queens> --problemType [all, find]";
    std::cout << std::endl;
}

void exportSolutions(int n, std::vector<std::vector<int>>& solutions)
{
    std::ofstream out;
    out.open("solutions.txt");
    out << "#Solutions for " << n << " queens" << std::endl;
    out << solutions.size() << std::endl;
    for(const std::vector<int>& solution : solutions)
    {
        for(int i : solution)
            out << i << ' ';
        out << std::endl;
    }
    out.close();
}

void plot(bool** board, int n)
{
    std::ofstream out;
    out.open("solution.dot");

    out <<
    "digraph D {\n"
    "    node [shape = plaintext]\n"
    "\n"
    "    some_node [\n"
    "        label = <\n"
    "            <table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n";

    for(int i {0}; i < n; ++i)
    {
        out << "                <tr>";
        for(int j {0}; j < n; ++j)
        {
            out << "<td>";
            if(board[i][j])
                out << QUEEN_STR;
            else
                out << EMPTY_STR;
            out << "</td>";
        }
        out << "</tr>\n";
    }

    out <<
    "            </table>\n"
    "        >\n"
    "    ];\n"
    "}" << std::endl;

    out.close();
}

} // namespace utils
