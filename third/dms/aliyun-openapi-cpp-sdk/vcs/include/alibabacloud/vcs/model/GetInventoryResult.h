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

#ifndef ALIBABACLOUD_VCS_MODEL_GETINVENTORYRESULT_H_
#define ALIBABACLOUD_VCS_MODEL_GETINVENTORYRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/vcs/VcsExport.h>

namespace AlibabaCloud
{
	namespace Vcs
	{
		namespace Model
		{
			class ALIBABACLOUD_VCS_EXPORT GetInventoryResult : public ServiceResult
			{
			public:
				struct Data
				{
					struct ResultObjectItem
					{
						std::string buyerId;
						std::string instanceId;
						std::string currentInventory;
						std::string commodityCode;
						std::string validEndTime;
						std::string validStartTime;
						std::string inventoryId;
					};
					std::vector<ResultObjectItem> resultObject;
				};


				GetInventoryResult();
				explicit GetInventoryResult(const std::string &payload);
				~GetInventoryResult();
				Data getData()const;
				bool getSuccess()const;

			protected:
				void parse(const std::string &payload);
			private:
				Data data_;
				bool success_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_VCS_MODEL_GETINVENTORYRESULT_H_