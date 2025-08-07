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

#include <alibabacloud/mse/model/DeleteNacosConfigsResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Mse;
using namespace AlibabaCloud::Mse::Model;

DeleteNacosConfigsResult::DeleteNacosConfigsResult() :
	ServiceResult()
{}

DeleteNacosConfigsResult::DeleteNacosConfigsResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

DeleteNacosConfigsResult::~DeleteNacosConfigsResult()
{}

void DeleteNacosConfigsResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	if(!value["HttpCode"].isNull())
		httpCode_ = value["HttpCode"].asString();
	if(!value["Message"].isNull())
		message_ = value["Message"].asString();
	if(!value["ErrorCode"].isNull())
		errorCode_ = value["ErrorCode"].asString();
	if(!value["Code"].isNull())
		code_ = std::stoi(value["Code"].asString());
	if(!value["Success"].isNull())
		success_ = value["Success"].asString() == "true";

}

std::string DeleteNacosConfigsResult::getHttpCode()const
{
	return httpCode_;
}

std::string DeleteNacosConfigsResult::getMessage()const
{
	return message_;
}

std::string DeleteNacosConfigsResult::getErrorCode()const
{
	return errorCode_;
}

int DeleteNacosConfigsResult::getCode()const
{
	return code_;
}

bool DeleteNacosConfigsResult::getSuccess()const
{
	return success_;
}

