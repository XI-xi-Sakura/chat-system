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

#include <alibabacloud/dataworks-public/model/SearchMetaTablesResult.h>
#include <json/json.h>

using namespace AlibabaCloud::Dataworks_public;
using namespace AlibabaCloud::Dataworks_public::Model;

SearchMetaTablesResult::SearchMetaTablesResult() :
	ServiceResult()
{}

SearchMetaTablesResult::SearchMetaTablesResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

SearchMetaTablesResult::~SearchMetaTablesResult()
{}

void SearchMetaTablesResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto dataNode = value["Data"];
	if(!dataNode["PageNumber"].isNull())
		data_.pageNumber = std::stoi(dataNode["PageNumber"].asString());
	if(!dataNode["PageSize"].isNull())
		data_.pageSize = std::stoi(dataNode["PageSize"].asString());
	if(!dataNode["TotalCount"].isNull())
		data_.totalCount = std::stol(dataNode["TotalCount"].asString());
	auto allDataEntityListNode = dataNode["DataEntityList"]["DataEntityListItem"];
	for (auto dataNodeDataEntityListDataEntityListItem : allDataEntityListNode)
	{
		Data::DataEntityListItem dataEntityListItemObject;
		if(!dataNodeDataEntityListDataEntityListItem["TableName"].isNull())
			dataEntityListItemObject.tableName = dataNodeDataEntityListDataEntityListItem["TableName"].asString();
		if(!dataNodeDataEntityListDataEntityListItem["DatabaseName"].isNull())
			dataEntityListItemObject.databaseName = dataNodeDataEntityListDataEntityListItem["DatabaseName"].asString();
		if(!dataNodeDataEntityListDataEntityListItem["EntityType"].isNull())
			dataEntityListItemObject.entityType = std::stoi(dataNodeDataEntityListDataEntityListItem["EntityType"].asString());
		if(!dataNodeDataEntityListDataEntityListItem["ProjectName"].isNull())
			dataEntityListItemObject.projectName = dataNodeDataEntityListDataEntityListItem["ProjectName"].asString();
		if(!dataNodeDataEntityListDataEntityListItem["ProjectId"].isNull())
			dataEntityListItemObject.projectId = std::stol(dataNodeDataEntityListDataEntityListItem["ProjectId"].asString());
		if(!dataNodeDataEntityListDataEntityListItem["TableGuid"].isNull())
			dataEntityListItemObject.tableGuid = dataNodeDataEntityListDataEntityListItem["TableGuid"].asString();
		if(!dataNodeDataEntityListDataEntityListItem["OwnerId"].isNull())
			dataEntityListItemObject.ownerId = dataNodeDataEntityListDataEntityListItem["OwnerId"].asString();
		if(!dataNodeDataEntityListDataEntityListItem["ClusterId"].isNull())
			dataEntityListItemObject.clusterId = dataNodeDataEntityListDataEntityListItem["ClusterId"].asString();
		if(!dataNodeDataEntityListDataEntityListItem["EnvType"].isNull())
			dataEntityListItemObject.envType = std::stoi(dataNodeDataEntityListDataEntityListItem["EnvType"].asString());
		if(!dataNodeDataEntityListDataEntityListItem["TenantId"].isNull())
			dataEntityListItemObject.tenantId = std::stol(dataNodeDataEntityListDataEntityListItem["TenantId"].asString());
		if(!dataNodeDataEntityListDataEntityListItem["Schema"].isNull())
			dataEntityListItemObject.schema = dataNodeDataEntityListDataEntityListItem["Schema"].asString();
		data_.dataEntityList.push_back(dataEntityListItemObject);
	}
	if(!value["HttpStatusCode"].isNull())
		httpStatusCode_ = std::stoi(value["HttpStatusCode"].asString());
	if(!value["ErrorMessage"].isNull())
		errorMessage_ = value["ErrorMessage"].asString();
	if(!value["Success"].isNull())
		success_ = value["Success"].asString() == "true";
	if(!value["ErrorCode"].isNull())
		errorCode_ = value["ErrorCode"].asString();

}

int SearchMetaTablesResult::getHttpStatusCode()const
{
	return httpStatusCode_;
}

SearchMetaTablesResult::Data SearchMetaTablesResult::getData()const
{
	return data_;
}

std::string SearchMetaTablesResult::getErrorCode()const
{
	return errorCode_;
}

std::string SearchMetaTablesResult::getErrorMessage()const
{
	return errorMessage_;
}

bool SearchMetaTablesResult::getSuccess()const
{
	return success_;
}

