#pragma once

#include <comdef.h>
#include <Wbemidl.h>

#pragma comment(lib, "wbemuuid.lib")

namespace WmiJS
{
  class WbemClient
  {
  public:
    WbemClient();
    ~WbemClient();

    void connect(const wchar_t *wmiNamespace);
    void disconnect();
    const bool isConnected() const;

  private:
    IWbemLocator *mWbemLocator;
    IWbemServices *mWbemServices;
  };
}
