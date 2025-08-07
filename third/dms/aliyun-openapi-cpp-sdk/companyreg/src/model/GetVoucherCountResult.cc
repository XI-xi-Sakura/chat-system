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

#include <alibabacloud/companyreg/model/GetVoucherCountResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Companyreg;
using namespace AlibabaCloud::Companyreg::Model;

GetVoucherCountResult::GetVoucherCountResult() :
	ServiceResult()
{}

GetVoucherCountResult::GetVoucherCountResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

GetVoucherCountResult::~GetVoucherCountResult()
{}

void GetVoucherCountResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allDataNode = value["Data"]["DataItem"];
	for (auto valueDataDataItem : allDataNode)
	{
		DataItem dataObject;
		if(!valueDataDataItem["Period"].isNull())
			dataObject.period = valueDataDataItem["Period"].asString();
		if(!valueDataDataItem["Count"].isNull())
			dataObject.count = std::stoi(valueDataDataItem["Count"].asString());
		data_.push_back(dataObject);
	}

}

std::vector<GetVoucherCountResult::DataItem> GetVoucherCountResult::getData()const
{
	return data_;
}

