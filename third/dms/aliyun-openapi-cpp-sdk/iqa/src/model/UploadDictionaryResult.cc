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

#include <alibabacloud/iqa/model/UploadDictionaryResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Iqa;
using namespace AlibabaCloud::Iqa::Model;

UploadDictionaryResult::UploadDictionaryResult() :
	ServiceResult()
{}

UploadDictionaryResult::UploadDictionaryResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

UploadDictionaryResult::~UploadDictionaryResult()
{}

void UploadDictionaryResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	if(!value["ProjectId"].isNull())
		projectId_ = value["ProjectId"].asString();
	if(!value["TotalCount"].isNull())
		totalCount_ = std::stoi(value["TotalCount"].asString());
	if(!value["FileDataCount"].isNull())
		fileDataCount_ = std::stoi(value["FileDataCount"].asString());
	if(!value["JsonDataCount"].isNull())
		jsonDataCount_ = std::stoi(value["JsonDataCount"].asString());

}

int UploadDictionaryResult::getTotalCount()const
{
	return totalCount_;
}

std::string UploadDictionaryResult::getProjectId()const
{
	return projectId_;
}

int UploadDictionaryResult::getFileDataCount()const
{
	return fileDataCount_;
}

int UploadDictionaryResult::getJsonDataCount()const
{
	return jsonDataCount_;
}

