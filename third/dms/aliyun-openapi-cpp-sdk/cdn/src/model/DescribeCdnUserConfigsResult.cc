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

#include <alibabacloud/cdn/model/DescribeCdnUserConfigsResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Cdn;
using namespace AlibabaCloud::Cdn::Model;

DescribeCdnUserConfigsResult::DescribeCdnUserConfigsResult() :
	ServiceResult()
{}

DescribeCdnUserConfigsResult::DescribeCdnUserConfigsResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

DescribeCdnUserConfigsResult::~DescribeCdnUserConfigsResult()
{}

void DescribeCdnUserConfigsResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allConfigsNode = value["Configs"]["Config"];
	for (auto valueConfigsConfig : allConfigsNode)
	{
		Config configsObject;
		if(!valueConfigsConfig["ArgValue"].isNull())
			configsObject.argValue = valueConfigsConfig["ArgValue"].asString();
		if(!valueConfigsConfig["ArgName"].isNull())
			configsObject.argName = valueConfigsConfig["ArgName"].asString();
		if(!valueConfigsConfig["FunctionName"].isNull())
			configsObject.functionName = valueConfigsConfig["FunctionName"].asString();
		configs_.push_back(configsObject);
	}

}

std::vector<DescribeCdnUserConfigsResult::Config> DescribeCdnUserConfigsResult::getConfigs()const
{
	return configs_;
}

