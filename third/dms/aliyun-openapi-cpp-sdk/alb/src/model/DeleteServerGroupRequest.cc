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

#include <alibabacloud/alb/model/DeleteServerGroupRequest.h>

using AlibabaCloud::Alb::Model::DeleteServerGroupRequest;

DeleteServerGroupRequest::DeleteServerGroupRequest()
    : RpcServiceRequest("alb", "2020-06-16", "DeleteServerGroup") {
  setMethod(HttpRequest::Method::Post);
}

DeleteServerGroupRequest::~DeleteServerGroupRequest() {}

std::string DeleteServerGroupRequest::getClientToken() const {
  return clientToken_;
}

void DeleteServerGroupRequest::setClientToken(const std::string &clientToken) {
  clientToken_ = clientToken;
  setParameter(std::string("ClientToken"), clientToken);
}

std::string DeleteServerGroupRequest::getServerGroupId() const {
  return serverGroupId_;
}

void DeleteServerGroupRequest::setServerGroupId(const std::string &serverGroupId) {
  serverGroupId_ = serverGroupId;
  setParameter(std::string("ServerGroupId"), serverGroupId);
}

bool DeleteServerGroupRequest::getDryRun() const {
  return dryRun_;
}

void DeleteServerGroupRequest::setDryRun(bool dryRun) {
  dryRun_ = dryRun;
  setParameter(std::string("DryRun"), dryRun ? "true" : "false");
}

