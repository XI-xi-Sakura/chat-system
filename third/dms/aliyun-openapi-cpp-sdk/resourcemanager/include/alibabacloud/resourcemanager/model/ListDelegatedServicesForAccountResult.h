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

#ifndef ALIBABACLOUD_RESOURCEMANAGER_MODEL_LISTDELEGATEDSERVICESFORACCOUNTRESULT_H_
#define ALIBABACLOUD_RESOURCEMANAGER_MODEL_LISTDELEGATEDSERVICESFORACCOUNTRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/resourcemanager/ResourceManagerExport.h>

namespace AlibabaCloud
{
	namespace ResourceManager
	{
		namespace Model
		{
			class ALIBABACLOUD_RESOURCEMANAGER_EXPORT ListDelegatedServicesForAccountResult : public ServiceResult
			{
			public:
				struct DelegatedService
				{
					std::string status;
					std::string delegationEnabledTime;
					std::string servicePrincipal;
				};


				ListDelegatedServicesForAccountResult();
				explicit ListDelegatedServicesForAccountResult(const std::string &payload);
				~ListDelegatedServicesForAccountResult();
				std::vector<DelegatedService> getDelegatedServices()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::vector<DelegatedService> delegatedServices_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_RESOURCEMANAGER_MODEL_LISTDELEGATEDSERVICESFORACCOUNTRESULT_H_