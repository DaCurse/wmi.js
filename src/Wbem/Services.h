#pragma once

#include "QueryResultEnumerator.h"

#include <string>
#include <Wbemidl.h>
#include <comutil.h>

namespace WmiJS::Wbem
{
  class Services
  {
  private:
    IWbemServices *mWbemServices;

  public:
    explicit Services() = delete;
    explicit Services(IWbemServices *wbemServices);
    ~Services();

    [[nodiscard]] QueryResultEnumerator query(const std::string &queryRequest);

  private:
    [[nodiscard]] QueryResultEnumerator query(const bstr_t &&queryRequest);
  };
}
