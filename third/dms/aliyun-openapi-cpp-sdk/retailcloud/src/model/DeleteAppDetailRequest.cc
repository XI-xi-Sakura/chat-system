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

#include <alibabacloud/retailcloud/model/DeleteAppDetailRequest.h>

using AlibabaCloud::Retailcloud::Model::DeleteAppDetailRequest;

DeleteAppDetailRequest::DeleteAppDetailRequest() :
	RpcServiceRequest("retailcloud", "2018-03-13", "DeleteAppDetail")
{
	setMethod(HttpRequest::Method::Get);
}

DeleteAppDetailRequest::~DeleteAppDetailRequest()
{}

long DeleteAppDetailRequest::getAppId()const
{
	return appId_;
}

void DeleteAppDetailRequest::setAppId(long appId)
{
	appId_ = appId;
	setParameter("AppId", std::to_string(appId));
}

bool DeleteAppDetailRequest::getForce()const
{
	return force_;
}

void DeleteAppDetailRequest::setForce(bool force)
{
	force_ = force;
	setParameter("Force", force ? "true" : "false");
}

