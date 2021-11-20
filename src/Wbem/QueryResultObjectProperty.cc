#include "QueryResultObjectProperty.h"

#include <comdef.h>

#include "Utils/StringUtils.h"

using namespace WmiJS::Wbem;

QueryResultObjectProperty::QueryResultObjectProperty(const VARIANT& property)
    : mProperty(property)
{
}

QueryResultObjectProperty::~QueryResultObjectProperty()
{
    VariantClear(&mProperty);
}

QueryResultObjectPropertyValueType QueryResultObjectProperty::get()
{
    switch(mProperty.vt) {
        case VT_EMPTY: {
            return QueryResultObjectPropertyValueType();
        }
        case VT_I1:
        case VT_I2:
        case VT_I4:
        case VT_I8: {
            return QueryResultObjectPropertyValueType((std::uint64_t)mProperty.llVal);
        }
        case VT_BSTR: {
            return QueryResultObjectPropertyValueType(Utils::utf16ToUtf8(std::wstring(mProperty.bstrVal)));
        }
        default: {
            throw 0 /* TODO: add exception */;
        }
    }
}
