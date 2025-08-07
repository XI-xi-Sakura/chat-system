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

#include <alibabacloud/dataworks-public/model/DeleteProjectMemberRequest.h>

using AlibabaCloud::Dataworks_public::Model::DeleteProjectMemberRequest;

DeleteProjectMemberRequest::DeleteProjectMemberRequest()
    : RpcServiceRequest("dataworks-public", "2020-05-18", "DeleteProjectMember") {
  setMethod(HttpRequest::Method::Post);
}

DeleteProjectMemberRequest::~DeleteProjectMemberRequest() {}

std::string DeleteProjectMemberRequest::getUserId() const {
  return userId_;
}

void DeleteProjectMemberRequest::setUserId(const std::string &userId) {
  userId_ = userId;
  setParameter(std::string("UserId"), userId);
}

long DeleteProjectMemberRequest::getProjectId() const {
  return projectId_;
}

void DeleteProjectMemberRequest::setProjectId(long projectId) {
  projectId_ = projectId;
  setParameter(std::string("ProjectId"), std::to_string(projectId));
}

