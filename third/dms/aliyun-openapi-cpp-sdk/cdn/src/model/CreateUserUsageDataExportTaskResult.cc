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

#include <alibabacloud/cdn/model/CreateUserUsageDataExportTaskResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Cdn;
using namespace AlibabaCloud::Cdn::Model;

CreateUserUsageDataExportTaskResult::CreateUserUsageDataExportTaskResult() :
	ServiceResult()
{}

CreateUserUsageDataExportTaskResult::CreateUserUsageDataExportTaskResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

CreateUserUsageDataExportTaskResult::~CreateUserUsageDataExportTaskResult()
{}

void CreateUserUsageDataExportTaskResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	if(!value["EndTime"].isNull())
		endTime_ = value["EndTime"].asString();
	if(!value["StartTime"].isNull())
		startTime_ = value["StartTime"].asString();
	if(!value["TaskId"].isNull())
		taskId_ = value["TaskId"].asString();

}

std::string CreateUserUsageDataExportTaskResult::getTaskId()const
{
	return taskId_;
}

std::string CreateUserUsageDataExportTaskResult::getEndTime()const
{
	return endTime_;
}

std::string CreateUserUsageDataExportTaskResult::getStartTime()const
{
	return startTime_;
}

