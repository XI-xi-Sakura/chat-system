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

#include <alibabacloud/cloudauth/model/Id2MetaVerifyResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Cloudauth;
using namespace AlibabaCloud::Cloudauth::Model;

Id2MetaVerifyResult::Id2MetaVerifyResult() :
	ServiceResult()
{}

Id2MetaVerifyResult::Id2MetaVerifyResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

Id2MetaVerifyResult::~Id2MetaVerifyResult()
{}

void Id2MetaVerifyResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto resultObjectNode = value["ResultObject"];
	if(!resultObjectNode["BizCode"].isNull())
		resultObject_.bizCode = resultObjectNode["BizCode"].asString();
	if(!value["Code"].isNull())
		code_ = value["Code"].asString();
	if(!value["Message"].isNull())
		message_ = value["Message"].asString();

}

Id2MetaVerifyResult::ResultObject Id2MetaVerifyResult::getResultObject()const
{
	return resultObject_;
}

std::string Id2MetaVerifyResult::getMessage()const
{
	return message_;
}

std::string Id2MetaVerifyResult::getCode()const
{
	return code_;
}

