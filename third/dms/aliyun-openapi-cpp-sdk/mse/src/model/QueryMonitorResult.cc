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

#include <alibabacloud/mse/model/QueryMonitorResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Mse;
using namespace AlibabaCloud::Mse::Model;

QueryMonitorResult::QueryMonitorResult() :
	ServiceResult()
{}

QueryMonitorResult::QueryMonitorResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

QueryMonitorResult::~QueryMonitorResult()
{}

void QueryMonitorResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allDataNode = value["Data"]["dataItem"];
	for (auto valueDatadataItem : allDataNode)
	{
		DataItem dataObject;
		if(!valueDatadataItem["podName"].isNull())
			dataObject.podName = valueDatadataItem["podName"].asString();
		if(!valueDatadataItem["clusterNamePrefix"].isNull())
			dataObject.clusterNamePrefix = valueDatadataItem["clusterNamePrefix"].asString();
		auto allValues = value["values"]["values"];
		for (auto value : allValues)
			dataObject.values.push_back(value.asString());
		data_.push_back(dataObject);
	}
	if(!value["Message"].isNull())
		message_ = value["Message"].asString();
	if(!value["ErrorCode"].isNull())
		errorCode_ = value["ErrorCode"].asString();
	if(!value["Success"].isNull())
		success_ = value["Success"].asString() == "true";

}

std::string QueryMonitorResult::getMessage()const
{
	return message_;
}

std::vector<QueryMonitorResult::DataItem> QueryMonitorResult::getData()const
{
	return data_;
}

std::string QueryMonitorResult::getErrorCode()const
{
	return errorCode_;
}

bool QueryMonitorResult::getSuccess()const
{
	return success_;
}

