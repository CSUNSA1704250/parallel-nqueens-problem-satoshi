#include <utils.hpp>
#include <nqueens.hpp>

#include <iostream>

int main(int argc, char** argv)
{
    int n;
    bool problemType;
    if(!utils::parseInput(argc, argv, n, problemType))
    {
        std::cout << "Correct Usage:\n";
        std::cout << "./nqueens --problemType [all, find] -N <number_of_queens>";
        std::cout << "\nor\n";
        std::cout << "./nqueens -N <number_of_queens> --problemType [all, find]";
        std::cout << std::endl;
        return 0;
    }
    std::cout << n << " " << problemType << std::endl;

    nq::solveFor(n);

    return 0;
}
