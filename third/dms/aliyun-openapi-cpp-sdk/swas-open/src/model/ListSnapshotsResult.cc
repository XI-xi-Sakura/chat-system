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

#include <alibabacloud/swas-open/model/ListSnapshotsResult.h>
#include <json/json.h>

using namespace AlibabaCloud::SWAS_OPEN;
using namespace AlibabaCloud::SWAS_OPEN::Model;

ListSnapshotsResult::ListSnapshotsResult() :
	ServiceResult()
{}

ListSnapshotsResult::ListSnapshotsResult(const std::string &payload) :
	ServiceResult()
{
	parse(payload);
}

ListSnapshotsResult::~ListSnapshotsResult()
{}

void ListSnapshotsResult::parse(const std::string &payload)
{
	Json::Reader reader;
	Json::Value value;
	reader.parse(payload, value);
	setRequestId(value["RequestId"].asString());
	auto allSnapshotsNode = value["Snapshots"]["Snapshot"];
	for (auto valueSnapshotsSnapshot : allSnapshotsNode)
	{
		Snapshot snapshotsObject;
		if(!valueSnapshotsSnapshot["Status"].isNull())
			snapshotsObject.status = valueSnapshotsSnapshot["Status"].asString();
		if(!valueSnapshotsSnapshot["CreationTime"].isNull())
			snapshotsObject.creationTime = valueSnapshotsSnapshot["CreationTime"].asString();
		if(!valueSnapshotsSnapshot["SourceDiskId"].isNull())
			snapshotsObject.sourceDiskId = valueSnapshotsSnapshot["SourceDiskId"].asString();
		if(!valueSnapshotsSnapshot["SnapshotName"].isNull())
			snapshotsObject.snapshotName = valueSnapshotsSnapshot["SnapshotName"].asString();
		if(!valueSnapshotsSnapshot["Progress"].isNull())
			snapshotsObject.progress = valueSnapshotsSnapshot["Progress"].asString();
		if(!valueSnapshotsSnapshot["Remark"].isNull())
			snapshotsObject.remark = valueSnapshotsSnapshot["Remark"].asString();
		if(!valueSnapshotsSnapshot["SnapshotId"].isNull())
			snapshotsObject.snapshotId = valueSnapshotsSnapshot["SnapshotId"].asString();
		if(!valueSnapshotsSnapshot["SourceDiskType"].isNull())
			snapshotsObject.sourceDiskType = valueSnapshotsSnapshot["SourceDiskType"].asString();
		if(!valueSnapshotsSnapshot["RegionId"].isNull())
			snapshotsObject.regionId = valueSnapshotsSnapshot["RegionId"].asString();
		if(!valueSnapshotsSnapshot["InstanceId"].isNull())
			snapshotsObject.instanceId = valueSnapshotsSnapshot["InstanceId"].asString();
		if(!valueSnapshotsSnapshot["RollbackTime"].isNull())
			snapshotsObject.rollbackTime = valueSnapshotsSnapshot["RollbackTime"].asString();
		if(!valueSnapshotsSnapshot["ResourceGroupId"].isNull())
			snapshotsObject.resourceGroupId = valueSnapshotsSnapshot["ResourceGroupId"].asString();
		auto allTagsNode = valueSnapshotsSnapshot["Tags"]["tag"];
		for (auto valueSnapshotsSnapshotTagstag : allTagsNode)
		{
			Snapshot::Tag tagsObject;
			if(!valueSnapshotsSnapshotTagstag["Key"].isNull())
				tagsObject.key = valueSnapshotsSnapshotTagstag["Key"].asString();
			if(!valueSnapshotsSnapshotTagstag["Value"].isNull())
				tagsObject.value = valueSnapshotsSnapshotTagstag["Value"].asString();
			snapshotsObject.tags.push_back(tagsObject);
		}
		snapshots_.push_back(snapshotsObject);
	}
	if(!value["TotalCount"].isNull())
		totalCount_ = std::stoi(value["TotalCount"].asString());
	if(!value["PageSize"].isNull())
		pageSize_ = std::stoi(value["PageSize"].asString());
	if(!value["PageNumber"].isNull())
		pageNumber_ = std::stoi(value["PageNumber"].asString());

}

int ListSnapshotsResult::getTotalCount()const
{
	return totalCount_;
}

int ListSnapshotsResult::getPageSize()const
{
	return pageSize_;
}

int ListSnapshotsResult::getPageNumber()const
{
	return pageNumber_;
}

std::vector<ListSnapshotsResult::Snapshot> ListSnapshotsResult::getSnapshots()const
{
	return snapshots_;
}

