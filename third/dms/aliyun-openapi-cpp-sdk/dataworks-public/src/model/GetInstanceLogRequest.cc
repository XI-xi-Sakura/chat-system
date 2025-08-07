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

#include <alibabacloud/dataworks-public/model/GetInstanceLogRequest.h>

using AlibabaCloud::Dataworks_public::Model::GetInstanceLogRequest;

GetInstanceLogRequest::GetInstanceLogRequest()
    : RpcServiceRequest("dataworks-public", "2020-05-18", "GetInstanceLog") {
  setMethod(HttpRequest::Method::Post);
}

GetInstanceLogRequest::~GetInstanceLogRequest() {}

std::string GetInstanceLogRequest::getProjectEnv() const {
  return projectEnv_;
}

void GetInstanceLogRequest::setProjectEnv(const std::string &projectEnv) {
  projectEnv_ = projectEnv;
  setBodyParameter(std::string("ProjectEnv"), projectEnv);
}

long GetInstanceLogRequest::getInstanceId() const {
  return instanceId_;
}

void GetInstanceLogRequest::setInstanceId(long instanceId) {
  instanceId_ = instanceId;
  setBodyParameter(std::string("InstanceId"), std::to_string(instanceId));
}

long GetInstanceLogRequest::getInstanceHistoryId() const {
  return instanceHistoryId_;
}

void GetInstanceLogRequest::setInstanceHistoryId(long instanceHistoryId) {
  instanceHistoryId_ = instanceHistoryId;
  setBodyParameter(std::string("InstanceHistoryId"), std::to_string(instanceHistoryId));
}

