#include "tokenizer.h"

vector<string> PiscesTokenizer::Tokenize(string input) {
	vector<string> tmp;
	if (input == "" || input.find_first_of("//") < 2)
		return tmp;

	string tstr = "";

	for (int i = 0; i < input.length(); i++) {
		if (!isSeparator(input[i]))
			tstr += input[i];
		else {
			if (tstr.substr(0, 2) == "//")
				break;
			tmp.emplace_back(tstr);
			ChumPrint("PiscesTokenizer::Tokenize: Added '" + tstr + "' to return vector.");
			tstr = "";
		}
	}

	if (tstr.substr(0, 2) != "//")
		tmp.emplace_back(tstr);

	return tmp;
} 

bool PiscesTokenizer::isSeparator(char c) {
	if (separators.find(c) == string::npos)
		return false;
	return true;
}