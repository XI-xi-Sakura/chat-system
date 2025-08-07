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

#include <alibabacloud/viapi-regen/model/DownloadFileNameListRequest.h>

using AlibabaCloud::Viapi_regen::Model::DownloadFileNameListRequest;

DownloadFileNameListRequest::DownloadFileNameListRequest()
    : RpcServiceRequest("viapi-regen", "2021-11-19", "DownloadFileNameList") {
  setMethod(HttpRequest::Method::Post);
}

DownloadFileNameListRequest::~DownloadFileNameListRequest() {}

std::string DownloadFileNameListRequest::getIdentity() const {
  return identity_;
}

void DownloadFileNameListRequest::setIdentity(const std::string &identity) {
  identity_ = identity;
  setBodyParameter(std::string("Identity"), identity);
}

long DownloadFileNameListRequest::getDatasetId() const {
  return datasetId_;
}

void DownloadFileNameListRequest::setDatasetId(long datasetId) {
  datasetId_ = datasetId;
  setBodyParameter(std::string("DatasetId"), std::to_string(datasetId));
}

