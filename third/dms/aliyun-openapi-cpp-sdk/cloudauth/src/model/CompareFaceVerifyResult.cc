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

#include <alibabacloud/cloudauth/model/CompareFaceVerifyResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Cloudauth;
using namespace AlibabaCloud::Cloudauth::Model;

CompareFaceVerifyResult::CompareFaceVerifyResult() :
	ServiceResult()
{}

CompareFaceVerifyResult::CompareFaceVerifyResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

CompareFaceVerifyResult::~CompareFaceVerifyResult()
{}

void CompareFaceVerifyResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto resultObjectNode = value["ResultObject"];
	if(!resultObjectNode["CertifyId"].isNull())
		resultObject_.certifyId = resultObjectNode["CertifyId"].asString();
	if(!resultObjectNode["VerifyScore"].isNull())
		resultObject_.verifyScore = std::stof(resultObjectNode["VerifyScore"].asString());
	if(!resultObjectNode["Passed"].isNull())
		resultObject_.passed = resultObjectNode["Passed"].asString();
	if(!value["Code"].isNull())
		code_ = value["Code"].asString();
	if(!value["Message"].isNull())
		message_ = value["Message"].asString();

}

CompareFaceVerifyResult::ResultObject CompareFaceVerifyResult::getResultObject()const
{
	return resultObject_;
}

std::string CompareFaceVerifyResult::getMessage()const
{
	return message_;
}

std::string CompareFaceVerifyResult::getCode()const
{
	return code_;
}

