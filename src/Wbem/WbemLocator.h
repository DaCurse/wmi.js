#pragma once

#include <string>
#include <comdef.h>

#include "WbemServices.h"

namespace WmiJS
{

  class WbemLocator
  {
  private:
    IWbemLocator *mWbemLocator;

  public:
    explicit WbemLocator() = delete;
    explicit WbemLocator(IWbemLocator *wbemLocator);
    ~WbemLocator();

    [[nodiscard]] WbemServices connect(const std::string &wmiNamespace);

  private:
    [[nodiscard]] WbemServices connect(const _bstr_t &&wmiNamespace);
  };

}
