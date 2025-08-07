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

#include <alibabacloud/config/model/ListSupportedProductsRequest.h>

using AlibabaCloud::Config::Model::ListSupportedProductsRequest;

ListSupportedProductsRequest::ListSupportedProductsRequest()
    : RpcServiceRequest("config", "2020-09-07", "ListSupportedProducts") {
  setMethod(HttpRequest::Method::Post);
}

ListSupportedProductsRequest::~ListSupportedProductsRequest() {}

std::string ListSupportedProductsRequest::getNextToken() const {
  return nextToken_;
}

void ListSupportedProductsRequest::setNextToken(const std::string &nextToken) {
  nextToken_ = nextToken;
  setParameter(std::string("NextToken"), nextToken);
}

int ListSupportedProductsRequest::getMaxResults() const {
  return maxResults_;
}

void ListSupportedProductsRequest::setMaxResults(int maxResults) {
  maxResults_ = maxResults;
  setParameter(std::string("MaxResults"), std::to_string(maxResults));
}

