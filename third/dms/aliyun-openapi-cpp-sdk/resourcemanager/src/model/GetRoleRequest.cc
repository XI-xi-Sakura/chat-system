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

#include <alibabacloud/resourcemanager/model/GetRoleRequest.h>

using AlibabaCloud::ResourceManager::Model::GetRoleRequest;

GetRoleRequest::GetRoleRequest()
    : RpcServiceRequest("resourcemanager", "2020-03-31", "GetRole") {
  setMethod(HttpRequest::Method::Post);
}

GetRoleRequest::~GetRoleRequest() {}

std::string GetRoleRequest::getRoleName() const {
  return roleName_;
}

void GetRoleRequest::setRoleName(const std::string &roleName) {
  roleName_ = roleName;
  setParameter(std::string("RoleName"), roleName);
}

std::string GetRoleRequest::getLanguage() const {
  return language_;
}

void GetRoleRequest::setLanguage(const std::string &language) {
  language_ = language;
  setParameter(std::string("Language"), language);
}

