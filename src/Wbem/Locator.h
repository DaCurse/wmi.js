#pragma once

#include <string>
#include <comdef.h>

#include "Services.h"

namespace WmiJS::Wbem
{
  class Locator
  {
  private:
    IWbemLocator *mWbemLocator;

  public:
    explicit Locator() = delete;
    explicit Locator(IWbemLocator *wbemLocator);
    ~Locator();

    [[nodiscard]] Services connect(const std::string &wmiNamespace);

  private:
    [[nodiscard]] Services connect(const _bstr_t &&wmiNamespace);
  };
}
