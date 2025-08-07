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

#include <alibabacloud/quotas/model/ListAlarmHistoriesResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Quotas;
using namespace AlibabaCloud::Quotas::Model;

ListAlarmHistoriesResult::ListAlarmHistoriesResult() :
	ServiceResult()
{}

ListAlarmHistoriesResult::ListAlarmHistoriesResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

ListAlarmHistoriesResult::~ListAlarmHistoriesResult()
{}

void ListAlarmHistoriesResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allAlarmHistoriesNode = value["AlarmHistories"]["AlarmHistory"];
	for (auto valueAlarmHistoriesAlarmHistory : allAlarmHistoriesNode)
	{
		AlarmHistory alarmHistoriesObject;
		if(!valueAlarmHistoriesAlarmHistory["QuotaUsage"].isNull())
			alarmHistoriesObject.quotaUsage = std::stof(valueAlarmHistoriesAlarmHistory["QuotaUsage"].asString());
		if(!valueAlarmHistoriesAlarmHistory["ThresholdPercent"].isNull())
			alarmHistoriesObject.thresholdPercent = std::stof(valueAlarmHistoriesAlarmHistory["ThresholdPercent"].asString());
		if(!valueAlarmHistoriesAlarmHistory["CreateTime"].isNull())
			alarmHistoriesObject.createTime = valueAlarmHistoriesAlarmHistory["CreateTime"].asString();
		if(!valueAlarmHistoriesAlarmHistory["QuotaActionCode"].isNull())
			alarmHistoriesObject.quotaActionCode = valueAlarmHistoriesAlarmHistory["QuotaActionCode"].asString();
		if(!valueAlarmHistoriesAlarmHistory["AlarmName"].isNull())
			alarmHistoriesObject.alarmName = valueAlarmHistoriesAlarmHistory["AlarmName"].asString();
		if(!valueAlarmHistoriesAlarmHistory["NotifyTarget"].isNull())
			alarmHistoriesObject.notifyTarget = valueAlarmHistoriesAlarmHistory["NotifyTarget"].asString();
		if(!valueAlarmHistoriesAlarmHistory["Threshold"].isNull())
			alarmHistoriesObject.threshold = std::stof(valueAlarmHistoriesAlarmHistory["Threshold"].asString());
		if(!valueAlarmHistoriesAlarmHistory["ProductCode"].isNull())
			alarmHistoriesObject.productCode = valueAlarmHistoriesAlarmHistory["ProductCode"].asString();
		auto allNotifyChannels = value["NotifyChannels"]["NotifyChannels"];
		for (auto value : allNotifyChannels)
			alarmHistoriesObject.notifyChannels.push_back(value.asString());
		alarmHistories_.push_back(alarmHistoriesObject);
	}
	if(!value["TotalCount"].isNull())
		totalCount_ = std::stoi(value["TotalCount"].asString());
	if(!value["NextToken"].isNull())
		nextToken_ = value["NextToken"].asString();
	if(!value["MaxResults"].isNull())
		maxResults_ = std::stoi(value["MaxResults"].asString());

}

int ListAlarmHistoriesResult::getTotalCount()const
{
	return totalCount_;
}

std::string ListAlarmHistoriesResult::getNextToken()const
{
	return nextToken_;
}

int ListAlarmHistoriesResult::getMaxResults()const
{
	return maxResults_;
}

std::vector<ListAlarmHistoriesResult::AlarmHistory> ListAlarmHistoriesResult::getAlarmHistories()const
{
	return alarmHistories_;
}

