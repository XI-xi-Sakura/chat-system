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

#include <alibabacloud/dataworks-public/model/DeleteBusinessRequest.h>

using AlibabaCloud::Dataworks_public::Model::DeleteBusinessRequest;

DeleteBusinessRequest::DeleteBusinessRequest()
    : RpcServiceRequest("dataworks-public", "2020-05-18", "DeleteBusiness") {
  setMethod(HttpRequest::Method::Post);
}

DeleteBusinessRequest::~DeleteBusinessRequest() {}

long DeleteBusinessRequest::getBusinessId() const {
  return businessId_;
}

void DeleteBusinessRequest::setBusinessId(long businessId) {
  businessId_ = businessId;
  setBodyParameter(std::string("BusinessId"), std::to_string(businessId));
}

long DeleteBusinessRequest::getProjectId() const {
  return projectId_;
}

void DeleteBusinessRequest::setProjectId(long projectId) {
  projectId_ = projectId;
  setBodyParameter(std::string("ProjectId"), std::to_string(projectId));
}

std::string DeleteBusinessRequest::getProjectIdentifier() const {
  return projectIdentifier_;
}

void DeleteBusinessRequest::setProjectIdentifier(const std::string &projectIdentifier) {
  projectIdentifier_ = projectIdentifier;
  setBodyParameter(std::string("ProjectIdentifier"), projectIdentifier);
}

