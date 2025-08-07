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

#include <alibabacloud/eais/model/AttachEaiResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Eais;
using namespace AlibabaCloud::Eais::Model;

AttachEaiResult::AttachEaiResult() :
	ServiceResult()
{}

AttachEaiResult::AttachEaiResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

AttachEaiResult::~AttachEaiResult()
{}

void AttachEaiResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	if(!value["ElasticAcceleratedInstanceId"].isNull())
		elasticAcceleratedInstanceId_ = value["ElasticAcceleratedInstanceId"].asString();
	if(!value["ClientInstanceId"].isNull())
		clientInstanceId_ = value["ClientInstanceId"].asString();

}

std::string AttachEaiResult::getClientInstanceId()const
{
	return clientInstanceId_;
}

std::string AttachEaiResult::getElasticAcceleratedInstanceId()const
{
	return elasticAcceleratedInstanceId_;
}

