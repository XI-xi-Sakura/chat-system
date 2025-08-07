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

#include <alibabacloud/viapi-regen/model/CreateTagTaskRequest.h>

using AlibabaCloud::Viapi_regen::Model::CreateTagTaskRequest;

CreateTagTaskRequest::CreateTagTaskRequest()
    : RpcServiceRequest("viapi-regen", "2021-11-19", "CreateTagTask") {
  setMethod(HttpRequest::Method::Post);
}

CreateTagTaskRequest::~CreateTagTaskRequest() {}

long CreateTagTaskRequest::getLabelsetId() const {
  return labelsetId_;
}

void CreateTagTaskRequest::setLabelsetId(long labelsetId) {
  labelsetId_ = labelsetId;
  setBodyParameter(std::string("LabelsetId"), std::to_string(labelsetId));
}

