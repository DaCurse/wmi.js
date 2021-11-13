#include "WbemQueryResultEnumerator.h"

static const WmiJS::WbemQueryResultObject NULL_QUERY_RESULT = WmiJS::WbemQueryResultObject(nullptr);

WmiJS::WbemQueryResultEnumerator::WbemQueryResultEnumerator(IEnumWbemClassObject *queryResultEnumerator)
    : mQueryResultEnumerator(queryResultEnumerator), mNextQueryResultObject(getNextQueryResult())
{
}

WmiJS::WbemQueryResultEnumerator::~WbemQueryResultEnumerator()
{
  if (nullptr != mQueryResultEnumerator)
  {
    mQueryResultEnumerator->Release();
  }
  mQueryResultEnumerator = nullptr;
}

WmiJS::WbemQueryResultObject WmiJS::WbemQueryResultEnumerator::next()
{
  if (hasEnded())
  {
    throw 0 /* TODO: add exception */;
  }

  WmiJS::WbemQueryResultObject returnValue = mNextQueryResultObject;
  mNextQueryResultObject = getNextQueryResult();

  return returnValue;
}

bool WmiJS::WbemQueryResultEnumerator::hasEnded() const
{
  return NULL_QUERY_RESULT == mNextQueryResultObject;
}

WmiJS::WbemQueryResultObject WmiJS::WbemQueryResultEnumerator::getNextQueryResult()
{
  IWbemClassObject *queryResultObject = nullptr;
  ULONG returnCount = 0;

  HRESULT hres = mQueryResultEnumerator->Next(
      WBEM_INFINITE, // Time out
      1L,            // One object
      &queryResultObject,
      &returnCount);

  if (FAILED(hres))
  {
    throw 0 /* TODO: add exception */;
  }

  if (0 == returnCount)
  {
    return WmiJS::WbemQueryResultObject(nullptr);
  }

  return WmiJS::WbemQueryResultObject(queryResultObject);
}