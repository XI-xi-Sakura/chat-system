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

#include <alibabacloud/rds/model/DescribeAnalyticdbByPrimaryDBInstanceRequest.h>

using AlibabaCloud::Rds::Model::DescribeAnalyticdbByPrimaryDBInstanceRequest;

DescribeAnalyticdbByPrimaryDBInstanceRequest::DescribeAnalyticdbByPrimaryDBInstanceRequest()
    : RpcServiceRequest("rds", "2014-08-15", "DescribeAnalyticdbByPrimaryDBInstance") {
  setMethod(HttpRequest::Method::Post);
}

DescribeAnalyticdbByPrimaryDBInstanceRequest::~DescribeAnalyticdbByPrimaryDBInstanceRequest() {}

long DescribeAnalyticdbByPrimaryDBInstanceRequest::getResourceOwnerId() const {
  return resourceOwnerId_;
}

void DescribeAnalyticdbByPrimaryDBInstanceRequest::setResourceOwnerId(long resourceOwnerId) {
  resourceOwnerId_ = resourceOwnerId;
  setParameter(std::string("ResourceOwnerId"), std::to_string(resourceOwnerId));
}

std::string DescribeAnalyticdbByPrimaryDBInstanceRequest::getResourceOwnerAccount() const {
  return resourceOwnerAccount_;
}

void DescribeAnalyticdbByPrimaryDBInstanceRequest::setResourceOwnerAccount(const std::string &resourceOwnerAccount) {
  resourceOwnerAccount_ = resourceOwnerAccount;
  setParameter(std::string("ResourceOwnerAccount"), resourceOwnerAccount);
}

long DescribeAnalyticdbByPrimaryDBInstanceRequest::getOwnerId() const {
  return ownerId_;
}

void DescribeAnalyticdbByPrimaryDBInstanceRequest::setOwnerId(long ownerId) {
  ownerId_ = ownerId;
  setParameter(std::string("OwnerId"), std::to_string(ownerId));
}

std::string DescribeAnalyticdbByPrimaryDBInstanceRequest::getAccessKeyId() const {
  return accessKeyId_;
}

void DescribeAnalyticdbByPrimaryDBInstanceRequest::setAccessKeyId(const std::string &accessKeyId) {
  accessKeyId_ = accessKeyId;
  setParameter(std::string("AccessKeyId"), accessKeyId);
}

std::string DescribeAnalyticdbByPrimaryDBInstanceRequest::getRegionId() const {
  return regionId_;
}

void DescribeAnalyticdbByPrimaryDBInstanceRequest::setRegionId(const std::string &regionId) {
  regionId_ = regionId;
  setParameter(std::string("RegionId"), regionId);
}

std::string DescribeAnalyticdbByPrimaryDBInstanceRequest::getDBInstanceId() const {
  return dBInstanceId_;
}

void DescribeAnalyticdbByPrimaryDBInstanceRequest::setDBInstanceId(const std::string &dBInstanceId) {
  dBInstanceId_ = dBInstanceId;
  setParameter(std::string("DBInstanceId"), dBInstanceId);
}

