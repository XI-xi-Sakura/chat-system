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

#include <alibabacloud/rtc/model/DescribeAppKeyRequest.h>

using AlibabaCloud::Rtc::Model::DescribeAppKeyRequest;

DescribeAppKeyRequest::DescribeAppKeyRequest()
    : RpcServiceRequest("rtc", "2018-01-11", "DescribeAppKey") {
  setMethod(HttpRequest::Method::Post);
}

DescribeAppKeyRequest::~DescribeAppKeyRequest() {}

std::string DescribeAppKeyRequest::getShowLog() const {
  return showLog_;
}

void DescribeAppKeyRequest::setShowLog(const std::string &showLog) {
  showLog_ = showLog;
  setParameter(std::string("ShowLog"), showLog);
}

std::string DescribeAppKeyRequest::getQueryAppId() const {
  return queryAppId_;
}

void DescribeAppKeyRequest::setQueryAppId(const std::string &queryAppId) {
  queryAppId_ = queryAppId;
  setParameter(std::string("QueryAppId"), queryAppId);
}

long DescribeAppKeyRequest::getOwnerId() const {
  return ownerId_;
}

void DescribeAppKeyRequest::setOwnerId(long ownerId) {
  ownerId_ = ownerId;
  setParameter(std::string("OwnerId"), std::to_string(ownerId));
}

std::string DescribeAppKeyRequest::getAppId() const {
  return appId_;
}

void DescribeAppKeyRequest::setAppId(const std::string &appId) {
  appId_ = appId;
  setParameter(std::string("AppId"), appId);
}

