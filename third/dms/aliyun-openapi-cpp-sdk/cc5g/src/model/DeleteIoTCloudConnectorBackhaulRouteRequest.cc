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

#include <alibabacloud/cc5g/model/DeleteIoTCloudConnectorBackhaulRouteRequest.h>

using AlibabaCloud::CC5G::Model::DeleteIoTCloudConnectorBackhaulRouteRequest;

DeleteIoTCloudConnectorBackhaulRouteRequest::DeleteIoTCloudConnectorBackhaulRouteRequest()
    : RpcServiceRequest("cc5g", "2022-03-14", "DeleteIoTCloudConnectorBackhaulRoute") {
  setMethod(HttpRequest::Method::Post);
}

DeleteIoTCloudConnectorBackhaulRouteRequest::~DeleteIoTCloudConnectorBackhaulRouteRequest() {}

bool DeleteIoTCloudConnectorBackhaulRouteRequest::getDryRun() const {
  return dryRun_;
}

void DeleteIoTCloudConnectorBackhaulRouteRequest::setDryRun(bool dryRun) {
  dryRun_ = dryRun;
  setParameter(std::string("DryRun"), dryRun ? "true" : "false");
}

std::string DeleteIoTCloudConnectorBackhaulRouteRequest::getNetLinkId() const {
  return netLinkId_;
}

void DeleteIoTCloudConnectorBackhaulRouteRequest::setNetLinkId(const std::string &netLinkId) {
  netLinkId_ = netLinkId;
  setParameter(std::string("NetLinkId"), netLinkId);
}

std::string DeleteIoTCloudConnectorBackhaulRouteRequest::getClientToken() const {
  return clientToken_;
}

void DeleteIoTCloudConnectorBackhaulRouteRequest::setClientToken(const std::string &clientToken) {
  clientToken_ = clientToken;
  setParameter(std::string("ClientToken"), clientToken);
}

std::string DeleteIoTCloudConnectorBackhaulRouteRequest::getWirelessCloudConnectorId() const {
  return wirelessCloudConnectorId_;
}

void DeleteIoTCloudConnectorBackhaulRouteRequest::setWirelessCloudConnectorId(const std::string &wirelessCloudConnectorId) {
  wirelessCloudConnectorId_ = wirelessCloudConnectorId;
  setParameter(std::string("WirelessCloudConnectorId"), wirelessCloudConnectorId);
}

