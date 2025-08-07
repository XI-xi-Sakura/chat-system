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

#include <alibabacloud/vcs/model/CreateVideoSummaryTaskResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Vcs;
using namespace AlibabaCloud::Vcs::Model;

CreateVideoSummaryTaskResult::CreateVideoSummaryTaskResult() :
	ServiceResult()
{}

CreateVideoSummaryTaskResult::CreateVideoSummaryTaskResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

CreateVideoSummaryTaskResult::~CreateVideoSummaryTaskResult()
{}

void CreateVideoSummaryTaskResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	if(!value["Code"].isNull())
		code_ = value["Code"].asString();
	if(!value["Message"].isNull())
		message_ = value["Message"].asString();
	if(!value["Data"].isNull())
		data_ = value["Data"].asString();

}

std::string CreateVideoSummaryTaskResult::getMessage()const
{
	return message_;
}

std::string CreateVideoSummaryTaskResult::getData()const
{
	return data_;
}

std::string CreateVideoSummaryTaskResult::getCode()const
{
	return code_;
}

