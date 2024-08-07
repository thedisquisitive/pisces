#include "asm.h"

vector<string> PiscesAssembler::getNextLine() {
	string tmp;
	getline(fin, tmp, '\n');
	PiscesTokenizer tokenizer;
	return tokenizer.Tokenize(tmp);
}

unsigned short PiscesAssembler::getByteCode(vector<string> src) {
	unsigned short ret;
	
	/*
	ret = (ret & 0x0F0F) | 0x0X0Y
	Use this format to assign values to ret
	The F's in the (ret & 0x0F0F) are the values that get changed
	*/

	if (src[0] == "CLS" || src[0] == "cls") {
		cout << "CLS - Clear the screen.\n";
		ret = (ret & 0x00F0) | 0x00E0;
	}
	else if (src[0] == "RET" || src[0] == "ret") {
		cout << "RET - Return from subroutine.\n";
		ret = (ret & 0x00FF) | 0x00EE;
	}

	fout.write(reinterpret_cast<char*>(&ret), sizeof(ret));
	return ret;
}