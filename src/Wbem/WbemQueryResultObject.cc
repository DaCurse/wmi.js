#include "WbemQueryResultObject.h"

WmiJS::WbemQueryResultObject::WbemQueryResultObject(IWbemClassObject *queryResult)
    : mQueryResult(queryResult)
{
}

WmiJS::WbemQueryResultObject::~WbemQueryResultObject()
{
  if (nullptr != mQueryResult)
  {
    mQueryResult->Release();
  }

  mQueryResult = nullptr;
}

bool WmiJS::WbemQueryResultObject::operator==(const WbemQueryResultObject &rhs) const
{
  return mQueryResult == rhs.mQueryResult;
}