#include "WbemClient.h"

using WmiJS::WbemClient;

WbemClient::WbemClient()
    : mWbemLocator(NULL),
      mWbemServices(NULL)
{
  HRESULT hres;

  hres = CoInitializeEx(0, COINIT_MULTITHREADED);

  if (FAILED(hres))
  {
    throw 0;
  }

  hres = CoInitializeSecurity(
      NULL,
      -1,                          // COM authentication
      NULL,                        // Authentication services
      NULL,                        // Reserved
      RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication
      RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation
      NULL,                        // Authentication info
      EOAC_NONE,                   // Additional capabilities
      NULL                         // Reserved
  );

  if (FAILED(hres))
  {
    throw 0;
  }

  hres = CoCreateInstance(
      CLSID_WbemLocator,
      0,
      CLSCTX_INPROC_SERVER,
      IID_IWbemLocator, (LPVOID *)&this->mWbemLocator);

  if (FAILED(hres))
  {
    throw 0;
  }
}

WbemClient::~WbemClient()
{
  if (this->mWbemLocator != NULL)
    this->mWbemLocator->Release();
  if (this->mWbemServices != NULL)
    this->mWbemServices->Release();
  CoUninitialize();
}

void WbemClient::connect(const wchar_t *wmiNamespace)
{
  HRESULT hres = mWbemLocator->ConnectServer(
      _bstr_t(wmiNamespace), // Object path of WMI namespace
      NULL,                  // User name. NULL = current user
      NULL,                  // User password. NULL = current
      0,                     // Locale. NULL indicates current
      NULL,                  // Security flags.
      0,                     // Authority (for example, Kerberos)
      0,                     // Context object
      &mWbemServices         // pointer to IWbemServices proxy
  );

  if (FAILED(hres))
  {
    throw 0;
  }

  hres = CoSetProxyBlanket(
      mWbemServices,               // Indicates the proxy to set
      RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
      RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
      NULL,                        // Server principal name
      RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx
      RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
      NULL,                        // client identity
      EOAC_NONE                    // proxy capabilities
  );

  if (FAILED(hres))
  {
    throw 0;
  }
}

void WbemClient::disconnect()
{
  if (!this->isConnected())
    throw 0;

  this->mWbemServices->Release();
  this->mWbemServices = NULL;
}

const bool WbemClient::isConnected() const
{
  return this->mWbemServices != NULL;
}
