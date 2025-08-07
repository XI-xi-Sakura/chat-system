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

#include <alibabacloud/rds/model/ModifyParameterGroupRequest.h>

using AlibabaCloud::Rds::Model::ModifyParameterGroupRequest;

ModifyParameterGroupRequest::ModifyParameterGroupRequest()
    : RpcServiceRequest("rds", "2014-08-15", "ModifyParameterGroup") {
  setMethod(HttpRequest::Method::Post);
}

ModifyParameterGroupRequest::~ModifyParameterGroupRequest() {}

long ModifyParameterGroupRequest::getResourceOwnerId() const {
  return resourceOwnerId_;
}

void ModifyParameterGroupRequest::setResourceOwnerId(long resourceOwnerId) {
  resourceOwnerId_ = resourceOwnerId;
  setParameter(std::string("ResourceOwnerId"), std::to_string(resourceOwnerId));
}

std::string ModifyParameterGroupRequest::getAccessKeyId() const {
  return accessKeyId_;
}

void ModifyParameterGroupRequest::setAccessKeyId(const std::string &accessKeyId) {
  accessKeyId_ = accessKeyId;
  setParameter(std::string("AccessKeyId"), accessKeyId);
}

std::string ModifyParameterGroupRequest::getResourceGroupId() const {
  return resourceGroupId_;
}

void ModifyParameterGroupRequest::setResourceGroupId(const std::string &resourceGroupId) {
  resourceGroupId_ = resourceGroupId;
  setParameter(std::string("ResourceGroupId"), resourceGroupId);
}

std::string ModifyParameterGroupRequest::getParameterGroupId() const {
  return parameterGroupId_;
}

void ModifyParameterGroupRequest::setParameterGroupId(const std::string &parameterGroupId) {
  parameterGroupId_ = parameterGroupId;
  setParameter(std::string("ParameterGroupId"), parameterGroupId);
}

std::string ModifyParameterGroupRequest::getRegionId() const {
  return regionId_;
}

void ModifyParameterGroupRequest::setRegionId(const std::string &regionId) {
  regionId_ = regionId;
  setParameter(std::string("RegionId"), regionId);
}

std::string ModifyParameterGroupRequest::getModifyMode() const {
  return modifyMode_;
}

void ModifyParameterGroupRequest::setModifyMode(const std::string &modifyMode) {
  modifyMode_ = modifyMode;
  setParameter(std::string("ModifyMode"), modifyMode);
}

std::string ModifyParameterGroupRequest::getResourceOwnerAccount() const {
  return resourceOwnerAccount_;
}

void ModifyParameterGroupRequest::setResourceOwnerAccount(const std::string &resourceOwnerAccount) {
  resourceOwnerAccount_ = resourceOwnerAccount;
  setParameter(std::string("ResourceOwnerAccount"), resourceOwnerAccount);
}

long ModifyParameterGroupRequest::getOwnerId() const {
  return ownerId_;
}

void ModifyParameterGroupRequest::setOwnerId(long ownerId) {
  ownerId_ = ownerId;
  setParameter(std::string("OwnerId"), std::to_string(ownerId));
}

std::string ModifyParameterGroupRequest::getParameterGroupName() const {
  return parameterGroupName_;
}

void ModifyParameterGroupRequest::setParameterGroupName(const std::string &parameterGroupName) {
  parameterGroupName_ = parameterGroupName;
  setParameter(std::string("ParameterGroupName"), parameterGroupName);
}

std::string ModifyParameterGroupRequest::getParameters() const {
  return parameters_;
}

void ModifyParameterGroupRequest::setParameters(const std::string &parameters) {
  parameters_ = parameters;
  setParameter(std::string("Parameters"), parameters);
}

std::string ModifyParameterGroupRequest::getParameterGroupDesc() const {
  return parameterGroupDesc_;
}

void ModifyParameterGroupRequest::setParameterGroupDesc(const std::string &parameterGroupDesc) {
  parameterGroupDesc_ = parameterGroupDesc;
  setParameter(std::string("ParameterGroupDesc"), parameterGroupDesc);
}

