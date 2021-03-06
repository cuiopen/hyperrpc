/* Copyright (c) 2016, Bin Wei <bin@vip.qq.com>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * The name of of its contributors may not be used to endorse or 
 * promote products derived from this software without specific prior 
 * written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _HRPC_SERVICE_H
#define _HRPC_SERVICE_H

#include <hyperrpc/hyperrpc.h>

namespace google {
namespace protobuf {
  class Descriptor;
  class ServiceDescriptor;
  class MethodDescriptor;
  class Message;
} // namespace protobuf
} // namespace google

namespace hrpc {

class Service
{
public:
  inline Service() {}
  virtual ~Service() {}

  virtual const ::google::protobuf::ServiceDescriptor* GetDescriptor() = 0;

  virtual void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                          const ::google::protobuf::Message* request,
                          ::google::protobuf::Message* response,
                          DoneFunc done) = 0;

  virtual const ::google::protobuf::Message& GetRequestPrototype(
                const ::google::protobuf::MethodDescriptor* method) const = 0;
  virtual const ::google::protobuf::Message& GetResponsePrototype(
                const ::google::protobuf::MethodDescriptor* method) const = 0;

private:
  // not copyable and movable
  Service(const Service&) = delete;
  void operator=(const Service&) = delete;
  Service(Service&&) = delete;
  void operator=(Service&&) = delete;
};

} // namespace hrpc

#endif // _HRPC_SERVICE_H
