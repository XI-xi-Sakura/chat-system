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

#ifndef ALIBABACLOUD_OOS_MODEL_CREATESECRETPARAMETERREQUEST_H_
#define ALIBABACLOUD_OOS_MODEL_CREATESECRETPARAMETERREQUEST_H_

#include <alibabacloud/oos/OosExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Oos {
namespace Model {
class ALIBABACLOUD_OOS_EXPORT CreateSecretParameterRequest : public RpcServiceRequest {
public:
	CreateSecretParameterRequest();
	~CreateSecretParameterRequest();
	std::string getClientToken() const;
	void setClientToken(const std::string &clientToken);
	std::string getDescription() const;
	void setDescription(const std::string &description);
	std::string getType() const;
	void setType(const std::string &type);
	std::string getConstraints() const;
	void setConstraints(const std::string &constraints);
	std::string getResourceGroupId() const;
	void setResourceGroupId(const std::string &resourceGroupId);
	std::string getRegionId() const;
	void setRegionId(const std::string &regionId);
	std::string getValue() const;
	void setValue(const std::string &value);
	std::string getKeyId() const;
	void setKeyId(const std::string &keyId);
	std::map<std::string, std::string> getTags() const;
	void setTags(const std::map<std::string, std::string> &tags);
	std::string getName() const;
	void setName(const std::string &name);

private:
	std::string clientToken_;
	std::string description_;
	std::string type_;
	std::string constraints_;
	std::string resourceGroupId_;
	std::string regionId_;
	std::string value_;
	std::string keyId_;
	std::map<std::string, std::string> tags_;
	std::string name_;
};
} // namespace Model
} // namespace Oos
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_OOS_MODEL_CREATESECRETPARAMETERREQUEST_H_
