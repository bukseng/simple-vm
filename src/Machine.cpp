#include "Machine.h"



Instruction Machine::parse(const std::string& line) const{
	boost::regex expr{"\\w+\\s\\w+"};
}

void Machine::loadInstruction(Instruction instruction){
	ins[ins_ptr++] = instruction;
}

void Machine::reset(){
	ins_ptr = 0;
}