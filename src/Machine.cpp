#include "Machine.h"

Instruction* Machine::parse(std::string& line){
	toUpper(line);
	std::regex rgx_cmd{"^([A-Z]+)"};
	std::regex rgx_3{"^([A-Z]+)\\s+([A-H])\\s+([A-H])\\s+([A-H])\\s*$"};
	std::regex rgx_2a{"^([A-Z]+)\\s+([A-H])\\s+([A-H])\\s*$"};
	std::regex rgx_2b{"^([A-Z]+)\\s+([A-H])\\s+([\\-0-9]+)\\s*$"};
	std::regex rgx_1a{"^([A-Z]+)\\s+([A-H])\\s*$"};
	std::regex rgx_1b{"^([A-Z]+)\\s+([\\-0-9]+)\\s*$"};
	std::regex rgx_0{"^([A-Z]+)\\s*$"};
	std::regex rgx_none{"^\\s*$"};
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
	}else if(std::regex_search(line, matches, rgx_none)){
		return new Instruction(1);
	}
	
	throw "Invalid command";
}

void Machine::loadInstruction(Instruction* instruction){
	ins[ins_ptr++] = instruction;
}

void Machine::validateInstruction() const{
	if(!ins[ins_ptr - 1]->validate()) throw "Invalid argument/s";
}

void Machine::executeProgram(){
	N = ins_ptr;
	ins_ptr = 0;
	int status = 0;
	while(ins_ptr < N){
		status = executeInstruction();
		if(status >= N || status < 0) throw "Invalid jump";
		if(status == 0){
			ins_ptr++;
		}else{
			ins_ptr = status;
		}
	}
}

int Machine::executeInstruction(){
	int oc = ins[ins_ptr]->opcode;
	char r1 = ins[ins_ptr]->reg1;
	char r2 = ins[ins_ptr]->reg2;
	char r3 = ins[ins_ptr]->reg3;
	int a1 = ins[ins_ptr]->arg1;
	switch(oc){
		case 0:
			return halt();
			break;
		case 1:
			return nop();
			break;
		case 2:
			return read(r1);
			break;
		case 3:
			return write(r1);
			break;
		case 4:
			return jumpr(r1);
			break;
		case 5:
			return jump(a1);
			break;
		case 6:
			return add(r1,r2,r3);
			break;
		case 7:
			return sub(r1,r2,r2);
			break;
		case 8:
			return mul(r1,r2,r3);
			break;
		case 9:
			return div(r1,r2,r3);
			break;
		case 10:
			return mod(r1,r2,r3);
			break;
		case 11:
			return neg(r1,r2);
			break;
		case 12:
			return cpy(r1,r2);
			break;
		case 13:
			return loadr(r1,r2);
			break;
		case 14:
			return storer(r1,r2);
			break;
		case 15:
			return push(r1,r2);
			break;
		case 16:
			return pop(r1,r2);
			break;
		case 17:
			return set(r1,a1);
			break;
		case 18:
			return inc(r1,a1);
			break;
		case 19:
			return dec(r1,a1);
			break;
		case 20:
			return load(r1,a1);
			break;
		case 21:
			return store(r1,a1);
			break;
		case 22:
			return jeqz(r1,a1);
			break;
		case 23:
			return jnez(r1,a1);
			break;
		case 24:
			return jgtz(r1,a1);
			break;
		case 25:
			return jltz(r1,a1);
			break;
		case 26:
			return call(r1,a1);
			break;
		default:
			return 0;
			break;
	}
	return 0;
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

int Machine::add(const char& r1, const char& r2, const char& r3){
	reg[r1-'A'] = reg[r2-'A'] + reg[r3-'A'];
	return 0;
}
	
int Machine::sub(const char& r1, const char& r2, const char& r3){
	reg[r1-'A'] = reg[r2-'A'] - reg[r3-'A'];
	return 0;
}

int Machine::mul(const char& r1, const char& r2, const char& r3){
	reg[r1-'A'] = reg[r2-'A'] * reg[r3-'A'];
	return 0;
}

int Machine::div(const char& r1, const char& r2, const char& r3){
	reg[r1-'A'] = reg[r2-'A'] / reg[r3-'A'];
	return 0;
}

int Machine::mod(const char& r1, const char& r2, const char& r3){
	reg[r1-'A'] = reg[r2-'A'] % reg[r3-'A'];
	return 0;
}

int Machine::neg(const char& r1, const char& r2){
	reg[r1-'A'] = -reg[r2-'A'];
	return 0;
}

int Machine::cpy(const char& r1, const char& r2){
	reg[r1-'A'] = reg[r2-'A'];
	return 0;
}

int Machine::loadr(const char& r1, const char& r2){
	if(reg[r2-'A'] >= MAXN || reg[r2-'A'] < 0) throw "Stack index out of bounds";
	reg[r1-'A'] = stk[reg[r2-'A']];	
	return 0;
}

int Machine::storer(const char& r1, const char& r2){
	if (reg[r2-'A'] >= MAXN  || reg[r2-'A'] < 0) throw "Stack index out of bounds";
	stk[reg[r2-'A']] = reg[r1-'A'];
	return 0;
}

int Machine::push(const char& r1, const char& r2){
	if(reg[r2-'A'] >= MAXN || reg[r2-'A'] < 0) throw "Stack index out of bounds";
	reg[r1-'A'] = stk[reg[r2-'A']];	
	return 0;
}

int Machine::pop(const char& r1, const char& r2){
	if (reg[r2-'A'] >= MAXN  || reg[r2-'A'] < 0) throw "Stack index out of bounds";
	stk[reg[r2-'A']] = reg[r1-'A'];
	return 0;
}

int Machine::inc(const char& r1, const int& a1){
	reg[r1-'A'] += a1;
	return 0;
}

int Machine::dec(const char& r1, const int& a1){
	reg[r1-'A'] -= a1;
	return 0;
}

int Machine::set(const char& r1, const int& a1){
	reg[r1-'A'] = a1;
	return 0;
}

int Machine::jeqz(const char& r1, const int& a1){
	if(reg[r1-'A'] == 0) return a1;
	return 0;
}

int Machine::jnez(const char& r1, const int& a1){
	if(reg[r1-'A'] != 0) return a1;
	return 0;
}

int Machine::jgtz(const char& r1, const int& a1){
	if(reg[r1-'A'] > 0) return a1;
	return 0;
}

int Machine::jltz(const char& r1, const int& a1){
	if(reg[r1-'A'] < 0) return a1;
	return 0;
}

int Machine::call(const char& r1, const int& a1){
	reg[r1-'A'] = ins_ptr + 1;
	return a1;
}

int Machine::load(const char& r1, const int& a1){
	if(a1 >= MAXN || a1 < 0) throw "Stack index out of bounds";
	reg[r1-'A'] = stk[a1];
	return 0;
}

int Machine::store(const char& r1, const int& a1){
	if (a1 >= MAXN  || a1 < 0) throw "Stack index out of bounds";
	stk[a1] = reg[r1-'A'];
	return 0;
}

int Machine::read(const char& r1){
	std::cin >> reg[r1-'A'];
	return 0;
}

int Machine::write(const char& r1){
	std::cout << reg[r1-'A'] << std::endl;
	return 0;
}

int Machine::jumpr(const char& r1){
	return reg[r1-'A'];
}

int Machine::jump(const int& a1){
	return a1;
}

int Machine::halt() const{
	throw "Program halted";
	return 0;
}
int Machine::nop() const{
	std::cout << "do nothing" << std::endl;
	return 0;
}
