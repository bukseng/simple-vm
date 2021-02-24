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
	int N;
	std::unordered_map<std::string, int> oTable;
	
public:
	Machine(){
		ins_ptr = 0;
		initMap();
	}
	
	int add(const char& r1, const char& r2, const char& r3);
	int sub(const char& r1, const char& r2, const char& r3);
	int mul(const char& r1, const char& r2, const char& r3);
	int div(const char& r1, const char& r2, const char& r3);
	int mod(const char& r1, const char& r2, const char& r3);
	int neg(const char& r1, const char& r2);
	int cpy(const char& r1, const char& r2);
	int loadr(const char& r1, const char& r2);
	int storer(const char& r1, const char& r2);
	int push(const char& r1, const char& r2);
	int pop(const char& r1, const char& r2);
	int inc(const char& r1, const int& a1);
	int dec(const char& r1, const int& a1);
	int set(const char& r1, const int& a1);
	int jeqz(const char& r1, const int& a1);
	int jnez(const char& r1, const int& a1);
	int jgtz(const char& r1, const int& a1);
	int jltz(const char& r1, const int& a1);
	int call(const char& r1, const int& a1);
	int load(const char& r1, const int& a1);
	int store(const char& r1, const int& a1);
	int read(const char& r1);
	int write(const char& r1);
	int jumpr(const char& r1);
	int jump(const int& a1);
	int halt() const;
	int nop() const;

	Instruction* parse(std::string& line);
	void validateInstruction() const; 
	void loadInstruction(Instruction* instruction);
	int executeInstruction();
	void executeProgram();
	void initMap();
	void toUpper(std::string& str);

};


#endif