# AlgorithmDS

Compiling and linking CPP
gcc *.cpp -lstdc++
g++ *.cpp -o *.o

Running 
./*.out

Learnings from compiler error
1) If function is declared, but not defined may cause compilation issues
   Example:
   ~dtor(); // dtor declaratiom
            // hence needs a definition
   Use
   ~dtor() {} // definition with the no functionality
2) For nested Class and enclosed Class
   A nested class is a class which is declared in another enclosing class. 
   A nested class is a member and as such has the same access rights as any other member. 
   The members of an enclosing class have no special access to members of a nested class; the usual access rules shall be obeyed. 
3) To access private variables
   use a get function to access it.
