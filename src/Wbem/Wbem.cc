#include "Wbem.h"

#include <comdef.h>

constexpr PSECURITY_DESCRIPTOR DEFAULT_SECURITY_DESCRIPTOR = NULL;
constexpr LONG DEFAULT_AUTHENTICATION_SERVICES_COUNT = -1;
constexpr SOLE_AUTHENTICATION_SERVICE *DEFAULT_AUTHENTICATION_SERVICE = NULL;
constexpr void *DEFAULT_AUTHENTICATION_INFO = NULL;

static void initializeThread()
{
  HRESULT hres;

  hres = CoInitializeEx(NULL, COINIT_MULTITHREADED);

  if (FAILED(hres))
  {
    throw 0 /* TODO: add exception */;
  }
}

void WmiJS::Wbem::initialize()
{
  initializeThread();

  HRESULT hres = CoInitializeSecurity(
      DEFAULT_SECURITY_DESCRIPTOR,
      DEFAULT_AUTHENTICATION_SERVICES_COUNT,
      DEFAULT_AUTHENTICATION_SERVICE,
      NULL,
      RPC_C_AUTHN_LEVEL_DEFAULT,
      RPC_C_IMP_LEVEL_IMPERSONATE,
      DEFAULT_AUTHENTICATION_INFO,
      EOAC_NONE,
      NULL);

  if (FAILED(hres))
  {
    throw 0 /* TODO: add exception */;
  }
}

void WmiJS::Wbem::uninitialize()
{
  CoUninitialize();
}