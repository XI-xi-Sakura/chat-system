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

#include <alibabacloud/imm/model/DetectImageScoreRequest.h>

using AlibabaCloud::Imm::Model::DetectImageScoreRequest;

DetectImageScoreRequest::DetectImageScoreRequest()
    : RpcServiceRequest("imm", "2020-09-30", "DetectImageScore") {
  setMethod(HttpRequest::Method::Post);
}

DetectImageScoreRequest::~DetectImageScoreRequest() {}

std::string DetectImageScoreRequest::getProjectName() const {
  return projectName_;
}

void DetectImageScoreRequest::setProjectName(const std::string &projectName) {
  projectName_ = projectName;
  setParameter(std::string("ProjectName"), projectName);
}

DetectImageScoreRequest::CredentialConfig DetectImageScoreRequest::getCredentialConfig() const {
  return credentialConfig_;
}

void DetectImageScoreRequest::setCredentialConfig(const DetectImageScoreRequest::CredentialConfig &credentialConfig) {
  credentialConfig_ = credentialConfig;
  for(int dep1 = 0; dep1 != credentialConfig.chain.size(); dep1++) {
    setParameter(std::string("CredentialConfig") + ".Chain." + std::to_string(dep1 + 1) + ".Role", credentialConfig.chain[dep1].role);
    setParameter(std::string("CredentialConfig") + ".Chain." + std::to_string(dep1 + 1) + ".RoleType", credentialConfig.chain[dep1].roleType);
    setParameter(std::string("CredentialConfig") + ".Chain." + std::to_string(dep1 + 1) + ".AssumeRoleFor", credentialConfig.chain[dep1].assumeRoleFor);
  }
  setParameter(std::string("CredentialConfig") + ".ServiceRole", credentialConfig.serviceRole);
  setParameter(std::string("CredentialConfig") + ".Policy", credentialConfig.policy);
}

std::string DetectImageScoreRequest::getSourceURI() const {
  return sourceURI_;
}

void DetectImageScoreRequest::setSourceURI(const std::string &sourceURI) {
  sourceURI_ = sourceURI;
  setParameter(std::string("SourceURI"), sourceURI);
}

