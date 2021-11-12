#include "WbemLocatorFactory.h"

#include <Wbemidl.h>

#pragma comment(lib, "wbemuuid.lib")

constexpr LPUNKNOWN NOT_PART_OF_AGGREGATE = NULL;

using WmiJS::WbemLocatorFactory;

WmiJS::WbemLocator WbemLocatorFactory::createWbemLocator()
{
  IWbemLocator *wbemLocator = nullptr;

  HRESULT hres = CoCreateInstance(
      CLSID_WbemLocator,
      NOT_PART_OF_AGGREGATE,
      CLSCTX_INPROC_SERVER,
      IID_IWbemLocator,
      (LPVOID *)&wbemLocator);

  if (FAILED(hres))
  {
    throw 0 /* TODO: add exception */;
  }

  return WbemLocator(wbemLocator);
}
