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

#include <alibabacloud/alimt/model/TranslateImageResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Alimt;
using namespace AlibabaCloud::Alimt::Model;

TranslateImageResult::TranslateImageResult() :
	ServiceResult()
{}

TranslateImageResult::TranslateImageResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

TranslateImageResult::~TranslateImageResult()
{}

void TranslateImageResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto dataNode = value["Data"];
	if(!dataNode["InPaintingUrl"].isNull())
		data_.inPaintingUrl = dataNode["InPaintingUrl"].asString();
	if(!dataNode["TemplateJson"].isNull())
		data_.templateJson = dataNode["TemplateJson"].asString();
	if(!dataNode["FinalImageUrl"].isNull())
		data_.finalImageUrl = dataNode["FinalImageUrl"].asString();
	if(!value["Code"].isNull())
		code_ = std::stoi(value["Code"].asString());
	if(!value["Message"].isNull())
		message_ = value["Message"].asString();

}

std::string TranslateImageResult::getMessage()const
{
	return message_;
}

TranslateImageResult::Data TranslateImageResult::getData()const
{
	return data_;
}

int TranslateImageResult::getCode()const
{
	return code_;
}

