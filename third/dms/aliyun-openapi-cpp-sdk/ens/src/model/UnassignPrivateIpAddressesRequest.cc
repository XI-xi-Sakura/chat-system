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

#include <alibabacloud/ens/model/UnassignPrivateIpAddressesRequest.h>

using AlibabaCloud::Ens::Model::UnassignPrivateIpAddressesRequest;

UnassignPrivateIpAddressesRequest::UnassignPrivateIpAddressesRequest()
    : RpcServiceRequest("ens", "2017-11-10", "UnassignPrivateIpAddresses") {
  setMethod(HttpRequest::Method::Post);
}

UnassignPrivateIpAddressesRequest::~UnassignPrivateIpAddressesRequest() {}

std::vector<UnassignPrivateIpAddressesRequest::std::string> UnassignPrivateIpAddressesRequest::getPrivateIpAddress() const {
  return privateIpAddress_;
}

void UnassignPrivateIpAddressesRequest::setPrivateIpAddress(const std::vector<UnassignPrivateIpAddressesRequest::std::string> &privateIpAddress) {
  privateIpAddress_ = privateIpAddress;
  for(int dep1 = 0; dep1 != privateIpAddress.size(); dep1++) {
    setParameter(std::string("PrivateIpAddress") + "." + std::to_string(dep1 + 1), privateIpAddress[dep1]);
  }
}

std::string UnassignPrivateIpAddressesRequest::getNetworkInterfaceId() const {
  return networkInterfaceId_;
}

void UnassignPrivateIpAddressesRequest::setNetworkInterfaceId(const std::string &networkInterfaceId) {
  networkInterfaceId_ = networkInterfaceId;
  setParameter(std::string("NetworkInterfaceId"), networkInterfaceId);
}

