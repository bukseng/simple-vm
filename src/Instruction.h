#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class Instruction{	
public:
	Instruction(const int& oc, const char& r1, const char& r2, const char& r3) : opcode(oc), reg1(r1), reg2(r2), reg3(r3), argc(3){}
	Instruction(const int& oc, const char& r1, const char& r2) : opcode(oc), reg1(r1), reg2(r2), argc(2){}
	Instruction(const int& oc, const char& r1, const int& a1) : opcode(oc), reg1(r1), arg1(a1), argc(2){}
	Instruction(const int& oc, const int& a1) : opcode(oc), arg1(a1), argc(1){}
	Instruction(const int& oc, const char& r1) : opcode(oc), reg1(r1), argc(1){}
	Instruction(const int& oc) : opcode(oc), argc(0){}	
	Instruction(){}
	
	int opcode;
	int arg1;
	char reg1;
	char reg2;
	char reg3;
	int argc;
	
	bool validate() const{
		if(opcode == 0 || opcode == 1){
			if(argc == 0) return true;
			return false;
		}else if(opcode > 1 && opcode < 5){
			if(argc == 1 && reg1 != '\0') return true;
			return false;
		}else if(opcode == 5){
			if(argc == 1 && reg1 == '\0' && reg2 == '\0' && reg3 == '\0') return true;
			return false;
		}else if(opcode > 5 && opcode < 11){
			if(argc == 3 && reg1 != '\0' && reg2 != '\0' && reg3 != '\0') return true;
			return false;
		}else if(opcode > 10 && opcode < 17){
			if(argc == 2 && reg1 != '\0' && reg2 != '\0') return true;
			return false;
		}else{
			if(argc == 2 && reg1 != '\0' && reg2 == '\0' && reg3 == '\0') return true;
			return false;
		}
	}
	
};

#endif