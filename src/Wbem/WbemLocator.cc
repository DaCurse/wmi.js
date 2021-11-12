#include "WbemLocator.h"

constexpr BSTR CURRENT_USER_NAME = NULL;
constexpr BSTR CURRENT_USER_PASSWORD = NULL;
constexpr BSTR CURRENT_LOCALE = NULL;
constexpr long DEFAULT_SECURITY_FLAGS = 0;
constexpr BSTR CURRENT_USER_DOMAIN = 0;
constexpr IWbemContext *DEFAULT_WBEM_CONTEXT = NULL;

constexpr BSTR DEFAULT_PRINCIPAL_NAME = NULL;
constexpr RPC_AUTH_IDENTITY_HANDLE CURRENT_PROXY_IDENTITY = NULL;

using WmiJS::WbemLocator;
using WmiJS::WbemServices;

WbemLocator::WbemLocator(IWbemLocator *wbemLocator)
    : mWbemLocator(wbemLocator)
{
}

WbemLocator::~WbemLocator()
{
  if (nullptr != mWbemLocator)
  {
    mWbemLocator->Release();
  }
  mWbemLocator = nullptr;
}

WbemServices WbemLocator::connect(const _bstr_t &&wmiNamespace)
{
  IWbemServices *wbemServices = nullptr;

  HRESULT hres = mWbemLocator->ConnectServer(
      wmiNamespace,
      CURRENT_USER_NAME,
      CURRENT_USER_PASSWORD,
      CURRENT_LOCALE,
      DEFAULT_SECURITY_FLAGS,
      CURRENT_USER_DOMAIN,
      DEFAULT_WBEM_CONTEXT,
      &wbemServices);

  if (FAILED(hres))
  {
    throw 0 /* TODO: add exception */;
  }

  hres = CoSetProxyBlanket(
      wbemServices,
      RPC_C_AUTHN_WINNT,
      RPC_C_AUTHZ_NONE,
      DEFAULT_PRINCIPAL_NAME,
      RPC_C_AUTHN_LEVEL_CALL,
      RPC_C_IMP_LEVEL_IMPERSONATE,
      CURRENT_PROXY_IDENTITY,
      EOAC_NONE);

  if (FAILED(hres))
  {
    throw 0 /* TODO: add exception */;
  }

  return WbemServices(wbemServices);
}

WbemServices WbemLocator::connect(const std::string &wmiNamespace)
{
  return connect(std::move(_bstr_t(wmiNamespace.data())));
}