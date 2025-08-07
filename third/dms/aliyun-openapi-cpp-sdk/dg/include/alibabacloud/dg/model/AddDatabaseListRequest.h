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

#ifndef ALIBABACLOUD_DG_MODEL_ADDDATABASELISTREQUEST_H_
#define ALIBABACLOUD_DG_MODEL_ADDDATABASELISTREQUEST_H_

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
			class ALIBABACLOUD_DG_EXPORT AddDatabaseListRequest : public RpcServiceRequest
			{

			public:
				AddDatabaseListRequest();
				~AddDatabaseListRequest();

				std::string getDatabaseString()const;
				void setDatabaseString(const std::string& databaseString);
				std::string getClientToken()const;
				void setClientToken(const std::string& clientToken);

            private:
				std::string databaseString_;
				std::string clientToken_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_DG_MODEL_ADDDATABASELISTREQUEST_H_