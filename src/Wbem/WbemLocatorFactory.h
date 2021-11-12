#pragma once

#include "WbemLocator.h"

namespace WmiJS
{
  class WbemLocatorFactory
  {
    explicit WbemLocatorFactory() = default;
    WbemLocator createWbemLocator();
  };
}
