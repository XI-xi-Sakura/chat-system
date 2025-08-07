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

#ifndef ALIBABACLOUD_CCC_MODEL_STARTPREDICTIVECALLREQUEST_H_
#define ALIBABACLOUD_CCC_MODEL_STARTPREDICTIVECALLREQUEST_H_

#include <alibabacloud/ccc/CCCExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace CCC {
namespace Model {
class ALIBABACLOUD_CCC_EXPORT StartPredictiveCallRequest : public RpcServiceRequest {
public:
	StartPredictiveCallRequest();
	~StartPredictiveCallRequest();
	std::string getContactFlowId() const;
	void setContactFlowId(const std::string &contactFlowId);
	std::string getCallee() const;
	void setCallee(const std::string &callee);
	std::string getMaskedCallee() const;
	void setMaskedCallee(const std::string &maskedCallee);
	std::string getContactFlowVariables() const;
	void setContactFlowVariables(const std::string &contactFlowVariables);
	std::string getTags() const;
	void setTags(const std::string &tags);
	int getTimeoutSeconds() const;
	void setTimeoutSeconds(int timeoutSeconds);
	std::string getCaller() const;
	void setCaller(const std::string &caller);
	std::string getInstanceId() const;
	void setInstanceId(const std::string &instanceId);
	std::string getSkillGroupId() const;
	void setSkillGroupId(const std::string &skillGroupId);

private:
	std::string contactFlowId_;
	std::string callee_;
	std::string maskedCallee_;
	std::string contactFlowVariables_;
	std::string tags_;
	int timeoutSeconds_;
	std::string caller_;
	std::string instanceId_;
	std::string skillGroupId_;
};
} // namespace Model
} // namespace CCC
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_CCC_MODEL_STARTPREDICTIVECALLREQUEST_H_
