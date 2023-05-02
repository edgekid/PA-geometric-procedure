##Requirements

In order to build the project the latest version of GNU MP (The GNU Multiple Precision Arithmetic Library) is needed.

##Installation

##For Linux

#Clone the repo

git clone https://github.com/edgekid/PA-geometric-procedure.git

#Build the project by running

make

#To run, type

./geometric_procedure.exe

##For Windows

#Clone the repo

git clone https://github.com/edgekid/PA-geometric-procedure.git

#Build the project by running

make

#To run, type

./geometric_procedure.exe

##Using the software

Currently the software supports no frontend. That is, there is no type checking and parser implemented for a formula in Presburger Arithmetic. In order for the user to use the software, they will need to hardcode a formula in the internal representation of the program inside geometric_procedure.cpp and call the appropriate functions. Inputs that are not in Prenex normal form with only existential quantifiers have not been tested.

We represent formulas as trees where each node is an instance of the class geometric::SENode. Their implementation can be found in semilinear_expression.h

To instantiate a node, there are two constructors available:

SENode(int dim, short op= 0, bool complement = false, SENode* left = nullptr, SENode* right = nullptr);
SENode(int dim, const vector<Integer>& v, short op = 0, bool complement = false, SENode* left = nullptr, SENode* right = nullptr);

dim - represents the number of variables the overall formula has +1. That is, if the formula has 2 variables, dim needs to be 3
op - has the meaning given in semilinear_set.h file
complement - if set to true, complements the semilinear set represented by SENode after performing the operation op on it.
left, right - represent left and right children. Note that for a node which represent an existence quantifier only the left child is taken into account.
the vector v represents a vector of size dim + 1 and represents a linear inequality as: v_1 * x_1 + v_2 * x_2 + ... + v_d * x_d >= -v_{dim+1}

In order to compute the formula, call the function ComputeSubtree on the root SENode of the formula. 

To get the generator representation of the whole solution set, call PrintSolutions() to the root SENode of the formula.
To get only one of the solutions, call GetSolution().

Examples are given in geometric_procedure.exe in the functions test1() and test2(). Images of the solutions for each of the tests is given in the /tests folder, where the highlitghted points are the solutions.

