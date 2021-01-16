
BOOST_INC := /usr/local/boost_1_66_0

output: svmain.o Machine.o 
	g++ -std=c++17 -I${BOOST_INC} svmain.o Machine.o -o output
	
svmain.o: svmain.cpp
	g++ -std=c++17 -c -I${BOOST_INC} svmain.cpp

Machine.o: Machine.cpp Machine.h Instruction.h
	g++ -std=c++17 -c -I${BOOST_INC} Machine.cpp
	
clean:
	rm *.o output
