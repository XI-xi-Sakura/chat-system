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

#include <alibabacloud/privatelink/model/RemoveZoneFromVpcEndpointRequest.h>

using AlibabaCloud::Privatelink::Model::RemoveZoneFromVpcEndpointRequest;

RemoveZoneFromVpcEndpointRequest::RemoveZoneFromVpcEndpointRequest()
    : RpcServiceRequest("privatelink", "2020-04-15", "RemoveZoneFromVpcEndpoint") {
  setMethod(HttpRequest::Method::Post);
}

RemoveZoneFromVpcEndpointRequest::~RemoveZoneFromVpcEndpointRequest() {}

std::string RemoveZoneFromVpcEndpointRequest::getClientToken() const {
  return clientToken_;
}

void RemoveZoneFromVpcEndpointRequest::setClientToken(const std::string &clientToken) {
  clientToken_ = clientToken;
  setParameter(std::string("ClientToken"), clientToken);
}

std::string RemoveZoneFromVpcEndpointRequest::getEndpointId() const {
  return endpointId_;
}

void RemoveZoneFromVpcEndpointRequest::setEndpointId(const std::string &endpointId) {
  endpointId_ = endpointId;
  setParameter(std::string("EndpointId"), endpointId);
}

std::string RemoveZoneFromVpcEndpointRequest::getRegionId() const {
  return regionId_;
}

void RemoveZoneFromVpcEndpointRequest::setRegionId(const std::string &regionId) {
  regionId_ = regionId;
  setParameter(std::string("RegionId"), regionId);
}

bool RemoveZoneFromVpcEndpointRequest::getDryRun() const {
  return dryRun_;
}

void RemoveZoneFromVpcEndpointRequest::setDryRun(bool dryRun) {
  dryRun_ = dryRun;
  setParameter(std::string("DryRun"), dryRun ? "true" : "false");
}

std::string RemoveZoneFromVpcEndpointRequest::getZoneId() const {
  return zoneId_;
}

void RemoveZoneFromVpcEndpointRequest::setZoneId(const std::string &zoneId) {
  zoneId_ = zoneId;
  setParameter(std::string("ZoneId"), zoneId);
}

