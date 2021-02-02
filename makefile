

output: svmain.o Machine.o 
	g++ svmain.o Machine.o -o output
	
svmain.o: src/svmain.cpp
	g++ -std=c++14 -c src/svmain.cpp

Machine.o: src/Machine.cpp src/Machine.h src/Instruction.h
	g++ -std=c++14 -c src/Machine.cpp
	
clean:
	rm *.o output
