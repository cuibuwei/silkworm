// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: remote/bor.proto

#include "remote/bor.pb.h"
#include "remote/bor.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace remote {

static const char* BridgeBackend_method_names[] = {
  "/remote.BridgeBackend/Version",
  "/remote.BridgeBackend/BorTxnLookup",
  "/remote.BridgeBackend/BorEvents",
};

std::unique_ptr< BridgeBackend::Stub> BridgeBackend::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< BridgeBackend::Stub> stub(new BridgeBackend::Stub(channel, options));
  return stub;
}

BridgeBackend::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Version_(BridgeBackend_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_BorTxnLookup_(BridgeBackend_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_BorEvents_(BridgeBackend_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status BridgeBackend::Stub::Version(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::types::VersionReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::Empty, ::types::VersionReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Version_, context, request, response);
}

void BridgeBackend::Stub::async::Version(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::types::VersionReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::Empty, ::types::VersionReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Version_, context, request, response, std::move(f));
}

void BridgeBackend::Stub::async::Version(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::types::VersionReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Version_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::types::VersionReply>* BridgeBackend::Stub::PrepareAsyncVersionRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::types::VersionReply, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Version_, context, request);
}

::grpc::ClientAsyncResponseReader< ::types::VersionReply>* BridgeBackend::Stub::AsyncVersionRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncVersionRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status BridgeBackend::Stub::BorTxnLookup(::grpc::ClientContext* context, const ::remote::BorTxnLookupRequest& request, ::remote::BorTxnLookupReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::remote::BorTxnLookupRequest, ::remote::BorTxnLookupReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_BorTxnLookup_, context, request, response);
}

void BridgeBackend::Stub::async::BorTxnLookup(::grpc::ClientContext* context, const ::remote::BorTxnLookupRequest* request, ::remote::BorTxnLookupReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::remote::BorTxnLookupRequest, ::remote::BorTxnLookupReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_BorTxnLookup_, context, request, response, std::move(f));
}

void BridgeBackend::Stub::async::BorTxnLookup(::grpc::ClientContext* context, const ::remote::BorTxnLookupRequest* request, ::remote::BorTxnLookupReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_BorTxnLookup_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::remote::BorTxnLookupReply>* BridgeBackend::Stub::PrepareAsyncBorTxnLookupRaw(::grpc::ClientContext* context, const ::remote::BorTxnLookupRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::remote::BorTxnLookupReply, ::remote::BorTxnLookupRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_BorTxnLookup_, context, request);
}

::grpc::ClientAsyncResponseReader< ::remote::BorTxnLookupReply>* BridgeBackend::Stub::AsyncBorTxnLookupRaw(::grpc::ClientContext* context, const ::remote::BorTxnLookupRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncBorTxnLookupRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status BridgeBackend::Stub::BorEvents(::grpc::ClientContext* context, const ::remote::BorEventsRequest& request, ::remote::BorEventsReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::remote::BorEventsRequest, ::remote::BorEventsReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_BorEvents_, context, request, response);
}

void BridgeBackend::Stub::async::BorEvents(::grpc::ClientContext* context, const ::remote::BorEventsRequest* request, ::remote::BorEventsReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::remote::BorEventsRequest, ::remote::BorEventsReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_BorEvents_, context, request, response, std::move(f));
}

void BridgeBackend::Stub::async::BorEvents(::grpc::ClientContext* context, const ::remote::BorEventsRequest* request, ::remote::BorEventsReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_BorEvents_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::remote::BorEventsReply>* BridgeBackend::Stub::PrepareAsyncBorEventsRaw(::grpc::ClientContext* context, const ::remote::BorEventsRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::remote::BorEventsReply, ::remote::BorEventsRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_BorEvents_, context, request);
}

::grpc::ClientAsyncResponseReader< ::remote::BorEventsReply>* BridgeBackend::Stub::AsyncBorEventsRaw(::grpc::ClientContext* context, const ::remote::BorEventsRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncBorEventsRaw(context, request, cq);
  result->StartCall();
  return result;
}

