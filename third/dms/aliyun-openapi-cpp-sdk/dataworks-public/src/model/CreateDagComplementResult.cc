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

#include <alibabacloud/dataworks-public/model/CreateDagComplementResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Dataworks_public;
using namespace AlibabaCloud::Dataworks_public::Model;

CreateDagComplementResult::CreateDagComplementResult() :
	ServiceResult()
{}

CreateDagComplementResult::CreateDagComplementResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

CreateDagComplementResult::~CreateDagComplementResult()
{}

void CreateDagComplementResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allData = value["Data"]["dagId"];
	for (const auto &item : allData)
		data_.push_back(item.asString());
	if(!value["HttpStatusCode"].isNull())
		httpStatusCode_ = std::stoi(value["HttpStatusCode"].asString());
	if(!value["ErrorMessage"].isNull())
		errorMessage_ = value["ErrorMessage"].asString();
	if(!value["Success"].isNull())
		success_ = value["Success"].asString() == "true";
	if(!value["ErrorCode"].isNull())
		errorCode_ = value["ErrorCode"].asString();

}

int CreateDagComplementResult::getHttpStatusCode()const
{
	return httpStatusCode_;
}

std::vector<std::string> CreateDagComplementResult::getData()const
{
	return data_;
}

std::string CreateDagComplementResult::getErrorCode()const
{
	return errorCode_;
}

std::string CreateDagComplementResult::getErrorMessage()const
{
	return errorMessage_;
}

bool CreateDagComplementResult::getSuccess()const
{
	return success_;
}

