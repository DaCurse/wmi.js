#include "QueryResultEnumerator.h"

using namespace WmiJS::Wbem;

static const QueryResultObject NULL_QUERY_RESULT = QueryResultObject(nullptr);

QueryResultEnumerator::QueryResultEnumerator(IEnumWbemClassObject *queryResultEnumerator)
    : mQueryResultEnumerator(queryResultEnumerator), mNextQueryResultObject(getNextQueryResult())
{
}

QueryResultEnumerator::~QueryResultEnumerator()
{
  if (nullptr != mQueryResultEnumerator)
  {
    mQueryResultEnumerator->Release();
  }
  mQueryResultEnumerator = nullptr;
}

QueryResultObject QueryResultEnumerator::next()
{
  if (hasEnded())
  {
    throw 0 /* TODO: add exception */;
  }

  QueryResultObject returnValue = mNextQueryResultObject;
  mNextQueryResultObject = getNextQueryResult();

  return returnValue;
}

bool QueryResultEnumerator::hasEnded() const
{
  return NULL_QUERY_RESULT == mNextQueryResultObject;
}

QueryResultObject QueryResultEnumerator::getNextQueryResult()
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
    return QueryResultObject(nullptr);
  }

  return QueryResultObject(queryResultObject);
}