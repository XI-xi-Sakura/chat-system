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

#ifndef ALIBABACLOUD_ENS_MODEL_DESCRIBEENSEIPADDRESSESREQUEST_H_
#define ALIBABACLOUD_ENS_MODEL_DESCRIBEENSEIPADDRESSESREQUEST_H_

#include <alibabacloud/ens/EnsExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Ens {
namespace Model {
class ALIBABACLOUD_ENS_EXPORT DescribeEnsEipAddressesRequest : public RpcServiceRequest {
public:
	DescribeEnsEipAddressesRequest();
	~DescribeEnsEipAddressesRequest();
	std::string getEipName() const;
	void setEipName(const std::string &eipName);
	std::string getEipAddress() const;
	void setEipAddress(const std::string &eipAddress);
	std::string getEnsRegionId() const;
	void setEnsRegionId(const std::string &ensRegionId);
	std::string getStatus() const;
	void setStatus(const std::string &status);
	std::string getStandby() const;
	void setStandby(const std::string &standby);
	std::string getAllocationId() const;
	void setAllocationId(const std::string &allocationId);
	int getPageNumber() const;
	void setPageNumber(int pageNumber);
	std::string getAssociatedInstanceType() const;
	void setAssociatedInstanceType(const std::string &associatedInstanceType);
	int getPageSize() const;
	void setPageSize(int pageSize);
	std::string getAssociatedInstanceId() const;
	void setAssociatedInstanceId(const std::string &associatedInstanceId);

private:
	std::string eipName_;
	std::string eipAddress_;
	std::string ensRegionId_;
	std::string status_;
	std::string standby_;
	std::string allocationId_;
	int pageNumber_;
	std::string associatedInstanceType_;
	int pageSize_;
	std::string associatedInstanceId_;
};
} // namespace Model
} // namespace Ens
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_ENS_MODEL_DESCRIBEENSEIPADDRESSESREQUEST_H_
