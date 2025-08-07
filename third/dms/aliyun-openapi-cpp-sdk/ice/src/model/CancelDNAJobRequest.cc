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

#include <alibabacloud/ice/model/CancelDNAJobRequest.h>

using AlibabaCloud::ICE::Model::CancelDNAJobRequest;

CancelDNAJobRequest::CancelDNAJobRequest()
    : RpcServiceRequest("ice", "2020-11-09", "CancelDNAJob") {
  setMethod(HttpRequest::Method::Post);
}

CancelDNAJobRequest::~CancelDNAJobRequest() {}

long CancelDNAJobRequest::getResourceOwnerId() const {
  return resourceOwnerId_;
}

void CancelDNAJobRequest::setResourceOwnerId(long resourceOwnerId) {
  resourceOwnerId_ = resourceOwnerId;
  setParameter(std::string("ResourceOwnerId"), std::to_string(resourceOwnerId));
}

std::string CancelDNAJobRequest::getResourceOwnerAccount() const {
  return resourceOwnerAccount_;
}

void CancelDNAJobRequest::setResourceOwnerAccount(const std::string &resourceOwnerAccount) {
  resourceOwnerAccount_ = resourceOwnerAccount;
  setParameter(std::string("ResourceOwnerAccount"), resourceOwnerAccount);
}

std::string CancelDNAJobRequest::getOwnerAccount() const {
  return ownerAccount_;
}

void CancelDNAJobRequest::setOwnerAccount(const std::string &ownerAccount) {
  ownerAccount_ = ownerAccount;
  setParameter(std::string("OwnerAccount"), ownerAccount);
}

long CancelDNAJobRequest::getOwnerId() const {
  return ownerId_;
}

void CancelDNAJobRequest::setOwnerId(long ownerId) {
  ownerId_ = ownerId;
  setParameter(std::string("OwnerId"), std::to_string(ownerId));
}

std::string CancelDNAJobRequest::getAccessKeyId() const {
  return accessKeyId_;
}

void CancelDNAJobRequest::setAccessKeyId(const std::string &accessKeyId) {
  accessKeyId_ = accessKeyId;
  setParameter(std::string("AccessKeyId"), accessKeyId);
}

std::string CancelDNAJobRequest::getJobId() const {
  return jobId_;
}

void CancelDNAJobRequest::setJobId(const std::string &jobId) {
  jobId_ = jobId;
  setParameter(std::string("JobId"), jobId);
}

