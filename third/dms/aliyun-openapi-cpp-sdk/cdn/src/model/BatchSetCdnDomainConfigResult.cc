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

#include <alibabacloud/cdn/model/BatchSetCdnDomainConfigResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Cdn;
using namespace AlibabaCloud::Cdn::Model;

BatchSetCdnDomainConfigResult::BatchSetCdnDomainConfigResult() :
	ServiceResult()
{}

BatchSetCdnDomainConfigResult::BatchSetCdnDomainConfigResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

BatchSetCdnDomainConfigResult::~BatchSetCdnDomainConfigResult()
{}

void BatchSetCdnDomainConfigResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allDomainConfigListNode = value["DomainConfigList"]["DomainConfigModel"];
	for (auto valueDomainConfigListDomainConfigModel : allDomainConfigListNode)
	{
		DomainConfigModel domainConfigListObject;
		if(!valueDomainConfigListDomainConfigModel["ConfigId"].isNull())
			domainConfigListObject.configId = std::stol(valueDomainConfigListDomainConfigModel["ConfigId"].asString());
		if(!valueDomainConfigListDomainConfigModel["DomainName"].isNull())
			domainConfigListObject.domainName = valueDomainConfigListDomainConfigModel["DomainName"].asString();
		if(!valueDomainConfigListDomainConfigModel["FunctionName"].isNull())
			domainConfigListObject.functionName = valueDomainConfigListDomainConfigModel["FunctionName"].asString();
		domainConfigList_.push_back(domainConfigListObject);
	}

}

std::vector<BatchSetCdnDomainConfigResult::DomainConfigModel> BatchSetCdnDomainConfigResult::getDomainConfigList()const
{
	return domainConfigList_;
}

