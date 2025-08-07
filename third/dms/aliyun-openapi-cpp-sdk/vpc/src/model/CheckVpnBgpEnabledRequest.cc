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

#include <alibabacloud/vpc/model/CheckVpnBgpEnabledRequest.h>

using AlibabaCloud::Vpc::Model::CheckVpnBgpEnabledRequest;

CheckVpnBgpEnabledRequest::CheckVpnBgpEnabledRequest()
    : RpcServiceRequest("vpc", "2016-04-28", "CheckVpnBgpEnabled") {
  setMethod(HttpRequest::Method::Post);
}

CheckVpnBgpEnabledRequest::~CheckVpnBgpEnabledRequest() {}

long CheckVpnBgpEnabledRequest::getResourceOwnerId() const {
  return resourceOwnerId_;
}

void CheckVpnBgpEnabledRequest::setResourceOwnerId(long resourceOwnerId) {
  resourceOwnerId_ = resourceOwnerId;
  setParameter(std::string("ResourceOwnerId"), std::to_string(resourceOwnerId));
}

std::string CheckVpnBgpEnabledRequest::getClientToken() const {
  return clientToken_;
}

void CheckVpnBgpEnabledRequest::setClientToken(const std::string &clientToken) {
  clientToken_ = clientToken;
  setParameter(std::string("ClientToken"), clientToken);
}

std::string CheckVpnBgpEnabledRequest::getRegionId() const {
  return regionId_;
}

void CheckVpnBgpEnabledRequest::setRegionId(const std::string &regionId) {
  regionId_ = regionId;
  setParameter(std::string("RegionId"), regionId);
}

std::string CheckVpnBgpEnabledRequest::getResourceOwnerAccount() const {
  return resourceOwnerAccount_;
}

void CheckVpnBgpEnabledRequest::setResourceOwnerAccount(const std::string &resourceOwnerAccount) {
  resourceOwnerAccount_ = resourceOwnerAccount;
  setParameter(std::string("ResourceOwnerAccount"), resourceOwnerAccount);
}

std::string CheckVpnBgpEnabledRequest::getOwnerAccount() const {
  return ownerAccount_;
}

void CheckVpnBgpEnabledRequest::setOwnerAccount(const std::string &ownerAccount) {
  ownerAccount_ = ownerAccount;
  setParameter(std::string("OwnerAccount"), ownerAccount);
}

