#include "Services.h"

static const bstr_t QUERY_LANGUAGE_WQL = bstr_t("WQL");
constexpr IWbemContext *DEFAULT_CONTEXT = NULL;

using namespace WmiJS::Wbem;

Services::Services(IWbemServices *wbemServices)
    : mWbemServices(wbemServices)
{
}

Services::~Services()
{
  if (nullptr != mWbemServices)
  {
    mWbemServices->Release();
  }
  mWbemServices = nullptr;
}

QueryResultEnumerator Services::query(const std::string &queryRequest)
{
  return query(std::move(bstr_t(queryRequest.data())));
}

QueryResultEnumerator Services::query(const bstr_t &&queryRequest)
{
  IEnumWbemClassObject *queryResultEnumrator = nullptr;
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

  return QueryResultEnumerator(queryResultEnumrator);
}