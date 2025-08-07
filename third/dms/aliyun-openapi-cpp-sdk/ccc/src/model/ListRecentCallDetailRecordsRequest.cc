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

#include <alibabacloud/ccc/model/ListRecentCallDetailRecordsRequest.h>

using AlibabaCloud::CCC::Model::ListRecentCallDetailRecordsRequest;

ListRecentCallDetailRecordsRequest::ListRecentCallDetailRecordsRequest()
    : RpcServiceRequest("ccc", "2020-07-01", "ListRecentCallDetailRecords") {
  setMethod(HttpRequest::Method::Post);
}

ListRecentCallDetailRecordsRequest::~ListRecentCallDetailRecordsRequest() {}

std::string ListRecentCallDetailRecordsRequest::getCriteria() const {
  return criteria_;
}

void ListRecentCallDetailRecordsRequest::setCriteria(const std::string &criteria) {
  criteria_ = criteria;
  setParameter(std::string("Criteria"), criteria);
}

long ListRecentCallDetailRecordsRequest::getEndTime() const {
  return endTime_;
}

void ListRecentCallDetailRecordsRequest::setEndTime(long endTime) {
  endTime_ = endTime;
  setParameter(std::string("EndTime"), std::to_string(endTime));
}

long ListRecentCallDetailRecordsRequest::getStartTime() const {
  return startTime_;
}

void ListRecentCallDetailRecordsRequest::setStartTime(long startTime) {
  startTime_ = startTime;
  setBodyParameter(std::string("StartTime"), std::to_string(startTime));
}

int ListRecentCallDetailRecordsRequest::getPageNumber() const {
  return pageNumber_;
}

void ListRecentCallDetailRecordsRequest::setPageNumber(int pageNumber) {
  pageNumber_ = pageNumber;
  setParameter(std::string("PageNumber"), std::to_string(pageNumber));
}

std::string ListRecentCallDetailRecordsRequest::getInstanceId() const {
  return instanceId_;
}

void ListRecentCallDetailRecordsRequest::setInstanceId(const std::string &instanceId) {
  instanceId_ = instanceId;
  setParameter(std::string("InstanceId"), instanceId);
}

int ListRecentCallDetailRecordsRequest::getPageSize() const {
  return pageSize_;
}

void ListRecentCallDetailRecordsRequest::setPageSize(int pageSize) {
  pageSize_ = pageSize;
  setParameter(std::string("PageSize"), std::to_string(pageSize));
}

