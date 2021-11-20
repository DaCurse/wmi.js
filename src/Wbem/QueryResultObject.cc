#include "QueryResultObject.h"

#include <OAIdl.h>
#include <comutil.h>

constexpr long DEFAULT_FLAGS = 0;
constexpr CIMTYPE* NO_CIM_TYPE = NULL;
constexpr long* NO_FLVAOR = NULL;

using namespace WmiJS::Wbem;

QueryResultObject::QueryResultObject(IWbemClassObject *queryResult)
    : mQueryResult(queryResult)
{
}

QueryResultObject::~QueryResultObject()
{
  if (nullptr != mQueryResult)
  {
    mQueryResult->Release();
  }

  mQueryResult = nullptr;
}

bool QueryResultObject::operator==(const QueryResultObject &rhs) const
{
  return mQueryResult == rhs.mQueryResult;
}

QueryResultObjectProperty QueryResultObject::getProperty(std::string propertyName)
{
  VARIANT property;

  HRESULT hres = mQueryResult->Get(_bstr_t(propertyName.data()), 
                                    DEFAULT_FLAGS, 
                                    &property, 
                                    NO_CIM_TYPE, 
                                    NO_FLVAOR);

  return QueryResultObjectProperty(property);
}