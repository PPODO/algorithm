#pragma once

class Convert {
private:
	int expLen, index;
	char tok, popOp;
	char* convExp;
public:
	Convert();
	void ConvToRPNExp(char*, char**);
	int GetOpPrec(char);
	int WhoPrecOp(char, char);
	int EvalPRNExp(const char[]);
	~Convert();
};