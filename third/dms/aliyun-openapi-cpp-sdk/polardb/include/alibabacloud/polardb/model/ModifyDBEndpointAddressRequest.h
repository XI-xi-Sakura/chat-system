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

#ifndef ALIBABACLOUD_POLARDB_MODEL_MODIFYDBENDPOINTADDRESSREQUEST_H_
#define ALIBABACLOUD_POLARDB_MODEL_MODIFYDBENDPOINTADDRESSREQUEST_H_

#include <alibabacloud/polardb/PolardbExport.h>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace Polardb {
namespace Model {
class ALIBABACLOUD_POLARDB_EXPORT ModifyDBEndpointAddressRequest : public RpcServiceRequest {
public:
	ModifyDBEndpointAddressRequest();
	~ModifyDBEndpointAddressRequest();
	long getResourceOwnerId() const;
	void setResourceOwnerId(long resourceOwnerId);
	std::string getConnectionStringPrefix() const;
	void setConnectionStringPrefix(const std::string &connectionStringPrefix);
	std::string getDBEndpointId() const;
	void setDBEndpointId(const std::string &dBEndpointId);
	std::string getAccessKeyId() const;
	void setAccessKeyId(const std::string &accessKeyId);
	std::string getPrivateZoneName() const;
	void setPrivateZoneName(const std::string &privateZoneName);
	std::string getPrivateZoneAddressPrefix() const;
	void setPrivateZoneAddressPrefix(const std::string &privateZoneAddressPrefix);
	std::string getResourceOwnerAccount() const;
	void setResourceOwnerAccount(const std::string &resourceOwnerAccount);
	std::string getDBClusterId() const;
	void setDBClusterId(const std::string &dBClusterId);
	std::string getOwnerAccount() const;
	void setOwnerAccount(const std::string &ownerAccount);
	long getOwnerId() const;
	void setOwnerId(long ownerId);
	std::string getVSwitchId() const;
	void setVSwitchId(const std::string &vSwitchId);
	std::string getPort() const;
	void setPort(const std::string &port);
	std::string getNetType() const;
	void setNetType(const std::string &netType);
	std::string getVPCId() const;
	void setVPCId(const std::string &vPCId);

private:
	long resourceOwnerId_;
	std::string connectionStringPrefix_;
	std::string dBEndpointId_;
	std::string accessKeyId_;
	std::string privateZoneName_;
	std::string privateZoneAddressPrefix_;
	std::string resourceOwnerAccount_;
	std::string dBClusterId_;
	std::string ownerAccount_;
	long ownerId_;
	std::string vSwitchId_;
	std::string port_;
	std::string netType_;
	std::string vPCId_;
};
} // namespace Model
} // namespace Polardb
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_POLARDB_MODEL_MODIFYDBENDPOINTADDRESSREQUEST_H_
