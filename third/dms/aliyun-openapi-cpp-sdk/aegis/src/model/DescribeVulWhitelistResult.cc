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

#include <alibabacloud/aegis/model/DescribeVulWhitelistResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Aegis;
using namespace AlibabaCloud::Aegis::Model;

DescribeVulWhitelistResult::DescribeVulWhitelistResult() :
	ServiceResult()
{}

DescribeVulWhitelistResult::DescribeVulWhitelistResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

DescribeVulWhitelistResult::~DescribeVulWhitelistResult()
{}

void DescribeVulWhitelistResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allVulWhitelistsNode = value["VulWhitelists"]["VulWhitelist"];
	for (auto valueVulWhitelistsVulWhitelist : allVulWhitelistsNode)
	{
		VulWhitelist vulWhitelistsObject;
		if(!valueVulWhitelistsVulWhitelist["Name"].isNull())
			vulWhitelistsObject.name = valueVulWhitelistsVulWhitelist["Name"].asString();
		if(!valueVulWhitelistsVulWhitelist["Type"].isNull())
			vulWhitelistsObject.type = valueVulWhitelistsVulWhitelist["Type"].asString();
		if(!valueVulWhitelistsVulWhitelist["AliasName"].isNull())
			vulWhitelistsObject.aliasName = valueVulWhitelistsVulWhitelist["AliasName"].asString();
		if(!valueVulWhitelistsVulWhitelist["Reason"].isNull())
			vulWhitelistsObject.reason = valueVulWhitelistsVulWhitelist["Reason"].asString();
		vulWhitelists_.push_back(vulWhitelistsObject);
	}
	if(!value["PageSize"].isNull())
		pageSize_ = std::stoi(value["PageSize"].asString());
	if(!value["CurrentPage"].isNull())
		currentPage_ = std::stoi(value["CurrentPage"].asString());
	if(!value["TotalCount"].isNull())
		totalCount_ = std::stoi(value["TotalCount"].asString());

}

int DescribeVulWhitelistResult::getTotalCount()const
{
	return totalCount_;
}

std::vector<DescribeVulWhitelistResult::VulWhitelist> DescribeVulWhitelistResult::getVulWhitelists()const
{
	return vulWhitelists_;
}

int DescribeVulWhitelistResult::getPageSize()const
{
	return pageSize_;
}

int DescribeVulWhitelistResult::getCurrentPage()const
{
	return currentPage_;
}

