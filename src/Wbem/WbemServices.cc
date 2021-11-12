#include "WbemServices.h"

using WmiJS::WbemServices;

WbemServices::WbemServices(IWbemServices *wbemServices)
    : mWbemServices(wbemServices)
{
}

WbemServices::~WbemServices()
{
  if (nullptr != mWbemServices)
  {
    mWbemServices->Release();
  }
  mWbemServices = nullptr;
}