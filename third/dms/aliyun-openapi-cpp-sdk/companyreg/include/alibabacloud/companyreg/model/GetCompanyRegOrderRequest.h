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

#ifndef ALIBABACLOUD_COMPANYREG_MODEL_GETCOMPANYREGORDERREQUEST_H_
#define ALIBABACLOUD_COMPANYREG_MODEL_GETCOMPANYREGORDERREQUEST_H_

#include <string>
#include <vector>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <alibabacloud/companyreg/CompanyregExport.h>

namespace AlibabaCloud
{
	namespace Companyreg
	{
		namespace Model
		{
			class ALIBABACLOUD_COMPANYREG_EXPORT GetCompanyRegOrderRequest : public RpcServiceRequest
			{

			public:
				GetCompanyRegOrderRequest();
				~GetCompanyRegOrderRequest();

				std::string getActionTypes()const;
				void setActionTypes(const std::string& actionTypes);
				std::string getBizCode()const;
				void setBizCode(const std::string& bizCode);
				std::string getBizId()const;
				void setBizId(const std::string& bizId);
				int getMaxOperationSize()const;
				void setMaxOperationSize(int maxOperationSize);
				std::string getBizSubCode()const;
				void setBizSubCode(const std::string& bizSubCode);

            private:
				std::string actionTypes_;
				std::string bizCode_;
				std::string bizId_;
				int maxOperationSize_;
				std::string bizSubCode_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_COMPANYREG_MODEL_GETCOMPANYREGORDERREQUEST_H_