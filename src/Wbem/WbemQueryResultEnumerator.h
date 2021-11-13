#pragma once

#include "WbemQueryResultObject.h"

namespace WmiJS
{
    class WbemQueryResultEnumerator
    {
        private:
            IEnumWbemClassObject* mQueryResultEnumerator;
            WbemQueryResultObject mNextQueryResultObject;

        public:
            explicit WbemQueryResultEnumerator() = delete;
            explicit WbemQueryResultEnumerator(IEnumWbemClassObject* queryResultEnumerator);
            ~WbemQueryResultEnumerator();

            [[nodiscard]] WbemQueryResultObject next();
            [[nodiscard]] bool hasEnded() const;
        
        private:
            [[nodiscard]] WbemQueryResultObject getNextQueryResult();
    };
}