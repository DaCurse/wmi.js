#pragma once

#include <Wbemidl.h>

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
  };
}
