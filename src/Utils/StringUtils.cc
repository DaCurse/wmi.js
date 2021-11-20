#include "StringUtils.h"

#include <vector>

#include <windows.h>
#include <stringapiset.h>

constexpr DWORD DEAFUALT_FLAGS = 0;
constexpr int NULL_TERMINATING_STRING = -1;
constexpr int REPORT_STRING_SIZE = 0;
constexpr LPCCH DEFAULT_CHAR = NULL;
constexpr LPBOOL DONT_REPORT_USED_DEFAULT_CHAR = NULL;

using namespace WmiJS::Utils;

std::string WmiJS::Utils::utf16ToUtf8(const std::wstring& utf16String) 
{
    int sizeRequired = WideCharToMultiByte(CP_UTF8, 
                                            DEAFUALT_FLAGS, 
                                            utf16String.c_str(), 
                                            NULL_TERMINATING_STRING, 
                                            NULL, 
                                            REPORT_STRING_SIZE, 
                                            DEFAULT_CHAR, 
                                            DONT_REPORT_USED_DEFAULT_CHAR);

    std::vector<char> utf8String(sizeRequired);
    WideCharToMultiByte(CP_UTF8, 
                        DEAFUALT_FLAGS, 
                        utf16String.c_str(), 
                        NULL_TERMINATING_STRING, 
                        &utf8String[0],
                        utf8String.size(), 
                        DEFAULT_CHAR, 
                        DONT_REPORT_USED_DEFAULT_CHAR);
    
    return utf8String.data();
}