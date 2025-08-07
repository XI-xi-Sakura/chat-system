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

#include <alibabacloud/config/model/GetDiscoveredResourceRequest.h>

using AlibabaCloud::Config::Model::GetDiscoveredResourceRequest;

GetDiscoveredResourceRequest::GetDiscoveredResourceRequest()
    : RpcServiceRequest("config", "2020-09-07", "GetDiscoveredResource") {
  setMethod(HttpRequest::Method::Get);
}

GetDiscoveredResourceRequest::~GetDiscoveredResourceRequest() {}

std::string GetDiscoveredResourceRequest::getResourceId() const {
  return resourceId_;
}

void GetDiscoveredResourceRequest::setResourceId(const std::string &resourceId) {
  resourceId_ = resourceId;
  setParameter(std::string("ResourceId"), resourceId);
}

std::string GetDiscoveredResourceRequest::getResourceType() const {
  return resourceType_;
}

void GetDiscoveredResourceRequest::setResourceType(const std::string &resourceType) {
  resourceType_ = resourceType;
  setParameter(std::string("ResourceType"), resourceType);
}

std::string GetDiscoveredResourceRequest::getRegion() const {
  return region_;
}

void GetDiscoveredResourceRequest::setRegion(const std::string &region) {
  region_ = region;
  setParameter(std::string("Region"), region);
}

