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

#include <alibabacloud/sae/model/ListTagResourcesRequest.h>

using AlibabaCloud::Sae::Model::ListTagResourcesRequest;

ListTagResourcesRequest::ListTagResourcesRequest()
    : RoaServiceRequest("sae", "2019-05-06") {
  setResourcePath("/tags"};
  setMethod(HttpRequest::Method::Get);
}

ListTagResourcesRequest::~ListTagResourcesRequest() {}

std::string ListTagResourcesRequest::getRegionId() const {
  return regionId_;
}

void ListTagResourcesRequest::setRegionId(const std::string &regionId) {
  regionId_ = regionId;
  setParameter(std::string("RegionId"), regionId);
}

std::string ListTagResourcesRequest::getNextToken() const {
  return nextToken_;
}

void ListTagResourcesRequest::setNextToken(const std::string &nextToken) {
  nextToken_ = nextToken;
  setParameter(std::string("NextToken"), nextToken);
}

std::string ListTagResourcesRequest::getResourceType() const {
  return resourceType_;
}

void ListTagResourcesRequest::setResourceType(const std::string &resourceType) {
  resourceType_ = resourceType;
  setParameter(std::string("ResourceType"), resourceType);
}

std::string ListTagResourcesRequest::getResourceIds() const {
  return resourceIds_;
}

void ListTagResourcesRequest::setResourceIds(const std::string &resourceIds) {
  resourceIds_ = resourceIds;
  setParameter(std::string("ResourceIds"), resourceIds);
}

std::string ListTagResourcesRequest::getTags() const {
  return tags_;
}

void ListTagResourcesRequest::setTags(const std::string &tags) {
  tags_ = tags;
  setParameter(std::string("Tags"), tags);
}

