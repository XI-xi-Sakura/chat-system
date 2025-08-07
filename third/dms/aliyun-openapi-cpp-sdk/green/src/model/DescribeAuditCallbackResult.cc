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

#include <alibabacloud/green/model/DescribeAuditCallbackResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Green;
using namespace AlibabaCloud::Green::Model;

DescribeAuditCallbackResult::DescribeAuditCallbackResult() :
	ServiceResult()
{}

DescribeAuditCallbackResult::DescribeAuditCallbackResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

DescribeAuditCallbackResult::~DescribeAuditCallbackResult()
{}

void DescribeAuditCallbackResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	if(!value["Seed"].isNull())
		seed_ = value["Seed"].asString();
	if(!value["Callback"].isNull())
		callback_ = value["Callback"].asString();
	if(!value["CryptType"].isNull())
		cryptType_ = std::stoi(value["CryptType"].asString());

}

int DescribeAuditCallbackResult::getCryptType()const
{
	return cryptType_;
}

std::string DescribeAuditCallbackResult::getCallback()const
{
	return callback_;
}

std::string DescribeAuditCallbackResult::getSeed()const
{
	return seed_;
}

