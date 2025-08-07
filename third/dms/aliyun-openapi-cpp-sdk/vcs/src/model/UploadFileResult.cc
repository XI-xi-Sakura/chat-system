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

#include <alibabacloud/vcs/model/UploadFileResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Vcs;
using namespace AlibabaCloud::Vcs::Model;

UploadFileResult::UploadFileResult() :
	ServiceResult()
{}

UploadFileResult::UploadFileResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

UploadFileResult::~UploadFileResult()
{}

void UploadFileResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto dataNode = value["Data"];
	auto allRecordsNode = dataNode["Records"]["OssPath"];
	for (auto dataNodeRecordsOssPath : allRecordsNode)
	{
		Data::OssPath ossPathObject;
		if(!dataNodeRecordsOssPath["OssPath"].isNull())
			ossPathObject.ossPath = dataNodeRecordsOssPath["OssPath"].asString();
		if(!dataNodeRecordsOssPath["SourceId"].isNull())
			ossPathObject.sourceId = dataNodeRecordsOssPath["SourceId"].asString();
		data_.records.push_back(ossPathObject);
	}
	if(!value["Code"].isNull())
		code_ = value["Code"].asString();
	if(!value["Message"].isNull())
		message_ = value["Message"].asString();

}

std::string UploadFileResult::getMessage()const
{
	return message_;
}

UploadFileResult::Data UploadFileResult::getData()const
{
	return data_;
}

std::string UploadFileResult::getCode()const
{
	return code_;
}

