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

#include <alibabacloud/ens/model/RemoveInstanceSDGResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Ens;
using namespace AlibabaCloud::Ens::Model;

RemoveInstanceSDGResult::RemoveInstanceSDGResult() :
	ServiceResult()
{}

RemoveInstanceSDGResult::RemoveInstanceSDGResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

RemoveInstanceSDGResult::~RemoveInstanceSDGResult()
{}

void RemoveInstanceSDGResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto dataNode = value["Data"];
	if(!dataNode["Message"].isNull())
		data_.message = dataNode["Message"].asString();
	if(!dataNode["Success"].isNull())
		data_.success = dataNode["Success"].asString() == "true";
	auto resultNode = dataNode["Result"];
	if(!resultNode["FailedCount"].isNull())
		data_.result.failedCount = std::stol(resultNode["FailedCount"].asString());
	if(!resultNode["SuccessCount"].isNull())
		data_.result.successCount = std::stol(resultNode["SuccessCount"].asString());
	auto allFailedItemsNode = resultNode["FailedItems"]["FailedItemsItem"];
	for (auto resultNodeFailedItemsFailedItemsItem : allFailedItemsNode)
	{
		Data::Result::FailedItemsItem failedItemsItemObject;
		if(!resultNodeFailedItemsFailedItemsItem["ErrMessage"].isNull())
			failedItemsItemObject.errMessage = resultNodeFailedItemsFailedItemsItem["ErrMessage"].asString();
		if(!resultNodeFailedItemsFailedItemsItem["InstanceId"].isNull())
			failedItemsItemObject.instanceId = resultNodeFailedItemsFailedItemsItem["InstanceId"].asString();
		data_.result.failedItems.push_back(failedItemsItemObject);
	}
	if(!value["Code"].isNull())
		code_ = std::stoi(value["Code"].asString());

}

RemoveInstanceSDGResult::Data RemoveInstanceSDGResult::getData()const
{
	return data_;
}

int RemoveInstanceSDGResult::getCode()const
{
	return code_;
}

