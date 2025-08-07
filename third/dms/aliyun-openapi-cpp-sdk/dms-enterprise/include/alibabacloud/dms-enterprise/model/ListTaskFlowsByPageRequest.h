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

#ifndef ALIBABACLOUD_DMS_ENTERPRISE_MODEL_LISTTASKFLOWSBYPAGEREQUEST_H_
#define ALIBABACLOUD_DMS_ENTERPRISE_MODEL_LISTTASKFLOWSBYPAGEREQUEST_H_

#include <alibabacloud/dms-enterprise/Dms_enterpriseExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Dms_enterprise {
namespace Model {
class ALIBABACLOUD_DMS_ENTERPRISE_EXPORT ListTaskFlowsByPageRequest : public RpcServiceRequest {
public:
	ListTaskFlowsByPageRequest();
	~ListTaskFlowsByPageRequest();
	std::string getSearchKey() const;
	void setSearchKey(const std::string &searchKey);
	std::vector<long> getDagIdList() const;
	void setDagIdList(const std::vector<long> &dagIdList);
	long getTid() const;
	void setTid(long tid);
	int getPageSize() const;
	void setPageSize(int pageSize);
	int getPageIndex() const;
	void setPageIndex(int pageIndex);
	long getScenarioId() const;
	void setScenarioId(long scenarioId);
	bool getNeedLastDagInstance() const;
	void setNeedLastDagInstance(bool needLastDagInstance);

private:
	std::string searchKey_;
	std::vector<long> dagIdList_;
	long tid_;
	int pageSize_;
	int pageIndex_;
	long scenarioId_;
	bool needLastDagInstance_;
};
} // namespace Model
} // namespace Dms_enterprise
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_DMS_ENTERPRISE_MODEL_LISTTASKFLOWSBYPAGEREQUEST_H_
