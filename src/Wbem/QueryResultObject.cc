#include "QueryResultObject.h"

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