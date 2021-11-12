#include <node.h>
#include "WbemClient.h"

namespace WmiJS
{

  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void Test(const FunctionCallbackInfo<Value> &args)
  {
    WbemClient wbemClient;
    wbemClient.connect(L"ROOT\\CIMV2");
    wbemClient.disconnect();
    const char *result = wbemClient.isConnected() ? "Connected" : "Not Connected";

    Isolate *isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, result).ToLocalChecked());
  }

  void Initialize(Local<Object> exports)
  {
    NODE_SET_METHOD(exports, "test", Test);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}
