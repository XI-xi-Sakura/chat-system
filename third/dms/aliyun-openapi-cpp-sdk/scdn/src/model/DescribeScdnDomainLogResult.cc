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

#include <alibabacloud/scdn/model/DescribeScdnDomainLogResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Scdn;
using namespace AlibabaCloud::Scdn::Model;

DescribeScdnDomainLogResult::DescribeScdnDomainLogResult() :
	ServiceResult()
{}

DescribeScdnDomainLogResult::DescribeScdnDomainLogResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

DescribeScdnDomainLogResult::~DescribeScdnDomainLogResult()
{}

void DescribeScdnDomainLogResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allDomainLogDetailsNode = value["DomainLogDetails"]["DomainLogDetail"];
	for (auto valueDomainLogDetailsDomainLogDetail : allDomainLogDetailsNode)
	{
		DomainLogDetail domainLogDetailsObject;
		if(!valueDomainLogDetailsDomainLogDetail["LogCount"].isNull())
			domainLogDetailsObject.logCount = std::stol(valueDomainLogDetailsDomainLogDetail["LogCount"].asString());
		auto allLogInfosNode = valueDomainLogDetailsDomainLogDetail["LogInfos"]["LogInfoDetail"];
		for (auto valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail : allLogInfosNode)
		{
			DomainLogDetail::LogInfoDetail logInfosObject;
			if(!valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail["EndTime"].isNull())
				logInfosObject.endTime = valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail["EndTime"].asString();
			if(!valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail["LogSize"].isNull())
				logInfosObject.logSize = std::stol(valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail["LogSize"].asString());
			if(!valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail["StartTime"].isNull())
				logInfosObject.startTime = valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail["StartTime"].asString();
			if(!valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail["LogName"].isNull())
				logInfosObject.logName = valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail["LogName"].asString();
			if(!valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail["LogPath"].isNull())
				logInfosObject.logPath = valueDomainLogDetailsDomainLogDetailLogInfosLogInfoDetail["LogPath"].asString();
			domainLogDetailsObject.logInfos.push_back(logInfosObject);
		}
		auto pageInfosNode = value["PageInfos"];
		if(!pageInfosNode["PageNumber"].isNull())
			domainLogDetailsObject.pageInfos.pageNumber = std::stol(pageInfosNode["PageNumber"].asString());
		if(!pageInfosNode["PageSize"].isNull())
			domainLogDetailsObject.pageInfos.pageSize = std::stol(pageInfosNode["PageSize"].asString());
		if(!pageInfosNode["Total"].isNull())
			domainLogDetailsObject.pageInfos.total = std::stol(pageInfosNode["Total"].asString());
		domainLogDetails_.push_back(domainLogDetailsObject);
	}
	if(!value["DomainName"].isNull())
		domainName_ = value["DomainName"].asString();

}

std::string DescribeScdnDomainLogResult::getDomainName()const
{
	return domainName_;
}

std::vector<DescribeScdnDomainLogResult::DomainLogDetail> DescribeScdnDomainLogResult::getDomainLogDetails()const
{
	return domainLogDetails_;
}

