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

#include <alibabacloud/config/model/ListCompliancePacksRequest.h>

using AlibabaCloud::Config::Model::ListCompliancePacksRequest;

ListCompliancePacksRequest::ListCompliancePacksRequest()
    : RpcServiceRequest("config", "2020-09-07", "ListCompliancePacks") {
  setMethod(HttpRequest::Method::Post);
}

ListCompliancePacksRequest::~ListCompliancePacksRequest() {}

int ListCompliancePacksRequest::getPageNumber() const {
  return pageNumber_;
}

void ListCompliancePacksRequest::setPageNumber(int pageNumber) {
  pageNumber_ = pageNumber;
  setParameter(std::string("PageNumber"), std::to_string(pageNumber));
}

int ListCompliancePacksRequest::getPageSize() const {
  return pageSize_;
}

void ListCompliancePacksRequest::setPageSize(int pageSize) {
  pageSize_ = pageSize;
  setParameter(std::string("PageSize"), std::to_string(pageSize));
}

std::string ListCompliancePacksRequest::getStatus() const {
  return status_;
}

void ListCompliancePacksRequest::setStatus(const std::string &status) {
  status_ = status;
  setParameter(std::string("Status"), status);
}

