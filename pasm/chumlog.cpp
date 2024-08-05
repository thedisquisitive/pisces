#include "chumlog.h"

void ChumPrint(string s) {
#ifdef ENABLE_CHUMMING
	cout << s << endl;
#endif
}