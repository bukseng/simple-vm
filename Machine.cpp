#include "Machine.h"



Instruction Machine::parse(const std::string& line) const{

}

void Machine::loadInstruction(Instruction instruction){
	ins[ins_ptr++] = instruction;
}

void Machine::reset(){
	ins_ptr = 0;
}