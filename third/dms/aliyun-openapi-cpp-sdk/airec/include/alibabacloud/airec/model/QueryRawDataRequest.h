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

#ifndef ALIBABACLOUD_AIREC_MODEL_QUERYRAWDATAREQUEST_H_
#define ALIBABACLOUD_AIREC_MODEL_QUERYRAWDATAREQUEST_H_

#include <string>
#include <vector>
#include <alibabacloud/core/RoaServiceRequest.h>
#include <alibabacloud/airec/AirecExport.h>

namespace AlibabaCloud
{
	namespace Airec
	{
		namespace Model
		{
			class ALIBABACLOUD_AIREC_EXPORT QueryRawDataRequest : public RoaServiceRequest
			{

			public:
				QueryRawDataRequest();
				~QueryRawDataRequest();

				std::string getItemId()const;
				void setItemId(const std::string& itemId);
				std::string getInstanceId()const;
				void setInstanceId(const std::string& instanceId);
				std::string getItemType()const;
				void setItemType(const std::string& itemType);
				std::string getUserType()const;
				void setUserType(const std::string& userType);
				std::string getUserId()const;
				void setUserId(const std::string& userId);
				std::string getTable()const;
				void setTable(const std::string& table);

            private:
				std::string itemId_;
				std::string instanceId_;
				std::string itemType_;
				std::string userType_;
				std::string userId_;
				std::string table_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_AIREC_MODEL_QUERYRAWDATAREQUEST_H_