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

#include <alibabacloud/reid/model/ListEmapResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Reid;
using namespace AlibabaCloud::Reid::Model;

ListEmapResult::ListEmapResult() :
	ServiceResult()
{}

ListEmapResult::ListEmapResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

ListEmapResult::~ListEmapResult()
{}

void ListEmapResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allOpenEmapsNode = value["OpenEmaps"]["OpenEmap"];
	for (auto valueOpenEmapsOpenEmap : allOpenEmapsNode)
	{
		OpenEmap openEmapsObject;
		if(!valueOpenEmapsOpenEmap["LocationId"].isNull())
			openEmapsObject.locationId = valueOpenEmapsOpenEmap["LocationId"].asString();
		if(!valueOpenEmapsOpenEmap["EmapId"].isNull())
			openEmapsObject.emapId = valueOpenEmapsOpenEmap["EmapId"].asString();
		if(!valueOpenEmapsOpenEmap["Name"].isNull())
			openEmapsObject.name = valueOpenEmapsOpenEmap["Name"].asString();
		if(!valueOpenEmapsOpenEmap["EmapUrl"].isNull())
			openEmapsObject.emapUrl = valueOpenEmapsOpenEmap["EmapUrl"].asString();
		openEmaps_.push_back(openEmapsObject);
	}
	if(!value["ErrorCode"].isNull())
		errorCode_ = value["ErrorCode"].asString();
	if(!value["ErrorMessage"].isNull())
		errorMessage_ = value["ErrorMessage"].asString();
	if(!value["Success"].isNull())
		success_ = value["Success"].asString() == "true";

}

std::vector<ListEmapResult::OpenEmap> ListEmapResult::getOpenEmaps()const
{
	return openEmaps_;
}

std::string ListEmapResult::getErrorCode()const
{
	return errorCode_;
}

std::string ListEmapResult::getErrorMessage()const
{
	return errorMessage_;
}

bool ListEmapResult::getSuccess()const
{
	return success_;
}

