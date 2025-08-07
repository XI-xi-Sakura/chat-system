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

#include <alibabacloud/tag/model/UntagResourcesRequest.h>

using AlibabaCloud::Tag::Model::UntagResourcesRequest;

UntagResourcesRequest::UntagResourcesRequest()
    : RpcServiceRequest("tag", "2018-08-28", "UntagResources") {
  setMethod(HttpRequest::Method::Post);
}

UntagResourcesRequest::~UntagResourcesRequest() {}

std::string UntagResourcesRequest::getRegionId() const {
  return regionId_;
}

void UntagResourcesRequest::setRegionId(const std::string &regionId) {
  regionId_ = regionId;
  setParameter(std::string("RegionId"), regionId);
}

std::vector<std::string> UntagResourcesRequest::getResourceARN() const {
  return resourceARN_;
}

void UntagResourcesRequest::setResourceARN(const std::vector<std::string> &resourceARN) {
  resourceARN_ = resourceARN;
}

std::string UntagResourcesRequest::getResourceOwnerAccount() const {
  return resourceOwnerAccount_;
}

void UntagResourcesRequest::setResourceOwnerAccount(const std::string &resourceOwnerAccount) {
  resourceOwnerAccount_ = resourceOwnerAccount;
  setParameter(std::string("ResourceOwnerAccount"), resourceOwnerAccount);
}

std::string UntagResourcesRequest::getOwnerAccount() const {
  return ownerAccount_;
}

void UntagResourcesRequest::setOwnerAccount(const std::string &ownerAccount) {
  ownerAccount_ = ownerAccount;
  setParameter(std::string("OwnerAccount"), ownerAccount);
}

long UntagResourcesRequest::getOwnerId() const {
  return ownerId_;
}

void UntagResourcesRequest::setOwnerId(long ownerId) {
  ownerId_ = ownerId;
  setParameter(std::string("OwnerId"), std::to_string(ownerId));
}

std::vector<std::string> UntagResourcesRequest::getTagKey() const {
  return tagKey_;
}

void UntagResourcesRequest::setTagKey(const std::vector<std::string> &tagKey) {
  tagKey_ = tagKey;
}

