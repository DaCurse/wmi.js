#pragma once

#include <node.h>

#include "Wbem/Wbem.h"

namespace WmiJS
{
  static void initialize()
  {
    Wbem::initialize();
  }

  static void uninitialize(void *)
  {
    Wbem::uninitialize();
  }

  NODE_MODULE_INIT()
  {
    initialize();

    v8::Isolate *isolate = context->GetIsolate();
    node::AddEnvironmentCleanupHook(isolate, uninitialize, nullptr);
  }
}
