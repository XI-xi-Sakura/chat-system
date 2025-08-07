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

#include <alibabacloud/oceanbasepro/model/DescribeSessionListRequest.h>

using AlibabaCloud::OceanBasePro::Model::DescribeSessionListRequest;

DescribeSessionListRequest::DescribeSessionListRequest()
    : RpcServiceRequest("oceanbasepro", "2019-09-01", "DescribeSessionList") {
  setMethod(HttpRequest::Method::Post);
}

DescribeSessionListRequest::~DescribeSessionListRequest() {}

std::string DescribeSessionListRequest::getInstanceId() const {
  return instanceId_;
}

void DescribeSessionListRequest::setInstanceId(const std::string &instanceId) {
  instanceId_ = instanceId;
  setBodyParameter(std::string("InstanceId"), instanceId);
}

std::string DescribeSessionListRequest::getTenantId() const {
  return tenantId_;
}

void DescribeSessionListRequest::setTenantId(const std::string &tenantId) {
  tenantId_ = tenantId;
  setBodyParameter(std::string("TenantId"), tenantId);
}

