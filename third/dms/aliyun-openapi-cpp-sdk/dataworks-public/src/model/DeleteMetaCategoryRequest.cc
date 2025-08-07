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

#include <alibabacloud/dataworks-public/model/DeleteMetaCategoryRequest.h>

using AlibabaCloud::Dataworks_public::Model::DeleteMetaCategoryRequest;

DeleteMetaCategoryRequest::DeleteMetaCategoryRequest()
    : RpcServiceRequest("dataworks-public", "2020-05-18", "DeleteMetaCategory") {
  setMethod(HttpRequest::Method::Get);
}

DeleteMetaCategoryRequest::~DeleteMetaCategoryRequest() {}

long DeleteMetaCategoryRequest::getCategoryId() const {
  return categoryId_;
}

void DeleteMetaCategoryRequest::setCategoryId(long categoryId) {
  categoryId_ = categoryId;
  setParameter(std::string("CategoryId"), std::to_string(categoryId));
}

