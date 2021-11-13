#include "WbemServices.h"

static const bstr_t QUERY_LANGUAGE_WQL = bstr_t("WQL");
constexpr IWbemContext *DEFAULT_CONTEXT = NULL;

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

WmiJS::WbemQueryResultEnumerator  WbemServices::query(const std::string& queryRequest)
{
  return query(std::move(bstr_t(queryRequest.data())));
}

WmiJS::WbemQueryResultEnumerator WbemServices::query(const bstr_t&& queryRequest)
{
  IEnumWbemClassObject* queryResultEnumrator = nullptr;
    HRESULT hres = mWbemServices->ExecQuery(
        QUERY_LANGUAGE_WQL, 
        queryRequest,
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, 
        DEFAULT_CONTEXT,
        &queryResultEnumrator);
    
  if (FAILED(hres))
  {
    throw 0 /* TODO: add exception */;
  }

  return WbemQueryResultEnumerator(queryResultEnumrator);
}