#ifndef MEMORY_H
#define MEMORY_H
#include "Instruction.h"
#include<iostream>
#include<cctype>
#include<regex>
#include<string>
#include<unordered_map>
#define MAXN 1000

enum OpCode {  
	HALT = 0, 
	NOP = 1,
    READ = 2, 
    WRITE = 3,
    JUMPR = 4,
	JUMP = 5,
	ADD = 6, 
    SUB = 7, 
    MUL = 8,
	DIV = 9, 
    MOD = 10, 
	NEG = 11,
    CPY = 12,
    LOADR = 13,
    STORER = 14,
	PUSH = 15, 
    POP = 16, 
	SET = 17, 
    INC = 18, 
    DEC = 19,
	LOAD = 20,
    STORE = 21,
    JEQZ = 22,
	JNEZ = 23, 
    JGTZ = 24, 
    JLTZ = 25,
    CALL = 26

};


class Machine{
	
private:
	Instruction* ins[MAXN];
	int stk[MAXN];
	int reg[8];
	int ins_ptr;
	int stk_ptr;
	std::unordered_map<std::string, int> oTable;
	
public:
	Machine(){
		ins_ptr = 0;
		stk_ptr = 0;
		initMap();
	}
	
	void add(const char& r1, const char& r2, const char& r3);
	void sub(const char& r1, const char& r2, const char& r3);
	void mul(const char& r1, const char& r2, const char& r3);
	void div(const char& r1, const char& r2, const char& r3);
	void mod(const char& r1, const char& r2, const char& r3);
	void neg(const char& r1, const char& r2);
	void cpy(const char& r1, const char& r2);
	void loadr(const char& r1, const char& r2);
	void storer(const char& r1, const char& r2);
	void push(const char& r1, const char& r2);
	void pop(const char& r1, const char& r2);
	void inc(const char& r1, const int& a1);
	void dec(const char& r1, const int& a1);
	void set(const char& r1, const int& a1);
	void jeqz(const char& r1, const int& a1);
	void jnez(const char& r1, const int& a1);
	void jgtz(const char& r1, const int& a1);
	void jltz(const char& r1, const int& a1);
	void call(const char& r1, const int& a1);
	void load(const char& r1, const int& a1);
	void store(const char& r1, const int& a1);
	void read(const char& r1);
	void write(const char& r1);
	void jumpr(const char& r1);
	void jump(const int& a1);
	void halt() const;
	void nop() const;

	Instruction* parse(std::string& line);
	void validateInstruction() const; 
	void loadInstruction(Instruction* instruction);
	void initMap();
	void reset();
	void toUpper(std::string& str);

};


#endif