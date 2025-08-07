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

#ifndef ALIBABACLOUD_DOMAIN_MODEL_LISTSERVERLOCKRESULT_H_
#define ALIBABACLOUD_DOMAIN_MODEL_LISTSERVERLOCKRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/domain/DomainExport.h>

namespace AlibabaCloud
{
	namespace Domain
	{
		namespace Model
		{
			class ALIBABACLOUD_DOMAIN_EXPORT ListServerLockResult : public ServiceResult
			{
			public:
				struct QueryTransferInResponse
				{
					std::string startDate;
					std::string gmtCreate;
					std::string expireDate;
					std::string domainName;
					std::string userId;
					std::string gmtModified;
					std::string domainInstanceId;
					std::string lockInstanceId;
					std::string serverLockStatus;
					std::string lockProductId;
				};


				ListServerLockResult();
				explicit ListServerLockResult(const std::string &payload);
				~ListServerLockResult();
				bool getPrePage()const;
				int getCurrentPageNum()const;
				int getPageSize()const;
				int getTotalPageNum()const;
				std::vector<QueryTransferInResponse> getData()const;
				int getTotalItemNum()const;
				bool getNextPage()const;

			protected:
				void parse(const std::string &payload);
			private:
				bool prePage_;
				int currentPageNum_;
				int pageSize_;
				int totalPageNum_;
				std::vector<QueryTransferInResponse> data_;
				int totalItemNum_;
				bool nextPage_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_DOMAIN_MODEL_LISTSERVERLOCKRESULT_H_