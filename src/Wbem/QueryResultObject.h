#pragma once

#include <WbemCli.h>

#include "QueryResultObjectProperty.h"

namespace WmiJS::Wbem
{
  class QueryResultObject
  {
  private:
    IWbemClassObject *mQueryResult;

  public:
    explicit QueryResultObject() = delete;
    explicit QueryResultObject(IWbemClassObject *queryResult);
    ~QueryResultObject();

    [[nodiscard]] bool operator==(const QueryResultObject &rhs) const;

    [[nodiscard]] QueryResultObjectProperty getProperty(std::string propertyName);
  };
}
