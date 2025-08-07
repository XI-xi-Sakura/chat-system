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

#include <alibabacloud/ens/model/UnloadRegionSDGResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Ens;
using namespace AlibabaCloud::Ens::Model;

UnloadRegionSDGResult::UnloadRegionSDGResult() :
	ServiceResult()
{}

UnloadRegionSDGResult::UnloadRegionSDGResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

UnloadRegionSDGResult::~UnloadRegionSDGResult()
{}

void UnloadRegionSDGResult::parse(const std::string &payload)
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
		if(!resultNodeFailedItemsFailedItemsItem["ErrorMessage"].isNull())
			failedItemsItemObject.errorMessage = resultNodeFailedItemsFailedItemsItem["ErrorMessage"].asString();
		if(!resultNodeFailedItemsFailedItemsItem["DestinationRegionId"].isNull())
			failedItemsItemObject.destinationRegionId = resultNodeFailedItemsFailedItemsItem["DestinationRegionId"].asString();
		data_.result.failedItems.push_back(failedItemsItemObject);
	}

}

UnloadRegionSDGResult::Data UnloadRegionSDGResult::getData()const
{
	return data_;
}

