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

#ifndef ALIBABACLOUD_COMPUTENEST_MODEL_LISTSERVICEINSTANCESREQUEST_H_
#define ALIBABACLOUD_COMPUTENEST_MODEL_LISTSERVICEINSTANCESREQUEST_H_

#include <alibabacloud/computenest/ComputeNestExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace ComputeNest {
namespace Model {
class ALIBABACLOUD_COMPUTENEST_EXPORT ListServiceInstancesRequest : public RpcServiceRequest {
public:
	struct Tag {
		std::string value;
		std::string key;
	};
	struct Filter {
		std::string name;
	};
	ListServiceInstancesRequest();
	~ListServiceInstancesRequest();
	std::string getResourceGroupId() const;
	void setResourceGroupId(const std::string &resourceGroupId);
	std::string getRegionId() const;
	void setRegionId(const std::string &regionId);
	std::string getNextToken() const;
	void setNextToken(const std::string &nextToken);
	std::vector<Tag> getTag() const;
	void setTag(const std::vector<Tag> &tag);
	std::vector<Filter> getFilter() const;
	void setFilter(const std::vector<Filter> &filter);
	int getMaxResults() const;
	void setMaxResults(int maxResults);

private:
	std::string resourceGroupId_;
	std::string regionId_;
	std::string nextToken_;
	std::vector<Tag> tag_;
	std::vector<Filter> filter_;
	int maxResults_;
};
} // namespace Model
} // namespace ComputeNest
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_COMPUTENEST_MODEL_LISTSERVICEINSTANCESREQUEST_H_
