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

#ifndef ALIBABACLOUD_ECD_MODEL_LISTOFFICESITEOVERVIEWREQUEST_H_
#define ALIBABACLOUD_ECD_MODEL_LISTOFFICESITEOVERVIEWREQUEST_H_

#include <alibabacloud/ecd/EcdExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Ecd {
namespace Model {
class ALIBABACLOUD_ECD_EXPORT ListOfficeSiteOverviewRequest : public RpcServiceRequest {
public:
	ListOfficeSiteOverviewRequest();
	~ListOfficeSiteOverviewRequest();
	std::vector<std::string> getOfficeSiteId() const;
	void setOfficeSiteId(const std::vector<std::string> &officeSiteId);
	int getQueryRange() const;
	void setQueryRange(int queryRange);
	std::string getRegionId() const;
	void setRegionId(const std::string &regionId);
	bool getForceRefresh() const;
	void setForceRefresh(bool forceRefresh);
	std::string getNextToken() const;
	void setNextToken(const std::string &nextToken);
	int getMaxResults() const;
	void setMaxResults(int maxResults);

private:
	std::vector<std::string> officeSiteId_;
	int queryRange_;
	std::string regionId_;
	bool forceRefresh_;
	std::string nextToken_;
	int maxResults_;
};
} // namespace Model
} // namespace Ecd
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_ECD_MODEL_LISTOFFICESITEOVERVIEWREQUEST_H_
