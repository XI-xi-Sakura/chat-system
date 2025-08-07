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

#ifndef ALIBABACLOUD_DMS_ENTERPRISE_MODEL_LISTPROXYACCESSESRESULT_H_
#define ALIBABACLOUD_DMS_ENTERPRISE_MODEL_LISTPROXYACCESSESRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/dms-enterprise/Dms_enterpriseExport.h>

namespace AlibabaCloud
{
	namespace Dms_enterprise
	{
		namespace Model
		{
			class ALIBABACLOUD_DMS_ENTERPRISE_EXPORT ListProxyAccessesResult : public ServiceResult
			{
			public:
				struct ProxyAccessListItem
				{
					std::string gmtCreate;
					std::string userName;
					std::string accessId;
					long instanceId;
					long userId;
					std::string userUid;
					long proxyId;
					long proxyAccessId;
					std::string originInfo;
					std::string indepAccount;
				};


				ListProxyAccessesResult();
				explicit ListProxyAccessesResult(const std::string &payload);
				~ListProxyAccessesResult();
				std::string getErrorCode()const;
				std::string getErrorMessage()const;
				bool getSuccess()const;
				std::vector<ProxyAccessListItem> getProxyAccessList()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string errorCode_;
				std::string errorMessage_;
				bool success_;
				std::vector<ProxyAccessListItem> proxyAccessList_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_DMS_ENTERPRISE_MODEL_LISTPROXYACCESSESRESULT_H_