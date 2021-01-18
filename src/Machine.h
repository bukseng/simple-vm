#ifndef MEMORY_H
#define MEMORY_H
#include "Instruction.h"
#include<iostream>
#include<string>
#include<boost/regex.hpp>
#include<unordered_map>
#define MAXN 1000

enum OpCode {  
	HALT = 0, 
    READ = 1, 
    WRITE = 2,
    NOP = 3,
	SET = 4, 
    INC = 5, 
    DEC = 6,
    CPY = 7,
	ADD = 8, 
    SUB = 9, 
    NEG = 10,
    MUL = 11,
	DIV = 12, 
    MOD = 13, 
    JUMP = 14,
    JUMPR = 15,
    JEQZ = 16,
	JNEZ = 17, 
    JGTZ = 18, 
    JLTZ = 19,
    CALL = 20,
	PUSH = 21, 
    POP = 22, 
    LOAD = 23,
    STORE = 24,
    LOADR = 25,
    STORER = 26
};


class Machine{
	
private:
	Instruction ins[MAXN];
	int stk[MAXN];
	int reg[8];
	int ins_ptr;
	int stk_ptr;
	std::unordered_map<std::string, int> oTable = {
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
	
public:
	Machine(){
		ins_ptr = 0;
		stk_ptr = 0;
	}
	
	void add(const char& r1, const char& r2, const char& r3);
	void sub(const char& r1, const char& r2, const char& r3);
	void mul(const char& r1, const char& r2, const char& r3);
	void div(const char& r1, const char& r2, const char& r3);
	void mod(const char& r1, const char& r2, const char& r3);
	void neg(const char& r1, const char& r2);
	void cpy(const char& r1, const char& r2);
	void inc(const char& r1, const int& a1);
	void dec(const char& r1, const int& a1);
	void set(const char& r1, const int& a1);
	void halt() const;
	void nop() const;
	void read(const char& r1);
	void write(const char& r1);
	void jump(const int& a1);
	void jumpr(const char& r1);
	void jeqz(const char& r1, const int& a1);
	void jnez(const char& r1, const int& a1);
	void jgtz(const char& r1, const int& a1);
	void jltz(const char& r1, const int& a1);
	void call(const char& r1, const int& a1);
	void load(const char& r1, const int& a1);
	void store(const char& r1, const int& a1);
	void loadr(const char& r1, const char& r2);
	void storer(const char& r1, const char& r2);
	void push(const char& r1, const char& r2);
	void pop(const char& r1, const char& r2);
	
	Instruction parse(const std::string& line) const;
	void loadInstruction(Instruction instruction);
	void reset();

};


#endif