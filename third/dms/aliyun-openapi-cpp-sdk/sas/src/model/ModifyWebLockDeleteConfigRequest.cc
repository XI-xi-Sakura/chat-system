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

#include <alibabacloud/sas/model/ModifyWebLockDeleteConfigRequest.h>

using AlibabaCloud::Sas::Model::ModifyWebLockDeleteConfigRequest;

ModifyWebLockDeleteConfigRequest::ModifyWebLockDeleteConfigRequest()
    : RpcServiceRequest("sas", "2018-12-03", "ModifyWebLockDeleteConfig") {
  setMethod(HttpRequest::Method::Post);
}

ModifyWebLockDeleteConfigRequest::~ModifyWebLockDeleteConfigRequest() {}

std::string ModifyWebLockDeleteConfigRequest::getUuid() const {
  return uuid_;
}

void ModifyWebLockDeleteConfigRequest::setUuid(const std::string &uuid) {
  uuid_ = uuid;
  setParameter(std::string("Uuid"), uuid);
}

std::string ModifyWebLockDeleteConfigRequest::getSourceIp() const {
  return sourceIp_;
}

void ModifyWebLockDeleteConfigRequest::setSourceIp(const std::string &sourceIp) {
  sourceIp_ = sourceIp;
  setParameter(std::string("SourceIp"), sourceIp);
}

int ModifyWebLockDeleteConfigRequest::getId() const {
  return id_;
}

void ModifyWebLockDeleteConfigRequest::setId(int id) {
  id_ = id;
  setParameter(std::string("Id"), std::to_string(id));
}

std::string ModifyWebLockDeleteConfigRequest::getLang() const {
  return lang_;
}

void ModifyWebLockDeleteConfigRequest::setLang(const std::string &lang) {
  lang_ = lang;
  setParameter(std::string("Lang"), lang);
}

