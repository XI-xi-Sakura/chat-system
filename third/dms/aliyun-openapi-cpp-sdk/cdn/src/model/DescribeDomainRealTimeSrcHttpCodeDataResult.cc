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

#include <alibabacloud/cdn/model/DescribeDomainRealTimeSrcHttpCodeDataResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Cdn;
using namespace AlibabaCloud::Cdn::Model;

DescribeDomainRealTimeSrcHttpCodeDataResult::DescribeDomainRealTimeSrcHttpCodeDataResult() :
	ServiceResult()
{}

DescribeDomainRealTimeSrcHttpCodeDataResult::DescribeDomainRealTimeSrcHttpCodeDataResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

DescribeDomainRealTimeSrcHttpCodeDataResult::~DescribeDomainRealTimeSrcHttpCodeDataResult()
{}

void DescribeDomainRealTimeSrcHttpCodeDataResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allRealTimeSrcHttpCodeDataNode = value["RealTimeSrcHttpCodeData"]["UsageData"];
	for (auto valueRealTimeSrcHttpCodeDataUsageData : allRealTimeSrcHttpCodeDataNode)
	{
		UsageData realTimeSrcHttpCodeDataObject;
		if(!valueRealTimeSrcHttpCodeDataUsageData["TimeStamp"].isNull())
			realTimeSrcHttpCodeDataObject.timeStamp = valueRealTimeSrcHttpCodeDataUsageData["TimeStamp"].asString();
		auto allValueNode = valueRealTimeSrcHttpCodeDataUsageData["Value"]["RealTimeSrcCodeProportionData"];
		for (auto valueRealTimeSrcHttpCodeDataUsageDataValueRealTimeSrcCodeProportionData : allValueNode)
		{
			UsageData::RealTimeSrcCodeProportionData valueObject;
			if(!valueRealTimeSrcHttpCodeDataUsageDataValueRealTimeSrcCodeProportionData["Code"].isNull())
				valueObject.code = valueRealTimeSrcHttpCodeDataUsageDataValueRealTimeSrcCodeProportionData["Code"].asString();
			if(!valueRealTimeSrcHttpCodeDataUsageDataValueRealTimeSrcCodeProportionData["Proportion"].isNull())
				valueObject.proportion = valueRealTimeSrcHttpCodeDataUsageDataValueRealTimeSrcCodeProportionData["Proportion"].asString();
			if(!valueRealTimeSrcHttpCodeDataUsageDataValueRealTimeSrcCodeProportionData["Count"].isNull())
				valueObject.count = valueRealTimeSrcHttpCodeDataUsageDataValueRealTimeSrcCodeProportionData["Count"].asString();
			realTimeSrcHttpCodeDataObject.value.push_back(valueObject);
		}
		realTimeSrcHttpCodeData_.push_back(realTimeSrcHttpCodeDataObject);
	}
	if(!value["EndTime"].isNull())
		endTime_ = value["EndTime"].asString();
	if(!value["StartTime"].isNull())
		startTime_ = value["StartTime"].asString();
	if(!value["DomainName"].isNull())
		domainName_ = value["DomainName"].asString();
	if(!value["DataInterval"].isNull())
		dataInterval_ = value["DataInterval"].asString();

}

std::string DescribeDomainRealTimeSrcHttpCodeDataResult::getEndTime()const
{
	return endTime_;
}

std::string DescribeDomainRealTimeSrcHttpCodeDataResult::getDomainName()const
{
	return domainName_;
}

std::string DescribeDomainRealTimeSrcHttpCodeDataResult::getStartTime()const
{
	return startTime_;
}

std::string DescribeDomainRealTimeSrcHttpCodeDataResult::getDataInterval()const
{
	return dataInterval_;
}

std::vector<DescribeDomainRealTimeSrcHttpCodeDataResult::UsageData> DescribeDomainRealTimeSrcHttpCodeDataResult::getRealTimeSrcHttpCodeData()const
{
	return realTimeSrcHttpCodeData_;
}

