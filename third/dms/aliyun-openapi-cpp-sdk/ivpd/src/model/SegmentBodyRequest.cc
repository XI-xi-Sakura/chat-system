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

#include <alibabacloud/ivpd/model/SegmentBodyRequest.h>

using AlibabaCloud::Ivpd::Model::SegmentBodyRequest;

SegmentBodyRequest::SegmentBodyRequest() :
	RpcServiceRequest("ivpd", "2019-06-25", "SegmentBody")
{
	setMethod(HttpRequest::Method::Post);
}

SegmentBodyRequest::~SegmentBodyRequest()
{}

std::string SegmentBodyRequest::getImageUrl()const
{
	return imageUrl_;
}

void SegmentBodyRequest::setImageUrl(const std::string& imageUrl)
{
	imageUrl_ = imageUrl;
	setBodyParameter("ImageUrl", imageUrl);
}

