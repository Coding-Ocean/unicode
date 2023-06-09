#include <Windows.h>
#include <sstream>

HANDLE HStdout = GetStdHandle(STD_OUTPUT_HANDLE);

void print(const wchar_t* wc_str)
{
	WriteConsoleW(HStdout, wc_str, wcslen(wc_str), NULL, NULL);
}

void print(const std::wstring& wstr)
{
	const wchar_t* wc_str = wstr.c_str();
	WriteConsoleW(HStdout, wc_str, wcslen(wc_str), NULL, NULL);
}

void print(const std::wostringstream& woss)
{
	const std::wstring& wstr = woss.str();
	const wchar_t* wc_str = wstr.c_str();
	WriteConsoleW(HStdout, wc_str, wcslen(wc_str), NULL,NULL);
}
