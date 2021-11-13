#pragma once

#include "WbemQueryResultEnumerator.h"

#include <string>
#include <Wbemidl.h>
#include <comutil.h>

namespace WmiJS
{
  class WbemServices
  {
  private:
    IWbemServices *mWbemServices;

  public:
    explicit WbemServices() = delete;
    explicit WbemServices(IWbemServices *wbemServices);
    ~WbemServices();

    [[nodiscard]] WbemQueryResultEnumerator query(const std::string &queryRequest);

  private:
    [[nodiscard]] WbemQueryResultEnumerator query(const bstr_t &&queryRequest);
  };
}
