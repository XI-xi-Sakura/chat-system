/*
 * Copyright 2009-2017 Alibaba Cloud All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <alibabacloud/privatelink/model/OpenPrivateLinkServiceRequest.h>

using AlibabaCloud::Privatelink::Model::OpenPrivateLinkServiceRequest;

OpenPrivateLinkServiceRequest::OpenPrivateLinkServiceRequest()
    : RpcServiceRequest("privatelink", "2020-04-15", "OpenPrivateLinkService") {
  setMethod(HttpRequest::Method::Post);
}

OpenPrivateLinkServiceRequest::~OpenPrivateLinkServiceRequest() {}

long OpenPrivateLinkServiceRequest::getOwnerId() const {
  return ownerId_;
}

void OpenPrivateLinkServiceRequest::setOwnerId(long ownerId) {
  ownerId_ = ownerId;
  setParameter(std::string("OwnerId"), std::to_string(ownerId));
}

