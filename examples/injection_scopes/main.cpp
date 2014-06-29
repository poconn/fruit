/*
 * Copyright 2014 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <fruit/fruit.h>

#include "server.h"

using fruit::Component;
using fruit::Injector;

int main() {
  ServerContext serverContext;
  
  Injector<Server> injector(
    fruit::createComponent()
      .install(getServerComponent())
      .bindInstance(serverContext));
  
  // Not necessary in this case. Would be necessary if the server used multiple threads to process requests in parallel,
  // creating a child injector in each thread.
  injector.eagerlyInjectAll();
  
  Server* server(injector);
  server->run();
  
  return 0;
}
