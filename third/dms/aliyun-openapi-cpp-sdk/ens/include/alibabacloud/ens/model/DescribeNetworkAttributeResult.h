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

#ifndef ALIBABACLOUD_ENS_MODEL_DESCRIBENETWORKATTRIBUTERESULT_H_
#define ALIBABACLOUD_ENS_MODEL_DESCRIBENETWORKATTRIBUTERESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/ens/EnsExport.h>

namespace AlibabaCloud
{
	namespace Ens
	{
		namespace Model
		{
			class ALIBABACLOUD_ENS_EXPORT DescribeNetworkAttributeResult : public ServiceResult
			{
			public:
				struct CloudResourceSetType
				{
					int resourceCount;
					std::string resourceType;
				};


				DescribeNetworkAttributeResult();
				explicit DescribeNetworkAttributeResult(const std::string &payload);
				~DescribeNetworkAttributeResult();
				std::string getStatus()const;
				std::string getNetworkName()const;
				std::string getGatewayRouteTableId()const;
				std::string getDescription()const;
				std::string getCreatedTime()const;
				std::string getRouteTableId()const;
				std::string getNetworkAclId()const;
				std::vector<std::string> getVSwitchIds()const;
				std::vector<std::string> getLoadBalancerIds()const;
				std::string getCidrBlock()const;
				std::vector<std::string> getNetworkInterfaceIds()const;
				std::string getNetworkId()const;
				std::vector<std::string> getNatGatewayIds()const;
				std::vector<std::string> getRouteTableIds()const;
				std::vector<std::string> getHaVipIds()const;
				std::string getRouterTableId()const;
				std::vector<std::string> getInstanceIds()const;
				std::string getEnsRegionId()const;
				std::vector<CloudResourceSetType> getCloudResources()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string status_;
				std::string networkName_;
				std::string gatewayRouteTableId_;
				std::string description_;
				std::string createdTime_;
				std::string routeTableId_;
				std::string networkAclId_;
				std::vector<std::string> vSwitchIds_;
				std::vector<std::string> loadBalancerIds_;
				std::string cidrBlock_;
				std::vector<std::string> networkInterfaceIds_;
				std::string networkId_;
				std::vector<std::string> natGatewayIds_;
				std::vector<std::string> routeTableIds_;
				std::vector<std::string> haVipIds_;
				std::string routerTableId_;
				std::vector<std::string> instanceIds_;
				std::string ensRegionId_;
				std::vector<CloudResourceSetType> cloudResources_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_ENS_MODEL_DESCRIBENETWORKATTRIBUTERESULT_H_