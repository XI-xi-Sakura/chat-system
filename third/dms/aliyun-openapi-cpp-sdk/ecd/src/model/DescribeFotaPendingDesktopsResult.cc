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

#include <alibabacloud/ecd/model/DescribeFotaPendingDesktopsResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Ecd;
using namespace AlibabaCloud::Ecd::Model;

DescribeFotaPendingDesktopsResult::DescribeFotaPendingDesktopsResult() :
	ServiceResult()
{}

DescribeFotaPendingDesktopsResult::DescribeFotaPendingDesktopsResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

DescribeFotaPendingDesktopsResult::~DescribeFotaPendingDesktopsResult()
{}

void DescribeFotaPendingDesktopsResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allFotaPendingDesktopsNode = value["FotaPendingDesktops"]["FotaPendingDesktop"];
	for (auto valueFotaPendingDesktopsFotaPendingDesktop : allFotaPendingDesktopsNode)
	{
		FotaPendingDesktop fotaPendingDesktopsObject;
		if(!valueFotaPendingDesktopsFotaPendingDesktop["DesktopId"].isNull())
			fotaPendingDesktopsObject.desktopId = valueFotaPendingDesktopsFotaPendingDesktop["DesktopId"].asString();
		if(!valueFotaPendingDesktopsFotaPendingDesktop["DesktopName"].isNull())
			fotaPendingDesktopsObject.desktopName = valueFotaPendingDesktopsFotaPendingDesktop["DesktopName"].asString();
		if(!valueFotaPendingDesktopsFotaPendingDesktop["OfficeSiteId"].isNull())
			fotaPendingDesktopsObject.officeSiteId = valueFotaPendingDesktopsFotaPendingDesktop["OfficeSiteId"].asString();
		if(!valueFotaPendingDesktopsFotaPendingDesktop["FotaProject"].isNull())
			fotaPendingDesktopsObject.fotaProject = valueFotaPendingDesktopsFotaPendingDesktop["FotaProject"].asString();
		if(!valueFotaPendingDesktopsFotaPendingDesktop["CurrentAppVersion"].isNull())
			fotaPendingDesktopsObject.currentAppVersion = valueFotaPendingDesktopsFotaPendingDesktop["CurrentAppVersion"].asString();
		fotaPendingDesktops_.push_back(fotaPendingDesktopsObject);
	}
	if(!value["NextToken"].isNull())
		nextToken_ = value["NextToken"].asString();

}

std::vector<DescribeFotaPendingDesktopsResult::FotaPendingDesktop> DescribeFotaPendingDesktopsResult::getFotaPendingDesktops()const
{
	return fotaPendingDesktops_;
}

std::string DescribeFotaPendingDesktopsResult::getNextToken()const
{
	return nextToken_;
}

