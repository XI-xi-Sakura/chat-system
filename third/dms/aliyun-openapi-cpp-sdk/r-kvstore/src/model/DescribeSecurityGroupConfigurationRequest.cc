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

#include <alibabacloud/r-kvstore/model/DescribeSecurityGroupConfigurationRequest.h>

using AlibabaCloud::R_kvstore::Model::DescribeSecurityGroupConfigurationRequest;

DescribeSecurityGroupConfigurationRequest::DescribeSecurityGroupConfigurationRequest()
    : RpcServiceRequest("r-kvstore", "2015-01-01", "DescribeSecurityGroupConfiguration") {
  setMethod(HttpRequest::Method::Post);
}

DescribeSecurityGroupConfigurationRequest::~DescribeSecurityGroupConfigurationRequest() {}

long DescribeSecurityGroupConfigurationRequest::getResourceOwnerId() const {
  return resourceOwnerId_;
}

void DescribeSecurityGroupConfigurationRequest::setResourceOwnerId(long resourceOwnerId) {
  resourceOwnerId_ = resourceOwnerId;
  setParameter(std::string("ResourceOwnerId"), std::to_string(resourceOwnerId));
}

std::string DescribeSecurityGroupConfigurationRequest::getAccessKeyId() const {
  return accessKeyId_;
}

void DescribeSecurityGroupConfigurationRequest::setAccessKeyId(const std::string &accessKeyId) {
  accessKeyId_ = accessKeyId;
  setParameter(std::string("AccessKeyId"), accessKeyId);
}

std::string DescribeSecurityGroupConfigurationRequest::getSecurityToken() const {
  return securityToken_;
}

void DescribeSecurityGroupConfigurationRequest::setSecurityToken(const std::string &securityToken) {
  securityToken_ = securityToken;
  setParameter(std::string("SecurityToken"), securityToken);
}

std::string DescribeSecurityGroupConfigurationRequest::getResourceOwnerAccount() const {
  return resourceOwnerAccount_;
}

void DescribeSecurityGroupConfigurationRequest::setResourceOwnerAccount(const std::string &resourceOwnerAccount) {
  resourceOwnerAccount_ = resourceOwnerAccount;
  setParameter(std::string("ResourceOwnerAccount"), resourceOwnerAccount);
}

std::string DescribeSecurityGroupConfigurationRequest::getOwnerAccount() const {
  return ownerAccount_;
}

void DescribeSecurityGroupConfigurationRequest::setOwnerAccount(const std::string &ownerAccount) {
  ownerAccount_ = ownerAccount;
  setParameter(std::string("OwnerAccount"), ownerAccount);
}

long DescribeSecurityGroupConfigurationRequest::getOwnerId() const {
  return ownerId_;
}

void DescribeSecurityGroupConfigurationRequest::setOwnerId(long ownerId) {
  ownerId_ = ownerId;
  setParameter(std::string("OwnerId"), std::to_string(ownerId));
}

std::string DescribeSecurityGroupConfigurationRequest::getInstanceId() const {
  return instanceId_;
}

void DescribeSecurityGroupConfigurationRequest::setInstanceId(const std::string &instanceId) {
  instanceId_ = instanceId;
  setParameter(std::string("InstanceId"), instanceId);
}

