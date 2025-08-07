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

#include <alibabacloud/devops-rdc/model/GetDevopsProjectMembersRequest.h>

using AlibabaCloud::Devops_rdc::Model::GetDevopsProjectMembersRequest;

GetDevopsProjectMembersRequest::GetDevopsProjectMembersRequest()
    : RpcServiceRequest("devops-rdc", "2020-03-03", "GetDevopsProjectMembers") {
  setMethod(HttpRequest::Method::Post);
}

GetDevopsProjectMembersRequest::~GetDevopsProjectMembersRequest() {}

int GetDevopsProjectMembersRequest::getPageSize() const {
  return pageSize_;
}

void GetDevopsProjectMembersRequest::setPageSize(int pageSize) {
  pageSize_ = pageSize;
  setBodyParameter(std::string("PageSize"), std::to_string(pageSize));
}

std::string GetDevopsProjectMembersRequest::getProjectId() const {
  return projectId_;
}

void GetDevopsProjectMembersRequest::setProjectId(const std::string &projectId) {
  projectId_ = projectId;
  setBodyParameter(std::string("ProjectId"), projectId);
}

std::string GetDevopsProjectMembersRequest::getOrgId() const {
  return orgId_;
}

void GetDevopsProjectMembersRequest::setOrgId(const std::string &orgId) {
  orgId_ = orgId;
  setBodyParameter(std::string("OrgId"), orgId);
}

std::string GetDevopsProjectMembersRequest::getPageToken() const {
  return pageToken_;
}

void GetDevopsProjectMembersRequest::setPageToken(const std::string &pageToken) {
  pageToken_ = pageToken;
  setBodyParameter(std::string("PageToken"), pageToken);
}

