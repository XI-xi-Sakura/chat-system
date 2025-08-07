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

#ifndef ALIBABACLOUD_ENS_MODEL_DEPLOYINSTANCESDGREQUEST_H_
#define ALIBABACLOUD_ENS_MODEL_DEPLOYINSTANCESDGREQUEST_H_

#include <alibabacloud/ens/EnsExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Ens {
namespace Model {
class ALIBABACLOUD_ENS_EXPORT DeployInstanceSDGRequest : public RpcServiceRequest {
public:
	DeployInstanceSDGRequest();
	~DeployInstanceSDGRequest();
	std::string getDeploymentType() const;
	void setDeploymentType(const std::string &deploymentType);
	std::string getSDGId() const;
	void setSDGId(const std::string &sDGId);
	std::vector<std::string> getInstanceIds() const;
	void setInstanceIds(const std::vector<std::string> &instanceIds);

private:
	std::string deploymentType_;
	std::string sDGId_;
	std::vector<std::string> instanceIds_;
};
} // namespace Model
} // namespace Ens
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_ENS_MODEL_DEPLOYINSTANCESDGREQUEST_H_
