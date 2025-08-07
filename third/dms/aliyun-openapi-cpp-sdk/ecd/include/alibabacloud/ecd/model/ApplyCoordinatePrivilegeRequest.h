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

#ifndef ALIBABACLOUD_ECD_MODEL_APPLYCOORDINATEPRIVILEGEREQUEST_H_
#define ALIBABACLOUD_ECD_MODEL_APPLYCOORDINATEPRIVILEGEREQUEST_H_

#include <alibabacloud/ecd/EcdExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Ecd {
namespace Model {
class ALIBABACLOUD_ECD_EXPORT ApplyCoordinatePrivilegeRequest : public RpcServiceRequest {
public:
	ApplyCoordinatePrivilegeRequest();
	~ApplyCoordinatePrivilegeRequest();
	std::string getCoId() const;
	void setCoId(const std::string &coId);
	std::string getUserType() const;
	void setUserType(const std::string &userType);
	std::string getUuid() const;
	void setUuid(const std::string &uuid);
	std::string getRegionId() const;
	void setRegionId(const std::string &regionId);
	std::string getEndUserId() const;
	void setEndUserId(const std::string &endUserId);

private:
	std::string coId_;
	std::string userType_;
	std::string uuid_;
	std::string regionId_;
	std::string endUserId_;
};
} // namespace Model
} // namespace Ecd
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_ECD_MODEL_APPLYCOORDINATEPRIVILEGEREQUEST_H_
