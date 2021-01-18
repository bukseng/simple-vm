#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class Instruction{
	
private:
	int opcode;
	int arg1;
	char reg1;
	char reg2;
	char reg3;
	
public:
	Instruction(int oc, char r1, char r2, char r3) : opcode(oc), reg1(r1), reg2(r2), reg3(r3){}
	
	Instruction(int oc, char r1, char r2) : opcode(oc), reg1(r1), reg2(r2){}

	Instruction(int oc, char r1, int a1) : opcode(oc), reg1(r1), arg1(a1){}

	Instruction(int oc, int a1) : opcode(oc), arg1(a1){}

	Instruction(int oc, char r1) : opcode(oc), reg1(r1){}
	
	Instruction(int oc) : opcode(oc){}
	
	Instruction(){}
};

#endif