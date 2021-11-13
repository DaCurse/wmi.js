#pragma once

#include <napi.h>

#include "Wbem/Wbem.h"

namespace WmiJS
{
  static void uninitialize()
  {
    Wbem::uninitialize();
  }

  Napi::Object initialize(Napi::Env env, Napi::Object exports)
  {
    env.AddCleanupHook(uninitialize);
    Wbem::initialize();

    return exports;
  }

  NODE_API_MODULE(NODE_GYP_MODULE_NAME, initialize)
}
