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

#include <alibabacloud/mse/model/ListClusterTypesResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Mse;
using namespace AlibabaCloud::Mse::Model;

ListClusterTypesResult::ListClusterTypesResult() :
	ServiceResult()
{}

ListClusterTypesResult::ListClusterTypesResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

ListClusterTypesResult::~ListClusterTypesResult()
{}

void ListClusterTypesResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allDataNode = value["Data"]["DataItem"];
	for (auto valueDataDataItem : allDataNode)
	{
		DataItem dataObject;
		if(!valueDataDataItem["Code"].isNull())
			dataObject.code = valueDataDataItem["Code"].asString();
		if(!valueDataDataItem["ShowName"].isNull())
			dataObject.showName = valueDataDataItem["ShowName"].asString();
		data_.push_back(dataObject);
	}
	if(!value["HttpStatusCode"].isNull())
		httpStatusCode_ = std::stoi(value["HttpStatusCode"].asString());
	if(!value["Success"].isNull())
		success_ = value["Success"].asString() == "true";
	if(!value["ErrorCode"].isNull())
		errorCode_ = value["ErrorCode"].asString();
	if(!value["Code"].isNull())
		code_ = std::stoi(value["Code"].asString());
	if(!value["Message"].isNull())
		message_ = value["Message"].asString();
	if(!value["DynamicMessage"].isNull())
		dynamicMessage_ = value["DynamicMessage"].asString();

}

std::string ListClusterTypesResult::getMessage()const
{
	return message_;
}

int ListClusterTypesResult::getHttpStatusCode()const
{
	return httpStatusCode_;
}

std::vector<ListClusterTypesResult::DataItem> ListClusterTypesResult::getData()const
{
	return data_;
}

std::string ListClusterTypesResult::getErrorCode()const
{
	return errorCode_;
}

std::string ListClusterTypesResult::getDynamicMessage()const
{
	return dynamicMessage_;
}

int ListClusterTypesResult::getCode()const
{
	return code_;
}

bool ListClusterTypesResult::getSuccess()const
{
	return success_;
}

