// Copyright 2015 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef COBALT_NETWORK_URL_REQUEST_CONTEXT_GETTER_H_
#define COBALT_NETWORK_URL_REQUEST_CONTEXT_GETTER_H_

#include "base/macros.h"
#include "base/task/single_thread_task_runner.h"
#include "base/threading/thread.h"
#include "net/url_request/url_request_context_getter.h"

namespace cobalt {
namespace network {

class URLRequestContext;

class URLRequestContextGetter : public net::URLRequestContextGetter {
 public:
  URLRequestContextGetter(URLRequestContext* url_request_context,
                          base::Thread* io_thread);

  // Implementation for net::UrlRequestContextGetter.
  net::URLRequestContext* GetURLRequestContext() override;
  scoped_refptr<base::SingleThreadTaskRunner> GetNetworkTaskRunner()
      const override;

 protected:
  virtual ~URLRequestContextGetter();

 private:
  URLRequestContext* url_request_context_;
  scoped_refptr<base::SingleThreadTaskRunner> network_task_runner_;
  DISALLOW_COPY_AND_ASSIGN(URLRequestContextGetter);
};

}  // namespace network
}  // namespace cobalt

#endif  // COBALT_NETWORK_URL_REQUEST_CONTEXT_GETTER_H_
