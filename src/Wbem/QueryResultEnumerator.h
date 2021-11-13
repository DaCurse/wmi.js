#pragma once

#include "QueryResultObject.h"

namespace WmiJS::Wbem
{
  class QueryResultEnumerator
  {
  private:
    IEnumWbemClassObject *mQueryResultEnumerator;
    QueryResultObject mNextQueryResultObject;

  public:
    explicit QueryResultEnumerator() = delete;
    explicit QueryResultEnumerator(IEnumWbemClassObject *queryResultEnumerator);
    ~QueryResultEnumerator();

    [[nodiscard]] QueryResultObject next();
    [[nodiscard]] bool hasEnded() const;

  private:
    [[nodiscard]] QueryResultObject getNextQueryResult();
  };
}