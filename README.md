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
