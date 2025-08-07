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

#ifndef ALIBABACLOUD_SCDN_MODEL_DESCRIBESCDNUSERDOMAINSRESULT_H_
#define ALIBABACLOUD_SCDN_MODEL_DESCRIBESCDNUSERDOMAINSRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/scdn/ScdnExport.h>

namespace AlibabaCloud
{
	namespace Scdn
	{
		namespace Model
		{
			class ALIBABACLOUD_SCDN_EXPORT DescribeScdnUserDomainsResult : public ServiceResult
			{
			public:
				struct PageData
				{
					struct Source
					{
						std::string type;
						std::string priority;
						std::string content;
						int port;
					};
					std::string description;
					std::string resourceGroupId;
					std::string domainName;
					std::string gmtModified;
					std::string gmtCreated;
					std::vector<PageData::Source> sources;
					std::string cname;
					std::string domainStatus;
					std::string sSLProtocol;
					std::string sandbox;
				};


				DescribeScdnUserDomainsResult();
				explicit DescribeScdnUserDomainsResult(const std::string &payload);
				~DescribeScdnUserDomainsResult();
				std::vector<PageData> getDomains()const;
				long getTotalCount()const;
				long getPageSize()const;
				long getPageNumber()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::vector<PageData> domains_;
				long totalCount_;
				long pageSize_;
				long pageNumber_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_SCDN_MODEL_DESCRIBESCDNUSERDOMAINSRESULT_H_