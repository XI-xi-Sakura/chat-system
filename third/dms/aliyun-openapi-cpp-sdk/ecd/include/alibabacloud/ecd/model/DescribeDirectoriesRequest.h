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

#ifndef ALIBABACLOUD_ECD_MODEL_DESCRIBEDIRECTORIESREQUEST_H_
#define ALIBABACLOUD_ECD_MODEL_DESCRIBEDIRECTORIESREQUEST_H_

#include <alibabacloud/ecd/EcdExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Ecd {
namespace Model {
class ALIBABACLOUD_ECD_EXPORT DescribeDirectoriesRequest : public RpcServiceRequest {
public:
	DescribeDirectoriesRequest();
	~DescribeDirectoriesRequest();
	std::string getDirectoryType() const;
	void setDirectoryType(const std::string &directoryType);
	std::string getRegionId() const;
	void setRegionId(const std::string &regionId);
	std::string getNextToken() const;
	void setNextToken(const std::string &nextToken);
	std::string getDirectoryStatus() const;
	void setDirectoryStatus(const std::string &directoryStatus);
	int getMaxResults() const;
	void setMaxResults(int maxResults);
	std::vector<std::string> getDirectoryId() const;
	void setDirectoryId(const std::vector<std::string> &directoryId);
	std::string getStatus() const;
	void setStatus(const std::string &status);

private:
	std::string directoryType_;
	std::string regionId_;
	std::string nextToken_;
	std::string directoryStatus_;
	int maxResults_;
	std::vector<std::string> directoryId_;
	std::string status_;
};
} // namespace Model
} // namespace Ecd
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_ECD_MODEL_DESCRIBEDIRECTORIESREQUEST_H_
