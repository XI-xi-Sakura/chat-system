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

#include <alibabacloud/mse/model/AddGatewayResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Mse;
using namespace AlibabaCloud::Mse::Model;

AddGatewayResult::AddGatewayResult() :
	ServiceResult()
{}

AddGatewayResult::AddGatewayResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

AddGatewayResult::~AddGatewayResult()
{}

void AddGatewayResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto dataNode = value["Data"];
	if(!dataNode["GatewayUniqueId"].isNull())
		data_.gatewayUniqueId = dataNode["GatewayUniqueId"].asString();
	if(!value["HttpStatusCode"].isNull())
		httpStatusCode_ = std::stoi(value["HttpStatusCode"].asString());
	if(!value["Message"].isNull())
		message_ = value["Message"].asString();
	if(!value["Code"].isNull())
		code_ = std::stoi(value["Code"].asString());
	if(!value["Success"].isNull())
		success_ = value["Success"].asString() == "true";

}

std::string AddGatewayResult::getMessage()const
{
	return message_;
}

int AddGatewayResult::getHttpStatusCode()const
{
	return httpStatusCode_;
}

AddGatewayResult::Data AddGatewayResult::getData()const
{
	return data_;
}

int AddGatewayResult::getCode()const
{
	return code_;
}

bool AddGatewayResult::getSuccess()const
{
	return success_;
}

