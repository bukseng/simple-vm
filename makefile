
BOOST_ROOT := /usr/include
BOOST_LIB := /usr/lib

output: svmain.o Machine.o 
	g++ -L$(BOOST_LIB) svmain.o Machine.o -lboost_regex -o output
	
svmain.o: src/svmain.cpp
	g++ -c -I$(BOOST_ROOT) src/svmain.cpp

Machine.o: src/Machine.cpp src/Machine.h src/Instruction.h
	g++ -c -I$(BOOST_ROOT) src/Machine.cpp
	
clean:
	rm *.o output
