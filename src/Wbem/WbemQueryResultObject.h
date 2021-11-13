#pragma once

#include <WbemCli.h>

namespace WmiJS
{
  class WbemQueryResultObject
  {
  private:
    IWbemClassObject *mQueryResult;

  public:
    explicit WbemQueryResultObject() = delete;
    explicit WbemQueryResultObject(IWbemClassObject *queryResult);
    ~WbemQueryResultObject();

    [[nodiscard]] bool operator==(const WbemQueryResultObject &rhs) const;
  };
}
