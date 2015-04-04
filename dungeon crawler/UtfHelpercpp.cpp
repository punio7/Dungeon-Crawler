#include <stdlib.h>
#include <string>
#include "atlbase.h"
#include "atlstr.h"
#include "comutil.h"
#include "UtfHelper.h"

using namespace std;

//char* wcharToMultibyteChar(wchar_t* source)
//{
//}

// Convert char* string to a wchar_t* string.
wchar_t* multibyteCharToWchar(char* source)
{
	size_t newsize = strlen(source) + 1;
	size_t convertedChars = 0;
	wchar_t * wcstring = new wchar_t[newsize];
	mbstowcs_s(&convertedChars, wcstring, newsize, source, _TRUNCATE);

	return wcstring;
}