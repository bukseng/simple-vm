#include<fstream>
#include "Machine.h"

int main(int argc, char* argv[]){
	if(argc < 2){
		std::cout << "Missing expected argument.\n";
		return 0;
	}
	Machine machine;
	std::string line;
	std::ifstream reader(argv[1]);
	while (std::getline (reader, line)) {
		//machine.loadInstruction(machine.parse(line));
	}
	reader.close();
	return 0;
}