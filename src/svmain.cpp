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
	try {
		while (std::getline (reader, line)) {
			machine.loadInstruction(machine.parse(line));
			machine.validateInstruction();
		}		
	}catch(const char* err){
		std::cerr << err << ": " << line <<  std::endl;
	}
	reader.close();
	return 0;
}