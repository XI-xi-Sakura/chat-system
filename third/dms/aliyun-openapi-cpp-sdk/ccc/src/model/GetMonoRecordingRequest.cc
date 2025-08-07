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

#include <alibabacloud/ccc/model/GetMonoRecordingRequest.h>

using AlibabaCloud::CCC::Model::GetMonoRecordingRequest;

GetMonoRecordingRequest::GetMonoRecordingRequest()
    : RpcServiceRequest("ccc", "2020-07-01", "GetMonoRecording") {
  setMethod(HttpRequest::Method::Post);
}

GetMonoRecordingRequest::~GetMonoRecordingRequest() {}

std::string GetMonoRecordingRequest::getContactId() const {
  return contactId_;
}

void GetMonoRecordingRequest::setContactId(const std::string &contactId) {
  contactId_ = contactId;
  setParameter(std::string("ContactId"), contactId);
}

std::string GetMonoRecordingRequest::getInstanceId() const {
  return instanceId_;
}

void GetMonoRecordingRequest::setInstanceId(const std::string &instanceId) {
  instanceId_ = instanceId;
  setParameter(std::string("InstanceId"), instanceId);
}

