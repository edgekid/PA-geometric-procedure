## Requirements

In order to build the project the latest version of GNU MP (The GNU Multiple Precision Arithmetic Library) is needed.

## Installation

## For Linux

# Clone the repo

git clone https://github.com/edgekid/PA-geometric-procedure.git

# Build the project by running

make

# To run, type

./geometric_procedure.exe

## For Windows

# Clone the repo

git clone https://github.com/edgekid/PA-geometric-procedure.git

# Build the project by running

make

# To run, type

./geometric_procedure.exe

## Using the software

A string given as input is accepted if it is derivable from the grammar specified in parser/LIA.g4, which is a grammar for a fragment in Linear Integer Arithmetic.
Currently the software supports inputs which are formulas that are in Prenex normal form.

To get the generator representation of the whole solution set, call PrintSolutions() to the root SENode of the formula.
To get only one of the solutions, call GetSolution().

Examples are given in geometric_procedure.cpp in the functions test1() and test2(). Images of the solutions for each of the tests is given in the /tests folder, where the highlighted points are the solutions.

