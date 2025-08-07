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

#ifndef ALIBABACLOUD_COMPANYREG_MODEL_BINDPRODUCEAUTHORIZATIONRESULT_H_
#define ALIBABACLOUD_COMPANYREG_MODEL_BINDPRODUCEAUTHORIZATIONRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/companyreg/CompanyregExport.h>

namespace AlibabaCloud
{
	namespace Companyreg
	{
		namespace Model
		{
			class ALIBABACLOUD_COMPANYREG_EXPORT BindProduceAuthorizationResult : public ServiceResult
			{
			public:
				struct Data
				{
					struct AuthorizedUserListItem
					{
						int accountValidType;
						std::string userName;
						std::string userId;
					};
					std::string message;
					std::vector<AuthorizedUserListItem> authorizedUserList;
					bool success;
				};


				BindProduceAuthorizationResult();
				explicit BindProduceAuthorizationResult(const std::string &payload);
				~BindProduceAuthorizationResult();
				std::string getErrorMsg()const;
				Data getData()const;
				std::string getErrorCode()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string errorMsg_;
				Data data_;
				std::string errorCode_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_COMPANYREG_MODEL_BINDPRODUCEAUTHORIZATIONRESULT_H_