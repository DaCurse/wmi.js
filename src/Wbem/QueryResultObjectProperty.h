#pragma once

#include <string>
#include <cstdint>
#include <variant>
#include <oaidl.h>

namespace WmiJS::Wbem
{
    using QueryResultObjectPropertyValueType = std::variant<std::monostate, std::uint64_t, std::string>;

    class QueryResultObjectProperty
    {
    private:
        VARIANT mProperty;

    public:
        QueryResultObjectProperty() = delete;
        explicit QueryResultObjectProperty(const VARIANT& property);
        ~QueryResultObjectProperty();

        [[nodiscard]] QueryResultObjectPropertyValueType get();
    };
} 
