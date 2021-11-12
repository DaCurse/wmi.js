#pragma once

#include "WbemLocator.h"

namespace WmiJS
{
  class WbemLocatorFactory
  {
  public:
    explicit WbemLocatorFactory() = default;
    WbemLocator createWbemLocator();
  };
}
