[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6116041&assignment_repo_type=AssignmentRepo)

# **N-Queens Problem - Team Satoshi**
## Members
- **AsulconS** - Adrian Rolando Bedregal Vento
- **Porotocorn** - Yober Maycol Mendoza Surco

## Compile Instructions
We use CMake in order to accomplish the compile tasks easily.
Instructions are simple; once in the source directory, configure by running:
```batch
mkdir build
cd build
cmake ..
```
If you are on *Windows*, CMake may deal with compiling.
### **Note**: Select Release Config in order to get Optimized Version.
```batch
cmake --build ./build --config [Debug, Release] --target ALL_BUILD
```
But if you are on *Linux*, just run the makefile command:
```shell
make
```

## Execution Instructions
Target Executable file follows a simple structure:
```
./nqueens --problemType [all, find] -N <number_of_queens>
```
For example, this would be a valid command:
```
./nqueens --problemType all -N 8
./nqueens -N 4 --problemType find
```

## Plotting Solution
Solution will be exported as a *dot* file format, so
if you have the *dot* program in your PATH, you may run:
```
dot -Tpng -O solution.dot
```
