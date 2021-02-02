#include "Machine.h"

Instruction* Machine::parse(std::string& line){
	toUpper(line);
	std::regex rgx_cmd{"^([A-Z]+)"};
	std::regex rgx_3{"^([A-Z]+)\\s+([A-Z])\\s+([A-Z])\\s+([A-Z])\\s*$"};
	std::regex rgx_2a{"^([A-Z]+)\\s+([A-Z])\\s+([A-Z])\\s*$"};
	std::regex rgx_2b{"^([A-Z]+)\\s+([A-Z])\\s+([0-9]+)\\s*$"};
	std::regex rgx_1a{"^([A-Z]+)\\s+([A-Z])\\s*$"};
	std::regex rgx_1b{"^([A-Z]+)\\s+([0-9]+)\\s*$"};
	std::regex rgx_0{"^([A-Z]+)\\s*$"};
	std::smatch matches;
	if(std::regex_search(line, matches, rgx_cmd)){
		if(oTable.count(matches.str(1)) == 0) throw "Invalid command";
	}		
	
	if(std::regex_search(line, matches, rgx_3)){
		return new Instruction(oTable[matches.str(1)], matches.str(2)[0], matches.str(3)[0], matches.str(4)[0]);
	}else if(std::regex_search(line, matches, rgx_2a)){
		return new Instruction(oTable[matches.str(1)], matches.str(2)[0], matches.str(3)[0]);
	}else if(std::regex_search(line, matches, rgx_2b)){
		return new Instruction(oTable[matches.str(1)], matches.str(2)[0], std::stoi(matches.str(3)));
	}else if(std::regex_search(line, matches, rgx_1a)){
		return new Instruction(oTable[matches.str(1)], matches.str(2)[0]);
	}else if(std::regex_search(line, matches, rgx_1b)){
		return new Instruction(oTable[matches.str(1)], std::stoi(matches.str(2)));
	}else if(std::regex_search(line, matches, rgx_0)){
		return new Instruction(oTable[matches.str(1)]);
	}
	
	throw "Invalid command";
}

void Machine::loadInstruction(Instruction* instruction){
	ins[ins_ptr++] = instruction;
}

void Machine::reset(){
	ins_ptr = 0;
}

void Machine::toUpper(std::string& str){
	int n = str.size();
	for(int i = 0; i < n; i++){
		str[i] = std::toupper(str[i]);
	}
}

void Machine::initMap(){
	oTable = {
		{"HALT", OpCode::HALT},
		{"READ", OpCode::READ},
		{"WRITE", OpCode::WRITE},
		{"NOP", OpCode::NOP},
		{"SET", OpCode::SET},
		{"INC", OpCode::INC},
		{"DEC", OpCode::DEC},
		{"CPY", OpCode::CPY},
		{"ADD", OpCode::ADD},
		{"SUB", OpCode::SUB},
		{"NEG", OpCode::NEG},
		{"MUL", OpCode::MUL},
		{"DIV", OpCode::DIV},
		{"MOD", OpCode::MOD},
		{"JUMP", OpCode::JUMP},
		{"JUMPR", OpCode::JUMPR},
		{"JEQZ", OpCode::JEQZ},
		{"JNEZ", OpCode::JNEZ},
		{"JGTZ", OpCode::JGTZ},
		{"JLTZ", OpCode::JLTZ},
		{"CALL", OpCode::CALL},
		{"PUSH", OpCode::PUSH},
		{"POP", OpCode::POP},
		{"LOAD", OpCode::LOAD},
		{"STORE", OpCode::STORE},
		{"LOADR", OpCode::LOADR},
		{"STORER", OpCode::STORER}
	};
}