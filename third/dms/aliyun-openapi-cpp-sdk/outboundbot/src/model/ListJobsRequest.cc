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

#include <alibabacloud/outboundbot/model/ListJobsRequest.h>

using AlibabaCloud::OutboundBot::Model::ListJobsRequest;

ListJobsRequest::ListJobsRequest()
    : RpcServiceRequest("outboundbot", "2019-12-26", "ListJobs") {
  setMethod(HttpRequest::Method::Post);
}

ListJobsRequest::~ListJobsRequest() {}

std::vector<std::string> ListJobsRequest::getJobId() const {
  return jobId_;
}

void ListJobsRequest::setJobId(const std::vector<std::string> &jobId) {
  jobId_ = jobId;
}

std::string ListJobsRequest::getInstanceId() const {
  return instanceId_;
}

void ListJobsRequest::setInstanceId(const std::string &instanceId) {
  instanceId_ = instanceId;
  setParameter(std::string("InstanceId"), instanceId);
}

