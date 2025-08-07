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

#include <alibabacloud/vod/model/UpdateCategoryRequest.h>

using AlibabaCloud::Vod::Model::UpdateCategoryRequest;

UpdateCategoryRequest::UpdateCategoryRequest()
    : RpcServiceRequest("vod", "2017-03-21", "UpdateCategory") {
  setMethod(HttpRequest::Method::Post);
}

UpdateCategoryRequest::~UpdateCategoryRequest() {}

long UpdateCategoryRequest::getCateId() const {
  return cateId_;
}

void UpdateCategoryRequest::setCateId(long cateId) {
  cateId_ = cateId;
  setParameter(std::string("CateId"), std::to_string(cateId));
}

std::string UpdateCategoryRequest::getCateName() const {
  return cateName_;
}

void UpdateCategoryRequest::setCateName(const std::string &cateName) {
  cateName_ = cateName;
  setParameter(std::string("CateName"), cateName);
}

