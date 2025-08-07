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

#include <alibabacloud/cloudapi/model/DescribeDatasetListResult.h>
#include <json/json.h>

using namespace AlibabaCloud::CloudAPI;
using namespace AlibabaCloud::CloudAPI::Model;

DescribeDatasetListResult::DescribeDatasetListResult() :
	ServiceResult()
{}

DescribeDatasetListResult::DescribeDatasetListResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

DescribeDatasetListResult::~DescribeDatasetListResult()
{}

void DescribeDatasetListResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allDatasetInfoListNode = value["DatasetInfoList"]["DatasetInfo"];
	for (auto valueDatasetInfoListDatasetInfo : allDatasetInfoListNode)
	{
		DatasetInfo datasetInfoListObject;
		if(!valueDatasetInfoListDatasetInfo["DatasetId"].isNull())
			datasetInfoListObject.datasetId = valueDatasetInfoListDatasetInfo["DatasetId"].asString();
		if(!valueDatasetInfoListDatasetInfo["DatasetName"].isNull())
			datasetInfoListObject.datasetName = valueDatasetInfoListDatasetInfo["DatasetName"].asString();
		if(!valueDatasetInfoListDatasetInfo["DatasetType"].isNull())
			datasetInfoListObject.datasetType = valueDatasetInfoListDatasetInfo["DatasetType"].asString();
		if(!valueDatasetInfoListDatasetInfo["ModifiedTime"].isNull())
			datasetInfoListObject.modifiedTime = valueDatasetInfoListDatasetInfo["ModifiedTime"].asString();
		if(!valueDatasetInfoListDatasetInfo["CreatedTime"].isNull())
			datasetInfoListObject.createdTime = valueDatasetInfoListDatasetInfo["CreatedTime"].asString();
		datasetInfoList_.push_back(datasetInfoListObject);
	}
	if(!value["PageNumber"].isNull())
		pageNumber_ = std::stoi(value["PageNumber"].asString());
	if(!value["PageSize"].isNull())
		pageSize_ = std::stoi(value["PageSize"].asString());
	if(!value["TotalCount"].isNull())
		totalCount_ = std::stoi(value["TotalCount"].asString());

}

int DescribeDatasetListResult::getTotalCount()const
{
	return totalCount_;
}

int DescribeDatasetListResult::getPageSize()const
{
	return pageSize_;
}

int DescribeDatasetListResult::getPageNumber()const
{
	return pageNumber_;
}

std::vector<DescribeDatasetListResult::DatasetInfo> DescribeDatasetListResult::getDatasetInfoList()const
{
	return datasetInfoList_;
}

