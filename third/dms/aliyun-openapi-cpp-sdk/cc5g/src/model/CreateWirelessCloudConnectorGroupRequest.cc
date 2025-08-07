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

#include <alibabacloud/cc5g/model/CreateWirelessCloudConnectorGroupRequest.h>

using AlibabaCloud::CC5G::Model::CreateWirelessCloudConnectorGroupRequest;

CreateWirelessCloudConnectorGroupRequest::CreateWirelessCloudConnectorGroupRequest()
    : RpcServiceRequest("cc5g", "2022-03-14", "CreateWirelessCloudConnectorGroup") {
  setMethod(HttpRequest::Method::Post);
}

CreateWirelessCloudConnectorGroupRequest::~CreateWirelessCloudConnectorGroupRequest() {}

bool CreateWirelessCloudConnectorGroupRequest::getDryRun() const {
  return dryRun_;
}

void CreateWirelessCloudConnectorGroupRequest::setDryRun(bool dryRun) {
  dryRun_ = dryRun;
  setParameter(std::string("DryRun"), dryRun ? "true" : "false");
}

std::string CreateWirelessCloudConnectorGroupRequest::getClientToken() const {
  return clientToken_;
}

void CreateWirelessCloudConnectorGroupRequest::setClientToken(const std::string &clientToken) {
  clientToken_ = clientToken;
  setParameter(std::string("ClientToken"), clientToken);
}

std::string CreateWirelessCloudConnectorGroupRequest::getDescription() const {
  return description_;
}

void CreateWirelessCloudConnectorGroupRequest::setDescription(const std::string &description) {
  description_ = description;
  setParameter(std::string("Description"), description);
}

std::string CreateWirelessCloudConnectorGroupRequest::getRegionId() const {
  return regionId_;
}

void CreateWirelessCloudConnectorGroupRequest::setRegionId(const std::string &regionId) {
  regionId_ = regionId;
  setParameter(std::string("RegionId"), regionId);
}

std::string CreateWirelessCloudConnectorGroupRequest::getName() const {
  return name_;
}

void CreateWirelessCloudConnectorGroupRequest::setName(const std::string &name) {
  name_ = name;
  setParameter(std::string("Name"), name);
}