BridgeBackend::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BridgeBackend_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BridgeBackend::Service, ::google::protobuf::Empty, ::types::VersionReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BridgeBackend::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::Empty* req,
             ::types::VersionReply* resp) {
               return service->Version(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BridgeBackend_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BridgeBackend::Service, ::remote::BorTxnLookupRequest, ::remote::BorTxnLookupReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BridgeBackend::Service* service,
             ::grpc::ServerContext* ctx,
             const ::remote::BorTxnLookupRequest* req,
             ::remote::BorTxnLookupReply* resp) {
               return service->BorTxnLookup(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BridgeBackend_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BridgeBackend::Service, ::remote::BorEventsRequest, ::remote::BorEventsReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BridgeBackend::Service* service,
             ::grpc::ServerContext* ctx,
             const ::remote::BorEventsRequest* req,
             ::remote::BorEventsReply* resp) {
               return service->BorEvents(ctx, req, resp);
             }, this)));
}

BridgeBackend::Service::~Service() {
}

::grpc::Status BridgeBackend::Service::Version(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::types::VersionReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BridgeBackend::Service::BorTxnLookup(::grpc::ServerContext* context, const ::remote::BorTxnLookupRequest* request, ::remote::BorTxnLookupReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BridgeBackend::Service::BorEvents(::grpc::ServerContext* context, const ::remote::BorEventsRequest* request, ::remote::BorEventsReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* HeimdallBackend_method_names[] = {
  "/remote.HeimdallBackend/Version",
  "/remote.HeimdallBackend/Producers",
};

std::unique_ptr< HeimdallBackend::Stub> HeimdallBackend::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< HeimdallBackend::Stub> stub(new HeimdallBackend::Stub(channel, options));
  return stub;
}

HeimdallBackend::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Version_(HeimdallBackend_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Producers_(HeimdallBackend_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status HeimdallBackend::Stub::Version(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::types::VersionReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::Empty, ::types::VersionReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Version_, context, request, response);
}

void HeimdallBackend::Stub::async::Version(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::types::VersionReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::Empty, ::types::VersionReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Version_, context, request, response, std::move(f));
}

void HeimdallBackend::Stub::async::Version(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::types::VersionReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Version_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::types::VersionReply>* HeimdallBackend::Stub::PrepareAsyncVersionRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::types::VersionReply, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Version_, context, request);
}

::grpc::ClientAsyncResponseReader< ::types::VersionReply>* HeimdallBackend::Stub::AsyncVersionRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncVersionRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status HeimdallBackend::Stub::Producers(::grpc::ClientContext* context, const ::remote::BorProducersRequest& request, ::remote::BorProducersResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::remote::BorProducersRequest, ::remote::BorProducersResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Producers_, context, request, response);
}

void HeimdallBackend::Stub::async::Producers(::grpc::ClientContext* context, const ::remote::BorProducersRequest* request, ::remote::BorProducersResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::remote::BorProducersRequest, ::remote::BorProducersResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Producers_, context, request, response, std::move(f));
}

void HeimdallBackend::Stub::async::Producers(::grpc::ClientContext* context, const ::remote::BorProducersRequest* request, ::remote::BorProducersResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Producers_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::remote::BorProducersResponse>* HeimdallBackend::Stub::PrepareAsyncProducersRaw(::grpc::ClientContext* context, const ::remote::BorProducersRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::remote::BorProducersResponse, ::remote::BorProducersRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Producers_, context, request);
}

::grpc::ClientAsyncResponseReader< ::remote::BorProducersResponse>* HeimdallBackend::Stub::AsyncProducersRaw(::grpc::ClientContext* context, const ::remote::BorProducersRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncProducersRaw(context, request, cq);
  result->StartCall();
  return result;
}

HeimdallBackend::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HeimdallBackend_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HeimdallBackend::Service, ::google::protobuf::Empty, ::types::VersionReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HeimdallBackend::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::Empty* req,
             ::types::VersionReply* resp) {
               return service->Version(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HeimdallBackend_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HeimdallBackend::Service, ::remote::BorProducersRequest, ::remote::BorProducersResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HeimdallBackend::Service* service,
             ::grpc::ServerContext* ctx,
             const ::remote::BorProducersRequest* req,
             ::remote::BorProducersResponse* resp) {
               return service->Producers(ctx, req, resp);
             }, this)));
}

HeimdallBackend::Service::~Service() {
}

::grpc::Status HeimdallBackend::Service::Version(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::types::VersionReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status HeimdallBackend::Service::Producers(::grpc::ServerContext* context, const ::remote::BorProducersRequest* request, ::remote::BorProducersResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace remote
