Compile and test the examples like this

g++ -o test -I. -std=c++17 num.cpp serie.cpp example-xxx.cpp
./test

You may want to display the computation related to the handle of the
moves. In this case, you have to define the macro
serieDEBUG_MOVE_CALLS like this

g++ -o test -I. -std=c++17 num.cpp serie.cpp -DserieDEBUG_MOVE_CALLS example-xxx.cpp
./test



