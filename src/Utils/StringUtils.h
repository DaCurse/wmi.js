#pragma once

#include <string>

namespace WmiJS::Utils
{
    std::string utf16ToUtf8(const std::wstring& utf16string);
}
