// Copyright 2024 The Cobalt Authors. All Rights Reserved.
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

#ifndef COBALT_COBALT_MAIN_DELEGATE_H_
#define COBALT_COBALT_MAIN_DELEGATE_H_

#include "build/build_config.h"
#include "cobalt/renderer/cobalt_content_renderer_client.h"
#include "content/shell/app/shell_main_delegate.h"

namespace cobalt {

class CobaltMainDelegate : public content::ShellMainDelegate {
 public:
  explicit CobaltMainDelegate(bool is_content_browsertests = false);

  CobaltMainDelegate(const CobaltMainDelegate&) = delete;
  CobaltMainDelegate& operator=(const CobaltMainDelegate&) = delete;

  // ContentMainDelegate implementation:
  content::ContentBrowserClient* CreateContentBrowserClient() override;
  content::ContentRendererClient* CreateContentRendererClient() override;
  absl::optional<int> PostEarlyInitialization(InvokedIn invoked_in) override;

  ~CobaltMainDelegate() override;

 private:
  std::unique_ptr<CobaltContentRendererClient> renderer_client_;
};

}  // namespace cobalt

#endif  // COBALT_COBALT_MAIN_DELEGATE_H_
