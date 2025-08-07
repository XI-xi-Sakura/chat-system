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

#ifndef ALIBABACLOUD_MTS_MODEL_LISTMEDIAWORKFLOWEXECUTIONSREQUEST_H_
#define ALIBABACLOUD_MTS_MODEL_LISTMEDIAWORKFLOWEXECUTIONSREQUEST_H_

#include <alibabacloud/mts/MtsExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Mts {
namespace Model {
class ALIBABACLOUD_MTS_EXPORT ListMediaWorkflowExecutionsRequest : public RpcServiceRequest {
public:
	ListMediaWorkflowExecutionsRequest();
	~ListMediaWorkflowExecutionsRequest();
	long getResourceOwnerId() const;
	void setResourceOwnerId(long resourceOwnerId);
	std::string getNextPageToken() const;
	void setNextPageToken(const std::string &nextPageToken);
	std::string getAccessKeyId() const;
	void setAccessKeyId(const std::string &accessKeyId);
	std::string getMediaWorkflowId() const;
	void setMediaWorkflowId(const std::string &mediaWorkflowId);
	std::string getResourceOwnerAccount() const;
	void setResourceOwnerAccount(const std::string &resourceOwnerAccount);
	std::string getOwnerAccount() const;
	void setOwnerAccount(const std::string &ownerAccount);
	long getMaximumPageSize() const;
	void setMaximumPageSize(long maximumPageSize);
	long getOwnerId() const;
	void setOwnerId(long ownerId);
	std::string getMediaWorkflowName() const;
	void setMediaWorkflowName(const std::string &mediaWorkflowName);
	std::string getInputFileURL() const;
	void setInputFileURL(const std::string &inputFileURL);

private:
	long resourceOwnerId_;
	std::string nextPageToken_;
	std::string accessKeyId_;
	std::string mediaWorkflowId_;
	std::string resourceOwnerAccount_;
	std::string ownerAccount_;
	long maximumPageSize_;
	long ownerId_;
	std::string mediaWorkflowName_;
	std::string inputFileURL_;
};
} // namespace Model
} // namespace Mts
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_MTS_MODEL_LISTMEDIAWORKFLOWEXECUTIONSREQUEST_H_
