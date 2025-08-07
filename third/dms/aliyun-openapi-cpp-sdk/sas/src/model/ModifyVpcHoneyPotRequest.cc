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

#include <alibabacloud/sas/model/ModifyVpcHoneyPotRequest.h>

using AlibabaCloud::Sas::Model::ModifyVpcHoneyPotRequest;

ModifyVpcHoneyPotRequest::ModifyVpcHoneyPotRequest()
    : RpcServiceRequest("sas", "2018-12-03", "ModifyVpcHoneyPot") {
  setMethod(HttpRequest::Method::Post);
}

ModifyVpcHoneyPotRequest::~ModifyVpcHoneyPotRequest() {}

std::string ModifyVpcHoneyPotRequest::getSourceIp() const {
  return sourceIp_;
}

void ModifyVpcHoneyPotRequest::setSourceIp(const std::string &sourceIp) {
  sourceIp_ = sourceIp;
  setParameter(std::string("SourceIp"), sourceIp);
}

std::string ModifyVpcHoneyPotRequest::getHoneyPotAction() const {
  return honeyPotAction_;
}

void ModifyVpcHoneyPotRequest::setHoneyPotAction(const std::string &honeyPotAction) {
  honeyPotAction_ = honeyPotAction;
  setParameter(std::string("HoneyPotAction"), honeyPotAction);
}

std::string ModifyVpcHoneyPotRequest::getVpcId() const {
  return vpcId_;
}

void ModifyVpcHoneyPotRequest::setVpcId(const std::string &vpcId) {
  vpcId_ = vpcId;
  setParameter(std::string("VpcId"), vpcId);
}

