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

#ifndef ALIBABACLOUD_SWAS_OPEN_MODEL_LISTSNAPSHOTSREQUEST_H_
#define ALIBABACLOUD_SWAS_OPEN_MODEL_LISTSNAPSHOTSREQUEST_H_

#include <alibabacloud/swas-open/SWAS_OPENExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace SWAS_OPEN {
namespace Model {
class ALIBABACLOUD_SWAS_OPEN_EXPORT ListSnapshotsRequest : public RpcServiceRequest {
public:
	struct Tag {
		std::string key;
		std::string value;
	};
	ListSnapshotsRequest();
	~ListSnapshotsRequest();
	std::string getSnapshotIds() const;
	void setSnapshotIds(const std::string &snapshotIds);
	int getPageNumber() const;
	void setPageNumber(int pageNumber);
	std::string getResourceGroupId() const;
	void setResourceGroupId(const std::string &resourceGroupId);
	std::string getRegionId() const;
	void setRegionId(const std::string &regionId);
	int getPageSize() const;
	void setPageSize(int pageSize);
	std::string getDiskId() const;
	void setDiskId(const std::string &diskId);
	std::vector<Tag> getTag() const;
	void setTag(const std::vector<Tag> &tag);
	std::string getSourceDiskType() const;
	void setSourceDiskType(const std::string &sourceDiskType);
	std::string getInstanceId() const;
	void setInstanceId(const std::string &instanceId);

private:
	std::string snapshotIds_;
	int pageNumber_;
	std::string resourceGroupId_;
	std::string regionId_;
	int pageSize_;
	std::string diskId_;
	std::vector<Tag> tag_;
	std::string sourceDiskType_;
	std::string instanceId_;
};
} // namespace Model
} // namespace SWAS_OPEN
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_SWAS_OPEN_MODEL_LISTSNAPSHOTSREQUEST_H_
