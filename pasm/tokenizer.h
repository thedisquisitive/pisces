#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "chumlog.h"

using namespace std;

class PiscesTokenizer {
private:
	string separators = " ,;.";
public:
	PiscesTokenizer() {};
	~PiscesTokenizer() {};

	vector<string> Tokenize(string input);
	bool isSeparator(char c);
};

#endif // TOKENIZER_H_