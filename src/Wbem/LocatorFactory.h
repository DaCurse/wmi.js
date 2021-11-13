#pragma once

#include "Locator.h"

namespace WmiJS::Wbem
{
  class LocatorFactory
  {
  public:
    explicit LocatorFactory() = default;
    [[nodiscard]] Locator createWbemLocator();
  };
}
