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

#include <alibabacloud/cdrs/model/ListMapRouteDetailsRequest.h>

using AlibabaCloud::CDRS::Model::ListMapRouteDetailsRequest;

ListMapRouteDetailsRequest::ListMapRouteDetailsRequest() :
	RpcServiceRequest("cdrs", "2020-11-01", "ListMapRouteDetails")
{
	setMethod(HttpRequest::Method::Post);
}

ListMapRouteDetailsRequest::~ListMapRouteDetailsRequest()
{}

std::string ListMapRouteDetailsRequest::getRouteList()const
{
	return routeList_;
}

void ListMapRouteDetailsRequest::setRouteList(const std::string& routeList)
{
	routeList_ = routeList;
	setBodyParameter("RouteList", routeList);
}

