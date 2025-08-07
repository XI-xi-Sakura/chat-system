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

#ifndef ALIBABACLOUD_DG_MODEL_GETUSERGATEWAYSREQUEST_H_
#define ALIBABACLOUD_DG_MODEL_GETUSERGATEWAYSREQUEST_H_

#include <string>
#include <vector>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <alibabacloud/dg/DgExport.h>

namespace AlibabaCloud
{
	namespace Dg
	{
		namespace Model
		{
			class ALIBABACLOUD_DG_EXPORT GetUserGatewaysRequest : public RpcServiceRequest
			{

			public:
				GetUserGatewaysRequest();
				~GetUserGatewaysRequest();

				std::string getSearchKey()const;
				void setSearchKey(const std::string& searchKey);
				int getPageNumber()const;
				void setPageNumber(int pageNumber);
				std::string getRegionId()const;
				void setRegionId(const std::string& regionId);
				int getPageSize()const;
				void setPageSize(int pageSize);

            private:
				std::string searchKey_;
				int pageNumber_;
				std::string regionId_;
				int pageSize_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_DG_MODEL_GETUSERGATEWAYSREQUEST_H_